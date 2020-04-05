/*
 * HLED_config.h
 *
 *  Created on: Mar 18, 2020
 *      Author: mayab
 */

#ifndef HLED_CONFIG_H_
#define HLED_CONFIG_H_

#define NUM_OF_LEDS              3


typedef struct
{
	volatile void * GPIO_port;
	u32 GPIO_pin;
	u32 GPIO_mode;
	u8 ActiveState;
	u8 LED_Name;

}ledMap_t;


#endif /* HLED_CONFIG_H_ */
