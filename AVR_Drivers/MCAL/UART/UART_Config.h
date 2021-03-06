/***********************************************************************************************/
/* AUTHOR: Fatima Gomaa                                                                        */
/* DATE	 : March 9 2020                                                                        */
/* VERSION: V01                                                                                */
/***********************************************************************************************/
#ifndef _UART_CONFIG_H
#define _UART_CONFIG_H

/*OPTIONS: UART_PARITY_DISABLES
		   UART_PARITY_EVEN
		   UART_PARITY_ODD 
*/
#define UART_U8_PARITY										UART_PARITY_DISABLES


/*OPTIONS: UART_BAUD_4800
		   UART_BAUD_9600
		   UART_BAUD_115200
*/
#define UART_U8_BAUD_RATE									UART_BAUD_9600

/*OPTIONS: UART_STOP_1_BIT
		   UART_STOP_2_BIT
*/
#define UART_U8_STOP_BIT									UART_STOP_1_BIT

/*OPTIONS: UART_SYS_FREQUENCY_8M
		   UART_SYS_FREQUENCY_12M
		   UART_SYS_FREQUENCY_16M
*/
#define UART_U*_SYS_FREQUENCY								UART_SYS_FREQUENCY_8M

#define UART_U32_TIME_OUT_TH								40000UL

#endif
