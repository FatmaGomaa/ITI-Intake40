/*
 * WatchDog.c
 *
 *  Created on: Apr 29, 2020
 *      Author: FatmaGomaa
 */

#include "STD_TYPES.h"
#include "WatchDog.h"

#define WDTCR							*((volatile u8 *)(0x41))

#define WDTCR_WDTOE						0x10
#define WDTCR_WDE						0x08
#define WDTCR_WDP_M						0x07
#define WDTCR_WDP_CLR_M					0xF8

void WDT_Sleep(u8 Prescaler){
	u8 RegTemp=0;
	/*stop watch dog then enable it*/
	/*set WDE and WDTOE at the same time*/
	WDTCR |= WDTCR_WDTOE | WDTCR_WDE;
	/*clear WDE*/
	WDTCR &=~ WDTCR_WDE;

	/*set prescaler and enable */
	RegTemp = WDTCR;
	RegTemp &= WDTCR_WDP_CLR_M;
	RegTemp |= Prescaler;
	WDTCR = RegTemp;

}

void WDT_Stop(void){
	/*set WDE and WDTOE at the same time*/
	WDTCR |= WDTCR_WDTOE | WDTCR_WDE;
	/*clear WDE*/
	WDTCR &=~ WDTCR_WDE;
}
