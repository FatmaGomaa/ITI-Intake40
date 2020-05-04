/*******************************************************************************************************
 * File name: dSTK.h                                                                                   *
 *                                                                                                     *
 *                                                                                                     *
 * Description: This file contains the Prototypes of the NVIC driver funcitons                         *
 * and the macros used by the user                                                                     *
 *                                                                                                     *
 * Author: Fatima Gomaa                                                                                *
 * Date:   March 10, 2020                                                                              *
 * Version 1.0 : Initial Creation of the STK Driver                                                    *
 *******************************************************************************************************/

#ifndef DSTK_H_
#define DSTK_H_

#define STK_PRESCALER_AHB_DIVIDED_BY_8						8u
#define STK_PRESCALER_AHB									1u

/*TODO: when making STK handler make sure that the Clock Source is sent as a Mega Value not HZ value*/
#define RCC_CLOCK_SOURCE									HSI
#define HSI													8u

typedef void(*STK_CBF_t)(void);

#define STK_PERIPHERAL				(volatile void *)0xE000E010

STD_ERROR STK_Init(void);
STD_ERROR STK_Start(void);
STD_ERROR STK_Stop(void);
STD_ERROR STK_SetPrescaler(u32 Copy_u32Prescaler);
STD_ERROR STK_SetTime(u32 Copy_u32TimeUS, u32 Copy_u32RCC_ClockValue);
STD_ERROR STK_SetCallBack(STK_CBF_t cbf);


#endif /* DSTK_H_ */
