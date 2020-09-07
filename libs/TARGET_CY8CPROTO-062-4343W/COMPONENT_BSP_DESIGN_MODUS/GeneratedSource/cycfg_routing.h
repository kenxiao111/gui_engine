/*******************************************************************************
* File Name: cycfg_routing.h
*
* Description:
* Establishes all necessary connections between hardware elements.
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

#if !defined(CYCFG_ROUTING_H)
#define CYCFG_ROUTING_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "cycfg_notices.h"
void init_cycfg_routing(void);
#define init_cycfg_connectivity() init_cycfg_routing()
#define ioss_0_port_11_pin_7_HSIOM P11_7_SMIF_SPI_CLK
#define ioss_0_port_12_pin_0_HSIOM P12_0_SMIF_SPI_DATA4
#define ioss_0_port_12_pin_1_HSIOM P12_1_SMIF_SPI_DATA5
#define ioss_0_port_12_pin_2_HSIOM P12_2_SMIF_SPI_DATA6
#define ioss_0_port_12_pin_3_HSIOM P12_3_SMIF_SPI_DATA7
#define ioss_0_port_12_pin_4_HSIOM P12_4_SMIF_SPI_SELECT3
#define ioss_0_port_4_pin_0_HSIOM P4_0_SCB7_UART_RX
#define ioss_0_port_4_pin_1_HSIOM P4_1_SCB7_UART_TX
#define ioss_0_port_6_pin_4_HSIOM P6_4_CPUSS_SWJ_SWO_TDO
#define ioss_0_port_6_pin_6_HSIOM P6_6_CPUSS_SWJ_SWDIO_TMS
#define ioss_0_port_6_pin_7_HSIOM P6_7_CPUSS_SWJ_SWCLK_TCLK

#define KIT_QSPI_tr_tx_req_0_TRIGGER_IN TRIG_IN_MUX_6_SMIF_TX
#define SMIF_Tx_DMA_tr_in_0_TRIGGER_OUT TRIG_OUT_MUX_6_MDMA_TR_IN0

#if defined(__cplusplus)
}
#endif


#endif /* CYCFG_ROUTING_H */
