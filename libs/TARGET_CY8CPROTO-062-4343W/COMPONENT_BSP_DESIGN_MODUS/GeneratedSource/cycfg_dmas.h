/*******************************************************************************
* File Name: cycfg_dmas.h
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

#if !defined(CYCFG_DMAS_H)
#define CYCFG_DMAS_H

#include "cycfg_notices.h"
#include "cy_dmac.h"
#if defined (CY_USING_HAL)
	#include "cyhal_hwmgr.h"
#endif //defined (CY_USING_HAL)

#if defined(__cplusplus)
extern "C" {
#endif

#define SMIF_Tx_DMA_ENABLED 1U
#define SMIF_Tx_DMA_HW DMAC
#define SMIF_Tx_DMA_CHANNEL 0U

extern cy_stc_dmac_descriptor_config_t SMIF_Tx_DMA_Descriptor_0_config;
extern cy_stc_dmac_descriptor_t SMIF_Tx_DMA_Descriptor_0;
extern cy_stc_dmac_channel_config_t SMIF_Tx_DMA_channelConfig;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t SMIF_Tx_DMA_obj;
#endif //defined (CY_USING_HAL)

void init_cycfg_dmas(void);

#if defined(__cplusplus)
}
#endif


#endif /* CYCFG_DMAS_H */
