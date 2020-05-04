/*
 * Nokia.c
 *
 *  Created on: Apr 24, 2020
 *      Author: FatmaGomaa
 */

#include "STD_TYPES.h"
#include <util/delay.h>
#include "DIO_Interface.h"
#include "Nokia.h"

#define FUNCTION_SET					0b00100000
/*PD=0 -> Active   PD=1->Power Down*/
#define FUNCTION_SET_PD					0b00100100
/*V=0 -> Horizontal   V=1->Vertical*/
#define FUNCTION_SET_V                  0b00100010
/*H=0 -> Basic   H=1->Extended*/
#define FUNCTION_SET_H                  0b00100001

#define TEMPERATURE_CURVE					0b00000100
#define TEMPERATURE_CURVE_C0				0b00000100
#define TEMPERATURE_CURVE_C1				0b00000101
#define TEMPERATURE_CURVE_C2				0b00000110
#define TEMPERATURE_CURVE_C3				0b00000111

#define BIAS_SYSTEM							0b00010011

#define VOP									0xBE

#define DISPLAY_CONTROL_DE					0b00001000
#define DISPLAY_CONTROL_DISPLAY_BLANK		0b00001000
#define DISPLAY_CONTROL_NORMAL_MODE			0b00001100
#define DISPLAY_CONTROL_SEGMENTS_ON			0b00001001
#define DISPLAY_CONTROL_INVERSE_VIDEO		0b00001101

#define NUM_OF_BYTES_IN_LCD					504

#define RETURN_X_TO_0						0b01000000
#define RETURN_Y_TO_0						0b10000000

static void writeCommand(u8 Command);
static void writeData(u8* Data, u16 size);

void Nokia_Init(void){

	/*Reset Cycle */
	DIO_SetPinValue('A', 2, 1);
	_delay_ms(2);
	DIO_SetPinValue('A', 2, 0);
	_delay_ms(2);
	DIO_SetPinValue('A', 2, 1);

	/*Init Commands*/
	writeCommand(FUNCTION_SET_H);
	writeCommand(TEMPERATURE_CURVE_C2);
	writeCommand(BIAS_SYSTEM);
	writeCommand(VOP);

	writeCommand(FUNCTION_SET);
	writeCommand(DISPLAY_CONTROL_NORMAL_MODE);

}

void Nokia_Display(u8* Data, u16 size){
	u16 Local_Iteration =0;

	/*return cursor to X = 0 and  Y = 0 */
	writeCommand(RETURN_X_TO_0);
	writeCommand(RETURN_Y_TO_0);

	/*write Data on LCD*/
	writeData(Data, size);


}

static void writeCommand(u8 Command){

	/*Select Nokia as a Slave*/
	DIO_SetPinValue('A', 3, 0);
	/*Select Command Mode*/
	DIO_SetPinValue('A', 1, 0);
	/*send data over SPI*/
	SPI_SendSync(Command);
	/*deselect Nokia from slavery*/
	DIO_SetPinValue('A', 3, 1);

}

static void writeData(u8* Data, u16 size){
	u16 i=0;
	/*Select Nokia as a Slave*/
	DIO_SetPinValue('A', 3, 0);
	/*Select Data Mode*/
	DIO_SetPinValue('A', 1, 1);
	/*send data over SPI*/
	for(i=0;i<504;i++){
		SPI_SendSync(Data[i]);
	}
	/*deselect Nokia from slavery*/
	DIO_SetPinValue('A', 3, 1);
}
