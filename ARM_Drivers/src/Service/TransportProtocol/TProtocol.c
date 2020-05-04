/*
 * TProtocol.c
 *
 *  Created on: Apr 9, 2020
 *      Author: FatmaGomaa
 */


#include "STD_TYPES.h"
#include "TProtocolMessages_Config.h"
#include "TProtocol.h"

#define FRAME_HEADER_START				0xFF
#define END_OF_FRAME					0xAA

u8* TProtocol_SendFrame( u8* RawTrasnmitterBuffer , u8 MessageID, u8 DataLength){
	ProtocolFrame_t* Frame = (ProtocolFrame_t*)RawTrasnmitterBuffer;
	Frame->Header.Start = 0x55;
	Frame->Header.ID = MessageID;
	Frame->Header.Length = DataLength;

	Frame->Data[DataLength] = END_OF_FRAME;


}
void TProtocol_ReceiveFrame( u8* RawReceiveBuffer , u8 MessageID, u8 DataLength){


}
