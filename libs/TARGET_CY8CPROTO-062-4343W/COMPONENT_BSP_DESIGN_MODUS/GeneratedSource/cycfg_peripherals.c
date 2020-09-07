/*******************************************************************************
* File Name: cycfg_peripherals.c
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

#include "cycfg_peripherals.h"

const cy_stc_scb_uart_config_t UART0_config = 
{
	.uartMode = CY_SCB_UART_STANDARD,
	.enableMutliProcessorMode = false,
	.smartCardRetryOnNack = false,
	.irdaInvertRx = false,
	.irdaEnableLowPowerReceiver = false,
	.oversample = 8,
	.enableMsbFirst = false,
	.dataWidth = 8UL,
	.parity = CY_SCB_UART_PARITY_NONE,
	.stopBits = CY_SCB_UART_STOP_BITS_1,
	.enableInputFilter = false,
	.breakWidth = 11UL,
	.dropOnFrameError = false,
	.dropOnParityError = false,
	.receiverAddress = 0x0UL,
	.receiverAddressMask = 0x0UL,
	.acceptAddrInFifo = false,
	.enableCts = false,
	.ctsPolarity = CY_SCB_UART_ACTIVE_LOW,
	.rtsRxFifoLevel = 0UL,
	.rtsPolarity = CY_SCB_UART_ACTIVE_LOW,
	.rxFifoTriggerLevel = 63UL,
	.rxFifoIntEnableMask = 0UL,
	.txFifoTriggerLevel = 63UL,
	.txFifoIntEnableMask = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t UART0_obj = 
	{
		.type = CYHAL_RSC_SCB,
		.block_num = 7U,
		.channel_num = 0U,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_smif_config_t KIT_QSPI_config = 
{
	.mode = (uint32_t)CY_SMIF_NORMAL,
	.deselectDelay = KIT_QSPI_DESELECT_DELAY,
	.rxClockSel = (uint32_t)CY_SMIF_SEL_INV_INTERNAL_CLK,
	.blockEvent = (uint32_t)CY_SMIF_BUS_ERROR,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t KIT_QSPI_obj = 
	{
		.type = CYHAL_RSC_SMIF,
		.block_num = 0U,
		.channel_num = 0U,
	};
#endif //defined (CY_USING_HAL)


void init_cycfg_peripherals(void)
{
	Cy_SysClk_PeriphAssignDivider(PCLK_SCB7_CLOCK, CY_SYSCLK_DIV_16_BIT, 0U);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&UART0_obj);
#endif //defined (CY_USING_HAL)

#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&KIT_QSPI_obj);
#endif //defined (CY_USING_HAL)
}
