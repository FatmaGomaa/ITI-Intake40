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
/*    input it writes to IDR.                                                                       */
/*	- GPIO getPinValue returns the reading of a single bit.                                         */
/*                                                                                                  */
/*                                                                                                  */
/****************************************************************************************************/

#include "STD_TYPES.h"
#include "dGPIO.h"


STD_ERROR 	GPIO_STD_ERROR_Config(GPIO_t * GPIO_Config){
	STD_ERROR Local_ErrorStatus = NOT_OK;
	PORT_REGISTERS* GPIO_Config_Struct = (PORT_REGISTERS*) GPIO_Config->PORT;
	u32 temp_GPIO_CRX = 0;

	if(GPIO_Config->PIN < 8){
		temp_GPIO_CRX = GPIO_Config_Struct->GPIO_CRL;
		temp_GPIO_CRX &=~ (0b1111) << (4*(GPIO_Config->PIN));
		temp_GPIO_CRX |= GPIO_Config->MOOD << (4*(GPIO_Config->PIN));
		GPIO_Config_Struct->GPIO_CRL = temp_GPIO_CRX;
		if(GPIO_Config_Struct->GPIO_CRL == temp_GPIO_CRX){
			Local_ErrorStatus= OK;
		}
	}else{
		temp_GPIO_CRX = GPIO_Config_Struct->GIPO_CRH;
		temp_GPIO_CRX &=~ (0b1111) << (4*(GPIO_Config->PIN -8 ));
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
	if(OutputValue == 1){
		GPIO_Config_Struct->GPIO_BSRR = 1 << (GPIO_Config->PIN);
	}else if(OutputValue == 0){
		GPIO_Config_Struct->GIPO_BRR = 1 << (GPIO_Config->PIN);
	}
	/*if(GPIO_Config_Struct->GIPO_ODR == ( GPIO_Config_Struct->GIPO_ODR | (1 << (GPIO_Config->PIN)) )){
		Local_ErrorStatus=OK;
	}*/
	Local_ErrorStatus=OK;
	return Local_ErrorStatus;

}

u8 GPIO_u8getPinValue(GPIO_t * GPIO_Config){
	PORT_REGISTERS* GPIO_Config_Struct = (PORT_REGISTERS*) GPIO_Config->PORT;
	return (GPIO_Config_Struct->GPIO_IDR >> GPIO_Config->PIN)&1 ;
}
