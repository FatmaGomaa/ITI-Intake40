/*
 * hLED_Config.c
 *
 *  Created on: Mar 3, 2020
 *      Author: FatmaGomaa
 */
#include "STD_TYPES.h"

#include "dRCC.h"
#include "dGPIO.h"
#include "hLED.h"


const LED_MAP_t APP_LEDS[NUM_OF_LEDS]={
		{LED_1, PIN_13, PORT_C,OUTPUT_GP_PUSH_PULL_10MHZ,GPIO_ACTIVE_LOW,HIGH },
		{LED_2, PIN_1, PORT_A,OUTPUT_GP_PUSH_PULL_10MHZ,GPIO_ACTIVE_HIGH,LOW },
		{LED_3, PIN_2, PORT_A,OUTPUT_GP_PUSH_PULL_10MHZ,GPIO_ACTIVE_HIGH,LOW }
};

