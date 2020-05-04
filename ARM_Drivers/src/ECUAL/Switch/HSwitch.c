/*
 * HSwitch.c
 *
 *  Created on: Mar 16, 2020
 *      Author: FatmaGomaa
 */
#include "STD_TYPES.h"
#include "dGPIO.h"
#include "dRCC.h"
#include "HSwitch.h"
#include "HSwitch_Config.h"

u8 Global_u8CurrentState[NUM_OF_SWITCHES];

extern Switch_t App_Switches[NUM_OF_SWITCHES];

GPIO_t Switch_Map[NUM_OF_SWITCHES];

SwitchAppNotify_t SwitchAppNotify;

STD_ERROR HSwitch_Init(void){
	STD_ERROR Local_ErrorStatus= OK;
	u8 Local_u8Iterator=0;

	for (Local_u8Iterator = 0; Local_u8Iterator < NUM_OF_SWITCHES; Local_u8Iterator ++){
		Switch_Map[Local_u8Iterator].PORT 		= App_Switches[Local_u8Iterator].PORT;
		Switch_Map[Local_u8Iterator].PIN 		= App_Switches[Local_u8Iterator].PIN;
		Switch_Map[Local_u8Iterator].MOOD		= INPUT_PULLUP_PULLDOWN_MODE;
	}

	for (Local_u8Iterator = 0; Local_u8Iterator < NUM_OF_SWITCHES; Local_u8Iterator ++){
		Local_ErrorStatus &= GPIO_Config(&Switch_Map[Local_u8Iterator]);
		Local_ErrorStatus &= GPIO_writePin(Switch_Map[Local_u8Iterator].PORT, Switch_Map[Local_u8Iterator].PIN, App_Switches[Local_u8Iterator].GPIO_MODE );
	}

	return Local_ErrorStatus;
}

STD_ERROR HSwitch_getSwitchStatus(u8 Copy_u8SwitchName, u8* Copy_u8SwitchStatus){
	STD_ERROR Local_ErrorStatus= OK;
	if(App_Switches[Copy_u8SwitchName].GPIO_MODE == PULL_UP){
		*Copy_u8SwitchStatus = HIGH ^ Global_u8CurrentState[Copy_u8SwitchName];
	}else if(App_Switches[Copy_u8SwitchName].GPIO_MODE == PULL_DOWN){
		*Copy_u8SwitchStatus = Global_u8CurrentState[Copy_u8SwitchName];
	}
	return Local_ErrorStatus;
}

/*Switch Task*/
void HSwitch_Debouncing(void){
	u8 Local_u8Iterator=0;
	static u8 Local_u8CurrentState[NUM_OF_SWITCHES], Local_u8PreviousState[NUM_OF_SWITCHES], Local_u8Counter[NUM_OF_SWITCHES];
	for(Local_u8Iterator = 0; Local_u8Iterator < NUM_OF_SWITCHES; Local_u8Iterator ++){
		Local_u8CurrentState[Local_u8Iterator] = GPIO_u8getPinValue(Switch_Map[Local_u8Iterator].PORT, Switch_Map[Local_u8Iterator].PIN);
		if(Local_u8CurrentState[Local_u8Iterator] == Local_u8PreviousState[Local_u8Iterator] ){
			Local_u8Counter[Local_u8Iterator]++;
		}else{
			Local_u8Counter[Local_u8Iterator] = 0;
		}
		Local_u8PreviousState[Local_u8Iterator]  = Local_u8CurrentState[Local_u8Iterator] ;

		if(Local_u8Counter[Local_u8Iterator]==HSwitch_OS_PeriodicTicks){

			if(Global_u8CurrentState[Local_u8Iterator] != Local_u8CurrentState[Local_u8Iterator]  ){

				SwitchAppNotify();
			}
			Global_u8CurrentState[Local_u8Iterator] = Local_u8CurrentState[Local_u8Iterator];

		}
	}

}

void HSwitch_SetCBF(SwitchAppNotify_t CBF){
	SwitchAppNotify = CBF;
}

