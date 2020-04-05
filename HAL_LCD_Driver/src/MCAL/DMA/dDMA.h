/*
 * dDMA.h
 *
 *  Created on: Mar 29, 2020
 *      Author: FatmaGomaa
 */

#ifndef DDMA_H_
#define DDMA_H_

#define DMA_BASE_ADDRESS				((volatile void *)(0x40020000))
#define DMA_1_CHANNELS_NUM				7
/*
#define DMA_CHANNEL_1_BASE_ADDRESS		((volatile void *)(0x40020008))
#define DMA_CHANNEL_2_BASE_ADDRESS		((volatile void *)(0x4002001C))
#define DMA_CHANNEL_3_BASE_ADDRESS		((volatile void *)(0x40020030))
#define DMA_CHANNEL_4_BASE_ADDRESS		((volatile void *)(0x40020044))
#define DMA_CHANNEL_5_BASE_ADDRESS		((volatile void *)(0x40020058))
#define DMA_CHANNEL_6_BASE_ADDRESS		((volatile void *)(0x4002006C))
#define DMA_CHANNEL_7_BASE_ADDRESS		((volatile void *)(0x40020080))
*/

#define DMA_CHANNEL_1		            0
#define DMA_CHANNEL_2		            1
#define DMA_CHANNEL_3		            2
#define DMA_CHANNEL_4		            3
#define DMA_CHANNEL_5		            4
#define DMA_CHANNEL_6		            5
#define DMA_CHANNEL_7		            6

#define DMA_CHANNEL_PRIORITY_LOW			0x00000000
#define DMA_CHANNEL_PRIORITY_MEDIUM			0x00001000
#define DMA_CHANNEL_PRIORITY_HIGH			0x00002000
#define DMA_CHANNEL_PRIORITY_VERY_HIGH		0x00003000


#define DMA_DIR_MEM2PER					0x00000000
#define DMA_DIR_PER2MEM					DMA_CCRx_DIR

#define DMA_CIRCULAR_MODE_EN			DMA_CCRx_CIRC
#define DMA_CIRCULAR_MODE_DIS			0x00000000

#define DMA_MEM_INC_EN					DMA_CCRx_MINC
#define DMA_MEM_INC_DIS					0x00000000

#define DMA_PER_INC_EN					DMA_CCRx_PINC
#define DMA_PER_INC_DIS					0x00000000

#define DMA_MEM_SIZE_8					0x00000000
#define DMA_MEM_SIZE_16					0x00000400
#define DMA_MEM_SIZE_32					0x00000800

#define DMA_PER_SIZE_8					0x00000000
#define DMA_PER_SIZE_16					0x00000100
#define DMA_PER_SIZE_32					0x00000200

#define DMA_MEM2MEM_EN					DMA_CCRx_MEM2MEM
#define DMA_MEM2MEM_DIS					0x00000000

#define DMA_ENABLE						DMA_CCRx_EN
#define DMA_DISABLE						0x00000000

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

typedef struct {
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
}DMA_Config_t;

void DMA_Init(DMA_Config_t ChannelConfig);
void DMA_Start(DMA_Config_t Channel);

#endif /* DDMA_H_ */
