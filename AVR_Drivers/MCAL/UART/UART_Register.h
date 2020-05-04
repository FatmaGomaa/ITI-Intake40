/***********************************************************************************************/
/* AUTHOR: Fatima Gomaa                                                                        */
/* DATE	 : March 9 2020                                                                        */
/* VERSION: V01                                                                                */
/***********************************************************************************************/
#ifndef _UART_REGISTER_H
#define _UART_REGISTER_H

#define UART_UDR_RXB								 *((volatile u8*)0x2C)
#define UART_UDR_TXB                                 *((volatile u8*)0x2C)
#define UART_UCSRA                                   *((volatile u8*)0x2B)
#define UART_UCSRB                                   *((volatile u8*)0x2A)
#define UART_UCSRC                                   *((volatile u8*)0x40)
#define UART_UBRRL                                   *((volatile u8*)0x29)
#define UART_UBRRH                                   *((volatile u8*)0x40)

#endif
