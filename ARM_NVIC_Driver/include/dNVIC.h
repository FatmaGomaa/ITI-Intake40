/*******************************************************************************************************
 * File name: dNVIC.h                                                                                  *
 *                                                                                                     *
 *                                                                                                     *
 * Description: This file contains the Prototypes of the NVIC driver funcitons                         *
 * and the macros used by the user                                                                     *
 *                                                                                                     *
 * Author: Fatima Gomaa                                                                                *
 * Date:   Feb 26, 2020                                                                                *
 * Version 1.0 : Initial Creation of the NVIC Driver                                                   *
 *                                                                                                     *
 * Version 1.1 : part of Documentation of the NVIC Driver                                              *
 * Version 1.2 : finished Documentation of the NVIC Driver                                             *
 *******************************************************************************************************/

#ifndef DNVIC_H_
#define DNVIC_H_

/*priority_group used in NVIC_setPriorityGroup function*/
#define PRIORITY_GROUP_0_sub0            		0x00000000
#define PRIORITY_GROUP_1_sub0to1         		0x00001000
#define PRIORITY_GROUP_2_sub0to2         	    0x00002000
#define PRIORITY_GROUP_3_sub0to3        	    0x00003000
#define PRIORITY_GROUP_4_sub0to4        	    0x00004000
#define PRIORITY_GROUP_5_sub0to5        	    0x00005000
#define PRIORITY_GROUP_6_sub0to6        	    0x00006000
#define PRIORITY_GROUP_7_sub0to7        	    0x00007000

/*state used in NVIC_controlIRQ function*/
#define IRQ_ON									1
#define IRQ_OFF									0

/*state used in NVIC_controlPendingIRQ function*/
#define PENDING_ON									1
#define PENDING_OFF									0

/*PRIMASK_STATUS used in NVIC_ControlPRIMMASK function*/
#define PRIMASK_ENABLE_ALL	 0
#define PRIMASK_DISABLE_ALL	 1

/*FAULTMASK_STATUS used in NVIC_ControlFAULTMASK function*/
#define FAULTMASK_ENABLE_ALL	 0
#define FAULTMASK_DISABLE_ALL	 1


/**********************************************************************************************************************
 * Function name: NVIC_setPriorityGroup                                                                               *
 *                                                                                                                    *
 * parameters:  Input:                                                                                                *
 *                 priority_group                                                                                     *
 *                     type: u8                                                                                       *
 *                     Description: The Priority group chosen for the NVIC, it takes one of the following Values:     *
 *                                    PRIORITY_GROUP_0_sub0,                                                          *
 *                                    PRIORITY_GROUP_1_sub0to1,                                                       *
 *                                    PRIORITY_GROUP_2_sub0to2,                                                       *
 *                                    PRIORITY_GROUP_3_sub0to3,                                                       *
 *                                    PRIORITY_GROUP_4_sub0to4,                                                       *
 *                                    PRIORITY_GROUP_5_sub0to5,                                                       *
 *                                    PRIORITY_GROUP_6_sub0to6,                                                        *
 *                                    PRIORITY_GROUP_7_sub0to7                                                         *
 *              Output: NA                                                                                            *
 *              In/out: NA                                                                                            *
 * return: STD_ERROR                                                                                                  *
 * Description: the function sets the Priority group chosen for the NVIC that would apply to all interrupts.          *
 *********************************************************************************************************************/
STD_ERROR NVIC_setPriorityGroup(u8 priority_group);

/***********************************************************************************************************************************
 * Function name: NVIC_setPriority                                                                                                 *
 *                                                                                                                                 *
 * parameters:  Input:                                                                                                             *
 *                 IRQn                                                                                                            *
 *                     type: u8                                                                                                    *
 *                     Description: Interrupt Number in the Interrupt Vector Table.                                                *
 *                 priority                                                                                                        *
 *                     type: u8                                                                                                    *
 *                     Description: the assigned priority to this Interrupt, the user sets both Subpriority and preempt priority   *
 *                                                                                                                                 *
 *              Output: NA                                                                                                         *
 *              In/out: NA                                                                                                         *
 * return: STD_ERROR                                                                                                               *
 * Description: a function to give an assigned priority to specific Interrupt.                                                     *
 ***********************************************************************************************************************************/
STD_ERROR NVIC_setPriority(u8 IRQn, u8 priority);

/***********************************************************************************************************************************
 * Function name: NVIC_controlIRQ                                                                                                  *
 *                                                                                                                                 *
 * parameters:  Input:                                                                                                             *
 *                 IRQn                                                                                                            *
 *                     type: u8                                                                                                    *
 *                     Description: Interrupt Number in the Interrupt Vector Table.                                                *
 *                 state                                                                                                           *
 *                     type: u8                                                                                                    *
 *                     Description: the assigned state to this Interrupt, whether to enable or disable it, it takes one of the     *
 *                     				following values:                                                                              *
 *                     				 IRQ_ON                                                                                        *
 *                     				 IRQ_OFF                                                                                       *
 *              Output: NA                                                                                                         *
 *              In/out: NA                                                                                                         *
 * return: STD_ERROR                                                                                                               *
 * Description: a function to control specific Interrupt (set it ON or OFF).                                                       *
 ***********************************************************************************************************************************/
