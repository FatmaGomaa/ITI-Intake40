/*
 * hDMA.c
 *
 *  Created on: Apr 16, 2020
 *      Author: FatmaGomaa
 */
#include "STD_TYPES.h"

#include "hDMA.h"
#include "DNVIC_interface.h"
#include "dRCC.h"

#define DMA_1_IRQ_Base								11
#define DMA_2_IRQ_Base								56

/*the function enables channel interrupt in NVIC, enables the clock for
 * the selected DMA and calls the Initialization function in DMA Driver */
STD_ERROR DMA_InitChannel(DMA_Config_t ChannelConfig){
	STD_ERROR Local_ErrorStatus = OK;

	if(ChannelConfig.DMA_ID == DMA_ONE){
		Local_ErrorStatus &= RCC_ControlPerihperal(AHP, RCC_AHP_CLOCK_DMA1, ON);
		DNVIC_EnableIRQ(DMA_1_IRQ_Base + ChannelConfig.ChannelID);
	}else if (ChannelConfig.DMA_ID == DMA_TWO){
		Local_ErrorStatus &= RCC_ControlPerihperal(AHP, RCC_AHP_CLOCK_DMA2, ON);
		DNVIC_EnableIRQ(DMA_2_IRQ_Base + ChannelConfig.ChannelID);
	}

	Local_ErrorStatus &= DMA_Init(ChannelConfig);
	return Local_ErrorStatus;
}

STD_ERROR DMA_StartTransfer(DMA_Config_t Channel){
	STD_ERROR Local_ErrorStatus = OK;
	Local_ErrorStatus &= DMA_Start(Channel);
	return Local_ErrorStatus;

}
