/*
 * EEPROM.c
 *
 *  Created on: May 7, 2020
 *      Author: FatmaGomaa
 */

#include "STD_TYPES.h"
#include "dI2C.h"
#include "EEPROM.h"

#define EEPROM_FIXED_ADDRESS			0b01010000

ERROR_STATUS EEPROM_WriteDataByte(u16 ByteAddress, u8 DataByte){
	ERROR_STATUS Local_ErrorStatus = NOT_OK;

	if(ByteAddress <= 1023 ){
		Local_ErrorStatus = OK;
	}
	/*send start condition on I2C Bus*/
	I2C_SendStart();
	/*Send Slave Address that consists of 3 Parts
	 * EEPROM Unique Address 0b1010 0000
	 * Value of Hardware Address in case of 8k EEPROM -> A2 Only
	 * Value of A1 and A2 which are the Ninth and eighth bit in the ByteAddress*/
	I2C_SendSlaveAddress( ( EEPROM_FIXED_ADDRESS | (EEPROM_A2_Value << 2  ) | ( ( (ByteAddress >> 8) & 3 ) ) ) , I2C_WRITE_OPERATION );

	/*send the rest of Byte Address */
	I2C_MasterSendDataByte((u8)ByteAddress);

	/*send Data Byte*/
	I2C_MasterSendDataByte(DataByte);

	/*send stop condition*/
	I2C_SendStop();

	return Local_ErrorStatus;

}
ERROR_STATUS EEPROM_ReadDataByte(u16 ByteAddress, u8* DataByte){
	ERROR_STATUS Local_ErrorStatus = NOT_OK;

	if( (ByteAddress <= 1023) && DataByte ){
		Local_ErrorStatus = OK;
	}

	/*send start condition on I2C Bus*/
	I2C_SendStart();
	/*Send Slave Address that consists of 3 Parts
	 * EEPROM Unique Address 0b1010 0000
	 * Value of Hardware Address in case of 8k EEPROM -> A2 Only
	 * Value of A1 and A2 which are the Ninth and eighth bit in the ByteAddress*/
	I2C_SendSlaveAddress( ( EEPROM_FIXED_ADDRESS | (EEPROM_A2_Value << 2  ) | ( ( (ByteAddress >> 8) & 3 ) ) ) , I2C_WRITE_OPERATION );
	/*send the rest of Byte Address */
	I2C_MasterSendDataByte((u8)ByteAddress);
	/*send repeated start condition*/
	I2C_SendRepeatedStart();
	/*Send Slave Address that consists of 3 Parts
	 * EEPROM Unique Address 0b1010 0000
	 * Value of Hardware Address in case of 8k EEPROM -> A2 Only
	 * Value of A1 and A2 which are the Ninth and eighth bit in the ByteAddress*/
	I2C_SendSlaveAddress( ( EEPROM_FIXED_ADDRESS | (EEPROM_A2_Value << 2  ) | ( ( (ByteAddress >> 8) & 3 ) ) ) , I2C_READ_OPERATION );
	/*Receive Data Byte*/
	I2C_MasterReceiveDataByte(DataByte);
	/*send stop condition*/
	I2C_SendStop();
	return Local_ErrorStatus;

}

