/*
 * hLCD.h
 *
 *  Created on: Mar 24, 2020
 *      Author: FatmaGomaa
 */

#ifndef HLCD_H_
#define HLCD_H_

typedef enum {
	idle_proc ,
	write_proc ,
	clear_proc,
	cursermove_proc
}process_t;

typedef enum
{
	power_on ,
	function_set ,
	display_control ,
	display_clear ,
	entry_mode_set

}initProcesses_t;

STD_ERROR LCD_Init(void);
ProcessState_t LCD_Write(u32* String, u32 Lenght);
ProcessState_t LCD_Clear(void);
ProcessState_t LCD_CursorMove(u8 Column, u8 Row);
void LCD_Task(void);


#endif /* HLCD_H_ */
