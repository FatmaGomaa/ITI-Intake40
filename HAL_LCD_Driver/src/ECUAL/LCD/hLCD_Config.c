/*
 * hLCD_Config.c
 *
 *  Created on: Mar 24, 2020
 *      Author: FatmaGomaa
 */

#include "STD_TYPES.h"
#include "dGPIO.h"
#include "dRCC.h"
#include "hLCD_Config.h"
#include "hLCD.h"

LCD_GPIO_MAP_t APP_LCDs[LCD_NUM]={
		{
			.LCD_CONTROL_PORT 							= PORT_A,
			.LCD_Data_PORT	  							= PORT_A,
			.LCD_RS_PIN		  							= PIN_0,
			.LCD_RW_PIN		                      		= PIN_1,
			.LCD_Enable_PIN								= PIN_2,

			{PIN_3,PIN_4,PIN_5,PIN_6,PIN_7,PIN_8,PIN_11,PIN_12},

			.LCD_Data_pins_Mode							= OUTPUT_GP_PUSH_PULL_10MHZ,
			.LCD_Data_InitialValue						= LOW
		}
};
