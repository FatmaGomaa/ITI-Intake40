/*
 * hLCD.c
 *
 *  Created on: Mar 24, 2020
 *      Author: FatmaGomaa
 */
#include "STD_TYPES.h"
#include "dGPIO.h"
#include "dRCC.h"
#include "hLCD_Config.h"
#include "hLCD.h"


#define LCD_VDD_RISING_TIME     16
#define LOW                     0
#define HIGH                    1

#define Conc(arg1,arg2,arg3,arg4)						Conc_Helper(arg1,arg2,arg3,arg4)
#define Conc_Helper(arg1,arg2,arg3,arg4)				arg1##arg2##arg3##arg4

#define FUNCTION_SET_COMMAND						Conc(0b0011,LCD_LINES_NUM,LCD_DOT_CHARACTER_FONT,00)
#define DISPLAY_CONTROL_COMMAND						Conc(0b00001,LCD_DISPLAY_STATE,LCD_CURSOR_STATE,LCD_BLINK_STATE)
#define DISPLAY_CLEAR_COMMAND						0x01
#define ENTRY_MODE_SET_COMMAND						Conc(0b000001,LCD_INCREMENT_MODE,LCD_SHIFT_OPERATION,)

extern LCD_GPIO_MAP_t APP_LCDs[LCD_DATA_PINS_NUM];
GPIO_t LCD_GPIO_MAP[LCD_NUM];

u8 Global_StringCopy[200];
u8 Global_StringLenght;

u8 Global_Column;
u8 Global_Row;

u32 GlobalInitCompleted = 0;
process_t currentProcess;

extern u32 String[];

static void LCD_initProcess(void)
{
	static u32 Local_u32CommandCounter = 0;
	static initProcesses_t Local_CurrentProcess = power_on ;
	u8 Local_u8Iterator, Local_u8BitValue;

	switch(Local_CurrentProcess)
	{
	case power_on :
		if(Local_u32CommandCounter < LCD_VDD_RISING_TIME)
		{
			Local_u32CommandCounter ++ ;
		}
		else
		{
			Local_u32CommandCounter = 0;
			Local_CurrentProcess = function_set ;
		}
		break;
	case function_set :

		if(GPIO_u8getPinValue(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_Enable_PIN)){
			GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_Enable_PIN, LOW);
			Local_CurrentProcess = display_control;

		}else {
			GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_RS_PIN, LOW);
			GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_RW_PIN, LOW);
			for (Local_u8Iterator = 0; Local_u8Iterator < LCD_DATA_PINS_NUM; Local_u8Iterator ++)
			{
				Local_u8BitValue =( (FUNCTION_SET_COMMAND >> Local_u8Iterator) & 0x01 );
				GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_Data_PORT, APP_LCDs[0].LCD_Data_Pins[Local_u8Iterator], Local_u8BitValue);

			}
			GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_Enable_PIN, HIGH);
		}
		break;

	case display_control:
		if(GPIO_u8getPinValue(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_Enable_PIN)){
			GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_Enable_PIN, LOW);
			Local_CurrentProcess = display_clear;

		}else{
			GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_RS_PIN, LOW);
			GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_RW_PIN, LOW);
			for (Local_u8Iterator = 0; Local_u8Iterator < LCD_DATA_PINS_NUM; Local_u8Iterator ++)
			{
				Local_u8BitValue =( (DISPLAY_CONTROL_COMMAND >> Local_u8Iterator) & 0x01 );
				GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_Data_PORT, APP_LCDs[0].LCD_Data_Pins[Local_u8Iterator], Local_u8BitValue);

			}
			GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_Enable_PIN, HIGH);
		}
		break;

	case display_clear:
		if(GPIO_u8getPinValue(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_Enable_PIN)){
			GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_Enable_PIN, LOW);
			Local_CurrentProcess = entry_mode_set;

		}else{
			GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_RS_PIN, LOW);
			GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_RW_PIN, LOW);
			for (Local_u8Iterator = 0; Local_u8Iterator < LCD_DATA_PINS_NUM; Local_u8Iterator ++)
			{
				Local_u8BitValue =( (DISPLAY_CLEAR_COMMAND >> Local_u8Iterator) & 0x01 );
				GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_Data_PORT, APP_LCDs[0].LCD_Data_Pins[Local_u8Iterator], Local_u8BitValue);

			}
			GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_Enable_PIN, HIGH);
		}
		break;

	case entry_mode_set:
		if(GPIO_u8getPinValue(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_Enable_PIN)){
			GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_Enable_PIN, LOW);
			GlobalInitCompleted = 1;

		}else{
			GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_RS_PIN, LOW);
			GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_RW_PIN, LOW);
			for (Local_u8Iterator = 0; Local_u8Iterator < LCD_DATA_PINS_NUM; Local_u8Iterator ++)
			{
				Local_u8BitValue =( (ENTRY_MODE_SET_COMMAND >> Local_u8Iterator) & 0x01 );
				GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_Data_PORT, APP_LCDs[0].LCD_Data_Pins[Local_u8Iterator], Local_u8BitValue);

			}
			GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_Enable_PIN, HIGH);
		}
		break;

	}
}

