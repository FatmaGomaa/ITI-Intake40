/*
 * HLED.c
 *
 *  Created on: Mar 8, 2020
 *      Author: mayab
 */




#include "STD_Types.h"
#include "dGPIO.h"
#include "HLED_interface.h"
#include "HLED_config.h"

extern const ledMap_t ledMap[NUM_OF_LEDS];


void HLED_init(void)
{

	GPIO_t pinMap[NUM_OF_LEDS];


	u8 i = 0;
	for (i = 0; i < NUM_OF_LEDS; i++)
	{
		//pinMap[i] = (GPIO_t) ledMap[i];
		pinMap[i].PORT = ledMap[i].GPIO_port;
		pinMap[i].PIN = ledMap[i].GPIO_pin;
		pinMap[i].MOOD = ledMap[i].GPIO_mode;
		GPIO_Config(&pinMap[i]);

	}


}

void HLED_setLedState (u8 ledNum, u8 ledState)
{
	if(ledMap[ledNum].ActiveState == LED_ACTIVE_HIGH)
	{
		if (ledState == LED_ON)
		{
			GPIO_writePin(ledMap[ledNum].GPIO_port, ledMap[ledNum].GPIO_pin, HIGH);
		}
		else if(ledState == LED_OFF)
		{
			GPIO_writePin(ledMap[ledNum].GPIO_port, ledMap[ledNum].GPIO_pin, LOW);
		}
	}
	else if (ledMap[ledNum].ActiveState == LED_ACTIVE_LOW)
	{
		if (ledState == LED_ON)
		{

			GPIO_writePin(ledMap[ledNum].GPIO_port, ledMap[ledNum].GPIO_pin, LOW);
		}

		else if(ledState == LED_OFF)
		{
			GPIO_writePin(ledMap[ledNum].GPIO_port, ledMap[ledNum].GPIO_pin, HIGH);
		}
	}

}

