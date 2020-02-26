#include "STD_TYPES.h"

#include "dRCC.h"
#include "dGPIO.h"
#include "SysTick_Interface.h"
#include "song.h"

u32 i=0;
void play(void);

void main(void){

	GPIO_t DAC = {PORT_A, PIN_0 | PIN_1 , OUTPUT_GP_PUSH_PULL_50MHZ};

	/*enable internal clock with 8 Mhz*/
	RCC_stdErrorControlClock(HSI_ON,ON);
	RCC_stdErrorSetSYSClock(HSI_SW);

	/*enable clock on APB2 PORTA*/
	RCC_stdErrorControlPerihperal(APB2,RCC_APB2_CLOCK_PORT_A,ON);
	STK_voidInitialize();
	STK_voidSetCallBack(&play);

	/*set pin A0 to A7 Mode to output push pull*/
	GPIO_STD_ERROR_Config(&DAC);

	GPIO_STD_ERROR_writePin(PORT_A,PIN_0,HIGH);
	GPIO_STD_ERROR_writePin(PORT_A,PIN_1,HIGH);
	GPIO_STD_ERROR_writePin(PORT_A,PIN_2,LOW);

	STK_voidStart(125);

	while(1){

	}
}

void play(void){
	GPIO_STD_ERROR_writePort(PORT_A,reemy_raw[i]);
	i++;
	if(i==19875){
		i=0;
	}
}
