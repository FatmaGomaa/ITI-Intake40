/*
 * HSwitch_Config.c
 *
 *  Created on: Mar 16, 2020
 *      Author: FatmaGomaa
 */

#include "STD_TYPES.h"
#include "dGPIO.h"
#include "dRCC.h"
#include "HSwitch.h"
#include "HSwitch_Config.h"



Switch_t App_Switches[NUM_OF_SWITCHES]={
		{
				.PORT= PORT_A,
				.PIN= PIN_0,
				.GPIO_MODE = PULL_UP
		},
		{
				.PORT= PORT_A,
				.PIN= PIN_1,
				.GPIO_MODE = PULL_UP
		}
};
