/******************************************************************************
* File Name:   main.c
*
* Description: This is the source code for the Empty PSoC6 Application
*              for ModusToolbox.
*
* Related Document: See Readme.md
*
*
*******************************************************************************
* (c) 2019, Cypress Semiconductor Corporation. All rights reserved.
*******************************************************************************
* This software, including source code, documentation and related materials
* ("Software"), is owned by Cypress Semiconductor Corporation or one of its
* subsidiaries ("Cypress") and is protected by and subject to worldwide patent
* protection (United States and foreign), United States copyright laws and
* international treaty provisions. Therefore, you may use this Software only
* as provided in the license agreement accompanying the software package from
* which you obtained this Software ("EULA").
*
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software source
* code solely for use in connection with Cypress's integrated circuit products.
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
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer of such
* system or application assumes all risk of such use and in doing so agrees to
* indemnify Cypress against all liability.
*******************************************************************************/

#include "cy_pdl.h"
#include "cycfg.h"
#include "cy_device_headers.h"
#include "cycfg_peripherals.h"
#include <rtthread.h>
#include "board.h"
#include "cybsp.h"
#include "cyhal.h"
#include "drv_gpio.h"

#ifdef RT_USING_FINSH
#include <finsh.h>
#include <shell.h>
#endif

#define THREAD_STACK_SIZE    512
#define THREAD_PRIORITY      8
#define THREAD_TIMESLICE     20

rt_thread_t led_tid;

//extern int drv_lcd_hw_init(void);


void led_entry(void *param)
{
	rt_pin_mode(P7_4, CYHAL_GPIO_DRIVE_STRONG<<4 | CYHAL_GPIO_DIR_OUTPUT);
	rt_pin_mode(P7_5, CYHAL_GPIO_DRIVE_STRONG<<4 | CYHAL_GPIO_DIR_OUTPUT);
	rt_pin_mode(P7_6, CYHAL_GPIO_DRIVE_STRONG<<4 | CYHAL_GPIO_DIR_OUTPUT);

	rt_pin_write(P7_4, 1);
	rt_pin_write(P7_5, 1);
	rt_pin_write(P7_6, 1);

	while (1)
	{
		rt_kprintf("LED blink\n");
		rt_pin_write(P7_4, 1);
		rt_pin_write(P7_6, 0);
		rt_thread_mdelay(400);
		rt_pin_write(P7_6, 1);
		rt_pin_write(P7_5, 0);
		rt_thread_mdelay(400);
		rt_pin_write(P7_5, 1);
		rt_pin_write(P7_4, 0);
		rt_thread_mdelay(400);
	}
}

void led_thread(void)
{
	led_tid = rt_thread_create("led", led_entry, RT_NULL, THREAD_STACK_SIZE, 24, THREAD_TIMESLICE);
	//led_tid = rt_thread_create("led", led_entry, RT_NULL, THREAD_STACK_SIZE, RT_THREAD_PRIORITY_MAX - 2, THREAD_TIMESLICE);
	if (RT_NULL != led_tid)
	{
		rt_thread_startup(led_tid);
	}
}
//INIT_DEVICE_EXPORT(led_thread);
int main(void)
{

//	drv_lcd_hw_init();
//	lcd_test();

//	led_thread();
    for(;;)
    {

    	rt_thread_mdelay(1000);
    }
}

//MSH_CMD_EXPORT(led_thread, LED example);

/* [] END OF FILE */
