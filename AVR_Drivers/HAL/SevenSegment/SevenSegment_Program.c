#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "SevenSegment_Interface.h"
#include "SevenSegment_Config.h"
#include "SevenSegment_Private.h"

u8 LastValue = SEVENSEG_INITIAL_VALUE;

void SevenSeg_SetNumber(u8 Number){

	/*values written in common and in case of common Anode use ~*/
	u8 SEVENSEG_ARR[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
	//u8 SEVENSEG_ARR[10] = {0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b11111111};
	/*Common Anode*/
#if (SevenSeg_ONE_Mode == 0)
	DIO_SetPinValue(SEVENSEG_PIN_A_PORT,SEVENSEG_PIN_A_PIN,GET_BIT(~SEVENSEG_ARR[Number],0));
	DIO_SetPinValue(SEVENSEG_PIN_B_PORT,SEVENSEG_PIN_B_PIN,GET_BIT(~SEVENSEG_ARR[Number],1));
	DIO_SetPinValue(SEVENSEG_PIN_C_PORT,SEVENSEG_PIN_C_PIN,GET_BIT(~SEVENSEG_ARR[Number],2));
	DIO_SetPinValue(SEVENSEG_PIN_D_PORT,SEVENSEG_PIN_D_PIN,GET_BIT(~SEVENSEG_ARR[Number],3));
	DIO_SetPinValue(SEVENSEG_PIN_E_PORT,SEVENSEG_PIN_E_PIN,GET_BIT(~SEVENSEG_ARR[Number],4));
	DIO_SetPinValue(SEVENSEG_PIN_F_PORT,SEVENSEG_PIN_F_PIN,GET_BIT(~SEVENSEG_ARR[Number],6));
	DIO_SetPinValue(SEVENSEG_PIN_G_PORT,SEVENSEG_PIN_G_PIN,GET_BIT(~SEVENSEG_ARR[Number],5));
	DIO_SetPinValue(SEVENSEG_PIN_H_PORT,SEVENSEG_PIN_H_PIN,GET_BIT(~SEVENSEG_ARR[Number],7));
#elif (SevenSeg_ONE_Mode == 1)
	/*CommonCathode*/
	DIO_SetPinValue(SEVENSEG_PIN_A_PORT,SEVENSEG_PIN_A_PIN,GET_BIT(SEVENSEG_ARR[Number],0));
	DIO_SetPinValue(SEVENSEG_PIN_B_PORT,SEVENSEG_PIN_B_PIN,GET_BIT(SEVENSEG_ARR[Number],1));
	DIO_SetPinValue(SEVENSEG_PIN_C_PORT,SEVENSEG_PIN_C_PIN,GET_BIT(SEVENSEG_ARR[Number],2));
	DIO_SetPinValue(SEVENSEG_PIN_D_PORT,SEVENSEG_PIN_D_PIN,GET_BIT(SEVENSEG_ARR[Number],3));
	DIO_SetPinValue(SEVENSEG_PIN_E_PORT,SEVENSEG_PIN_E_PIN,GET_BIT(SEVENSEG_ARR[Number],4));
	DIO_SetPinValue(SEVENSEG_PIN_F_PORT,SEVENSEG_PIN_F_PIN,GET_BIT(SEVENSEG_ARR[Number],6));
	DIO_SetPinValue(SEVENSEG_PIN_G_PORT,SEVENSEG_PIN_G_PIN,GET_BIT(SEVENSEG_ARR[Number],5));
	DIO_SetPinValue(SEVENSEG_PIN_H_PORT,SEVENSEG_PIN_H_PIN,GET_BIT(SEVENSEG_ARR[Number],7));
#endif

	//LastValue = Number;
}
void SevenSeg_Enable(u8 SevenSeg_Num){
	/*COMMON ANODE 			(SevenSeg_Mode == 0)
	 COMMON CATHODE 			(SevenSeg_Mode == 1)
	 */
	if(SevenSeg_Num ==1){
#if (SevenSeg_ONE_Mode == 0)
		DIO_SetPinValue(SEVENSEG_ONE_ENABLE_PORT,SEVENSEG_ONE_ENABLE_PIN,1);
		//SevenSeg_SetNumber(LastValue);
#elif (SevenSeg_ONE_Mode == 1)
		DIO_SetPinValue(SEVENSEG_ONE_ENABLE_PORT,SEVENSEG_ONE_ENABLE_PIN,0);
		//SevenSeg_SetNumber(LastValue);
#endif
	}else if (SevenSeg_Num ==2){
#if (SevenSeg_ONE_Mode == 0)
		DIO_SetPinValue(SEVENSEG_TWO_ENABLE_PORT,SEVENSEG_TWO_ENABLE_PIN,1);
		//SevenSeg_SetNumber(LastValue);
#elif (SevenSeg_ONE_Mode == 1)
		DIO_SetPinValue(SEVENSEG_TWO_ENABLE_PORT,SEVENSEG_TWO_ENABLE_PIN,0);
		//SevenSeg_SetNumber(LastValue);
#endif
	}else{
		/*do nothing*/
	}

}

void SevenSeg_Disable(u8 SevenSeg_Num){
	/*COMMON ANODE 			(SevenSeg_Mode == 0)
	 COMMON CATHODE 			(SevenSeg_Mode == 1)
	 */
	if(SevenSeg_Num ==1){
#if (SevenSeg_ONE_Mode == 0)
		DIO_SetPinValue(SEVENSEG_ONE_ENABLE_PORT,SEVENSEG_ONE_ENABLE_PIN,0);
		//SevenSeg_SetNumber(LastValue);
#elif (SevenSeg_ONE_Mode == 1)
		DIO_SetPinValue(SEVENSEG_ONE_ENABLE_PORT,SEVENSEG_ONE_ENABLE_PIN,1);
		//SevenSeg_SetNumber(LastValue);
#endif
	}else if (SevenSeg_Num ==2){
#if (SevenSeg_ONE_Mode == 0)
		DIO_SetPinValue(SEVENSEG_TWO_ENABLE_PORT,SEVENSEG_TWO_ENABLE_PIN,0);
		//SevenSeg_SetNumber(LastValue);
#elif (SevenSeg_ONE_Mode == 1)
		DIO_SetPinValue(SEVENSEG_TWO_ENABLE_PORT,SEVENSEG_TWO_ENABLE_PIN,1);
		//SevenSeg_SetNumber(LastValue);
#endif
	}else{
		/*do nothing*/
	}

}


void SevenSeg_SetLed(u8 Led_Num){

	u8 LedOutput = 1<< Led_Num;
	/*Common Anode*/
#if (SevenSeg_ONE_Mode == 0)
	DIO_SetPinValue(SEVENSEG_PIN_A_PORT,SEVENSEG_PIN_A_PIN,GET_BIT(~LedOutput,0));
	DIO_SetPinValue(SEVENSEG_PIN_B_PORT,SEVENSEG_PIN_B_PIN,GET_BIT(~LedOutput,1));
	DIO_SetPinValue(SEVENSEG_PIN_C_PORT,SEVENSEG_PIN_C_PIN,GET_BIT(~LedOutput,2));
	DIO_SetPinValue(SEVENSEG_PIN_D_PORT,SEVENSEG_PIN_D_PIN,GET_BIT(~LedOutput,3));
	DIO_SetPinValue(SEVENSEG_PIN_E_PORT,SEVENSEG_PIN_E_PIN,GET_BIT(~LedOutput,4));
	DIO_SetPinValue(SEVENSEG_PIN_F_PORT,SEVENSEG_PIN_F_PIN,GET_BIT(~LedOutput,6));
	DIO_SetPinValue(SEVENSEG_PIN_G_PORT,SEVENSEG_PIN_G_PIN,GET_BIT(~LedOutput,5));
	DIO_SetPinValue(SEVENSEG_PIN_H_PORT,SEVENSEG_PIN_H_PIN,GET_BIT(~LedOutput,7));
#elif (SevenSeg_ONE_Mode == 1)
	/*CommonCathode*/
	DIO_SetPinValue(SEVENSEG_PIN_A_PORT,SEVENSEG_PIN_A_PIN,GET_BIT(LedOutput,0));
	DIO_SetPinValue(SEVENSEG_PIN_B_PORT,SEVENSEG_PIN_B_PIN,GET_BIT(LedOutput,1));
	DIO_SetPinValue(SEVENSEG_PIN_C_PORT,SEVENSEG_PIN_C_PIN,GET_BIT(LedOutput,2));
	DIO_SetPinValue(SEVENSEG_PIN_D_PORT,SEVENSEG_PIN_D_PIN,GET_BIT(LedOutput,3));
	DIO_SetPinValue(SEVENSEG_PIN_E_PORT,SEVENSEG_PIN_E_PIN,GET_BIT(LedOutput,4));
	DIO_SetPinValue(SEVENSEG_PIN_F_PORT,SEVENSEG_PIN_F_PIN,GET_BIT(LedOutput,6));
	DIO_SetPinValue(SEVENSEG_PIN_G_PORT,SEVENSEG_PIN_G_PIN,GET_BIT(LedOutput,5));
	DIO_SetPinValue(SEVENSEG_PIN_H_PORT,SEVENSEG_PIN_H_PIN,GET_BIT(LedOutput,7));
#endif




}
