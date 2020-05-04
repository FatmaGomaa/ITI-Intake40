/*
 * TProtocol.h
 *
 *  Created on: Apr 9, 2020
 *      Author: FatmaGomaa
 */

#ifndef SERVICE_TRANSPORTPROTOCOL_TPROTOCOL_H_
#define SERVICE_TRANSPORTPROTOCOL_TPROTOCOL_H_

/*this Macro includes both Data and End of Frame Byte*/
#define FRAME_DATA_BYTES						9

typedef struct{
	u8 Start;
	u8 ID;
	u16 Length;
}TProtocolHeader_t;

typedef struct{
	TProtocolHeader_t Header;
	u8 Data[FRAME_DATA_BYTES];
}ProtocolFrame_t;

u8* TProtocol_SendFrame( u8* RawTrasnmitterBuffer , u8 MessageID, u8 DataLength);
void TProtocol_ReceiveFrame( u8* RawReceiveBuffer , u8 MessageID, u8 DataLength);


#endif /* SERVICE_TRANSPORTPROTOCOL_TPROTOCOL_H_ */
