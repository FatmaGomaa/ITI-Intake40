/*******************************************************************************************************
 * File name: dSTK.c                                                                                   *
 *                                                                                                     *
 *                                                                                                     *
 * Description: This file contains the Prototypes of the NVIC driver funcitons                         *
 * and the macros used by the user                                                                     *
 *                                                                                                     *
 * Author: Fatima Gomaa                                                                                *
 * Date:   March 10, 2020                                                                              *
 * Version 1.0 : Initial Creation of the STK Driver                                                    *
 *******************************************************************************************************/

#include "STD_TYPES.h"
#include "dSTK.h"


#define STK_CTRL_COUNTFLAG							0X00010000
#define STK_CTRL_CLKSOURCE							0X00000004
#define STK_CTRL_TICKINT							0X00000002
#define STK_CTRL_ENABLE								0X00000001

#define STK_LOAD_RELOAD								0X00FFFFFF
#define STK_LOAD_RELOAD_CLEAR						0XFF000000

#define STK_VAL_CURRENT								0X00FFFFFF
#define STK_VAL_CURRENT_CLEAR						0XFF000000

#define MAX_PRELOAD_VALUE							16777216ull

static STK_CBF_t APP_CPF = (void*)0;

STD_ERROR STK_Init(void){
	STD_ERROR Local_ErrorStatus = NOT_OK;
	STK_Peripheral_t* STK_Peripheral = (STK_Peripheral_t*)STK_PERIPHERAL;
	/*Prescaler AHB/8 */
	STK_Peripheral->STK_CTRL &=~ STK_CTRL_CLKSOURCE;
	/*Interrupt Enable*/
	STK_Peripheral->STK_CTRL |=  STK_CTRL_TICKINT;
	/*Preload = 0*/
	STK_Peripheral->STK_LOAD &=  STK_LOAD_RELOAD_CLEAR;

	if( (STK_Peripheral->STK_CTRL &  STK_CTRL_TICKINT) == STK_CTRL_TICKINT){
		Local_ErrorStatus = OK;
	}

	return Local_ErrorStatus;
}

STD_ERROR STK_Start(void){
	STD_ERROR Local_ErrorStatus = NOT_OK;
	STK_Peripheral_t* STK_Peripheral = (STK_Peripheral_t*)STK_PERIPHERAL;
	STK_Peripheral->STK_CTRL |=  STK_CTRL_ENABLE;
	if( (STK_Peripheral->STK_CTRL &  STK_CTRL_ENABLE) == STK_CTRL_ENABLE){
		Local_ErrorStatus = OK;
	}
	return Local_ErrorStatus;

}
STD_ERROR STK_Stop(void){
	STD_ERROR Local_ErrorStatus = NOT_OK;
	STK_Peripheral_t* STK_Peripheral = (STK_Peripheral_t*)STK_PERIPHERAL;
	STK_Peripheral->STK_CTRL &=~  STK_CTRL_ENABLE;

	if( (STK_Peripheral->STK_CTRL &  STK_CTRL_ENABLE) == LOW){
		Local_ErrorStatus = OK;
	}
	return Local_ErrorStatus;


}
STD_ERROR STK_SetPrescaler(u32 Copy_u32Prescaler){
	STD_ERROR Local_ErrorStatus = NOT_OK;
	STK_Peripheral_t* STK_Peripheral = (STK_Peripheral_t*)STK_PERIPHERAL;
		if(Copy_u32Prescaler == STK_PRESCALER_AHB_DIVIDED_BY_8){
			STK_Peripheral->STK_CTRL &=~ STK_CTRL_CLKSOURCE;
			if( (STK_Peripheral->STK_CTRL & STK_CTRL_CLKSOURCE) == LOW ){
				Local_ErrorStatus = OK;
			}
		}else if(Copy_u32Prescaler == STK_PRESCALER_AHB){
			STK_Peripheral->STK_CTRL |= STK_CTRL_CLKSOURCE;
			if( (STK_Peripheral->STK_CTRL & STK_CTRL_CLKSOURCE) >= HIGH ){
				Local_ErrorStatus = OK;
			}

		}
		return Local_ErrorStatus;

}
STD_ERROR STK_SetTime(u32 Copy_u32TimeUS, u32 Copy_u32RCC_ClockValue){
	STD_ERROR Local_ErrorStatus = NOT_OK;
	u32 Local_u32NumOfTicks=0;
	STK_Peripheral_t* STK_Peripheral = (STK_Peripheral_t*)STK_PERIPHERAL;

	if((STK_Peripheral->STK_CTRL & STK_CTRL_CLKSOURCE) == LOW){
		/* AHB/8 */
		Local_u32NumOfTicks = ((Copy_u32TimeUS * Copy_u32RCC_ClockValue) / STK_PRESCALER_AHB_DIVIDED_BY_8);
	}else{
		/* AHB */
		Local_u32NumOfTicks = ((Copy_u32TimeUS * Copy_u32RCC_ClockValue) / STK_PRESCALER_AHB);
	}


	if(Local_u32NumOfTicks < MAX_PRELOAD_VALUE){
		STK_Peripheral->STK_LOAD =  Local_u32NumOfTicks;

	}

	if(STK_Peripheral->STK_LOAD == Local_u32NumOfTicks){
		Local_ErrorStatus = OK;
	}

	return Local_ErrorStatus;

}
STD_ERROR STK_SetCallBack(STK_CBF_t cbf){
	STD_ERROR Local_ErrorStatus = NOT_OK;

	if(cbf){
	APP_CPF = cbf;
	Local_ErrorStatus = OK;
	}
	return Local_ErrorStatus;

}

