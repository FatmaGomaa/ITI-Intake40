/*
 * HLED.h
 *
 *  Created on: Mar 8, 2020
 *      Author: mayab
 */

#ifndef HLED_INTERFACE_H_
#define HLED_INTERFACE_H_


/* All the LEDs in the project
 * ps : the name of the LED is it's index (ledNum) */
#define LED_ALARM    0
#define LED_DOOR     1
#define LED_X        2


/* Indicates the the LED state (ledState) */
#define LED_ON     0
#define LED_OFF    1



#define LED_ACTIVE_LOW   0
#define LED_ACTIVE_HIGH  1



/* Initializes all the led's pins and ports */
void HLED_init(void);


/* Sets a LED to On or OFF
   First Argument  : LED_ALARM
                     LED_DOOR
                     LED_X
   Second Argument : LED_ON
                     LED_OFF
*/
void HLED_setLedState (u8 ledNum, u8 ledState);


#endif /* HLED_INTERFACE_H_ */
