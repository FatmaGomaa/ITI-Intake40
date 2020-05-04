/***********************************************************************************************/
/* AUTHOR: Fatima Gomaa                                                                        */
/* DATE	 : March 9 2020                                                                        */
/* VERSION: V01                                                                                */
/***********************************************************************************************/
#include "STD_TYPES.h"

#include "UART_Interface.h"
#include "UART_Private.h" 
#include "UART_Config.h"
#include "UART_Register.h"


#define UCSRA_U2X							0b00000010
#define UCSRA_UDRE							0b00100000
#define UCSRA_TXC							0b01000000
#define UCSRA_RXC							0b10000000

#define UCSRB_RXCIE							0b10000000
#define UCSRB_TXCIE							0b01000000
#define UCSRB_UDRIE							0b00100000
#define UCSRB_RXEN							0b00010000
#define UCSRB_TXEN							0b00001000
#define UCSRB_UCSZ2							0b00000100
#define UCSRB_RXB8							0b00000010
#define UCSRB_TXB8							0b00000001

#define UCSRC_URSEL							0b10000000
#define UCSRC_UMSEL							0b01000000
#define UCSRC_UPM1							0b00100000
#define UCSRC_UPM0							0b00010000
#define UCSRC_USBS							0b00001000
#define UCSRC_UCSZ1							0b00000100
#define UCSRC_UCSZ0							0b00000010
#define UCSRC_UCPOL							0b00000001

void(*EndOfTransmitCallBack)(void);
void (*EndOfRecieveCallBack)(u8);

void UART_voidInitialize(void){
	/*disable U2X*/
	UART_UCSRA &= ~ UCSRA_U2X;
	
	/*1. Disable all interrupts
	  2. Enable RX and TX
	  3. Choose Character Size of 8 bit*/
	UART_UCSRB &= ~ (UCSRB_RXCIE | UCSRB_TXCIE | UCSRB_UDRIE | UCSRB_UCSZ2 | UCSRB_TXB8 | UCSRB_RXB8);
	UART_UCSRB |= UCSRB_RXEN | UCSRB_TXEN;
	
	/*Asynchronous Mode
	  Character Size = 8 bit*/ //parity is disabled
	UART_UCSRC |= (UCSRC_URSEL | UCSRC_UCSZ1 | UCSRC_UCSZ0);
	UART_UCSRC &= ~ (UCSRC_UMSEL | UCSRC_UPM1 | UCSRC_UPM0 | UCSRC_USBS | UCSRC_UCPOL);

	/*Assign BaudRate*/
	UART_UBRRL |= UART_U8_BAUD_RATE;
}

void UART_voidTransmitDataSynch(u8 Copy_u8Data){
	u32 Local_u32TimeOut =0, Local_u8Error = OK; 

	while( !(UART_UCSRA & UCSRA_UDRE) );

	/*Disable TXC and UDRE flags*/
	UART_UCSRA |= UCSRA_TXC | UCSRA_UDRE;

	/*send data on UDR*/
	UART_UDR_TXB = Copy_u8Data;

	
	/*wait till flag is raised */

	while( ((UART_UCSRA & UCSRA_TXC) == 0 ) && ( Local_u32TimeOut < UART_U32_TIME_OUT_TH) ){
		Local_u32TimeOut++;
	}

	if(Local_u32TimeOut >= UART_U32_TIME_OUT_TH){
		Local_u8Error = NOT_OK;
	}else{
		UART_UCSRA |= UCSRA_TXC; 
		
	}

}

void UART_voidTransmitDataASynch(u8 Copy_u8Data, void(*Copy_ptr)(void)){
	/*Enable Tx Interrupt*/
	UART_UCSRB |= UCSRB_TXCIE;
	/*set received data to udr*/
	UART_UDR_TXB = Copy_u8Data;
	/*save the call back address*/
	EndOfTransmitCallBack = Copy_ptr;
}

u8	 UART_voidReceiveDataSynch(u8* Copy_u8Data){
	u32 Local_u32TimeOut =0, Local_u8Error = OK; 
	
	/*wait till flag is raised */
	while( ((UART_UCSRA & UCSRA_RXC) == 0 ) );

	*Copy_u8Data = UART_UDR_RXB;
	
	UART_UCSRA |= UCSRA_RXC;
	
	return Local_u8Error;
}

void UART_voidReceiveDataASynch(void(*Copy_ptr)(u8)){
	
	/*check if there is data to receive*/
	if ( (UART_UCSRA & UCSRA_RXC)==1 ){
		Copy_ptr(UART_UDR_RXB);
	}
	/*if nothing to receive now, enable interrupt*/
	else{
		UART_UCSRB |= UCSRB_RXCIE;
		EndOfRecieveCallBack = Copy_ptr;
	}
}
