/*
 * Nokia_LCfg.c
 *
 *  Created on: Apr 24, 2020
 *      Author: FatmaGomaa
 */
#include "STD_TYPES.h"
#include "dGPIO.h"
#include "Nokia.h"

Nokia_Cfg_t Nokia = {

		.SPI_Channel = SPI_CH_1,
		.RST = {
				.PORT = PORT_A,
				.PIN  = PIN_2,
				.MOOD = OUTPUT_GP_PUSH_PULL_2MHZ
		},

		.CE = {
				.PORT = PORT_A,
				.PIN  = PIN_3,
				.MOOD = OUTPUT_GP_PUSH_PULL_2MHZ
		},

		.DC = {
				.PORT = PORT_A,
				.PIN  = PIN_1,
				.MOOD = OUTPUT_GP_PUSH_PULL_2MHZ
		}

};
