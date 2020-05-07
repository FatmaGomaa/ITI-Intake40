/*
 * EEPROM.h
 *
 *  Created on: May 7, 2020
 *      Author: FatmaGomaa
 */

#ifndef HAL_EEPROM_EEPROM_H_
#define HAL_EEPROM_EEPROM_H_

#define EEPROM_A2_Value			0

ERROR_STATUS EEPROM_WriteDataByte(u16 ByteAddress, u8 DataByte);
ERROR_STATUS EEPROM_ReadDataByte(u16 ByteAddress, u8* DataByte);


#endif /* HAL_EEPROM_EEPROM_H_ */
