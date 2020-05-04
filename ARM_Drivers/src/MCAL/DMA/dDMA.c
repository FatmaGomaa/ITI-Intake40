/*
 * dDMA.c
 *
 *  Created on: Mar 29, 2020
 *      Author: FatmaGomaa
 */
#include "STD_TYPES.h"
#include "dDMA.h"

#define DMA_1_BASE_ADDRESS				((volatile void *)(0x40020000))
#define DMA_2_BASE_ADDRESS				((volatile void *)(0x40020400))
#define DMA_1_CHANNELS_NUM				7
#define DMA_2_CHANNELS_NUM				5

#define DMA_ISR_GIF1						0x00000001
#define DMA_ISR_TCIF1						0x00000002
#define DMA_ISR_HTIF1						0x00000004
#define DMA_ISR_TEIF1						0x00000008
#define DMA_ISR_GIF2						0x00000010
#define DMA_ISR_TCIF2						0x00000020
#define DMA_ISR_HTIF2						0x00000040
#define DMA_ISR_TEIF2						0x00000080
#define DMA_ISR_GIF3						0x00000100
#define DMA_ISR_TCIF3						0x00000200
#define DMA_ISR_HTIF3						0x00000400
#define DMA_ISR_TEIF3						0x00000800
#define DMA_ISR_GIF4						0x00001000
#define DMA_ISR_TCIF4						0x00002000
#define DMA_ISR_HTIF4						0x00004000
#define DMA_ISR_TEIF4						0x00008000
#define DMA_ISR_GIF5						0x00010000
#define DMA_ISR_TCIF5						0x00020000
#define DMA_ISR_HTIF5						0x00040000
#define DMA_ISR_TEIF5						0x00080000
#define DMA_ISR_GIF6						0x00100000
#define DMA_ISR_TCIF6						0x00200000
#define DMA_ISR_HTIF6						0x00400000
#define DMA_ISR_TEIF6						0x00800000
#define DMA_ISR_GIF7						0x01000000
#define DMA_ISR_TCIF7						0x02000000
#define DMA_ISR_HTIF7						0x04000000
#define DMA_ISR_TEIF7						0x08000000


#define DMA_ISR_CGIF1						0x00000001
#define DMA_ISR_CTCIF1						0x00000002
#define DMA_ISR_CHTIF1						0x00000004
#define DMA_ISR_CTEIF1						0x00000008
#define DMA_ISR_CGIF2						0x00000010
#define DMA_ISR_CTCIF2						0x00000020
#define DMA_ISR_CHTIF2						0x00000040
#define DMA_ISR_CTEIF2						0x00000080
#define DMA_ISR_CGIF3						0x00000100
#define DMA_ISR_CTCIF3						0x00000200
#define DMA_ISR_CHTIF3						0x00000400
#define DMA_ISR_CTEIF3						0x00000800
#define DMA_ISR_CGIF4						0x00001000
#define DMA_ISR_CTCIF4						0x00002000
#define DMA_ISR_CHTIF4						0x00004000
#define DMA_ISR_CTEIF4						0x00008000
#define DMA_ISR_CGIF5						0x00010000
#define DMA_ISR_CTCIF5						0x00020000
#define DMA_ISR_CHTIF5						0x00040000
#define DMA_ISR_CTEIF5						0x00080000
#define DMA_ISR_CGIF6						0x00100000
#define DMA_ISR_CTCIF6						0x00200000
#define DMA_ISR_CHTIF6						0x00400000
#define DMA_ISR_CTEIF6						0x00800000
#define DMA_ISR_CGIF7						0x01000000
#define DMA_ISR_CTCIF7						0x02000000
#define DMA_ISR_CHTIF7						0x04000000
#define DMA_ISR_CTEIF7						0x08000000

