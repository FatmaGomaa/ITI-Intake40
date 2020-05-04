/*
 * dSPI.c
 *
 *  Created on: Apr 19, 2020
 *      Author: FatmaGomaa
 */
#include "STD_TYPES.h"
#include "dSPI.h"

typedef struct {

	u32 SPI_CR1;
	u32 SPI_CR2;
	u32 SPI_SR;
	u32 SPI_DR;
	u32 SPI_CRCPR;
	u32 SPI_RXCRCR;
	u32 SPI_TXCRCR;
	u32 SPI_I2SCFGR;
	u32 SPI_I2SPR;
}SPI_Peripheral_t;

#define CR1_BIDIMOD				0x00008000
#define CR1_BIDIOE				0x00004000
#define CR1_CRCEN				0x00002000
#define CR1_CRCNEXT				0x00001000
#define CR1_DFF					0x00000800
#define CR1_RXONLY				0x00000400
#define CR1_SSM					0x00000200
#define CR1_SSI					0x00000100
#define CR1_LSBFIRST			0x00000080
#define CR1_SPE					0x00000040
#define CR1_BR_M				0x00000038
#define CR1_BR_CLR_M			0xFFFFFFC7
#define CR1_MSTR				0x00000004
#define CR1_CPOL				0x00000002
#define CR1_CPHA				0x00000001

#define CR2_TXEIE				0x00000080
#define CR2_RXNEIE			    0x00000040
#define CR2_ERRIE			    0x00000020
#define CR2_SSOE			    0x00000004
#define CR2_TXDMAEN			    0x00000002
#define CR2_RXDMAEN			    0x00000001

#define SR_BSY					0x00000080
#define SR_OVR					0x00000040
#define SR_MODF					0x00000020
#define SR_CRCERR				0x00000010
#define SR_UDR					0x00000008
#define SR_CHSIDE				0x00000004
#define SR_TXE					0x00000002
#define SR_RXNE					0x00000001

typedef enum{
	Idle_State ,
	Busy_State
}BufferState_t;

typedef struct{
	u8 * ptr;
	u32 position;
	u32 size;
	BufferState_t state;
}DataBuffer_t;

static DataBuffer_t TxBuffer;
static DataBuffer_t RxBuffer;

static CallBackFunction APPTXNotifier, APPRXNotifier;
extern SPI_Cfg_t SPI_CFG;

/* 1 for Send
 * 2 for SendReceive */
static u8 CurrentCaller=8;

/*TODO: RCC, GPIO and NVIC -> SPI Handler*/
STD_ERROR SPI_Init(void){
	STD_ERROR Local_ErrorStatus = OK;
	u32 RegTemp = 0;
	SPI_Peripheral_t * SPI = (SPI_Peripheral_t * )SPI_CFG.SPI_ID;

	RegTemp = SPI_CFG.BaudRate | SPI_CFG.CLK_Phase | SPI_CFG.CLK_Polarity | SPI_CFG.DataFrameFormat |
			SPI_CFG.DataSequence | SPI_CFG.CRC_Control | SPI_CFG.WiringMode | SPI_CFG.MCU_Mode |
			SPI_CFG.SlaveMode;

	SPI->SPI_CR1 = RegTemp;

	//RegTemp = CR2_TXEIE | CR2_RXNEIE;
	//SPI->SPI_CR2 = RegTemp;

	return Local_ErrorStatus;
}

void SPI1_IRQHandler(void){
	SPI_Peripheral_t * SPI = (SPI_Peripheral_t *)SPI_CFG.SPI_ID;
	u16 dummy;

	if (SPI->SPI_SR & SR_TXE){
		if(TxBuffer.ptr){
			if (TxBuffer.position == TxBuffer.size ) {
				TxBuffer.state = Idle_State;
				TxBuffer.ptr = NULL;
				TxBuffer.size = 0;
				TxBuffer.position = 0;

				SPI->SPI_CR2 &=~ (CR2_TXEIE | CR2_RXNEIE);

				if (APPTXNotifier){
					APPTXNotifier();
				}

			}else{
				SPI->SPI_DR = TxBuffer.ptr[TxBuffer.position];
				if(CurrentCaller == 2){
				RxBuffer.ptr[RxBuffer.position] = SPI->SPI_DR;
				RxBuffer.position++;
				}
				TxBuffer.position++;

			}
		}else{
			SPI->SPI_DR = 0;
		}

	}

	if(SPI->SPI_SR & SR_RXNE ){
		if (RxBuffer.ptr){
			if (RxBuffer.position == RxBuffer.size ) {
				RxBuffer.state = Idle_State;
				RxBuffer.ptr = NULL;
				RxBuffer.size = 0;
				RxBuffer.position = 0;

				SPI->SPI_CR2 &=~ (CR2_TXEIE | CR2_RXNEIE);

				if (APPRXNotifier){
					APPRXNotifier();
				}
			}else{
				RxBuffer.ptr[RxBuffer.position] = SPI->SPI_DR;
				RxBuffer.position++;
			}
		}else{
			dummy = SPI->SPI_DR;
		}
	}

}

