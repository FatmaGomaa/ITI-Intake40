/***********************************************************************************************/
/* AUTHOR: Fatima Gomaa                                                                        */
/* DATE	 : March 9 2020                                                                        */
/* VERSION: V01                                                                                */
/***********************************************************************************************/
#ifndef _UART_PRIVATE_H
#define _UART_PRIVATE_H

#define UART_PARITY_DISABLES										0b00000000
#define UART_PARITY_EVEN                                            0b00100000
#define UART_PARITY_ODD                                             0b00110000

#define UART_BAUD_4800                                              0X64
#define UART_BAUD_9600                                              0X33
#define UART_BAUD_115200                                            0X03

#define UART_STOP_1_BIT												0b00000000
#define UART_STOP_2_BIT                                             0b00001000

#define UART_SYS_FREQUENCY_8M										0u
#define UART_SYS_FREQUENCY_12M                                      1u
#define UART_SYS_FREQUENCY_16M                                      2u

#define UART_BAUD_RATE_4800											0X64
#define UART_BAUD_RATE_9600											0X33
#define UART_BAUD_RATE_115200										0X03


#endif