/*******************************************************************************************************
 * File name: hLCD.h                                                                                   *
 *                                                                                                     *
 *                                                                                                     *
 * Description: This file contains the Prototypes of the LCD driver funcitons                          *
 * and the macros used by the user                                                                     *
 *                                                                                                     *
 * Author: Fatima Gomaa                                                                                *
 * Date:   March 24, 2020                                                                              *
 * Version 1.0 : Initial Creation of the NVIC Driver                                                   *
 *******************************************************************************************************/

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

/***********************************************************************************************************************************
 * Function name: LCD_Init
 *
 * parameters:  Input:
 *                 void
 *
 *              Output: NA
 * return: STD_ERROR
 * Description: a function to init the LCD when the system starts, it sets a flag that the OS uses to start LCD_initProcess
 ***********************************************************************************************************************************/
STD_ERROR LCD_Init(void);

/***********************************************************************************************************************************
 * Function name: LCD_Write
 *
 * parameters:  Input:
 *                 String
 *                 		type: u8*
 *                 		Description: it's the string to be written to the LCD
 *
 *				   Length
 *				   		type: u32
 *				   		Description: length of the string.
 *              Output: NA
 * return: ProcessState_t
 * Description: a function to write buffer to the LCD by user and it sets a flag that the OS uses to start LCD_writeProcess
 ***********************************************************************************************************************************/
ProcessState_t LCD_Write(u32* String, u32 Lenght);

/***********************************************************************************************************************************
 * Function name: LCD_Clear
 *
 * parameters:  Input:
 *                 void
 *
 *              Output: NA
 * return: ProcessState_t
 * Description: a function to clear the LCD by user and it sets a flag that the OS uses to start LCD_clearProcess
 ***********************************************************************************************************************************/
ProcessState_t LCD_Clear(void);

/***********************************************************************************************************************************
 * Function name: LCD_Write
 *
 * parameters:  Input:
 *                 Column
 *                 		type: u8
 *                 		Description: cursor of LCD moves to that column
 *
 *				   Row
 *				   		type: u8
 *				   		Description: cursor of LCD moves to that Row
 *              Output: NA
 * return: ProcessState_t
 * Description: a function to move cursor to certain row and column
 ***********************************************************************************************************************************/
ProcessState_t LCD_CursorMove(u8 Column, u8 Row);

/***********************************************************************************************************************************
 * Function name: LCD_Write
 *
 * parameters:  Input:
 *                 void
 *
 *              Output: NA
 * return: ProcessState_t
 * Description: the task that manages all the LCD operations according to the OS calls
 ***********************************************************************************************************************************/
void LCD_Task(void);


#endif /* HLCD_H_ */
