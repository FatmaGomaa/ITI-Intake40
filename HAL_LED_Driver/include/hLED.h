/*
 * hLED.h
 *
 *  Created on: Mar 3, 2020
 *      Author: FatmaGomaa
 */

#ifndef HLED_H_
#define HLED_H_

#define NUM_OF_LEDS							3

#define LED_1                               0
#define LED_2                               1
#define LED_3                               2

/*it is used in an XOR expression so that it's defined this way*/
#define GPIO_ACTIVE_LOW						1
#define GPIO_ACTIVE_HIGH					0

typedef struct{
	u8  LED_ID;
	u32 GPIO_PIN;
	void* GPIO_PORT;
	u32 GPIO_MOOD;
	u32 GPIO_STATE;
	u8  INITIAL_VALUE;
}LED_MAP_t;

STD_ERROR HLed_writeLedState(u8 Copy_u8Led, u8 Copy_u8LedState);
STD_ERROR HLed_Init(void);


#endif /* HLED_H_ */
