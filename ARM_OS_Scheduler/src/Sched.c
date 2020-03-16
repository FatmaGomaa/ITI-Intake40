/*******************************************************************************************************
 * File name: Sched.c                                                                                  *
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

#include "STD_TYPES.h"
#include "Sched.h"
#include "Sched_Config.h"
#include "dSTK.h"

u8 OSFlag = 0;
extern BaseTaskInfo_t SysTasksInfo[OS_TASKS_NUM];


/*TODO: State to be added [STATE_RREADY, STATE_SUSPENDED]*/
typedef struct{
	BaseTaskInfo_t * Task;
	u32 PeriodicTicks;
	u32 TimeToExec;
}SysTask_t;

SysTask_t SysTasks[OS_TASKS_NUM];

STD_ERROR Sched_Init(void){
	STD_ERROR Local_ErrorStatus = NOT_OK;
	u8 Local_u8Iterator = 0;

	/*1. STK_init*/
	STK_Init();
	/*2. STK_setTime*/
	STK_SetTime(OS_TICK_TIME_US, RCC_CLOCK_SOURCE);
	/*3. setCall Back*/
	if(	 STK_SetCallBack(Sched_SetOSFlag) == OK){
	 Local_ErrorStatus=OK;
	}
	/*4. SysTask Structure filling*/
	 for(Local_u8Iterator=0; Local_u8Iterator < OS_TASKS_NUM ;Local_u8Iterator++){
		 SysTasks[Local_u8Iterator].Task = &SysTasksInfo[Local_u8Iterator];
		 SysTasks[Local_u8Iterator].TimeToExec = SysTasksInfo[Local_u8Iterator].FirstDelay;
		 SysTasks[Local_u8Iterator].PeriodicTicks = SysTasks[Local_u8Iterator].Task->Task->Periodicity / OS_TICK_TIME_US;
	 }
	/*5. STK_start*/
	 STK_Start();
	 return Local_ErrorStatus;
}

STD_ERROR Sched_Exec(void){
	STD_ERROR Local_ErrorStatus = NOT_OK;
	u8 Local_u8Iterator = 0;

	 for(Local_u8Iterator=0; Local_u8Iterator < OS_TASKS_NUM ;Local_u8Iterator++){
		 if(SysTasks[Local_u8Iterator].TimeToExec == 0){
			 SysTasks[Local_u8Iterator].Task->Task->Runnable();
			 SysTasks[Local_u8Iterator].TimeToExec =  SysTasks[Local_u8Iterator].PeriodicTicks;
		 }else{
			 SysTasks[Local_u8Iterator].TimeToExec --;
		 }
	 }
	 if(OSFlag != 0){
	 OSFlag--;
	 }
	 return Local_ErrorStatus;
}

STD_ERROR Sched_Start(void){
	while(1){
		if(OSFlag){
			OSFlag=0;
			Sched_Exec();
		}
	}

}


void Sched_SetOSFlag(void){
	OSFlag++;
}
