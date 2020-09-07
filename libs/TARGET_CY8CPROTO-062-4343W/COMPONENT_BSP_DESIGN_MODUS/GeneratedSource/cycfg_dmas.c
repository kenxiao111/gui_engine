/*******************************************************************************
* File Name: cycfg_dmas.c
*
* Description:
* DMA configuration
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

#include "cycfg_dmas.h"

cy_stc_dmac_descriptor_config_t SMIF_Tx_DMA_Descriptor_0_config = 
{
	.retrigger = CY_DMAC_RETRIG_IM,
	.interruptType = CY_DMAC_1ELEMENT,
	.triggerOutType = CY_DMAC_1ELEMENT,
	.channelState = CY_DMAC_CHANNEL_DISABLED,
	.triggerInType = CY_DMAC_1ELEMENT,
	.dataPrefetch = true,
	.dataSize = CY_DMAC_WORD,
	.srcTransferSize = CY_DMAC_TRANSFER_SIZE_WORD,
	.dstTransferSize = CY_DMAC_TRANSFER_SIZE_WORD,
	.descriptorType = CY_DMAC_1D_TRANSFER,
	.srcAddress = NULL,
	.dstAddress = NULL,
	.srcXincrement = 1,
	.dstXincrement = 0,
	.xCount = 10800,
	.srcYincrement = 1,
	.dstYincrement = 1,
	.yCount = 1,
	.nextDescriptor = NULL,
};
cy_stc_dmac_descriptor_t SMIF_Tx_DMA_Descriptor_0 = 
{
	.ctl = 0UL,
	.src = 0UL,
	.dst = 0UL,
	.xSize = 0UL,
	.xIncr = 0UL,
	.ySize = 0UL,
	.yIncr = 0UL,
	.nextPtr = 0UL,
};
cy_stc_dmac_channel_config_t SMIF_Tx_DMA_channelConfig = 
{
	.descriptor = &SMIF_Tx_DMA_Descriptor_0,
	.priority = 3,
	.enable = false,
	.bufferable = false,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t SMIF_Tx_DMA_obj = 
	{
		.type = CYHAL_RSC_DMA,
		.block_num = 2U,
		.channel_num = SMIF_Tx_DMA_CHANNEL,
	};
#endif //defined (CY_USING_HAL)


void init_cycfg_dmas(void)
{
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&SMIF_Tx_DMA_obj);
#endif //defined (CY_USING_HAL)
}
