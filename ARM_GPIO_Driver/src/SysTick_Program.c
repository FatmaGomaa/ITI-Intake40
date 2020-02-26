#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SysTick_Interface.h"
#include "SysTick_Register.h"

void (*SysTick_CallBack)(void);

void STK_voidInitialize(void){
	/*1.Enable SysTick and Clock = AHB/8 
	  2.Stop SysTick1*/
	  STK_CTRL = 0x00000002;
}
void STK_voidStart(u32 copy_u32Value){
	/*Load Value into Load Register*/
	STK_LOAD = copy_u32Value;
	STK_VAL = 0;
	/*start system timer*/
	SET_BIT(STK_CTRL,0);
}
void STK_voidSetCallBack(void(*Copy_ptr)(void)){
	SysTick_CallBack = Copy_ptr;
}


