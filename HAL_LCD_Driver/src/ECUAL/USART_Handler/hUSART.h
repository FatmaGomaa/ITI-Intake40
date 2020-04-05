/*
 * hUSART.h
 *
 *  Created on: Apr 5, 2020
 *      Author: FatmaGomaa
 */

#ifndef ECUAL_USART_HANDLER_HUSART_H_
#define ECUAL_USART_HANDLER_HUSART_H_


extern STD_ERROR UART_Init(UART_Frame_Cfg_t * cfg);
extern ProcessState_t UART_SendBuffer(u8 * buffer, u16 bytesCount);
extern ProcessState_t UART_ReceiveBuffer(u8 * buffer, u16 bytesCount);
extern void UART_setTransmitterCbf (AppTxNotify_t txCbf);
extern void UART_setRecveiverCbf(AppRxNotify_t rxCbf);


#endif /* ECUAL_USART_HANDLER_HUSART_H_ */
