/*******************************************************************************************************
 * File name: Sched.h                                                                                  *
 *                                                                                                     *
 *                                                                                                     *
 * Description: This file contains the Prototypes of the NVIC driver funcitons                         *
 * and the macros used by the user                                                                     *
 *                                                                                                     *
 * Author: Fatima Gomaa                                                                                *
 * Date:   March 11, 2020                                                                              *
 * Version 1.0 : Initial Creation of the STK Driver                                                    *
 * Version 1.1 : added Sched Start and Sched Exec as well as testing the OS functionalities			   *
 *******************************************************************************************************/
#ifndef SCHED_H_
#define SCHED_H_

typedef void(*TaskRunnable_t)(void);

typedef struct{
	TaskRunnable_t Runnable;
	u32 Periodicity;
}Task_t;

extern STD_ERROR Sched_Init(void);
extern STD_ERROR Sched_Start(void);
extern STD_ERROR Sched_Exec(void);
void Sched_SetOSFlag(void);

#endif /* SCHED_H_ */
