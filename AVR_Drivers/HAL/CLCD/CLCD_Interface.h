/***********************************************/
/* Author: Fatma Gomaa*/
/* Version: v01 */
/* Date: 14 Jan 2020 */
/************************************************/

/*Description; this API shall initialize LCD*/
void CLCD_voidInitialize(void);

/*Description; this API shall display Data on LCD*/
void CLCD_voidWriteData(u8 Copy_u8Data);

/*Description; this API shall write Command to LCD*/
void CLCD_voidWriteCmd(u8 Copy_u8Cmd);

void CLCD_displayAtCertainPosition(u8 line, u8 colNum);

void CLCD_voidWriteString(const char* copy_pchString);
