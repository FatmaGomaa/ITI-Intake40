/*
 * dNVIC.h
 *
 *  Created on: Feb 26, 2020
 *  Author: FatmaGomaa
 *  V1 : Initial Creation of NVIC Driver.
 */

#ifndef DNVIC_H_
#define DNVIC_H_


#define PRIORITY_GROUP_0_sub0            		0x00000000
#define PRIORITY_GROUP_1_sub0to1         		0x00001000
#define PRIORITY_GROUP_2_sub0to2         	    0x00002000
#define PRIORITY_GROUP_3_sub0to3        	    0x00003000
#define PRIORITY_GROUP_4_sub0to4        	    0x00004000
#define PRIORITY_GROUP_5_sub0to5        	    0x00005000
#define PRIORITY_GROUP_6_sub0to6        	    0x00006000
#define PRIORITY_GROUP_7_sub0to7        	    0x00007000

#define IRQ_ON									1
#define IRQ_OFF									0

#define PRIMASK_ENABLE_ALL	 0
#define PRIMASK_DISABLE_ALL	 1

#define FAULTMASK_ENABLE_ALL	 0
#define FAULTMASK_DISABLE_ALL	 1

/*PRIORITY_GROUP_0_sub0            */
/*PRIORITY_GROUP_1_sub0to1         */
/*PRIORITY_GROUP_2_sub0to2         */
/*PRIORITY_GROUP_3_sub0to3         */
/*PRIORITY_GROUP_4_sub0to4         */
/*PRIORITY_GROUP_5_sub0to5         */
/*PRIORITY_GROUP_6_sub0to6         */
/*PRIORITY_GROUP_7_sub0to7         */
STD_ERROR NVIC_setPriorityGroup(u8 priority_group);

STD_ERROR NVIC_setPriority(u8 IRQn, u8 priority);

/*IRQ_ON	*/
/*IRQ_OFF	*/
STD_ERROR NVIC_controlIRQ(u8 IRQn, u8 state);
STD_ERROR NVIC_getPendingFlag (u8 IRQn, u8* PendingFlagValue);
STD_ERROR NVIC_controlPendingIRQ (u8 IRQn, u8 state);
void NVIC_ControlPRIMMASK(u8  PRIMASK_STATUS);
void NVIC_ControlFAULTMASK(u8 FAULTMASK_STATUS);
void NVIC_ControlBASEPRI(u8 PriorityLevel);

#endif /* DNVIC_H_ */
