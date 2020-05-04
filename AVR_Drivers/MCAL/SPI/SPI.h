/*
 * SPI.h
 *
 *  Created on: Apr 20, 2020
 *      Author: FatmaGomaa
 */

#ifndef SPI_H_
#define SPI_H_

/* 1. SPI_MASTER
   2. SPI_SLAVE */
#define SPI_NODE_MODE						SPI_MASTER

/*
 * 1.SPI_INT_ENABLE
   2.SPI_INT_DISABLE
 */
#define SPI_INT_STATE						SPI_INT_DISABLE
/* 1.SPI_MSB
   2.SPI_LSB*/
#define SPI_DATA_ORDER						SPI_MSB

/* 1.SPI_RISING_EDGE
   2.SPI_FALLING_EDGE*/
#define SPI_CLK_POLARITY					SPI_RISING_EDGE

/* 1.SPI_SETUP
   2.SPI_SAMPLE*/
#define SPI_CLK_PHASE						SPI_SETUP

/*1.SPI_CLK_OVER_4
  2.SPI_CLK_OVER_16
  3.SPI_CLK_OVER_64
  4.SPI_CLK_OVER_128
  5.SPI_HCLK_OVER_2
  6.SPI_HCLK_OVER_8
  7.SPI_HCLK_OVER_32
  8.SPI_HCLK_OVER_64*/
#define SPI_CLK_SPEED						SPI_CLK_OVER_4

#define SPI_TIME_OUT						50000UL


ERROR_STATUS SPI_Init(void);
ERROR_STATUS SPI_SendSync(u8 Data);
ERROR_STATUS SPI_ReceiveSync(u8* Data);
ERROR_STATUS SPI_SendReceiveSync(u8 SentData, u8* ReceivedData);
ERROR_STATUS SPI_SendReceiveAsync(u8* SentData, u8* ReceivedData, u8 BufferSize, void(*AppNotifier)(void));

#endif /* SPI_H_ */
