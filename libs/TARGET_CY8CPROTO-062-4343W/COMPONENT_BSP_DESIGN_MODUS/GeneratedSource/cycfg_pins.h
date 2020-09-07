/*******************************************************************************
* File Name: cycfg_pins.h
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

#if !defined(CYCFG_PINS_H)
#define CYCFG_PINS_H

#include "cycfg_notices.h"
#include "cy_gpio.h"
#if defined (CY_USING_HAL)
	#include "cyhal_hwmgr.h"
#endif //defined (CY_USING_HAL)
#include "cycfg_routing.h"

#if defined(__cplusplus)
extern "C" {
#endif

#define OLED_RST_ENABLED 1U
#define OLED_RST_PORT GPIO_PRT0
#define OLED_RST_PORT_NUM 0U
#define OLED_RST_PIN 3U
#define OLED_RST_NUM 3U
#define OLED_RST_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define OLED_RST_INIT_DRIVESTATE 1
#ifndef ioss_0_port_0_pin_3_HSIOM
	#define ioss_0_port_0_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define OLED_RST_HSIOM ioss_0_port_0_pin_3_HSIOM
#define OLED_RST_IRQ ioss_interrupts_gpio_0_IRQn
#if defined (CY_USING_HAL)
	#define OLED_RST_HAL_PORT_PIN P0_3
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define OLED_RST_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define OLED_RST_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define OLED_RST_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define QSPI_CLK_ENABLED 1U
#define QSPI_CLK_PORT GPIO_PRT11
#define QSPI_CLK_PORT_NUM 11U
#define QSPI_CLK_PIN 7U
#define QSPI_CLK_NUM 7U
#define QSPI_CLK_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define QSPI_CLK_INIT_DRIVESTATE 1
#ifndef ioss_0_port_11_pin_7_HSIOM
	#define ioss_0_port_11_pin_7_HSIOM HSIOM_SEL_GPIO
#endif
#define QSPI_CLK_HSIOM ioss_0_port_11_pin_7_HSIOM
#define QSPI_CLK_IRQ ioss_interrupts_gpio_11_IRQn
#if defined (CY_USING_HAL)
	#define QSPI_CLK_HAL_PORT_PIN P11_7
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define QSPI_CLK_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define QSPI_CLK_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define QSPI_CLK_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define QSPI_D0_ENABLED 1U
#define QSPI_D0_PORT GPIO_PRT12
#define QSPI_D0_PORT_NUM 12U
#define QSPI_D0_PIN 0U
#define QSPI_D0_NUM 0U
#define QSPI_D0_DRIVEMODE CY_GPIO_DM_STRONG
#define QSPI_D0_INIT_DRIVESTATE 1
#ifndef ioss_0_port_12_pin_0_HSIOM
	#define ioss_0_port_12_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define QSPI_D0_HSIOM ioss_0_port_12_pin_0_HSIOM
#define QSPI_D0_IRQ ioss_interrupts_gpio_12_IRQn
#if defined (CY_USING_HAL)
	#define QSPI_D0_HAL_PORT_PIN P12_0
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define QSPI_D0_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define QSPI_D0_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define QSPI_D0_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define QSPI_D1_ENABLED 1U
#define QSPI_D1_PORT GPIO_PRT12
#define QSPI_D1_PORT_NUM 12U
#define QSPI_D1_PIN 1U
#define QSPI_D1_NUM 1U
#define QSPI_D1_DRIVEMODE CY_GPIO_DM_STRONG
#define QSPI_D1_INIT_DRIVESTATE 1
#ifndef ioss_0_port_12_pin_1_HSIOM
	#define ioss_0_port_12_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define QSPI_D1_HSIOM ioss_0_port_12_pin_1_HSIOM
#define QSPI_D1_IRQ ioss_interrupts_gpio_12_IRQn
#if defined (CY_USING_HAL)
	#define QSPI_D1_HAL_PORT_PIN P12_1
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define QSPI_D1_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define QSPI_D1_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define QSPI_D1_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define QSPI_D2_ENABLED 1U
#define QSPI_D2_PORT GPIO_PRT12
#define QSPI_D2_PORT_NUM 12U
#define QSPI_D2_PIN 2U
#define QSPI_D2_NUM 2U
#define QSPI_D2_DRIVEMODE CY_GPIO_DM_STRONG
#define QSPI_D2_INIT_DRIVESTATE 1
#ifndef ioss_0_port_12_pin_2_HSIOM
	#define ioss_0_port_12_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define QSPI_D2_HSIOM ioss_0_port_12_pin_2_HSIOM
#define QSPI_D2_IRQ ioss_interrupts_gpio_12_IRQn
#if defined (CY_USING_HAL)
	#define QSPI_D2_HAL_PORT_PIN P12_2
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define QSPI_D2_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define QSPI_D2_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define QSPI_D2_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define QSPI_D3_ENABLED 1U
#define QSPI_D3_PORT GPIO_PRT12
#define QSPI_D3_PORT_NUM 12U
#define QSPI_D3_PIN 3U
#define QSPI_D3_NUM 3U
#define QSPI_D3_DRIVEMODE CY_GPIO_DM_STRONG
#define QSPI_D3_INIT_DRIVESTATE 1
#ifndef ioss_0_port_12_pin_3_HSIOM
	#define ioss_0_port_12_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define QSPI_D3_HSIOM ioss_0_port_12_pin_3_HSIOM
#define QSPI_D3_IRQ ioss_interrupts_gpio_12_IRQn
#if defined (CY_USING_HAL)
	#define QSPI_D3_HAL_PORT_PIN P12_3
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define QSPI_D3_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define QSPI_D3_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define QSPI_D3_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define QSPI_CS_ENABLED 1U
#define QSPI_CS_PORT GPIO_PRT12
#define QSPI_CS_PORT_NUM 12U
#define QSPI_CS_PIN 4U
#define QSPI_CS_NUM 4U
#define QSPI_CS_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define QSPI_CS_INIT_DRIVESTATE 1
#ifndef ioss_0_port_12_pin_4_HSIOM
	#define ioss_0_port_12_pin_4_HSIOM HSIOM_SEL_GPIO
#endif
#define QSPI_CS_HSIOM ioss_0_port_12_pin_4_HSIOM
#define QSPI_CS_IRQ ioss_interrupts_gpio_12_IRQn
#if defined (CY_USING_HAL)
	#define QSPI_CS_HAL_PORT_PIN P12_4
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define QSPI_CS_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define QSPI_CS_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define QSPI_CS_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define ioss_0_port_4_pin_0_ENABLED 1U
#define ioss_0_port_4_pin_0_PORT GPIO_PRT4
#define ioss_0_port_4_pin_0_PORT_NUM 4U
#define ioss_0_port_4_pin_0_PIN 0U
#define ioss_0_port_4_pin_0_NUM 0U
#define ioss_0_port_4_pin_0_DRIVEMODE CY_GPIO_DM_HIGHZ
#define ioss_0_port_4_pin_0_INIT_DRIVESTATE 1
#ifndef ioss_0_port_4_pin_0_HSIOM
	#define ioss_0_port_4_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_4_pin_0_IRQ ioss_interrupts_gpio_4_IRQn
#if defined (CY_USING_HAL)
	#define ioss_0_port_4_pin_0_HAL_PORT_PIN P4_0
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ioss_0_port_4_pin_0_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ioss_0_port_4_pin_0_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ioss_0_port_4_pin_0_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif //defined (CY_USING_HAL)
#define ioss_0_port_4_pin_1_ENABLED 1U
#define ioss_0_port_4_pin_1_PORT GPIO_PRT4
#define ioss_0_port_4_pin_1_PORT_NUM 4U
#define ioss_0_port_4_pin_1_PIN 1U
#define ioss_0_port_4_pin_1_NUM 1U
#define ioss_0_port_4_pin_1_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_4_pin_1_INIT_DRIVESTATE 1
#ifndef ioss_0_port_4_pin_1_HSIOM
	#define ioss_0_port_4_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_4_pin_1_IRQ ioss_interrupts_gpio_4_IRQn
#if defined (CY_USING_HAL)
	#define ioss_0_port_4_pin_1_HAL_PORT_PIN P4_1
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ioss_0_port_4_pin_1_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ioss_0_port_4_pin_1_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ioss_0_port_4_pin_1_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define ioss_0_port_5_pin_0_ENABLED 1U
#define ioss_0_port_5_pin_0_PORT GPIO_PRT5
#define ioss_0_port_5_pin_0_PORT_NUM 5U
#define ioss_0_port_5_pin_0_PIN 0U
#define ioss_0_port_5_pin_0_NUM 0U
#define ioss_0_port_5_pin_0_DRIVEMODE CY_GPIO_DM_HIGHZ
#define ioss_0_port_5_pin_0_INIT_DRIVESTATE 1
#ifndef ioss_0_port_5_pin_0_HSIOM
	#define ioss_0_port_5_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_5_pin_0_IRQ ioss_interrupts_gpio_5_IRQn
#if defined (CY_USING_HAL)
	#define ioss_0_port_5_pin_0_HAL_PORT_PIN P5_0
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ioss_0_port_5_pin_0_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ioss_0_port_5_pin_0_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ioss_0_port_5_pin_0_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif //defined (CY_USING_HAL)
#define ioss_0_port_5_pin_1_ENABLED 1U
#define ioss_0_port_5_pin_1_PORT GPIO_PRT5
#define ioss_0_port_5_pin_1_PORT_NUM 5U
#define ioss_0_port_5_pin_1_PIN 1U
#define ioss_0_port_5_pin_1_NUM 1U
#define ioss_0_port_5_pin_1_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_5_pin_1_INIT_DRIVESTATE 1
#ifndef ioss_0_port_5_pin_1_HSIOM
	#define ioss_0_port_5_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_5_pin_1_IRQ ioss_interrupts_gpio_5_IRQn
#if defined (CY_USING_HAL)
	#define ioss_0_port_5_pin_1_HAL_PORT_PIN P5_1
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ioss_0_port_5_pin_1_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ioss_0_port_5_pin_1_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ioss_0_port_5_pin_1_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define BackupControl_ENABLED 1U
#define BackupControl_PORT GPIO_PRT6
#define BackupControl_PORT_NUM 6U
#define BackupControl_PIN 2U
#define BackupControl_NUM 2U
#define BackupControl_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define BackupControl_INIT_DRIVESTATE 1
#ifndef ioss_0_port_6_pin_2_HSIOM
	#define ioss_0_port_6_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define BackupControl_HSIOM ioss_0_port_6_pin_2_HSIOM
#define BackupControl_IRQ ioss_interrupts_gpio_6_IRQn
#if defined (CY_USING_HAL)
	#define BackupControl_HAL_PORT_PIN P6_2
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define BackupControl_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define BackupControl_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define BackupControl_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define CYBSP_SWO_ENABLED 1U
#define CYBSP_SWO_PORT GPIO_PRT6
#define CYBSP_SWO_PORT_NUM 6U
#define CYBSP_SWO_PIN 4U
#define CYBSP_SWO_NUM 4U
#define CYBSP_SWO_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define CYBSP_SWO_INIT_DRIVESTATE 1
#ifndef ioss_0_port_6_pin_4_HSIOM
	#define ioss_0_port_6_pin_4_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_SWO_HSIOM ioss_0_port_6_pin_4_HSIOM
#define CYBSP_SWO_IRQ ioss_interrupts_gpio_6_IRQn
#if defined (CY_USING_HAL)
	#define CYBSP_SWO_HAL_PORT_PIN P6_4
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CYBSP_SWO_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CYBSP_SWO_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CYBSP_SWO_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define CYBSP_SWDIO_ENABLED 1U
#define CYBSP_SWDIO_PORT GPIO_PRT6
#define CYBSP_SWDIO_PORT_NUM 6U
#define CYBSP_SWDIO_PIN 6U
#define CYBSP_SWDIO_NUM 6U
#define CYBSP_SWDIO_DRIVEMODE CY_GPIO_DM_PULLUP
#define CYBSP_SWDIO_INIT_DRIVESTATE 1
#ifndef ioss_0_port_6_pin_6_HSIOM
	#define ioss_0_port_6_pin_6_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_SWDIO_HSIOM ioss_0_port_6_pin_6_HSIOM
#define CYBSP_SWDIO_IRQ ioss_interrupts_gpio_6_IRQn
#if defined (CY_USING_HAL)
	#define CYBSP_SWDIO_HAL_PORT_PIN P6_6
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CYBSP_SWDIO_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CYBSP_SWDIO_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CYBSP_SWDIO_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_PULLUP
#endif //defined (CY_USING_HAL)
#define CYBSP_SWDCK_ENABLED 1U
#define CYBSP_SWDCK_PORT GPIO_PRT6
#define CYBSP_SWDCK_PORT_NUM 6U
#define CYBSP_SWDCK_PIN 7U
#define CYBSP_SWDCK_NUM 7U
#define CYBSP_SWDCK_DRIVEMODE CY_GPIO_DM_PULLDOWN
#define CYBSP_SWDCK_INIT_DRIVESTATE 1
#ifndef ioss_0_port_6_pin_7_HSIOM
	#define ioss_0_port_6_pin_7_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_SWDCK_HSIOM ioss_0_port_6_pin_7_HSIOM
#define CYBSP_SWDCK_IRQ ioss_interrupts_gpio_6_IRQn
#if defined (CY_USING_HAL)
	#define CYBSP_SWDCK_HAL_PORT_PIN P6_7
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CYBSP_SWDCK_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CYBSP_SWDCK_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CYBSP_SWDCK_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_PULLDOWN
#endif //defined (CY_USING_HAL)
#define CYBSP_CINA_ENABLED 1U
#define CYBSP_CINA_PORT GPIO_PRT7
#define CYBSP_CINA_PORT_NUM 7U
#define CYBSP_CINA_PIN 1U
#define CYBSP_CINA_NUM 1U
#define CYBSP_CINA_DRIVEMODE CY_GPIO_DM_ANALOG
#define CYBSP_CINA_INIT_DRIVESTATE 1
#ifndef ioss_0_port_7_pin_1_HSIOM
	#define ioss_0_port_7_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_CINA_HSIOM ioss_0_port_7_pin_1_HSIOM
#define CYBSP_CINA_IRQ ioss_interrupts_gpio_7_IRQn
#if defined (CY_USING_HAL)
	#define CYBSP_CINA_HAL_PORT_PIN P7_1
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CYBSP_CINA_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CYBSP_CINA_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CYBSP_CINA_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#endif //defined (CY_USING_HAL)
#define CYBSP_CINB_ENABLED 1U
#define CYBSP_CINB_PORT GPIO_PRT7
#define CYBSP_CINB_PORT_NUM 7U
#define CYBSP_CINB_PIN 2U
#define CYBSP_CINB_NUM 2U
#define CYBSP_CINB_DRIVEMODE CY_GPIO_DM_ANALOG
#define CYBSP_CINB_INIT_DRIVESTATE 1
#ifndef ioss_0_port_7_pin_2_HSIOM
	#define ioss_0_port_7_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_CINB_HSIOM ioss_0_port_7_pin_2_HSIOM
#define CYBSP_CINB_IRQ ioss_interrupts_gpio_7_IRQn
#if defined (CY_USING_HAL)
	#define CYBSP_CINB_HAL_PORT_PIN P7_2
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CYBSP_CINB_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CYBSP_CINB_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CYBSP_CINB_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#endif //defined (CY_USING_HAL)
#define CYBSP_CMOD_ENABLED 1U
#define CYBSP_CMOD_PORT GPIO_PRT7
#define CYBSP_CMOD_PORT_NUM 7U
#define CYBSP_CMOD_PIN 7U
#define CYBSP_CMOD_NUM 7U
#define CYBSP_CMOD_DRIVEMODE CY_GPIO_DM_ANALOG
#define CYBSP_CMOD_INIT_DRIVESTATE 1
#ifndef ioss_0_port_7_pin_7_HSIOM
	#define ioss_0_port_7_pin_7_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_CMOD_HSIOM ioss_0_port_7_pin_7_HSIOM
#define CYBSP_CMOD_IRQ ioss_interrupts_gpio_7_IRQn
#if defined (CY_USING_HAL)
	#define CYBSP_CMOD_HAL_PORT_PIN P7_7
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CYBSP_CMOD_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CYBSP_CMOD_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CYBSP_CMOD_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#endif //defined (CY_USING_HAL)

extern const cy_stc_gpio_pin_config_t OLED_RST_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t OLED_RST_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t QSPI_CLK_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t QSPI_CLK_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t QSPI_D0_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t QSPI_D0_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t QSPI_D1_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t QSPI_D1_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t QSPI_D2_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t QSPI_D2_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t QSPI_D3_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t QSPI_D3_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t QSPI_CS_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t QSPI_CS_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t ioss_0_port_4_pin_0_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t ioss_0_port_4_pin_0_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t ioss_0_port_4_pin_1_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t ioss_0_port_4_pin_1_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t ioss_0_port_5_pin_0_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t ioss_0_port_5_pin_0_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t ioss_0_port_5_pin_1_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t ioss_0_port_5_pin_1_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t BackupControl_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t BackupControl_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t CYBSP_SWO_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t CYBSP_SWO_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t CYBSP_SWDIO_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t CYBSP_SWDIO_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t CYBSP_SWDCK_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t CYBSP_SWDCK_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t CYBSP_CINA_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t CYBSP_CINA_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t CYBSP_CINB_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t CYBSP_CINB_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t CYBSP_CMOD_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t CYBSP_CMOD_obj;
#endif //defined (CY_USING_HAL)

void init_cycfg_pins(void);

#if defined(__cplusplus)
}
#endif


#endif /* CYCFG_PINS_H */
