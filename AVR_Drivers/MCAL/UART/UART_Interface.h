/***********************************************************************************************/
/* AUTHOR: Fatima Gomaa                                                                        */
/* DATE	 : March 9 2020                                                                        */
/* VERSION: V01                                                                                */
/***********************************************************************************************/

#ifndef _UART_INTERFACE_H
#define _UART_INTERFACE_H

void UART_voidInitialize(void);

void UART_voidTransmitDataSynch(u8 Copy_u8Data);
void UART_voidTransmitDataASynch(u8 Copy_u8Data, void(*Copy_ptr)(void));

u8	 UART_voidReceiveDataSynch(u8* Copy_u8Data);
void UART_voidReceiveDataASynch(void(*Copy_ptr)(u8));

#endif
