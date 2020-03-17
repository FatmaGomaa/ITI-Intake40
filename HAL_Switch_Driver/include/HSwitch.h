/*
 * HSwitch.h
 *
 *  Created on: Mar 16, 2020
 *      Author: FatmaGomaa
 */

#ifndef HSWITCH_H_
#define HSWITCH_H_

#define LED_SWITCH										0
#define BUZZER_SWITCH									1

#define	PULL_UP											1
#define PULL_DOWN										0

STD_ERROR HSwitch_Init(void);
STD_ERROR HSwitch_getSwitchStatus(u8 Copy_u8SwitchName, u8* Copy_u8SwitchStatus);
void 	  HSwitch_Debouncing(void);

#endif /* HSWITCH_H_ */
