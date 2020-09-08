/******************************************************************************
* File Name: main.c
*
* Version 1.0
*
* Description:  Demonstrates read/write operation to external memory by using
* Serial memory interface(SMIF) in Quad Serial peripheral interface (QSPI) mode.
* This example also checks the integrity of the read data against written data.
*
* Related Document: CE220823_PSoC6_SMIFMemWriteAndRead.pdf
*
*******************************************************************************
* Copyright (2018-2019), Cypress Semiconductor Corporation. All rights reserved.
*******************************************************************************
* This software, including source code, documentation and related materials
* (“Software”), is owned by Cypress Semiconductor Corporation or one of its
* subsidiaries (“Cypress”) and is protected by and subject to worldwide patent
* protection (United States and foreign), United States copyright laws and
* international treaty provisions. Therefore, you may use this Software only
* as provided in the license agreement accompanying the software package from
* which you obtained this Software (“EULA”).
*
* If no EULA applies, Cypress hereby grants you a personal, nonexclusive,
* non-transferable license to copy, modify, and compile the Software source
* code solely for use in connection with Cypress’s integrated circuit products.
* Any reproduction, modification, translation, compilation, or representation
* of this Software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death (“High Risk Product”). By
* including Cypress’s product in a High Risk Product, the manufacturer of such
* system or application assumes all risk of such use and in doing so agrees to
* indemnify Cypress against all liability.
*******************************************************************************/
#include "cy_pdl.h"
#include "cyhal.h"
#include "cybsp.h"
#include "cycfg.h"
#include "lcd_qspi.h"
#include "lcd_port.h"
#if 1
//#include "cy_retarget_io.h"
//#include "smif_mem.h"

//#include "slider.h"

extern unsigned char demoPic1[];
extern unsigned char demoPic2[];

/***************************************************************************
* Global constants
***************************************************************************/
#define SMIF_PRIORITY       (1u)      /* SMIF interrupt priority */
#define TIMEOUT_1_MS        (1000ul)  /* 1 ms timeout for all blocking functions */
#define ONEWIRECMD			(0x02)	  /* 1wire flag command */
#define FOURWIRECMD			(0x32)	  /* 4wire flag command */
#define	QSPIBUFSIZE			(7)
//#define DEMOBUFSIZE			(360*360*3)
#define	ROWNUMONETIME		(40u)

#define SWITCH_INTR_PRIORITY	(3u)
#define	PATTERNNUM			(2u)
#define	BMPPICTURE1			(1u)
#define	BMPPICTURE2			(2u)

/***************************************************************************
* Global variables
***************************************************************************/
cy_stc_smif_context_t KIT_QSPI_context;
uint8_t qspiBuf[QSPIBUFSIZE];
//uint8_t rowDataBuf[DEMOBUFSIZE];

// Switch interrupt configuration structure
const cy_stc_sysint_t switch_intr_config = {
	.intrSrc = ioss_interrupts_gpio_0_IRQn,		/* Source of interrupt signal */
	.intrPriority = SWITCH_INTR_PRIORITY		/* Interrupt priority */
};

// Global variable
uint32_t interrupt_flag = false;
uint32_t pattern_index = BMPPICTURE1;

/***************************************************************************
* Forward declaration
***************************************************************************/
void Isr_SMIF(void);
void SMIF_Init(void);
void WriteCmd(uint8_t pCmd);
void WriteCmdParameter(uint8_t pCmd, uint8_t *pPara, uint8_t pParaSize);
void WriteDisplayData(uint8_t *pDisData, uint32_t pSize);
void DMA_Configure(uint8_t * pDMASrc);

