/*
 * Nokia.h
 *
 *  Created on: Apr 24, 2020
 *      Author: FatmaGomaa
 */

#ifndef ECUAL_NOKIA5110_NOKIA_H_
#define ECUAL_NOKIA5110_NOKIA_H_

#define SPI_CH_1						0

typedef struct {
	u32 SPI_Channel;
	GPIO_t RST;
	GPIO_t CE;
	GPIO_t DC;
}Nokia_Cfg_t;

void Nokia_Init(void);
void Nokia_Display(u8* Data, u16 size);


#endif /* ECUAL_NOKIA5110_NOKIA_H_ */