STD_ERROR NVIC_controlIRQ(u8 IRQn, u8 state);

/***********************************************************************************************************************************
 * Function name: NVIC_getPendingFlag                                                                                              *
 *                                                                                                                                 *
 * parameters:  Input:                                                                                                             *
 *                 IRQn                                                                                                            *
 *                     type: u8                                                                                                    *
 *                     Description: Interrupt Number in the Interrupt Vector Table.                                                *
 *                                                                                                                                 *
 *              Output:                                                                                                            *
 *              	PendingFlagValue                                                                                               *
 *                     type: u8*                                                                                                   *
 *                     Description: pointer to the variable that will hold the value of the pending flag.                          *
 *              In/out:NA                                                                                                          *
 *                                                                                                                                 *
 * return: STD_ERROR                                                                                                               *
 * Description: a function that get the pending flag value.                                                                        *
 ***********************************************************************************************************************************/
STD_ERROR NVIC_getPendingFlag (u8 IRQn, u8* PendingFlagValue);

/***********************************************************************************************************************************
 * Function name: NVIC_controlPendingIRQ                                                                                           *
 *                                                                                                                                 *
 * parameters:  Input:                                                                                                             *
 *                 IRQn                                                                                                            *
 *                     type: u8                                                                                                    *
 *                     Description: Interrupt Number in the Interrupt Vector Table.                                                *
 *                 state                                                                                                           *
 *                     type: u8                                                                                                    *
 *                     Description: decides whether the pending flag is written high or low, takes one of the following choices.   *
 *                     				PENDING_ON                                                                                     *
 *                     				PENDING_OFF                                                                                    *
 *                                                                                                                                 *
 *              Output:NA                                                                                                          *
 *              In/out:NA                                                                                                          *
 *                                                                                                                                 *
 * return: STD_ERROR                                                                                                               *
 * Description: a function that control the pending flag value whether it's high or low.                                           *
 ***********************************************************************************************************************************/
STD_ERROR NVIC_controlPendingIRQ (u8 IRQn, u8 state);

/***********************************************************************************************************************************
 * Function name: NVIC_ControlPRIMMASK                                                                                             *
 *                                                                                                                                 *
 * parameters:  Input:                                                                                                             *
 *                 PRIMASK_STATUS                                                                                                  *
 *                     type: u8                                                                                                    *
 *                     Description: PRIMASK determines whether the Exceptions are enabled or not.                                  *
 *                     				PRIMASK_ENABLE_ALL                                                                             *
 *                     				PRIMASK_DISABLE_ALL                                                                            *                                                            *
 *              Output:NA                                                                                                          *
 *              In/out:NA                                                                                                          *
 *                                                                                                                                 *
 * return: void                                                                                                                    *
 * Description: a function that control the PRIMASK value whether the Exceptions are enabled or not.                               *
 ***********************************************************************************************************************************/
void NVIC_ControlPRIMMASK(u8  PRIMASK_STATUS);

/***********************************************************************************************************************************
 * Function name: NVIC_ControlFAULTMASK                                                                                            *
 *                                                                                                                                 *
 * parameters:  Input:                                                                                                             *
 *                 FAULTMASK_STATUS                                                                                                  *
 *                     type: u8                                                                                                    *
 *                     Description: FAULTMASK determines whether the Hard Fault Exception is enabled or not.                       *
 *                     				FAULTMASK_ENABLE_ALL                                                                           *
 *                     				FAULTMASK_DISABLE_ALL                                                                          *                                              *
 *              Output:NA                                                                                                          *
 *              In/out:NA                                                                                                          *
 *                                                                                                                                 *
 * return: void                                                                                                                    *
 * Description: a function that control the FAULTMASK value whether the Exception is enabled or not.                               *
 ***********************************************************************************************************************************/
void NVIC_ControlFAULTMASK(u8 FAULTMASK_STATUS);

/***********************************************************************************************************************************
 * Function name: NVIC_ControlBASEPRI                                                                                              *
 *                                                                                                                                 *
 * parameters:  Input:                                                                                                             *
 *                 PriorityLevel                                                                                                   *
 *                     type: u8                                                                                                    *
 *                     Description: it holds the Interrupt Level which is used to disable all other interrupts that have lower     *
 *                     				priority.                                                                                      *
 *              Output:NA                                                                                                          *
 *              In/out:NA                                                                                                          *
 *                                                                                                                                 *
 * return: void                                                                                                                    *
 * Description: a function that control the FAULTMASK value whether the Exception is enabled or not.                               *
 ***********************************************************************************************************************************/
void NVIC_ControlBASEPRI(u8 PriorityLevel);

#endif /* DNVIC_H_ */