ProcessState_t SPI_Send(u8* Data, u8 DataLength){
	static ProcessState_t SPI_ChannelState = STATE_NOK;
	SPI_Peripheral_t * SPI = (SPI_Peripheral_t *)SPI_CFG.SPI_ID;

	if (Data && (DataLength > 0) ){

		if (TxBuffer.state == Idle_State){
			CurrentCaller=1;
			TxBuffer.state = Busy_State;
			TxBuffer.ptr = Data;
			TxBuffer.size = DataLength;
			TxBuffer.position = 0;

			SPI->SPI_CR1 |= CR1_SPE;

			SPI->SPI_DR = TxBuffer.ptr[TxBuffer.position];
			TxBuffer.position++;

			SPI->SPI_CR2 |= (CR2_TXEIE | CR2_RXNEIE);

			SPI_ChannelState = STATE_OK;
		}else{
			SPI_ChannelState = STATE_BUSY;
		}

	}else{
		SPI_ChannelState = STATE_NOK;
	}

	return SPI_ChannelState;
}

ProcessState_t SPI_Receive(u8* Data, u8 DataLength){
	static ProcessState_t SPI_ChannelState = STATE_NOK;
	SPI_Peripheral_t * SPI = (SPI_Peripheral_t *)SPI_CFG.SPI_ID;

	if (Data && (DataLength > 0) ){

		if (RxBuffer.state == Idle_State){
			RxBuffer.state = Busy_State;
			RxBuffer.ptr = Data;
			RxBuffer.size = DataLength;
			RxBuffer.position = 0;

			SPI->SPI_CR1 |= CR1_SPE;
			SPI->SPI_CR2 |= (CR2_TXEIE | CR2_RXNEIE);

			SPI_ChannelState = STATE_OK;
		}else{
			SPI_ChannelState = STATE_BUSY;
		}

	}else{
		SPI_ChannelState = STATE_NOK;
	}

	return SPI_ChannelState;
}

ProcessState_t SPI_SendReceive(u8* SentData, u8* ReceivedData, u8 DataLength){
	static ProcessState_t SPI_ChannelState = STATE_NOK;
	SPI_Peripheral_t * SPI = (SPI_Peripheral_t *)SPI_CFG.SPI_ID;
	u16 dummy;

	if (SentData && ReceivedData && (DataLength > 0) ){

		if (TxBuffer.state == Idle_State && RxBuffer.state == Idle_State){
			CurrentCaller=2;
			TxBuffer.state = Busy_State;
			TxBuffer.ptr = SentData;
			TxBuffer.size = DataLength;
			TxBuffer.position = 0;

			RxBuffer.state = Busy_State;
			RxBuffer.ptr = ReceivedData;
			RxBuffer.size = DataLength;
			RxBuffer.position = 0;

			SPI->SPI_CR1 |= CR1_SPE;

			SPI->SPI_DR = TxBuffer.ptr[TxBuffer.position];
			RxBuffer.ptr[RxBuffer.position] = SPI->SPI_DR;
			RxBuffer.position++;
			TxBuffer.position++;

			SPI->SPI_CR2 |= (CR2_TXEIE | CR2_RXNEIE);

			SPI_ChannelState = STATE_OK;
		}else{
			SPI_ChannelState = STATE_BUSY;
		}

	}else{
		SPI_ChannelState = STATE_NOK;
	}

	return SPI_ChannelState;
}

void SPI_SetTXCBF(CallBackFunction TxCbf){
	if (TxCbf){
		APPTXNotifier = TxCbf;
	}
}

void SPI_SetRXCBF(CallBackFunction	RxCbf){
	if (RxCbf){
		APPRXNotifier = RxCbf;

	}
}


