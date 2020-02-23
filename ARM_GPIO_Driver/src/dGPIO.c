/***************************************************************************************************/
/* 											GPIO Driver												*/
/*                                                                                                  */
/*  Created on	: Feb 4, 2020                                                                       */
/*  Author		: FatmaGomaa  																		*/
/*  Versions	:																					*/
/*  V1 -> in this version:																			*/
/*  - the GPIO Config API receives a structure that holds the information of the 					*/
/*    passed pin                                                                                    */
/*  - GPIO write, writes both High and Low Values on Pin. If it's output, it writes to ODR. If it's */
/*    input it writes to ODR to turn the pull up or pull down register.                        		*/
/*	- GPIO getPinValue returns the reading of a single bit.                                         */
/*                                                                                                  */
/* V1.1 Solved a bug in GPIO_STD_ERROR_Config,the function was writing over the past values which is*/
/* not what we seek, every write cycle shouldn't affect the values of the other pins.   			*/
/* 																									*/
/* V1.2 added GPIO_STD_ERROR_writePort to set the Whole Port Value once.				            */
/****************************************************************************************************/

#include "STD_TYPES.h"
#include "dGPIO.h"


STD_ERROR 	GPIO_STD_ERROR_Config(GPIO_t * GPIO_Config){
	STD_ERROR Local_ErrorStatus = NOT_OK;
	PORT_REGISTERS* GPIO_Config_Struct = (PORT_REGISTERS*) GPIO_Config->PORT;
	u32 temp_GPIO_CRX = LOW;

	if(GPIO_Config->PIN < 8){
		temp_GPIO_CRX = GPIO_Config_Struct->GPIO_CRL;
		temp_GPIO_CRX &=~ ((0b1111) << (4*(GPIO_Config->PIN)));
		temp_GPIO_CRX |= GPIO_Config->MOOD << (4*(GPIO_Config->PIN));
		GPIO_Config_Struct->GPIO_CRL = temp_GPIO_CRX;
		if(GPIO_Config_Struct->GPIO_CRL == temp_GPIO_CRX){
			Local_ErrorStatus= OK;
		}
	}else{
		temp_GPIO_CRX = GPIO_Config_Struct->GIPO_CRH;
		temp_GPIO_CRX &=~ ((0b1111) << (4*(GPIO_Config->PIN -8 )));
		temp_GPIO_CRX |=GPIO_Config->MOOD << (4*(GPIO_Config->PIN -8));
		GPIO_Config_Struct->GIPO_CRH = temp_GPIO_CRX;
		if(GPIO_Config_Struct->GIPO_CRH == temp_GPIO_CRX){
			Local_ErrorStatus= OK;
		}
	}
	return Local_ErrorStatus;
}

STD_ERROR GPIO_STD_ERROR_writePin(GPIO_t * GPIO_Config, u8 OutputValue){
	STD_ERROR Local_ErrorStatus = NOT_OK;
	PORT_REGISTERS* GPIO_Config_Struct = (PORT_REGISTERS*) GPIO_Config->PORT;
	if(OutputValue == HIGH){
		GPIO_Config_Struct->GPIO_BSRR = HIGH << (GPIO_Config->PIN);
	}else if(OutputValue == LOW){
		GPIO_Config_Struct->GIPO_BRR = HIGH << (GPIO_Config->PIN);
	}
	if(GPIO_Config_Struct->GIPO_ODR == ( GPIO_Config_Struct->GIPO_ODR & (HIGH << (GPIO_Config->PIN)) )){
		Local_ErrorStatus=OK;
	}
	Local_ErrorStatus=OK;
	return Local_ErrorStatus;

}

STD_ERROR GPIO_STD_ERROR_writePort(PORT_REGISTERS * PORT, u8 OutputValue){
	STD_ERROR Local_ErrorStatus = NOT_OK;
	PORT->GIPO_ODR = OutputValue;
	if(PORT->GIPO_ODR == OutputValue){
		Local_ErrorStatus=OK;
	}
	return Local_ErrorStatus;

}


u8 GPIO_u8getPinValue(GPIO_t * GPIO_Config){
	u8 Local_ReturnValue=HIGH;
	PORT_REGISTERS* GPIO_Config_Struct = (PORT_REGISTERS*) GPIO_Config->PORT;
	//trace_printf("Pin Value %d \n", (GPIO_Config_Struct->GPIO_IDR >> GPIO_Config->PIN)&1);
	Local_ReturnValue= (GPIO_Config_Struct->GPIO_IDR >> GPIO_Config->PIN)&HIGH;
	return Local_ReturnValue;
}