/***************************************************************************
* Function Name: main.c
***************************************************************************/
int SMIF_lcd_drawpic(void * image)
{
    for(int j=0; j<(LCD_WIDTH/ROWNUMONETIME); j++)
    {
    	qspiBuf[0] = (ROWNUMONETIME*j >> 8);
		qspiBuf[1] = ROWNUMONETIME*j;
		qspiBuf[2] = ((ROWNUMONETIME*j + (ROWNUMONETIME-1)) >> 8);
		qspiBuf[3] = ROWNUMONETIME*j + (ROWNUMONETIME-1);
    	WriteCmdParameter(0x2B,qspiBuf,4);				//set row position

    	DMA_Configure((image + ROWNUMONETIME*1080*j));

		WriteDisplayData(NULL, ROWNUMONETIME*1080);		//transmit display data
    }
    return 0;
}

void DMA_Configure(uint8_t * pDMASrc)
{
	/* set the source and destination of transfer in the descriptor config structure */
	SMIF_Tx_DMA_Descriptor_0_config.srcAddress = pDMASrc;
	SMIF_Tx_DMA_Descriptor_0_config.dstAddress = (uint32_t *) &KIT_QSPI_HW->TX_DATA_FIFO_WR4;

	/* Initialize the Descriptor for the DMA channel */
	Cy_DMAC_Descriptor_Init(&SMIF_Tx_DMA_Descriptor_0, &SMIF_Tx_DMA_Descriptor_0_config);

	/* Initialize the DMA channel */
	Cy_DMAC_Channel_Init(SMIF_Tx_DMA_HW, SMIF_Tx_DMA_CHANNEL, &SMIF_Tx_DMA_channelConfig);

	Cy_DMAC_Enable(SMIF_Tx_DMA_HW);
}


void WriteDisplayData(uint8_t *pDisData, uint32_t pSize)
{
	uint8_t cmdBuf[4];
	cmdBuf[0] = 0x00;
	cmdBuf[1] = 0x2C;
	cmdBuf[2] = 0x00;

	Cy_SMIF_TransmitCommand( KIT_QSPI_HW,
							 FOURWIRECMD,				//quad flag command
							 CY_SMIF_WIDTH_SINGLE,
							 cmdBuf,
							 3,
							 CY_SMIF_WIDTH_SINGLE,
							 CY_SMIF_SLAVE_SELECT_3,
							 CY_SMIF_TX_NOT_LAST_BYTE,
							 &KIT_QSPI_context);

	Cy_SMIF_TransmitData( KIT_QSPI_HW,
						  pDisData,
						  pSize,
						  CY_SMIF_WIDTH_QUAD,	//quad mode
						  NULL,
						  &KIT_QSPI_context);

	Cy_DMAC_Channel_Enable(SMIF_Tx_DMA_HW, SMIF_Tx_DMA_CHANNEL);

	while(Cy_SMIF_BusyCheck(KIT_QSPI_HW));

}



void WriteCmd(uint8_t pCmd)
{
	uint8_t cmdBuf[4];
	cmdBuf[0] = 0x00;
	cmdBuf[1] = pCmd;
	cmdBuf[2] = 0x00;


	Cy_SMIF_TransmitCommand( KIT_QSPI_HW,
			                 ONEWIRECMD,
							 CY_SMIF_WIDTH_SINGLE,
							 cmdBuf,
							 3,
							 CY_SMIF_WIDTH_SINGLE,
							 CY_SMIF_SLAVE_SELECT_3,
							 CY_SMIF_TX_LAST_BYTE,
							 &KIT_QSPI_context);

	while(Cy_SMIF_BusyCheck(KIT_QSPI_HW));
}

void WriteCmdParameter(uint8_t pCmd, uint8_t *pPara, uint8_t pParaSize)
{
	uint8_t cmdParBuf[10];
	cmdParBuf[0] = 0x00;
	cmdParBuf[1] = pCmd;
	cmdParBuf[2] = 0x00;

	for(int i=0; i<pParaSize; i++)
	{
		cmdParBuf[3+i] = *(pPara+i);
	}


	Cy_SMIF_TransmitCommand( KIT_QSPI_HW,
			                 ONEWIRECMD,
							 CY_SMIF_WIDTH_SINGLE,
							 cmdParBuf,
							 (pParaSize+3),
							 CY_SMIF_WIDTH_SINGLE,
							 CY_SMIF_SLAVE_SELECT_3,
							 CY_SMIF_TX_LAST_BYTE,
							 &KIT_QSPI_context);

	while(Cy_SMIF_BusyCheck(KIT_QSPI_HW));
}


