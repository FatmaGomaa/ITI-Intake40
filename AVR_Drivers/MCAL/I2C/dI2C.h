/*
 * dI2C.h
 *
 *  Created on: May 7, 2020
 *      Author: FatmaGomaa
 */

#ifndef MCAL_I2C_DI2C_H_
#define MCAL_I2C_DI2C_H_

#define I2C_PRESCALER_1				0b00000000
#define I2C_PRESCALER_4				0b00000001
#define I2C_PRESCALER_16			0b00000010
#define I2C_PRESCALER_64			0b00000011

#define I2C_READ_OPERATION			0x01
#define I2C_WRITE_OPERATION			0x00

/*User Selected Configurations*/
#define I2C_PRESCALER_VALUE			I2C_PRESCALER_1

ERROR_STATUS I2C_MasterInit(void);
ERROR_STATUS I2C_SlaveInit(u8 SlaveAddress);
ERROR_STATUS I2C_SendStart(void);
ERROR_STATUS I2C_SendStop(void);
ERROR_STATUS I2C_SendRepeatedStart(void);
ERROR_STATUS I2C_SendSlaveAddress(u8 SlaveAddress, u8 Operation);
ERROR_STATUS I2C_MasterSendDataByte(u8 Data);
ERROR_STATUS I2C_MasterReceiveDataByte(u8* Data);



#endif /* MCAL_I2C_DI2C_H_ */
