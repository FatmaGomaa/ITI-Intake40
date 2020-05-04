#include"STD_Types.h"

#include"DIO_Interface.h"
#include"KEYPAD_Config.h"
#include"KEYPAD_Interface.h"
#include"KEYPAD_Private.h"

void KEYPAD_init(void)
{
	DIO_SetPinValue('B', 0, 1);
	DIO_SetPinValue('B', 1, 1);
	DIO_SetPinValue('B', 2, 1);
	DIO_SetPinValue('B', 3, 1);
}



u8 KEYPAD_getPressedKey(void)
{
	u8 static keypad_RowsPort[KEYPAD_ROWS_NUMBER]= KEYPAD_ROWS_PORT;
	u8 static keypad_ColumnsPort[KEYPAD_COLUMNS_NUMBER]=KEYPAD_COLUMNS_PORT;

	u8 static keypad_RowsPin[KEYPAD_ROWS_NUMBER]= KEYPAD_ROWS_PIN;
	u8 static keypad_ColumnsPin[KEYPAD_COLUMNS_NUMBER]=KEYPAD_COLUMNS_PIN;

	u8 static keypad_Keys[KEYPAD_ROWS_NUMBER][KEYPAD_COLUMNS_NUMBER]=KEYPAD_KEYS;

	u8 RowIdx, ColIdx, pinState, pressedKey=KEYPAD_DEFAULT;

	for(RowIdx = 0; RowIdx < KEYPAD_ROWS_NUMBER; RowIdx++)
	{
		/*Activate the current Row*/
		DIO_SetPinValue( keypad_RowsPort[RowIdx], keypad_RowsPin[RowIdx], 0);

		/*check columns if pressed*/
		for(ColIdx=0; ColIdx<KEYPAD_COLUMNS_NUMBER; ColIdx++)
		{
			pinState=DIO_GetPinValue(keypad_ColumnsPort[ColIdx],keypad_ColumnsPin[ColIdx]);

			/*check if the key is pressed*/


			if(0==pinState)
			{
				pressedKey=keypad_Keys[RowIdx][ColIdx];


				/*busy waiting until the key is released*/
				while(0==pinState)
				{
					pinState=DIO_GetPinValue(keypad_ColumnsPort[ColIdx],keypad_ColumnsPin[ColIdx]);
				}
				return pressedKey;
			}

		}
		/*deactivate the current row*/
		DIO_SetPinValue(keypad_RowsPort[RowIdx],keypad_RowsPin[RowIdx],1);
	}
	return pressedKey;
}
