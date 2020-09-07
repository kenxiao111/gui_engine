/*******************************************************************************
* File Name: cycfg_pins.c
*
* Description:
* Pin configuration
* This file was automatically generated and should not be modified.
* Tools Package 2.1.0.1266
* psoc6pdl 1.5.2.3446
* personalities_2.0 2.0.0.0
* udd 1.2.0.136
*
********************************************************************************
* Copyright 2020 Cypress Semiconductor Corporation
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
********************************************************************************/

#include "cycfg_pins.h"

const cy_stc_gpio_pin_config_t OLED_RST_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_STRONG_IN_OFF,
	.hsiom = OLED_RST_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t OLED_RST_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = OLED_RST_PORT_NUM,
		.channel_num = OLED_RST_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t QSPI_CLK_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_STRONG_IN_OFF,
	.hsiom = QSPI_CLK_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t QSPI_CLK_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = QSPI_CLK_PORT_NUM,
		.channel_num = QSPI_CLK_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t QSPI_D0_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_STRONG,
	.hsiom = QSPI_D0_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t QSPI_D0_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = QSPI_D0_PORT_NUM,
		.channel_num = QSPI_D0_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t QSPI_D1_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_STRONG,
	.hsiom = QSPI_D1_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t QSPI_D1_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = QSPI_D1_PORT_NUM,
		.channel_num = QSPI_D1_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t QSPI_D2_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_STRONG,
	.hsiom = QSPI_D2_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t QSPI_D2_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = QSPI_D2_PORT_NUM,
		.channel_num = QSPI_D2_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t QSPI_D3_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_STRONG,
	.hsiom = QSPI_D3_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t QSPI_D3_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = QSPI_D3_PORT_NUM,
		.channel_num = QSPI_D3_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t QSPI_CS_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_STRONG_IN_OFF,
	.hsiom = QSPI_CS_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t QSPI_CS_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = QSPI_CS_PORT_NUM,
		.channel_num = QSPI_CS_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t ioss_0_port_4_pin_0_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_HIGHZ,
	.hsiom = ioss_0_port_4_pin_0_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t ioss_0_port_4_pin_0_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = ioss_0_port_4_pin_0_PORT_NUM,
		.channel_num = ioss_0_port_4_pin_0_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t ioss_0_port_4_pin_1_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_STRONG_IN_OFF,
	.hsiom = ioss_0_port_4_pin_1_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t ioss_0_port_4_pin_1_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = ioss_0_port_4_pin_1_PORT_NUM,
		.channel_num = ioss_0_port_4_pin_1_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t ioss_0_port_5_pin_0_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_HIGHZ,
	.hsiom = ioss_0_port_5_pin_0_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t ioss_0_port_5_pin_0_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = ioss_0_port_5_pin_0_PORT_NUM,
		.channel_num = ioss_0_port_5_pin_0_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t ioss_0_port_5_pin_1_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_STRONG_IN_OFF,
	.hsiom = ioss_0_port_5_pin_1_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t ioss_0_port_5_pin_1_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = ioss_0_port_5_pin_1_PORT_NUM,
		.channel_num = ioss_0_port_5_pin_1_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t BackupControl_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_STRONG_IN_OFF,
	.hsiom = BackupControl_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t BackupControl_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = BackupControl_PORT_NUM,
		.channel_num = BackupControl_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t CYBSP_SWO_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_STRONG_IN_OFF,
	.hsiom = CYBSP_SWO_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t CYBSP_SWO_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = CYBSP_SWO_PORT_NUM,
		.channel_num = CYBSP_SWO_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t CYBSP_SWDIO_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_PULLUP,
	.hsiom = CYBSP_SWDIO_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t CYBSP_SWDIO_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = CYBSP_SWDIO_PORT_NUM,
		.channel_num = CYBSP_SWDIO_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t CYBSP_SWDCK_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_PULLDOWN,
	.hsiom = CYBSP_SWDCK_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t CYBSP_SWDCK_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = CYBSP_SWDCK_PORT_NUM,
		.channel_num = CYBSP_SWDCK_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t CYBSP_CINA_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_ANALOG,
	.hsiom = CYBSP_CINA_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t CYBSP_CINA_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = CYBSP_CINA_PORT_NUM,
		.channel_num = CYBSP_CINA_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t CYBSP_CINB_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_ANALOG,
	.hsiom = CYBSP_CINB_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t CYBSP_CINB_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = CYBSP_CINB_PORT_NUM,
		.channel_num = CYBSP_CINB_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t CYBSP_CMOD_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_ANALOG,
	.hsiom = CYBSP_CMOD_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t CYBSP_CMOD_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = CYBSP_CMOD_PORT_NUM,
		.channel_num = CYBSP_CMOD_PIN,
	};
#endif //defined (CY_USING_HAL)


void init_cycfg_pins(void)
{
	Cy_GPIO_Pin_Init(OLED_RST_PORT, OLED_RST_PIN, &OLED_RST_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&OLED_RST_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(QSPI_CLK_PORT, QSPI_CLK_PIN, &QSPI_CLK_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&QSPI_CLK_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(QSPI_D0_PORT, QSPI_D0_PIN, &QSPI_D0_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&QSPI_D0_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(QSPI_D1_PORT, QSPI_D1_PIN, &QSPI_D1_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&QSPI_D1_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(QSPI_D2_PORT, QSPI_D2_PIN, &QSPI_D2_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&QSPI_D2_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(QSPI_D3_PORT, QSPI_D3_PIN, &QSPI_D3_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&QSPI_D3_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(QSPI_CS_PORT, QSPI_CS_PIN, &QSPI_CS_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&QSPI_CS_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(ioss_0_port_4_pin_0_PORT, ioss_0_port_4_pin_0_PIN, &ioss_0_port_4_pin_0_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&ioss_0_port_4_pin_0_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(ioss_0_port_4_pin_1_PORT, ioss_0_port_4_pin_1_PIN, &ioss_0_port_4_pin_1_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&ioss_0_port_4_pin_1_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(ioss_0_port_5_pin_0_PORT, ioss_0_port_5_pin_0_PIN, &ioss_0_port_5_pin_0_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&ioss_0_port_5_pin_0_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(ioss_0_port_5_pin_1_PORT, ioss_0_port_5_pin_1_PIN, &ioss_0_port_5_pin_1_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&ioss_0_port_5_pin_1_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(BackupControl_PORT, BackupControl_PIN, &BackupControl_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&BackupControl_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(CYBSP_SWO_PORT, CYBSP_SWO_PIN, &CYBSP_SWO_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&CYBSP_SWO_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(CYBSP_SWDIO_PORT, CYBSP_SWDIO_PIN, &CYBSP_SWDIO_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&CYBSP_SWDIO_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(CYBSP_SWDCK_PORT, CYBSP_SWDCK_PIN, &CYBSP_SWDCK_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&CYBSP_SWDCK_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(CYBSP_CINA_PORT, CYBSP_CINA_PIN, &CYBSP_CINA_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&CYBSP_CINA_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(CYBSP_CINB_PORT, CYBSP_CINB_PIN, &CYBSP_CINB_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&CYBSP_CINB_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(CYBSP_CMOD_PORT, CYBSP_CMOD_PIN, &CYBSP_CMOD_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&CYBSP_CMOD_obj);
#endif //defined (CY_USING_HAL)
}