#define DMA_CCRx_EN							0x00000001
#define DMA_CCRx_TCIE					    0x00000002
#define DMA_CCRx_HTIE					    0x00000004
#define DMA_CCRx_TEIE					    0x00000008
#define DMA_CCRx_DIR					    0x00000010
#define DMA_CCRx_CIRC					    0x00000020
#define DMA_CCRx_PINC					    0x00000040
#define DMA_CCRx_MINC					    0x00000080
#define DMA_CCRx_PSIZE_M					0x00000300
#define DMA_CCRx_PSIZE_CLEAR_M				0XFFFFFCFF
#define DMA_CCRx_MSIZE_M					0x00000C00
#define DMA_CCRx_MSIZE_CLEAR_M				0XFFFFF3FF
#define DMA_CCRxPL_M					    0x00003000
#define DMA_CCRxPL_CLEAR_M				    0XFFFFCFFF
#define DMA_CCRx_MEM2MEM					0x00004000

#define DMA_CNDTRx_NDT_M					0x0000FFFF
#define DMA_CNDTRx_NDT_CLEAR_M				0xFFFF0000

#define DMA_CPARx_PA_M						0xFFFFFFFF
#define DMA_CPARx_PA_CLEAR_M				0x00000000

#define DMA_CMARx_MA_M						0xFFFFFFFF
#define DMA_CMARx_MA_CLEAR_M				0x00000000

typedef struct {
	u32 DMA_CCRx;
	u32 DMA_CNDTRx;
	u32 DMA_CPARx;
	u32 DMA_CMARx;
	u32 RESERVEDx;
}DMA_Channel_t;

typedef struct {
	u32 DMA_ISR;
	u32 DMA_IFCR;
	DMA_Channel_t DMA_Channels[DMA_1_CHANNELS_NUM];
}DMA_t;


STD_ERROR DMA_Init(DMA_Config_t ChannelConfig){
	u32 Local_u32RegisterTemp;
	STD_ERROR Local_ErrorStatus = NOT_OK;

	DMA_t* DMA = (DMA_t * )DMA_1_BASE_ADDRESS;

	if( ChannelConfig.DMA_ID == DMA_TWO ){
		DMA = (DMA_t * )DMA_2_BASE_ADDRESS;
	}

	/*Checks that the user is selecting a proper channel on a proper DMA */
	if ( ( (ChannelConfig.DMA_ID == DMA_TWO) && (ChannelConfig.ChannelID <= DMA_2_CHANNELS_NUM ) ) ||
			( (ChannelConfig.DMA_ID == DMA_ONE) && (ChannelConfig.ChannelID <= DMA_1_CHANNELS_NUM ) )  ){
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
	Local_u32RegisterTemp &=~ ( DMA_CCRx_DIR | DMA_CCRx_CIRC | DMA_CCRx_MINC | DMA_CCRx_PINC | DMA_CCRx_MSIZE_M | DMA_CCRx_PSIZE_M | DMA_CCRx_MEM2MEM | DMA_CCRx_TCIE | DMA_CCRx_HTIE | DMA_CCRx_TEIE);
	Local_u32RegisterTemp |= ChannelConfig.Direction | ChannelConfig.Mode | ChannelConfig.MemoryAutoInc | ChannelConfig.PheripheralAutoInc | ChannelConfig.MemoryAddressSize | ChannelConfig.PheripheralAddressSize | ChannelConfig.InterruptType |  ChannelConfig.Mem2Mem;
	DMA->DMA_Channels[ChannelConfig.ChannelID].DMA_CCRx = Local_u32RegisterTemp;

	Local_ErrorStatus = OK;
}
	return Local_ErrorStatus;
}

STD_ERROR DMA_Start(DMA_Config_t Channel){
	STD_ERROR Local_ErrorStatus = NOT_OK;

	DMA_t* DMA = (DMA_t * )DMA_1_BASE_ADDRESS;

	if( Channel.DMA_ID == DMA_TWO ){
		DMA = (DMA_t * )DMA_2_BASE_ADDRESS;
	}
	/*
	 * 6. Activate the channel by setting the ENABLE bit in the DMA_CCRx register.
	 */
	/*Checks that both Memory Address and Peripheral Address are correct to avoid Hard Faults */

	if (Channel.MemoryAddress && Channel.PeripheralAddress ){
		DMA->DMA_Channels[Channel.ChannelID].DMA_CCRx |= Channel.Control;
		Local_ErrorStatus = OK;
	}

	return Local_ErrorStatus;
}


