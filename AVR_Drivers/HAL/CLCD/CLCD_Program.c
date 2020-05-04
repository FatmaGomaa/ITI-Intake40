/***********************************************/
/* Author: Fatma Gomaa*/
/* Version: v01 */
/* Date: 14 Jan 2020 */
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DELAY_INTERFACE.h"

#include "DIO_Interface.h"
#include "CLCD_Interface.h"
#include "CLCD_Private.h"
#include "CLCD_Config.h"
#include "CLCD_Register.h"

#define secondHalfOfCommand		4

/*Description; this API shall initialize LCD*/
void CLCD_voidInitialize(void){
#if CLCD_u8_DATALENGHT == EIGHT_BITS_MODE

	Delay_ms(40);
	CLCD_voidWriteCmd(0b00111000);
	CLCD_voidWriteCmd(0b00001100);
	CLCD_voidWriteCmd(0b00000001);
	Delay_ms(2);
#elif CLCD_u8_DATALENGHT == FOUR_BITS_MODE
	Delay_ms(40);
	/*Function Set*/
	CLCD_voidSetHalfDataPort(0b0010);
	/*Enable Pulse*/
	CLCD_voidSetEnablePulse();
	/*send 0010*/
	CLCD_voidSetHalfDataPort(0b0010);
	/*Enable Pulse*/
	CLCD_voidSetEnablePulse();
	/*2 lines display, 5*7 */
	CLCD_voidSetHalfDataPort(0b1000);
	/*Enable Pulse*/
	CLCD_voidSetEnablePulse();

	Delay_ms(2);
	CLCD_voidWriteCmd(0b00001100);
	Delay_ms(2);
	CLCD_voidWriteCmd(0b00000001);
	Delay_ms(2);

#else #error "Wrong Data Length Choice"
#endif
}

/*Description; this API shall display Data on LCD*/
void CLCD_voidWriteData(u8 Copy_u8Data){
	/*SET RS to 1*/
	DIO_SetPinValue(CLCD_u8_RS_PORT,CLCD_u8_RS_PIN,1);
	
	/*clear RW*/
	DIO_SetPinValue(CLCD_u8_RW_PORT,CLCD_u8_RW_PIN,0);
	
#if	CLCD_u8_DATALENGHT == EIGHT_BITS_MODE

	/*set Data on Data port*/
	CLCD_voidSetDataPort(Copy_u8Data);
	
	/*Enable Pulse*/
	CLCD_voidSetEnablePulse();

#elif	CLCD_u8_DATALENGHT == FOUR_BITS_MODE
	/*set Data on Data port*/
	CLCD_voidSetHalfDataPort(Copy_u8Data>>secondHalfOfCommand);
	/*Enable Pulse*/
	CLCD_voidSetEnablePulse();

	/*set Data on Data port*/
	CLCD_voidSetHalfDataPort(Copy_u8Data);
	/*Enable Pulse*/
	CLCD_voidSetEnablePulse();

#else #error "Wrong Data Length Choice"
#endif
}

/*Description; this API shall write Command to LCD*/
void CLCD_voidWriteCmd(u8 Copy_u8Cmd){
	/*SET RS to 0*/
	DIO_SetPinValue(CLCD_u8_RS_PORT,CLCD_u8_RS_PIN,0);

	/*clear RW*/
	DIO_SetPinValue(CLCD_u8_RW_PORT,CLCD_u8_RW_PIN,0);

#if CLCD_u8_DATALENGHT == EIGHT_BITS_MODE

	/*set Data on Data port*/
	CLCD_voidSetDataPort(Copy_u8Cmd);
	
	/*Enable Pulse*/
	CLCD_voidSetEnablePulse();



#elif CLCD_u8_DATALENGHT == FOUR_BITS_MODE

	/*set Data on Data port*/
	CLCD_voidSetHalfDataPort(Copy_u8Cmd>>secondHalfOfCommand);
	/*Enable Pulse*/
	CLCD_voidSetEnablePulse();

	/*set Data on Data port*/
	CLCD_voidSetHalfDataPort(Copy_u8Cmd);
	/*Enable Pulse*/
	CLCD_voidSetEnablePulse();

#else #error "Wrong Data Length Choice"
#endif
	
}

static void CLCD_voidSetDataPort(u8 Copy_u8Data){
	u8 Local_u8BitVal;
	
	Local_u8BitVal = GET_BIT(Copy_u8Data,0);
	DIO_SetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D0,Local_u8BitVal);
	Local_u8BitVal = GET_BIT(Copy_u8Data,1);
	DIO_SetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D1,Local_u8BitVal);
	Local_u8BitVal = GET_BIT(Copy_u8Data,2);
	DIO_SetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D2,Local_u8BitVal);
	Local_u8BitVal = GET_BIT(Copy_u8Data,3);
	DIO_SetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D3,Local_u8BitVal);
	Local_u8BitVal = GET_BIT(Copy_u8Data,4);
	DIO_SetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D4,Local_u8BitVal);
	Local_u8BitVal = GET_BIT(Copy_u8Data,5);
	DIO_SetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D5,Local_u8BitVal);
	Local_u8BitVal = GET_BIT(Copy_u8Data,6);
	DIO_SetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D6,Local_u8BitVal);
	Local_u8BitVal = GET_BIT(Copy_u8Data,7);
	DIO_SetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D7,Local_u8BitVal);
}

static void CLCD_voidSetHalfDataPort(u8 Copy_u8Data){
	u8 Local_u8BitVal;

	Local_u8BitVal = GET_BIT(Copy_u8Data,0);
	DIO_SetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D4,Local_u8BitVal);
	Local_u8BitVal = GET_BIT(Copy_u8Data,1);
	DIO_SetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D5,Local_u8BitVal);
	Local_u8BitVal = GET_BIT(Copy_u8Data,2);
	DIO_SetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D6,Local_u8BitVal);
	Local_u8BitVal = GET_BIT(Copy_u8Data,3);
	DIO_SetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D7,Local_u8BitVal);
}

void CLCD_displayAtCertainPosition(u8 line, u8 colNum){

	switch(line){
	case 1:
		CLCD_voidWriteCmd(0x80);
		CLCD_voidWriteCmd( (0b10000000)|colNum );
		break;

	case 2:
		CLCD_voidWriteCmd(0xC0);
		CLCD_voidWriteCmd((0b11000000)|colNum);
		break;

	}

}
void CLCD_voidWriteString(const char* copy_pchString){
	while(*copy_pchString != '\0'){
		CLCD_voidWriteData(*copy_pchString);
		copy_pchString++;
	}
}

static void CLCD_voidSetEnablePulse(void){
	/*Enable Pulse*/
	DIO_SetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,1);
	Delay_ms(1);
	DIO_SetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,0);
	Delay_ms(1);

}





