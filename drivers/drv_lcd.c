/***************************************************************************//**
* \file drv_gpio.h
*
* Description:
* Provides APIs for rt-thread IO device
*
********************************************************************************
* \copyright
* Copyright 2018-2020 Cypress Semiconductor Corporation
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
*******************************************************************************/

#include <board.h>
#include "drv_lcd.h"

#ifdef BSP_USING_LCD
#include <lcd_port.h>
#include <string.h>

//#define DRV_DEBUG
#define LOG_TAG             "drv.lcd"
#include <drv_log.h>

#define LCD_DEVICE(dev)     (struct drv_lcd_device*)(dev)

//static LTDC_HandleTypeDef LtdcHandle = {0};

struct drv_lcd_device
{
    struct rt_device parent;

    struct rt_device_graphic_info lcd_info;

    struct rt_semaphore lcd_lock;

};

struct drv_lcd_device _lcd;

static rt_err_t drv_lcd_init(struct rt_device *device)
{
    struct drv_lcd_device *lcd = LCD_DEVICE(device);
    /* nothing, right now */
    lcd = lcd;
    return RT_EOK;
}

static rt_err_t drv_lcd_control(struct rt_device *device, int cmd, void *args)
{
    struct drv_lcd_device *lcd = LCD_DEVICE(device);

    switch (cmd)
    {
		case RTGRAPHIC_CTRL_RECT_UPDATE:
		{
		   /* back_buf is being used */
	//		memcpy(_lcd.front_buf, _lcd.lcd_info.framebuffer, LCD_BUF_SIZE);
			/* Configure the color frame buffer start address */
	//           LTDC_LAYER(&LtdcHandle, 0)->CFBAR &= ~(LTDC_LxCFBAR_CFBADD);
	//           LTDC_LAYER(&LtdcHandle, 0)->CFBAR = (uint32_t)(_lcd.front_buf);
			lcd_drawpic(_lcd.lcd_info.framebuffer);
//			rt_sem_take(&_lcd.lcd_lock, RT_TICK_PER_SECOND / 20);
	 //       HAL_LTDC_Relaod(&LtdcHandle, LTDC_SRCR_VBR);
		}
		break;

		case RTGRAPHIC_CTRL_GET_INFO:
		{
			struct rt_device_graphic_info *info = (struct rt_device_graphic_info *)args;

			RT_ASSERT(info != RT_NULL);
			info->pixel_format  = lcd->lcd_info.pixel_format;
			info->bits_per_pixel = LCD_BITS_PER_PIXEL;
			info->width         = lcd->lcd_info.width;
			info->height        = lcd->lcd_info.height;
			info->framebuffer   = lcd->lcd_info.framebuffer;
		}
		break;
		case RTGRAPHIC_CTRL_GET_EXT:
		break;
		default:
		break;
    }

    return RT_EOK;
}

//void HAL_LTDC_ReloadEventCallback(LTDC_HandleTypeDef *hltdc)
//{
//    /* emable line interupt */
//    __HAL_LTDC_ENABLE_IT(&LtdcHandle, LTDC_IER_LIE);
//}

//void HAL_LTDC_LineEventCallback(LTDC_HandleTypeDef *hltdc)
//{
//    rt_sem_release(&_lcd.lcd_lock);
//}

void LTDC_IRQHandler(void)
{
//    rt_enter_critical();

//    HAL_LTDC_IRQHandler(&LtdcHandle);

//    rt_exit_critical();
}
#if defined(LCD_BACKLIGHT_USING_PWM)
void turn_on_lcd_backlight(void)
{
    struct rt_device_pwm *pwm_dev;

    /* turn on the LCD backlight */
    pwm_dev = (struct rt_device_pwm *)rt_device_find(LCD_PWM_DEV_NAME);
    /* pwm frequency:100K = 10000ns */
    rt_pwm_set(pwm_dev, LCD_PWM_DEV_CHANNEL, 10000, 10000);
    rt_pwm_enable(pwm_dev, LCD_PWM_DEV_CHANNEL);
}
#elif defined(LCD_BACKLIGHT_USING_GPIO)
void turn_on_lcd_backlight(void)
{
    rt_pin_mode(LCD_BL_GPIO_NUM, PIN_MODE_OUTPUT);
    rt_pin_mode(LCD_DISP_GPIO_NUM, PIN_MODE_OUTPUT);

    rt_pin_write(LCD_DISP_GPIO_NUM, PIN_HIGH);
    rt_pin_write(LCD_BL_GPIO_NUM, PIN_HIGH);
}
#else
void turn_on_lcd_backlight(void)
{

}
#endif

