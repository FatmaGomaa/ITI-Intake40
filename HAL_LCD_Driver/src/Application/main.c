#include "STD_TYPES.h"
#include "dGPIO.h"
#include "dRCC.h"
#include "dUART.h"
#include "DNVIC_interface.h"
#include "hLCD.h"
#include "hLCD_Config.h"
#include "dSTK.h"
#include "Sched.h"
#include "Sched_Config.h"
#include "HSwitch.h"
#include "HSwitch_Config.h"
#include "HLED_interface.h"
#include "hUART_Config.h"
#include "hUSART.h"

void toggelLed(void);
void UART_Receive_Notify(void);
void UART_Transmit_Notify(void);

extern u8 Global_u8CurrentState[NUM_OF_SWITCHES];
extern UART_Frame_Cfg_t App_UART_Config[APP_USARTs_NUM];

u8 x=0;
u32 String[] = {' ','H','E','L','L','O',' ','R','O','O','M','I','E',':',' ',48};
u8 StringCopy;
u8 LED_HIGH = 'N';
u8 LED_LOW = 'F';

Task_t AppTask = {&LCD_Task , 2000} ;
Task_t SwitchTask = {&HSwitch_Debouncing,HSwitch_OS_Periodicity};

void main(void)
{
	//GPIO_t	LED = {PORT_C, PIN_13, OUTPUT_GP_PUSH_PULL_2MHZ};

	RCC_stdErrorControlClock(HSI_ON, ON);
	RCC_stdErrorSetSYSClock(HSI_SW);
	RCC_stdErrorControlPerihperal(APB2, RCC_APB2_CLOCK_PORT_A,  ON);
	RCC_stdErrorControlPerihperal(APB2, RCC_APB2_CLOCK_PORT_C,  ON);

	Sched_Init();
	LCD_Init();
	HSwitch_Init();
	HLED_init();

	HSwitch_SetCBF(toggelLed);
	UART_setRecveiverCbf(UART_Receive_Notify);
	UART_setTransmitterCbf(UART_Transmit_Notify);

	UART_Init(&App_UART_Config[UART_ONE]);
	UART_ReceiveBuffer(StringCopy, 1);
	//UART_Send(String, 16);
	LCD_Write(String, 16);
	Sched_Start();

	while (1)
	{
	}
}

void toggelLed(void){
	static u8 led_state = LOW;

	if (Global_u8CurrentState[0] == 0){
		if(led_state == LOW){
			UART_SendBuffer(&LED_HIGH, 1);
			led_state = HIGH;
		}else{
			UART_SendBuffer(&LED_LOW, 1);
			led_state = LOW;
		}
		String[15]=x+48;
		LCD_Clear();
		x++;
		if(x>9){
			x=0;
		}

	}
}
void UART_Receive_Notify(void)
{
	if (StringCopy == LED_HIGH){
		LCD_Write(String, 16);
		HLED_setLedState(LED_ALARM, LED_ON);
		//GPIO_STD_ERROR_writePin(PORT_C,PIN_13,LOW);
	}else if (StringCopy == LED_LOW){
		LCD_Write(String, 16);
		HLED_setLedState(LED_ALARM, LED_OFF);
		//GPIO_STD_ERROR_writePin(PORT_C,PIN_13,HIGH);
	}

}
void UART_Transmit_Notify(void){
	UART_ReceiveBuffer(&StringCopy, 1);
}
