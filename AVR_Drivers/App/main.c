/*
 * main.c
 *
 *  Created on: Apr 20, 2020
 *      Author: FatmaGomaa
 */
#include <util/delay.h>
#include "STD_Types.h"
#include "WatchDog.h"

void LED(void);
void main(void){
	u8 NokiaData[504] = {0xff,0xff,0x81,0x81,0x81,0x81,0xff,0xff};

	/*SPI GPIO PINS*/
	DIO_SetPinDir('B',5,1); //SPI MOSI
	DIO_SetPinDir('B',7,1); //SPI CLK

	DIO_SetPinDir('A',1,1); //Nokia DC
	DIO_SetPinDir('A',2,1); //Nokia RST
	DIO_SetPinDir('A',3,1); //Nokia CE

	/*Master SS is input with pull up */


	SPI_Init();
	Nokia_Init();

	while(1){
		Nokia_Display(NokiaData,504);
	}
}

void LED(void){
	static u8 flag=0;
	if(flag == 0){
		DIO_SetPinValue('A',0,0);
		flag=1;
	}else if(flag == 1){
		DIO_SetPinValue('A',0,1);
		flag=0;
	}
}