ProcessState_t LCD_Write(u32* String, u32 Lenght){
	ProcessState_t Local_ProcessState = STATE_NOK;
	u32 Local_u32Iterator = 0;
	if(currentProcess == idle_proc){
		currentProcess = write_proc;

		for(Local_u32Iterator = 0; Local_u32Iterator< Lenght; Local_u32Iterator++){
			Global_StringCopy[Local_u32Iterator] = String[Local_u32Iterator];
		}
		Global_StringLenght = Lenght;
		Local_ProcessState = STATE_OK;

	}else{
		Local_ProcessState = STATE_BUSY;
	}

	return Local_ProcessState;
}

ProcessState_t LCD_Clear(void){
	ProcessState_t Local_ProcessState = STATE_NOK;

	if(currentProcess == idle_proc){
		currentProcess = clear_proc;
		Local_ProcessState = STATE_OK;

	}else{
		Local_ProcessState = STATE_BUSY;
	}

	return Local_ProcessState;
}

ProcessState_t LCD_CursorMove(u8 Copy_u32Column, u8 Copy_u32Row){

	ProcessState_t Local_ProcessState = STATE_NOK;

	if(currentProcess == idle_proc){
		currentProcess = cursermove_proc;
		Global_Column = Copy_u32Column;
		Global_Row    = Copy_u32Row;
		Local_ProcessState = STATE_OK;

	}else{
		Local_ProcessState = STATE_BUSY;
	}

	return Local_ProcessState;
}



static void LCD_WriteProcess(void){
	u32 Local_u8Iterator = 0;
	u8 Local_u8BitValue = 0;
	static u8 Local_u8Counter = 0;
	if(Local_u8Counter < Global_StringLenght){
		if(GPIO_u8getPinValue(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_Enable_PIN)){
			GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_Enable_PIN, LOW);
			Local_u8Counter ++;
		}else {

			GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_RS_PIN, HIGH);
			GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_RW_PIN, LOW);
			for (Local_u8Iterator = 0; Local_u8Iterator < LCD_DATA_PINS_NUM; Local_u8Iterator ++)
			{
				Local_u8BitValue =( (Global_StringCopy[Local_u8Counter] >> Local_u8Iterator) & 0x01 );
				GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_Data_PORT, APP_LCDs[0].LCD_Data_Pins[Local_u8Iterator], Local_u8BitValue);

			}
			GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_Enable_PIN, HIGH);
		}
	}else{
		currentProcess = idle_proc;
		Local_u8Counter =0;
	}

}

static void LCD_ClearProcess(void){
	u8  Local_u8Iterator =0, Local_u8BitValue =0;

	if(GPIO_u8getPinValue(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_Enable_PIN)){
		GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_Enable_PIN, LOW);
		currentProcess = idle_proc;
		LCD_Write(String, 16);

	}else{
	GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_RS_PIN, LOW);
	GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_RW_PIN, LOW);
	for (Local_u8Iterator = 0; Local_u8Iterator < LCD_DATA_PINS_NUM; Local_u8Iterator ++)
	{
		Local_u8BitValue =( (DISPLAY_CLEAR_COMMAND >> Local_u8Iterator) & 0x01 );
		GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_Data_PORT, APP_LCDs[0].LCD_Data_Pins[Local_u8Iterator], Local_u8BitValue);

	}
	GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_Enable_PIN, HIGH);
	}

}

