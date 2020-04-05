/*
 * HLED_config.c
 *
 *  Created on: Mar 8, 2020
 *      Author: mayab
 */
#include <stdint-gcc.h>

#include "STD_Types.h"
#include "dGPIO.h"
#include "HLED_interface.h"
#include "HLED_config.h"

/* An array of all the LEDs in the project */

const ledMap_t ledMap[NUM_OF_LEDS] = {
		{
			     .GPIO_port   = PORT_C,
			     .GPIO_pin    = PIN_13,
			     .GPIO_mode   = OUTPUT_GP_PUSH_PULL_10MHZ,
			     .ActiveState = LED_ACTIVE_LOW,
				 .LED_Name    = LED_ALARM

		},
		{
				.GPIO_port   = PORT_B,
				.GPIO_pin    = PIN_1,
				.GPIO_mode   = OUTPUT_GP_PUSH_PULL_10MHZ,
				.ActiveState = LED_ACTIVE_LOW,
				.LED_Name    = LED_DOOR

		},
		{
				.GPIO_port   = PORT_A,
				.GPIO_pin    = PIN_0,
				.GPIO_mode   = OUTPUT_GP_PUSH_PULL_10MHZ,
				.ActiveState = LED_ACTIVE_HIGH,
				.LED_Name    = LED_X

		}



};
