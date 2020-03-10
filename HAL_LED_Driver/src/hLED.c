/*
 * hLED.c
 *
 *  Created on: Mar 3, 2020
 *      Author: FatmaGomaa
 */

#include "STD_TYPES.h"

#include "dRCC.h"
#include "dGPIO.h"
#include "hLED.h"

extern const LED_MAP_t APP_LEDS[NUM_OF_LEDS];

STD_ERROR HLed_writeLedState(u8 Copy_u8Led, u8 Copy_u8LedState){
	STD_ERROR Local_ErrorStatus = NOT_OK;
	Local_ErrorStatus = GPIO_STD_ERROR_writePin((PORT_REGISTERS*)APP_LEDS[Copy_u8Led].GPIO_PORT,APP_LEDS[Copy_u8Led].GPIO_PIN,APP_LEDS[Copy_u8Led].GPIO_STATE ^ Copy_u8LedState);
	return Local_ErrorStatus;
}

STD_ERROR HLed_Init(void){
	STD_ERROR Local_ErrorStatus = NOT_OK;
	u8 Local_u8Iteration = 0;
	GPIO_t LED_GPIO;

	for(Local_u8Iteration=0; Local_u8Iteration <NUM_OF_LEDS ; Local_u8Iteration++){
		LED_GPIO.PORT=(PORT_REGISTERS*) APP_LEDS[Local_u8Iteration].GPIO_PORT;
		LED_GPIO.PIN= APP_LEDS[Local_u8Iteration].GPIO_PIN;
		LED_GPIO.MOOD=APP_LEDS[Local_u8Iteration].GPIO_MOOD ;
		Local_ErrorStatus = GPIO_STD_ERROR_Config(&LED_GPIO);
		GPIO_STD_ERROR_writePin(LED_GPIO.PORT,LED_GPIO.PIN,APP_LEDS[Local_u8Iteration].INITIAL_VALUE);
	}

	return Local_ErrorStatus;
}
