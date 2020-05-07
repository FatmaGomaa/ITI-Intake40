/*
 * dI2C.c
 *
 *  Created on: May 7, 2020
 *      Author: FatmaGomaa
 */

#include "STD_TYPES.h"
#include "dI2C.h"

#define I2C_TWBR				*((volatile u8 * const)0x20)
#define I2C_TWSR				*((volatile u8 * const)0x21)
#define I2C_TWAR				*((volatile u8 * const)0x22)
#define I2C_TWDR				*((volatile u8 * const)0x23)
#define I2C_TWCR				*((volatile u8 * const)0x56)

#define I2C_TWCR_TWINT			0b10000000
#define I2C_TWCR_TWEA			0b01000000
#define I2C_TWCR_TWSTA			0b00100000
#define I2C_TWCR_TWSTO			0b00010000
#define I2C_TWCR_TWWC			0b00001000
#define I2C_TWCR_TWEN			0b00000100
#define I2C_TWCR_TWIE			0b00000001

#define I2C_TWSR_TWS_M			0b11111000
#define I2C_TWSR_TWS_CLR_M		0b00000111

#define I2C_TWSR_TWPS_M			0b00000011
#define I2C_TWSR_TWPS_CLR_M		0b11111100

#define I2C_TWDR_TWD_M			0b11111110
#define I2C_TWDR_TWD_CLR_M		0b00000001
/*Select read or write operation*/
#define I2C_TWDR_OPERATION		0b00000001

#define I2C_TWAR_TWA_M			0b11111110
#define I2C_TWAR_TWA_CLR_M		0b00000001
/*Select General Call operation*/
#define I2C_TWDR_GC				0b00000001

#define I2C_TWBR_400K			2

/*Status Codes for Master Transmitter Mode*/
#define I2C_SC_START			0x08
#define I2C_SC_RSTART			0x10
#define I2C_SC_SLA_W_ACK		0x18
#define I2C_SC_SLA_W_NACK		0x20
#define I2C_SC_SLA_R_ACK		0x40
#define I2C_SC_SLA_R_NACK		0x48
#define I2C_SC_TDATA_ACK		0x28
#define I2C_SC_TDATA_NACK		0x30
#define I2C_SC_RDATA_ACK		0x50
#define I2C_SC_RDATA_NACK		0x58
#define I2C_SC_ARB_LOST			0x38

ERROR_STATUS I2C_MasterInit(void){
	ERROR_STATUS Local_ErrorStatus = OK;

	/*Set Frequency 400 K and No Prescaler*/
	I2C_TWBR = I2C_TWBR_400K;
	I2C_TWSR &= I2C_TWSR_TWPS_CLR_M;

	/*Enable I2C*/
	/*Enable Acknowledgment*/
	I2C_TWCR = I2C_TWCR_TWEN | I2C_TWCR_TWEA;

	return Local_ErrorStatus;

}

ERROR_STATUS I2C_SlaveInit(u8 SlaveAddress){
	ERROR_STATUS Local_ErrorStatus = NOT_OK;
	if(SlaveAddress){
		Local_ErrorStatus = OK;
	}
	/*Set Slave Address */
	u8 RegTemp = I2C_TWAR;
	RegTemp &= I2C_TWAR_TWA_CLR_M;
	RegTemp |= (SlaveAddress << 1);
	I2C_TWAR = RegTemp;

	/*Enable I2C*/
	/*Enable Acknowledgment*/
	I2C_TWCR |= I2C_TWCR_TWEN | I2C_TWCR_TWEA;
	return Local_ErrorStatus;

}

ERROR_STATUS I2C_SendStart(void){
	ERROR_STATUS Local_ErrorStatus = NOT_OK;
	/*Clear Previous Interrupt Flag
	 *Send Start Condition */
	I2C_TWCR |= I2C_TWCR_TWINT | I2C_TWCR_TWSTA ;

	/*Wait for Interrupt Flag to be raised */
	while(!(I2C_TWCR & I2C_TWCR_TWINT));

	/*Check Status Register */
	if ( (I2C_TWSR & I2C_TWSR_TWS_M) == I2C_SC_START){
		Local_ErrorStatus = OK;
	}
	return Local_ErrorStatus;
}

