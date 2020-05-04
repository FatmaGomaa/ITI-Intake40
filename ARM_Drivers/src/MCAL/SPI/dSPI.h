/*
 * dSPI.h
 *
 *  Created on: Apr 19, 2020
 *      Author: FatmaGomaa
 */

#ifndef MCAL_SPI_DSPI_H_
#define MCAL_SPI_DSPI_H_

#include "STD_TYPES.h"
#include "dSPI_Private.h"

/*SPI_Cfg_t SPI_ID*/
#define SPI_ONE								SPI_ONE_BASE
#define SPI_TWO								SPI_TWO_BASE
#define SPI_THREE							SPI_THREE_BASE

/*SPI_Cfg_t SPI_Mode*/
#define SPI_WIRING_MODE_UNIDIR				0x00000000
#define SPI_WIRING_MODE_BIDIR_RECEIVER		0x00008400
#define SPI_WIRING_MODE_BIDIR_TRANSMIT		0x0000C000

/*SPI_Cfg_t CRC_Control*/
#define SPI_CRC_ENABLE						0x00004000
#define SPI_CRC_DISABLE						0x00000000

/*SPI_Cfg_t DataFrameFormat*/
#define SPI_DATA_FORMATE_8					0x00000000
#define SPI_DATA_FORMATE_16					0x00000800

/*SPI_Cfg_t SlaveMode*/
#define SPI_SLAVE_MODE_SW_HIGH              0x00000300
#define SPI_SLAVE_MODE_SW_LOW               0x00000200
#define SPI_SLAVE_MODE_HW                   0x00000000

/*SPI_Cfg_t SlaveMode*/
#define SPI_DATA_SEQUENCE_MSB				0x00000000
#define SPI_DATA_SEQUENCE_LSB				0x00000080

/*SPI_Cfg_t BaudRate*/
#define SPI_BAUDRATE_CLK_2					0x00000000
#define SPI_BAUDRATE_CLK_4					0x00000008
#define SPI_BAUDRATE_CLK_8					0x00000010
#define SPI_BAUDRATE_CLK_16					0x00000018
#define SPI_BAUDRATE_CLK_32					0x00000020
#define SPI_BAUDRATE_CLK_64					0x00000028
#define SPI_BAUDRATE_CLK_128				0x00000030
#define SPI_BAUDRATE_CLK_256				0x00000038

/*SPI_Cfg_t MCU_Mode*/
#define SPI_MCU_MODE_MASTER					0x00000004
#define SPI_MCU_MODE_SLAVE					0x00000000

/*SPI_Cfg_t CLK_Polarity*/
#define SPI_CLK_POLARITY_HIGH				0x00000002
#define SPI_CLK_POLARITY_LOW				0x00000000

/*SPI_Cfg_t CLK_Phase*/
#define SPI_CLK_PHASE_FIRST_EDGE			0x00000000
#define SPI_CLK_PHASE_SECOND_EDGE			0x00000001

typedef void(*CallBackFunction)(void);

typedef struct {
	u32 SPI_ID;
	u32 WiringMode;
	u32 CRC_Control;
	u32 DataFrameFormat;
	u32 SlaveMode;
	u32 DataSequence;
	u32 BaudRate;
	u32 MCU_Mode;
	u32 CLK_Polarity;
	u32 CLK_Phase;
}SPI_Cfg_t;


STD_ERROR SPI_Init(void);
ProcessState_t SPI_Send(u8* Data, u8 DataLength);
ProcessState_t SPI_Receive(u8* Data, u8 DataLength);
ProcessState_t SPI_SendReceive(u8* SentData, u8* ReceivedData, u8 DataLength);

void SPI_SetTXCBF(CallBackFunction TxCbf);
void SPI_SetRXCBF(CallBackFunction	RxCbf);

#endif /* MCAL_SPI_DSPI_H_ */
