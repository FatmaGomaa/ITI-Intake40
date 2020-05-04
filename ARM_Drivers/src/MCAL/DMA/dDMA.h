/*
 * dDMA.h
 *
 *  Created on: Mar 29, 2020
 *      Author: FatmaGomaa
 */


/***********************************Driver Manual *****************************************************
 * To work with this DMA Driver, you need to :
 * 1. create an element from the Structure named DMA_Config_t
 * 2. call DMA_Init API to set up the channel configuration
 * 3. call DMA_Start when you need to start the transmission of Data  */

#ifndef DDMA_H_
#define DDMA_H_

#define DMA_ONE																		   1
#define DMA_TWO																		   2

#define DMA_CHANNEL_1		                                                           0
#define DMA_CHANNEL_2		                                                           1
#define DMA_CHANNEL_3		                                                           2
#define DMA_CHANNEL_4		                                                           3
#define DMA_CHANNEL_5		                                                           4
#define DMA_CHANNEL_6		                                                           5
#define DMA_CHANNEL_7		                                                           6

#define DMA_CHANNEL_PRIORITY_LOW			                                           0x00000000
#define DMA_CHANNEL_PRIORITY_MEDIUM			                                           0x00001000
#define DMA_CHANNEL_PRIORITY_HIGH			                                           0x00002000
#define DMA_CHANNEL_PRIORITY_VERY_HIGH		                                           0x00003000

#define DMA_DIR_MEM2PER					                                               0x00000000
#define DMA_DIR_PER2MEM					                                               0x00000010

#define DMA_CIRCULAR_MODE_EN			                                               0x00000020
#define DMA_CIRCULAR_MODE_DIS			                                               0x00000000

#define DMA_MEM_INC_EN					                                               0x00000080
#define DMA_MEM_INC_DIS					                                               0x00000000

#define DMA_PER_INC_EN					                                               0x00000040
#define DMA_PER_INC_DIS					                                               0x00000000

#define DMA_MEM_SIZE_8					                                               0x00000000
#define DMA_MEM_SIZE_16					                                               0x00000400
#define DMA_MEM_SIZE_32					                                               0x00000800

#define DMA_PER_SIZE_8					                                               0x00000000
#define DMA_PER_SIZE_16					                                               0x00000100
#define DMA_PER_SIZE_32					                                               0x00000200

#define DMA_MEM2MEM_EN					                                               0x00004000
#define DMA_MEM2MEM_DIS					                                               0x00000000

#define DMA_INTERRUPT_TRANSFER_ERROR												   0x00000008
#define DMA_INTERRUPT_TRANSFER_HALF													   0x00000004
#define DMA_INTERRUPT_TRANSFER_COMPLETE												   0x00000002

#define DMA_ENABLE						                                               0x00000001
#define DMA_DISABLE						                                               0x00000000

/* DMA_ID : DMA_ONE or DMA_TWO
 * ChannelID: takes input from DMA_CHANNEL_1 to DMA_CHANNEL_7 in case of DMA_ONE and DMA_CHANNEL_1 to DMA_CHANNEL_5 in case of DMA_TWO
 * PeripheralAddress: depends on the use, 32 bit address.
 * MemoryAddress: depends on the use, 32 bit address.
 * PheripheralAddressSize: takes the following DMA_PER_SIZE_x
 * MemoryAddressSize: takes the following DMA_MEM_SIZE_x
 * Counter : takes the number of times DMA transmit Data, user depended.
 * PheripheralAutoInc: DMA_PER_INC_EN or  DMA_PER_INC_DIS
 * MemoryAutoInc: DMA_MEM_INC_EN or DMA_MEM_INC_DIS
 * Direction : DMA_DIR_MEM2PER or DMA_DIR_PER2MEM
 * Mem2Mem : DMA_MEM2MEM_EN or DMA_MEM2MEM_DIS
 * Mode : DMA_CIRCULAR_MODE_EN or DMA_CIRCULAR_MODE_DIS
 * ChannelPriority : DMA_CHANNEL_PRIORITY_x
 * Control : DMA_ENABLE or DMA_DISABLE
 * InterruptType : DMA_INTERRUPT_TRANSFER_x and you can choose more than one interrupt by ORING them
 * */
typedef struct {
	u32 DMA_ID;
	u32 ChannelID;
	u32 PeripheralAddress;
	u32 MemoryAddress;
	u32 PheripheralAddressSize;
	u32 MemoryAddressSize;
	u32 Counter;
	u32 PheripheralAutoInc;
	u32 MemoryAutoInc;
	u32 Direction;
	u32 Mem2Mem;
	u32 Mode;
	u32 ChannelPriority;
	u32 Control;
	u32 InterruptType;
}DMA_Config_t;

STD_ERROR DMA_Init(DMA_Config_t ChannelConfig);
STD_ERROR DMA_Start(DMA_Config_t Channel);



#endif /* DDMA_H_ */
