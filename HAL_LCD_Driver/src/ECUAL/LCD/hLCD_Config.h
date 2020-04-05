/*
 * hLCD_Config.h
 *
 *  Created on: Mar 24, 2020
 *      Author: FatmaGomaa
 */

#ifndef HLCD_CONFIG_H_
#define HLCD_CONFIG_H_

#define LCD_NUM										1

#define LCD_DATA_PINS_NUM							8
#define LCD_DATA_LENGTH								1
#define LCD_LINES_NUM								1
#define LCD_DOT_CHARACTER_FONT						0
#define LCD_DISPLAY_STATE							1
#define LCD_CURSOR_STATE							0
#define LCD_BLINK_STATE								0
#define LCD_INCREMENT_MODE							1
#define LCD_SHIFT_OPERATION							0


typedef struct{
	void volatile * LCD_CONTROL_PORT;
	void volatile * LCD_Data_PORT;

	u32 LCD_RS_PIN;
	u32 LCD_RW_PIN;
	u32 LCD_Enable_PIN;

	u32 LCD_Data_Pins[LCD_DATA_PINS_NUM];

	u32 LCD_Data_pins_Mode;
	u32 LCD_Data_InitialValue;

}LCD_GPIO_MAP_t;


#endif /* HLCD_CONFIG_H_ */