static void LCD_CursorMoveProcess(void){
	u8  Local_u8Iterator =0, Local_u8BitValue =0;

	if(Global_Row == 1){

		if(GPIO_u8getPinValue(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_Enable_PIN)){
			GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_Enable_PIN, LOW);
			currentProcess = idle_proc;

		}
		GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_RS_PIN, LOW);
		GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_RW_PIN, LOW);
		for (Local_u8Iterator = 0; Local_u8Iterator < LCD_DATA_PINS_NUM; Local_u8Iterator ++)
		{
			Local_u8BitValue =( ( (0x80 | Global_Column) >> Local_u8Iterator) & 0x01 );
			GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_Data_PORT, APP_LCDs[0].LCD_Data_Pins[Local_u8Iterator], Local_u8BitValue);

		}
		GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_Enable_PIN, HIGH);

	}else if(Global_Row == 2){

		if(GPIO_u8getPinValue(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_Enable_PIN)){
			GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_Enable_PIN, LOW);
			currentProcess = idle_proc;

		}
		GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_RS_PIN, LOW);
		GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_RW_PIN, LOW);
		for (Local_u8Iterator = 0; Local_u8Iterator < LCD_DATA_PINS_NUM; Local_u8Iterator ++)
		{
			Local_u8BitValue =( ( (0x80 | (Global_Column + 0x40)) >> Local_u8Iterator) & 0x01 );
			GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_Data_PORT, APP_LCDs[0].LCD_Data_Pins[Local_u8Iterator], Local_u8BitValue);

		}
		GPIO_STD_ERROR_writePin(APP_LCDs[0].LCD_CONTROL_PORT, APP_LCDs[0].LCD_Enable_PIN, HIGH);

	}


}

void LCD_Task(void){
	if(GlobalInitCompleted)
	{

		switch(currentProcess)
		{
		case idle_proc:
			/*Do Nafe3 */
			break;

		case write_proc:
			LCD_WriteProcess();
			break;

		case clear_proc:
			LCD_ClearProcess();
			break;

		case cursermove_proc:
			LCD_CursorMoveProcess();
			break;


		}

	}
	else
	{

		LCD_initProcess();
	}

}


STD_ERROR LCD_Init(void){

	STD_ERROR Local_ErrorStatus= OK;
	u8 Local_u8Iterator=0;

	for (Local_u8Iterator = 0; Local_u8Iterator < LCD_NUM; Local_u8Iterator ++)
	{
		LCD_GPIO_MAP[Local_u8Iterator].PORT 	= APP_LCDs[Local_u8Iterator].LCD_Data_PORT;
		LCD_GPIO_MAP[Local_u8Iterator].PIN 		= (APP_LCDs[Local_u8Iterator].LCD_Data_Pins[0] | APP_LCDs[Local_u8Iterator].LCD_Data_Pins[1] | APP_LCDs[Local_u8Iterator].LCD_Data_Pins[2] | APP_LCDs[Local_u8Iterator].LCD_Data_Pins[3] | APP_LCDs[Local_u8Iterator].LCD_Data_Pins[4] | APP_LCDs[Local_u8Iterator].LCD_Data_Pins[5] | APP_LCDs[Local_u8Iterator].LCD_Data_Pins[6] | APP_LCDs[Local_u8Iterator].LCD_Data_Pins[7] ) ;
		LCD_GPIO_MAP[Local_u8Iterator].MOOD		= APP_LCDs[Local_u8Iterator].LCD_Data_pins_Mode;
	}

	for (Local_u8Iterator = 0; Local_u8Iterator < LCD_NUM; Local_u8Iterator ++)
	{
		GPIO_Config(&LCD_GPIO_MAP[Local_u8Iterator]);
	}

	for (Local_u8Iterator = 0; Local_u8Iterator < LCD_NUM; Local_u8Iterator ++)
	{
		LCD_GPIO_MAP[Local_u8Iterator].PORT 	= APP_LCDs[Local_u8Iterator].LCD_CONTROL_PORT;
		LCD_GPIO_MAP[Local_u8Iterator].PIN 		= (APP_LCDs[Local_u8Iterator].LCD_RS_PIN | APP_LCDs[Local_u8Iterator].LCD_RW_PIN | APP_LCDs[Local_u8Iterator].LCD_Enable_PIN  ) ;
		LCD_GPIO_MAP[Local_u8Iterator].MOOD		= APP_LCDs[Local_u8Iterator].LCD_Data_pins_Mode;
	}

	for (Local_u8Iterator = 0; Local_u8Iterator < LCD_NUM; Local_u8Iterator ++)
	{
		GPIO_Config(&LCD_GPIO_MAP[Local_u8Iterator]);
	}


	return Local_ErrorStatus;
}



