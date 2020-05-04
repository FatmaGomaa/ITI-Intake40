/*
 * WatchDog.h
 *
 *  Created on: Apr 29, 2020
 *      Author: FatmaGomaa
 */

#ifndef WATCHDOG_H_
#define WATCHDOG_H_

#define WATCHDOG_PRESCALER_16			0x00
#define WATCHDOG_PRESCALER_32			0x01
#define WATCHDOG_PRESCALER_64			0x02
#define WATCHDOG_PRESCALER_128			0x03
#define WATCHDOG_PRESCALER_256			0x04
#define WATCHDOG_PRESCALER_512			0x05
#define WATCHDOG_PRESCALER_1024			0x06
#define WATCHDOG_PRESCALER_2048			0x07

void WDT_Sleep(u8 Prescaler);
void WDT_Stop(void);

#endif /* WATCHDOG_H_ */
