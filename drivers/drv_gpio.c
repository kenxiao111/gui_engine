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
#include "drv_gpio.h"

/*******************************************************************************
* Function Name: cy_pin_write
****************************************************************************//**
* This function is mainly used to GPIO output
*
* \param dev
* Do not use, keep it in line with RT-thread API
*
* \param pin
* The pin name such as: P0_4, P11_2 etc.
*
* \param value
* The output value.
*
* \return
* None.
*
*******************************************************************************/
static void cy_pin_write(rt_device_t dev, rt_base_t pin, rt_base_t value)
{
	cyhal_gpio_write(pin, value);
    return;
}

/*******************************************************************************
* Function Name: cy_pin_read
****************************************************************************//**
* This function is mainly used to GPIO input
*
* \param dev
* Do not use, keep it in line with RT-thread API
*
* \param pin
* The pin name such as: P0_4, P11_2 etc.
*
* \return
* The pin's value
*
*******************************************************************************/
static int cy_pin_read(rt_device_t dev, rt_base_t pin)
{
	return cyhal_gpio_read(pin);
}

/*******************************************************************************
* Function Name: cy_pin_mode
****************************************************************************//**
* Initialize the GPIO, the usage as:
*  cy_pin_mode( dev, P0_4, (CYHAL_GPIO_DRIVE_PULLUP<<4) | CYHAL_GPIO_DIR_OUTPUT) )
*
* \param dev
* Do not use, keep it in line with RT-thread API
*
* \param pin
* The pin name such as: P0_4, P11_2 etc.
*
* \param mode
* bit8  bit7  bit6  bit5  bit4   bit3  bit2  bit1  bit0
*  |     |     |      |     |     x     x     x     x
*    cyhal_gpio_drive_mode_t
*                                 |     |     |     |
*                                cyhal_gpio_direction_t
*
* \return
* None
*
*******************************************************************************/
static void cy_pin_mode(rt_device_t dev, rt_base_t pin, rt_base_t mode)
{
	cyhal_gpio_init(pin, mode&0x0F, mode>>4, 0);
}


const static struct rt_pin_ops _cy_pin_ops =
{
    cy_pin_mode,
    cy_pin_write,
    cy_pin_read,
    RT_NULL,
    RT_NULL,
    RT_NULL,
};

rt_uint16_t rt_hw_pin_init(void)
{
	rt_uint16_t ret;
	ret = rt_device_pin_register("pin", &_cy_pin_ops, RT_NULL);
	return ret;
}