ERROR_STATUS I2C_SendStop(void){
	ERROR_STATUS Local_ErrorStatus = OK;

	/*Clear Previous Interrupt Flag
	 *Send Stop Condition */
	I2C_TWCR |= I2C_TWCR_TWINT | I2C_TWCR_TWSTO ;

	return Local_ErrorStatus;

}

ERROR_STATUS I2C_SendRepeatedStart(void){
	ERROR_STATUS Local_ErrorStatus = NOT_OK;
	/*Clear Previous Interrupt Flag
	 *Send Start Condition */
	I2C_TWCR |= I2C_TWCR_TWINT | I2C_TWCR_TWSTA ;

	/*Wait for Interrupt Flag to be raised */
	while(!(I2C_TWCR & I2C_TWCR_TWINT));

	/*Check Status Register */
	if ( (I2C_TWSR & I2C_TWSR_TWS_M) == I2C_SC_RSTART){
		Local_ErrorStatus = OK;
	}
	return Local_ErrorStatus;

}

ERROR_STATUS I2C_SendSlaveAddress(u8 SlaveAddress, u8 Operation){
	ERROR_STATUS Local_ErrorStatus = NOT_OK;
	if(SlaveAddress){
		Local_ErrorStatus = OK;
	}
	/*Set Slave Address and Operation*/
	I2C_TWDR = ( (SlaveAddress << 1) | Operation );
	/*Clear Interrupt and Start Condition*/
	I2C_TWCR &=~ I2C_TWCR_TWSTA;
	I2C_TWCR |= I2C_TWCR_TWINT;

	/*Wait for Interrupt Flag to be raised */
	while(!(I2C_TWCR & I2C_TWCR_TWINT));

	/*Check Status Register */
	if(Operation == I2C_READ_OPERATION){
		if ( (I2C_TWSR & I2C_TWSR_TWS_M) == I2C_SC_SLA_R_NACK){
			Local_ErrorStatus = OK;
		}
	}else if(Operation == I2C_WRITE_OPERATION){
		if ( (I2C_TWSR & I2C_TWSR_TWS_M) == I2C_SC_SLA_W_ACK){
			Local_ErrorStatus = OK;
		}
	}

	return Local_ErrorStatus;
}

ERROR_STATUS I2C_MasterSendDataByte(u8 Data){
	ERROR_STATUS Local_ErrorStatus = NOT_OK;
	/*write data to TWI Data Register */
	I2C_TWDR = Data;
	/*Clear Interrupt and Start Condition*/
	I2C_TWCR |= I2C_TWCR_TWINT;
	/*Wait for Interrupt Flag to be raised */
	while(!(I2C_TWCR & I2C_TWCR_TWINT));

	/*Check Status Register */
	if ( (I2C_TWSR & I2C_TWSR_TWS_M) == I2C_SC_TDATA_ACK){
		Local_ErrorStatus = OK;
	}
	return Local_ErrorStatus;

}
ERROR_STATUS I2C_MasterReceiveDataByte(u8* Data){
	ERROR_STATUS Local_ErrorStatus = NOT_OK;
	/*Clear Interrupt and Start Condition*/
	I2C_TWCR |= I2C_TWCR_TWINT;
	/*Wait for Interrupt Flag to be raised */
	while(!(I2C_TWCR & I2C_TWCR_TWINT));
	/*Check Status Register */
	if ( (I2C_TWSR & I2C_TWSR_TWS_M) == I2C_SC_RDATA_ACK){
		/*Read data from TWI Data Register */
		*Data = I2C_TWDR;
		Local_ErrorStatus = OK;
	}
	return Local_ErrorStatus;
}
