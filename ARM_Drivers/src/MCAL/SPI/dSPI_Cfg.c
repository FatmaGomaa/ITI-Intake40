/*
 * dSPI_Cfg.c
 *
 *  Created on: Apr 22, 2020
 *      Author: FatmaGomaa
 */

#include "dSPI.h"

SPI_Cfg_t SPI_CFG = {
		.SPI_ID = SPI_ONE,
		.WiringMode = SPI_WIRING_MODE_UNIDIR,
		.CRC_Control = SPI_CRC_DISABLE,
		.DataFrameFormat = SPI_DATA_FORMATE_8,
		.SlaveMode = SPI_SLAVE_MODE_SW_HIGH,
		.DataSequence = SPI_DATA_SEQUENCE_MSB,
		.BaudRate = SPI_BAUDRATE_CLK_8,
		.CLK_Polarity = SPI_CLK_POLARITY_LOW,
		.CLK_Phase = SPI_CLK_PHASE_SECOND_EDGE,
		.MCU_Mode = SPI_MCU_MODE_MASTER
};

