/*******************************************************************************************************
 * File name: Sched_Config.c                                                                           *
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

extern Task_t AppTask1 , AppTask2;

BaseTaskInfo_t SysTasksInfo[OS_TASKS_NUM]= {

		{
				.Task = &AppTask1,
				.FirstDelay=2
		},

		{
				.Task= &AppTask2,
				.FirstDelay=4
		}

};
