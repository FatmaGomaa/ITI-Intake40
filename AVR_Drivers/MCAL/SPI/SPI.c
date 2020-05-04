/*
 * SPI.c
 *
 *  Created on: Apr 20, 2020
 *      Author: FatmaGomaa
 */

#include "STD_TYPES.h"
#include "SPI.h"

#define SPI_SPCR				*((volatile u8 *)0x2D)
#define SPI_SPSR				*((volatile u8 *)0x2E)
#define SPI_SPDR				*((volatile u8 *)0x2F)

#define SPCR_SPIE				0b10000000
#define SPCR_SPE				0b01000000
#define SPCR_DORD				0b00100000
#define SPCR_MSTR				0b00010000
#define SPCR_CPOL				0b00001000
#define SPCR_CPHA				0b00000100
#define SPCR_SPR1				0b00000010
#define SPCR_SPR0				0b00000001
#define SPCR_SPR_M				0b00000011
#define SPCR_SPR_CLR_M			0b11111100

#define SPSR_SPIF				0b10000000
#define SPSR_WCOL				0b01000000
#define SPSR_SPI2X				0b00000001

#define SPDR_M					0b11111111
#define SPDR_CLEAR_M			0b00000000

#define SPI_MASTER				0b00010000
#define SPI_SLAVE				0b00000000

#define SPI_INT_ENABLE			0b10000000
#define SPI_INT_DISABLE			0b00000000

#define SPI_MSB					0b00000000
#define SPI_LSB					0b00100000

#define SPI_RISING_EDGE			0b00000000
#define SPI_FALLING_EDGE		0b00001000

#define SPI_SETUP				0b00000100
#define SPI_SAMPLE				0b00000000

#define SPI_CLK_OVER_4			0
#define SPI_CLK_OVER_16         1
#define SPI_CLK_OVER_64         2
#define SPI_CLK_OVER_128        3
#define SPI_HCLK_OVER_2         4
#define SPI_HCLK_OVER_8         5
#define SPI_HCLK_OVER_32        6
#define SPI_HCLK_OVER_64        7

/*Global Pointer to Asynchronous buffers and their size*/
u8* SPI_TransmittedBuffer = NULL;
u8* SPI_ReceivedBuffer = NULL;
u8  SPI_BufferSize;
u8  SPI_BufferIDX=0;
void(*EndOfJobNotification)(void);

/*Protoype of ISR Function of SPI*/
void __vector_12(void) __attribute__((signal));

#define ISR(NO) 	void __vector_##NO(void)  __attribute__((signal));\
					void __vector##NO(void)

ERROR_STATUS SPI_Init(void){
	/* 1- DIO Pins Configuration
	 * 2- Data Order
	 * 3- Master or Slave Mode
	 * 4- Clock Polarity and Clock Phase
	 * 5- Enable SPI*/
	ERROR_STATUS Local_ErrorState = NOT_OK;

	u8 RegTemp = 0x00;
	RegTemp = SPI_NODE_MODE | SPI_INT_STATE | SPCR_SPE | SPI_DATA_ORDER | SPI_CLK_POLARITY | SPI_CLK_PHASE;
	if (SPI_CLK_SPEED < 4){
		RegTemp |= SPI_CLK_SPEED;
	}else {
		RegTemp |= (SPI_CLK_SPEED - 4) ;
		SPI_SPSR |= SPSR_SPI2X;
	}
		SPI_SPCR = RegTemp ;

		if (SPI_SPCR == RegTemp){
			Local_ErrorState = OK;
		}
	return Local_ErrorState;
}

ERROR_STATUS SPI_SendSync(u8 Data){
	ERROR_STATUS Local_ErrorStatus = NOT_OK;
	u16 Local_TimeOutCounter=0;
	u8 Local_DummyData;

	SPI_SPDR = Data;

	while ( ( (SPI_SPSR & SPSR_SPIF) == 0 ) && (Local_TimeOutCounter < SPI_TIME_OUT )  ){
		Local_TimeOutCounter++;
	}

	if (Local_TimeOutCounter <=  SPI_TIME_OUT){
		Local_ErrorStatus = OK;
	}

	Local_DummyData = SPI_SPDR ;
	return Local_ErrorStatus;
}

ERROR_STATUS SPI_ReceiveSync(u8* Data){
	ERROR_STATUS Local_ErrorStatus = NOT_OK;
	u16 Local_TimeOutCounter=0;

	/*Check Pointer Validity*/
	if (Data){

		SPI_SPDR = 0;

		while ( ( (SPI_SPSR & SPSR_SPIF) == 0 ) && (Local_TimeOutCounter < SPI_TIME_OUT )  ){
			Local_TimeOutCounter++;
		}

		if (Local_TimeOutCounter <=  SPI_TIME_OUT){
			*Data = SPI_SPDR;
			Local_ErrorStatus = OK;
		}
	}
	return Local_ErrorStatus;

}

ERROR_STATUS SPI_SendReceiveSync(u8 SentData, u8* ReceivedData){
	ERROR_STATUS Local_ErrorStatus = NOT_OK;
	u16 Local_TimeOutCounter=0;

	/*Check Pointer Validity*/
	if (ReceivedData){

		SPI_SPDR = SentData;

		while ( ( (SPI_SPSR & SPSR_SPIF) == 0 ) && (Local_TimeOutCounter < SPI_TIME_OUT )  ){
			Local_TimeOutCounter++;
		}

		if (Local_TimeOutCounter <=  SPI_TIME_OUT){
			*ReceivedData = SPI_SPDR;
			Local_ErrorStatus = OK;
		}
	}
	return Local_ErrorStatus;
}
ERROR_STATUS SPI_SendReceiveAsync(u8* SentData, u8* ReceivedData, u8 BufferSize, void(*AppNotifier)(void)){
	ERROR_STATUS Local_ErrorStatus = NOT_OK;
	u16 Local_TimeOutCounter=0;

	/*Check Pointer Validity*/
	if (SentData && ReceivedData && AppNotifier){
		SPI_TransmittedBuffer = SentData;
		SPI_ReceivedBuffer = ReceivedData;
		SPI_BufferSize = BufferSize;
		EndOfJobNotification = AppNotifier;

		/*Transmit First Byte in Buffer*/
		SPI_SPDR = SPI_TransmittedBuffer[SPI_BufferIDX];

		/*Enable SPI Interrupt*/
		SPI_SPCR |= SPCR_SPIE;
	}
	return Local_ErrorStatus;
}

ISR(12){
	SPI_ReceivedBuffer[SPI_BufferIDX] = SPI_SPDR;
	SPI_BufferIDX++;
	if(SPI_BufferIDX == SPI_BufferSize){
		/*clear buffer idx*/
		SPI_BufferIDX =0;
		SPI_BufferSize=0;
	}else{
		SPI_SPDR = SPI_TransmittedBuffer[SPI_BufferIDX];
	}
}
