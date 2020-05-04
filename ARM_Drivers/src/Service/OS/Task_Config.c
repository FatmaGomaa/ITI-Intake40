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
#include "Task_Config.h"
#include "dSTK.h"

extern Task_t AppTask, SwitchTask;

BaseTaskInfo_t SysTasksInfo[OS_TASKS_NUM]= {

		{
				.Task = &AppTask,
				.FirstDelay=0
		},

		{
				.Task = &SwitchTask,
				.FirstDelay=0
		}
};
