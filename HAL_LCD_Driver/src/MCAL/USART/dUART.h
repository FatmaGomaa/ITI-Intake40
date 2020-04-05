/*
 * dUART.h
 *
 *  Created on: Mar 25, 2020
 *      Author: FatmaGomaa
 */

#ifndef DUART_H_
#define DUART_H_

typedef struct {
	u32 UART_SR;
	u32 UART_DR;
	u32 UART_BRR;
	u32 UART_CR1;
	u32 UART_CR2;
	u32 UART_CR3;
	u32 UART_GTPR;
}UartPeripheral_t;

typedef enum{
	Idle_State ,
	Busy_State
}BufferState_t;

typedef struct{
	u8 * ptr;
	u32 position;
	u32 size;
	BufferState_t state;
}DataBuffer_t;

typedef struct{
	u32 UART_ID;
	u32 UART_NumOfDataBits;
	u32 UART_Baudrate;
	u32 UART_StopBits;
	u32 UART_ParityBits;
}UART_Frame_Cfg_t;

typedef void (*AppTxNotify_t) (void);
typedef void (*AppRxNotify_t) (void);

extern ProcessState_t UART_Send(u8 * buffer, u16 bytesCount);
extern ProcessState_t UART_Reveive(u8 * buffer, u16 bytesCount);
extern void UART_Configure( UART_Frame_Cfg_t * cfg );
extern void UART_setTxCbf (AppTxNotify_t txCbf);
extern void UART_setRxCbf(AppRxNotify_t rxCbf);
extern void USART1_IRQHandler(void);

#endif /* DUART_H_ */
