/*
 * HSwitch_Config.h
 *
 *  Created on: Mar 16, 2020
 *      Author: FatmaGomaa
 */

#ifndef HSWITCH_CONFIG_H_
#define HSWITCH_CONFIG_H_

#define NUM_OF_SWITCHES									2
#define HSwitch_OS_Periodicity							20000 //20 ms
#define HSwitch_OS_PeriodicTicks						5    //debouncing counter

typedef struct{
	void* PORT;
	u32 PIN;
	u32 GPIO_MODE; // pull up or pull down
}Switch_t;



#endif /* HSWITCH_CONFIG_H_ */
