/*
 * hDMA.h
 *
 *  Created on: Apr 16, 2020
 *      Author: FatmaGomaa
 */

#ifndef ECUAL_DMA_HANDLER_HDMA_H_
#define ECUAL_DMA_HANDLER_HDMA_H_

#include "dDMA.h"


STD_ERROR DMA_InitChannel(DMA_Config_t ChannelConfig);
STD_ERROR DMA_StartTransfer(DMA_Config_t Channel);


#endif /* ECUAL_DMA_HANDLER_HDMA_H_ */
