/*******************************************************************************
* File Name: cycfg_peripherals.h
*
* Description:
* Peripheral Hardware Block configuration
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

#if !defined(CYCFG_PERIPHERALS_H)
#define CYCFG_PERIPHERALS_H

#include "cycfg_notices.h"
#include "cy_scb_uart.h"
#include "cy_sysclk.h"
#if defined (CY_USING_HAL)
	#include "cyhal_hwmgr.h"
#endif //defined (CY_USING_HAL)
#include "cy_smif.h"
#include "cycfg_qspi_memslot.h"

#if defined(__cplusplus)
extern "C" {
#endif

#define UART0_ENABLED 1U
#define UART0_HW SCB7
#define UART0_IRQ scb_7_interrupt_IRQn
#define KIT_QSPI_ENABLED 1U
#define KIT_QSPI_HW SMIF0
#define KIT_QSPI_IRQ smif_interrupt_IRQn
#define KIT_QSPI_MEMORY_MODE_ALIGMENT_ERROR (0UL)
#define KIT_QSPI_RX_DATA_FIFO_UNDERFLOW (0UL)
#define KIT_QSPI_TX_COMMAND_FIFO_OVERFLOW (0UL)
#define KIT_QSPI_TX_DATA_FIFO_OVERFLOW (0UL)
#define KIT_QSPI_RX_FIFO_TRIGEER_LEVEL (0UL)
#define KIT_QSPI_TX_FIFO_TRIGEER_LEVEL (3UL)
#define KIT_QSPI_DATALINES0_1 (0UL)
#define KIT_QSPI_DATALINES2_3 (0UL)
#define KIT_QSPI_DATALINES4_5 (1UL)
#define KIT_QSPI_DATALINES6_7 (1UL)
#define KIT_QSPI_SS0 (0UL)
#define KIT_QSPI_SS1 (0UL)
#define KIT_QSPI_SS2 (0UL)
#define KIT_QSPI_SS3 (1UL)
#define KIT_QSPI_DESELECT_DELAY 7

extern const cy_stc_scb_uart_config_t UART0_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t UART0_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_smif_config_t KIT_QSPI_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t KIT_QSPI_obj;
#endif //defined (CY_USING_HAL)

void init_cycfg_peripherals(void);

#if defined(__cplusplus)
}
#endif


#endif /* CYCFG_PERIPHERALS_H */