void OLEDInit(void)
{
	Cy_GPIO_Write(OLED_RST_PORT, OLED_RST_NUM, 1);
	Cy_SysLib_Delay(10/*msec*/);
	Cy_GPIO_Write(OLED_RST_PORT, OLED_RST_NUM, 0);
	Cy_SysLib_Delay(10/*msec*/);
	Cy_GPIO_Write(OLED_RST_PORT, OLED_RST_NUM, 1);

	qspiBuf[0] = 0x01;
	WriteCmdParameter(0xFE,qspiBuf,1);

	qspiBuf[0] = 0x23;
	WriteCmdParameter(0x6A,qspiBuf,1);

	qspiBuf[0] = 0x00;
	WriteCmdParameter(0xFE,qspiBuf,1);

	qspiBuf[0] = 0x80;
	WriteCmdParameter(0xC4,qspiBuf,1);

    qspiBuf[0] = 0xFF;
    WriteCmdParameter(0x51,qspiBuf,1);

    qspiBuf[0] = 0x00;
    WriteCmdParameter(0x35,qspiBuf,1);

	qspiBuf[0] = 0x00;
	WriteCmdParameter(0x11,qspiBuf,1);
    Cy_SysLib_Delay(200);

	qspiBuf[0] = 0x00;
	WriteCmdParameter(0x29,qspiBuf,1);
	Cy_SysLib_Delay(200);
}


void SMIF_Init(void)
{
	/* Initialize SMIF */
	Cy_SMIF_Init(KIT_QSPI_HW, &KIT_QSPI_config, TIMEOUT_1_MS, &KIT_QSPI_context);

	/* Configure data select, refer the kit schematics to choose the right configuration */
	Cy_SMIF_SetDataSelect(KIT_QSPI_HW, CY_SMIF_SLAVE_SELECT_3, CY_SMIF_DATA_SEL2);
	Cy_SMIF_Enable(KIT_QSPI_HW, &KIT_QSPI_context);

	/* Configure SMIF interrupt */
	cy_stc_sysint_t smifIntConfig =
	{
	   .intrSrc = KIT_QSPI_IRQ,     /* SMIF interrupt */
	   .intrPriority = SMIF_PRIORITY       /* SMIF interrupt priority */
	};

	/* SMIF interrupt initialization status */
	Cy_SysInt_Init(&smifIntConfig, Isr_SMIF);


	/* Enable the SMIF interrupt */
	NVIC_EnableIRQ(smif_interrupt_IRQn);

	Cy_SysLib_Delay(10/*msec*/);
}

/*******************************************************************************
* Function Name: Isr_SMIF
********************************************************************************
*
* The ISR for the SMIF interrupt. All Read/Write transfers to/from the external
* memory are processed inside the SMIF ISR.
*
*******************************************************************************/
void Isr_SMIF(void)
{
    Cy_SMIF_Interrupt(KIT_QSPI_HW, &KIT_QSPI_context);
}


int SMIF_lcd_init(void)
{
	init_cycfg_all();
	__enable_irq();
	Cy_GPIO_Write(BackupControl_PORT, BackupControl_NUM, 0);
	CyDelay(1000);
    SMIF_Init();	//initial SMIF
    OLEDInit();

	qspiBuf[0] = 0x00;
	qspiBuf[1] = 0x00;
	qspiBuf[2] = 0x01;
	qspiBuf[3] = 0x67;
	Cy_SMIF_SetTxFifoTriggerLevel(KIT_QSPI_HW, 3);
	WriteCmdParameter(0x2A,qspiBuf,4);					//set column position
	return 0;
}
#endif
