/*
 * dNVIC.h
 *
 *  Created on: Feb 26, 2020
 *  Author: Fatma Gomaa
 *  V1 : Initial Creation of NVIC Driver.
 */

#include "STD_TYPES.h"
#include "dNVIC.h"

#define NUM_OF_INTERRUPTS_PER_REGISTER		32
#define HIGH								1
#define LOW									(u32)0

#define NVIC_REGISTERS						(volatile NVIC_t *)0xE000E100
#define NVIC_SCB_ACTLR						*(volatile u32 *)0xE000E014


#define PRIORITY_GROUP_M		 			0x00000700
#define PRIORITY_GROUP_CLEAR_M		   		0xfffff8ff
#define NVIC_IPR_M							0xff
#define NVIC_VECTKEY						0x05FA0000


typedef struct {

	u32 NVIC_ISER[8];
	u32 RESERVED0[24];
	u32 NVIC_ICER[8];
	u32 RESERVED1[24];
	u32 NVIC_ISPR[8];
	u32 RESERVED2[24];
	u32 NVIC_ICPR[8];
	u32 RESERVED3[24];
	u32 NVIC_IABR[8];
	u32 RESERVED4[56];
	u8  NVIC_IPR[240];
	u32 RESERVED5[608];
	u32 NVIC_STIR;

}NVIC_t;

STD_ERROR NVIC_getPendingFlag (u8 IRQn, u8* PendingFlagValue){
	u8 Local_u8ArrayIndex = (IRQn / NUM_OF_INTERRUPTS_PER_REGISTER);
	u8 Local_u8BitIndex = (IRQn % NUM_OF_INTERRUPTS_PER_REGISTER);
	STD_ERROR Local_ErrorStatus = NOT_OK;
	NVIC_t * NVIC_PERIPHERAL = (NVIC_t *) NVIC_REGISTERS;

	*PendingFlagValue =( ( (NVIC_PERIPHERAL ->NVIC_ISPR[Local_u8ArrayIndex]) >>Local_u8BitIndex)  & HIGH );

	if ( *PendingFlagValue == ( ( (NVIC_PERIPHERAL ->NVIC_ISPR[Local_u8ArrayIndex]) >>Local_u8BitIndex)  & HIGH ) ){
		Local_ErrorStatus = OK;
	}

	return Local_ErrorStatus;
}


STD_ERROR NVIC_controlPendingIRQ (u8 IRQn, u8 state){
	u8 Local_u8ArrayIndex = (IRQn / NUM_OF_INTERRUPTS_PER_REGISTER);
	u8 Local_u8BitIndex = (IRQn % NUM_OF_INTERRUPTS_PER_REGISTER);
	STD_ERROR Local_ErrorStatus = NOT_OK;
	NVIC_t * NVIC_PERIPHERAL = (NVIC_t *) NVIC_REGISTERS;
	if(state == HIGH){
		NVIC_PERIPHERAL ->NVIC_ISPR[Local_u8ArrayIndex] |= (HIGH<<Local_u8BitIndex);
		if( (NVIC_PERIPHERAL ->NVIC_ISPR[Local_u8ArrayIndex] & (HIGH<<Local_u8BitIndex) ) == (state <<Local_u8BitIndex)  ){
			Local_ErrorStatus = OK;
		}
	}else if(state == LOW){
		NVIC_PERIPHERAL ->NVIC_ICPR[Local_u8ArrayIndex] |= (HIGH<<Local_u8BitIndex);
		/****************************WHY ISPR NOT ICPR********************************************/
		if( (NVIC_PERIPHERAL ->NVIC_ISPR[Local_u8ArrayIndex] & (HIGH<<Local_u8BitIndex) ) == (state <<Local_u8BitIndex)  ){
			Local_ErrorStatus = OK;
		}
	}

	return Local_ErrorStatus;

}

STD_ERROR NVIC_controlIRQ(u8 IRQn, u8 state){
	u8 Local_u8ArrayIndex = (IRQn / NUM_OF_INTERRUPTS_PER_REGISTER);
	u8 Local_u8BitIndex = (IRQn % NUM_OF_INTERRUPTS_PER_REGISTER);
	STD_ERROR Local_ErrorStatus = NOT_OK;
	NVIC_t * NVIC_PERIPHERAL = (NVIC_t *) NVIC_REGISTERS;
	if(state == HIGH){
		NVIC_PERIPHERAL ->NVIC_ISER[Local_u8ArrayIndex] |= (HIGH<<Local_u8BitIndex);
		if( (NVIC_PERIPHERAL ->NVIC_ISER[Local_u8ArrayIndex] & (HIGH<<Local_u8BitIndex) ) == (state <<Local_u8BitIndex)  ){
			Local_ErrorStatus = OK;
		}
	}else if(state == LOW){
		NVIC_PERIPHERAL ->NVIC_ICER[Local_u8ArrayIndex] |= (HIGH<<Local_u8BitIndex);
		if( (NVIC_PERIPHERAL ->NVIC_ISER[Local_u8ArrayIndex] & (HIGH<<Local_u8BitIndex) ) == (state <<Local_u8BitIndex)  ){
			Local_ErrorStatus = OK;
		}
	}

	return Local_ErrorStatus;
}

STD_ERROR NVIC_setPriority(u8 IRQn, u8 priority){
	STD_ERROR Local_ErrorStatus = NOT_OK;
	NVIC_t * NVIC_PERIPHERAL = (NVIC_t *) NVIC_REGISTERS;
	NVIC_PERIPHERAL ->NVIC_IPR[IRQn] = priority;
	if((NVIC_PERIPHERAL ->NVIC_IPR[IRQn] & NVIC_IPR_M ) == priority){
		Local_ErrorStatus = OK;
	}
	return Local_ErrorStatus;

}

STD_ERROR NVIC_setPriorityGroup(u8 priority_group){
	STD_ERROR Local_ErrorStatus = NOT_OK;
	u32 NVIC_SCB_ACTLR_TEMP =NVIC_SCB_ACTLR;
	NVIC_SCB_ACTLR_TEMP &=PRIORITY_GROUP_CLEAR_M;
	NVIC_SCB_ACTLR_TEMP |= NVIC_VECTKEY | priority_group;
	NVIC_SCB_ACTLR=NVIC_SCB_ACTLR_TEMP;

	if( (NVIC_SCB_ACTLR & PRIORITY_GROUP_M) == priority_group ){
		Local_ErrorStatus = OK;
		trace_printf("Local_ErrorStatus: %d", Local_ErrorStatus);
	}
	return Local_ErrorStatus;
}

void NVIC_ControlPRIMMASK(u8  PRIMASK_STATUS){
	if(PRIMASK_STATUS == PRIMASK_ENABLE_ALL){
		asm ("MOV R0, #0");
		asm("MSR PRIMASK, R0");

	}else if(PRIMASK_STATUS == PRIMASK_DISABLE_ALL){
		asm ("MOV R0, #1");
		asm("MSR PRIMASK, R0");
	}
}

void NVIC_ControlFAULTMASK(u8 FAULTMASK_STATUS){

	if(FAULTMASK_STATUS == FAULTMASK_ENABLE_ALL){

		asm ("MOV R0, #0");
		asm("MSR FAULTMASK, R0");

	}else if(FAULTMASK_STATUS == FAULTMASK_DISABLE_ALL){
		asm ("MOV R0, #1");
		asm("MSR FAULTMASK, R0");
	}

}

void NVIC_ControlBASEPRI(u8 PriorityLevel)
{
	asm ("LSLS R0, R0, #4");
	asm("MSR BASEPRI, R0");

}