#ifdef RT_USING_DEVICE_OPS
const static struct rt_device_ops lcd_ops =
{
    drv_lcd_init,
    RT_NULL,
    RT_NULL,
    RT_NULL,
    RT_NULL,
    drv_lcd_control
};
#endif

int drv_lcd_hw_init(void)
{
    rt_err_t result = RT_EOK;
    struct rt_device *device = &_lcd.parent;

    /* memset _lcd to zero */
    memset(&_lcd, 0x00, sizeof(_lcd));

    /* init lcd_lock semaphore */
    result = rt_sem_init(&_lcd.lcd_lock, "lcd_lock", 0, RT_IPC_FLAG_FIFO);
    if (result != RT_EOK)
    {
        LOG_E("init semaphore failed!\n");
        result = -RT_ENOMEM;
        goto __exit;
    }

    /* config LCD dev info */
    _lcd.lcd_info.height = LCD_HEIGHT;
    _lcd.lcd_info.width = LCD_WIDTH;
    _lcd.lcd_info.bits_per_pixel = LCD_BITS_PER_PIXEL;
    _lcd.lcd_info.pixel_format = LCD_PIXEL_FORMAT;

    /* malloc memory for Triple Buffering */
    _lcd.lcd_info.framebuffer = rt_malloc(LCD_BUF_SIZE);
    if (_lcd.lcd_info.framebuffer == RT_NULL)
    {
        LOG_E("init frame buffer failed!\n");
        result = -RT_ENOMEM;
        goto __exit;
    }

    /* memset buff to 0xFF */
    memset(_lcd.lcd_info.framebuffer, 0xFF, LCD_BUF_SIZE);

    device->type    = RT_Device_Class_Graphic;
#ifdef RT_USING_DEVICE_OPS
    device->ops     = &lcd_ops;
#else
    device->init    = drv_lcd_init;
    device->control = drv_lcd_control;
#endif

    /* register lcd device */
    rt_device_register(device, "lcd", RT_DEVICE_FLAG_RDWR);

    /* init stm32 LTDC */
    if (LCD_init(&_lcd) != RT_EOK)
    {
        result = -RT_ERROR;
        goto __exit;
    }
    else
    {
        turn_on_lcd_backlight();
    }

__exit:
    if (result != RT_EOK)
    {
        rt_sem_delete(&_lcd.lcd_lock);

        if (_lcd.lcd_info.framebuffer)
        {
            rt_free(_lcd.lcd_info.framebuffer);
        }
    }
    return result;
}
INIT_DEVICE_EXPORT(drv_lcd_hw_init);

#ifdef PKG_USING_GUIENGINE
#include <rtgui/driver.h>
static int graphic_device_init(void)
{
    struct rt_device *device;
    device = rt_device_find("lcd");
    if (device)
    {
        rtgui_graphic_set_device(device);
    }
    else
    {
        rt_kprintf("can't find lcd device\r\n");
    }

    return 0;
}
INIT_ENV_EXPORT(graphic_device_init);
#endif

int lcd_test(void)
{
    struct drv_lcd_device *lcd;
    lcd = (struct drv_lcd_device *)rt_device_find("lcd");

    while (1)
    {
        /* red */
        for (int i = 0; i < LCD_BUF_SIZE / 2; i++)
        {
            lcd->lcd_info.framebuffer[2 * i] = 0x00;
            lcd->lcd_info.framebuffer[2 * i + 1] = 0xF8;
        }
        lcd->parent.control(&lcd->parent, RTGRAPHIC_CTRL_RECT_UPDATE, RT_NULL);
//        rt_thread_mdelay(1000);
        /* green */
        for (int i = 0; i < LCD_BUF_SIZE / 2; i++)
        {
            lcd->lcd_info.framebuffer[2 * i] = 0xE0;
            lcd->lcd_info.framebuffer[2 * i + 1] = 0x07;
        }
        lcd->parent.control(&lcd->parent, RTGRAPHIC_CTRL_RECT_UPDATE, RT_NULL);
//        rt_thread_mdelay(1000);
        /* blue */
        for (int i = 0; i < LCD_BUF_SIZE / 2; i++)
        {
            lcd->lcd_info.framebuffer[2 * i] = 0x1F;
            lcd->lcd_info.framebuffer[2 * i + 1] = 0x00;
        }
        lcd->parent.control(&lcd->parent, RTGRAPHIC_CTRL_RECT_UPDATE, RT_NULL);
//        rt_thread_mdelay(1000);
    }
}
//MSH_CMD_EXPORT(lcd_test, lcd_test);

#endif /* BSP_USING_LCD */

