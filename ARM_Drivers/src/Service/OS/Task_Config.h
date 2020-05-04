/*******************************************************************************************************
 * File name: Sched_Config.h                                                                           *
 *                                                                                                     *
 *                                                                                                     *
 * Author: Fatima Gomaa                                                                                *
 * Date:   March 11, 2020                                                                              *
 * Version 1.0 : Initial Creation of the STK Driver                                                    *
 * Version 1.1 : added Sched Start and Sched Exec as well as testing the OS functionalities			   *
 *******************************************************************************************************/

#ifndef SERVICE_OS_TASK_CONFIG_H_
#define SERVICE_OS_TASK_CONFIG_H_


#define OS_TASKS_NUM										2
/*Multiplier of the Timer Clock*/
#define OS_TICK_TIME_US										2000

typedef struct{
	Task_t * Task;
	u32 FirstDelay;

}BaseTaskInfo_t;





#endif /* SERVICE_OS_TASK_CONFIG_H_ */
