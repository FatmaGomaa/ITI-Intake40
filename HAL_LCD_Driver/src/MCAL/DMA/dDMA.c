/*
 * dDMA.c
 *
 *  Created on: Mar 29, 2020
 *      Author: FatmaGomaa
 */
#include "STD_TYPES.h"
#include "dDMA.h"



DMA_t* DMA = (DMA_t * )DMA_BASE_ADDRESS;

void DMA_Init(DMA_Config_t ChannelConfig){
	u32 Local_u32RegisterTemp;
/*Channel configuration procedure
1. Set the peripheral register address in the DMA_CPARx register.
2. Set the memory address in the DMA_CMARx register.
3. Configure the total number of data to be transferred in the DMA_CNDTRx register.
4. Configure the channel priority using the PL[1:0] bits in the DMA_CCRx register
5. Configure data transfer direction, circular mode, peripheral & memory incremented
mode, peripheral & memory data size, and interrupt after half and/or full transfer in the
DMA_CCRx register
6. Activate the channel by setting the ENABLE bit in the DMA_CCRx register.
*/
/*
1. Set the peripheral register address in the DMA_CPARx register.
*/
DMA->DMA_Channels[ChannelConfig.ChannelID].DMA_CPARx = ChannelConfig.PeripheralAddress;

/*
 * 2. Set the memory address in the DMA_CMARx register.
 */
DMA->DMA_Channels[ChannelConfig.ChannelID].DMA_CMARx = ChannelConfig.MemoryAddress;

/*
 * 3. Configure the total number of data to be transferred in the DMA_CNDTRx register.
 */
DMA->DMA_Channels[ChannelConfig.ChannelID].DMA_CNDTRx = ChannelConfig.Counter;

/*
 * 4. Configure the channel priority using the PL[1:0] bits in the DMA_CCRx register
 */
Local_u32RegisterTemp = DMA->DMA_Channels[ChannelConfig.ChannelID].DMA_CCRx;
Local_u32RegisterTemp &= DMA_CCRxPL_CLEAR_M ;
Local_u32RegisterTemp |= ChannelConfig.ChannelPriority;
DMA->DMA_Channels[ChannelConfig.ChannelID].DMA_CCRx = Local_u32RegisterTemp;

/*
 * 5. Configure data transfer direction, circular mode, peripheral & memory incremented
mode, peripheral & memory data size, and interrupt after half and/or full transfer in the
DMA_CCRx register
 */
Local_u32RegisterTemp = DMA->DMA_Channels[ChannelConfig.ChannelID].DMA_CCRx;
Local_u32RegisterTemp &=~ ( DMA_CCRx_DIR | DMA_CCRx_CIRC | DMA_CCRx_MINC | DMA_CCRx_PINC | DMA_CCRx_MSIZE_M | DMA_CCRx_PSIZE_M );
Local_u32RegisterTemp |= ChannelConfig.Direction | ChannelConfig.Mode | ChannelConfig.MemoryAutoInc | ChannelConfig.PheripheralAutoInc | ChannelConfig.MemoryAddressSize | ChannelConfig.PheripheralAddressSize | DMA_CCRx_TCIE |  ChannelConfig.Mem2Mem;
DMA->DMA_Channels[ChannelConfig.ChannelID].DMA_CCRx = Local_u32RegisterTemp;

}

void DMA_Start(DMA_Config_t Channel){
/*
 * 6. Activate the channel by setting the ENABLE bit in the DMA_CCRx register.
 */
	DMA->DMA_Channels[Channel.ChannelID].DMA_CCRx |= Channel.Control;

}
