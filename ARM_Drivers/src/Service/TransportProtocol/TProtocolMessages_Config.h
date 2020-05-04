/*
 * TProtocolMessages_Config.h
 *
 *  Created on: Apr 9, 2020
 *      Author: FatmaGomaa
 */

#ifndef SERVICE_TRANSPORTPROTOCOL_TPROTOCOLMESSAGES_CONFIG_H_
#define SERVICE_TRANSPORTPROTOCOL_TPROTOCOLMESSAGES_CONFIG_H_

typedef enum{
	ID_SwitchStatus

}Message_ID;

typedef struct{
	u8 Switch_Config;
	u8 Switch_Date;
	u8 Switch_UpArrow;
	u8 Switch_DownArrow;
	u8 Switch_RightArrow;
	u8 Switch_LeftArrow;
	u8 Switch_OK;
	u8 End_Of_Frame;
}SwitchStatusData_t;

#endif /* SERVICE_TRANSPORTPROTOCOL_TPROTOCOLMESSAGES_CONFIG_H_ */
