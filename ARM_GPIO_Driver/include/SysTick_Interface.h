#ifndef	STK_INTERFACE_H
#define STK_INTERFACE_H

/*Core Peripherals doesn't need to enable peripheral clock*/
void STK_voidInitialize(void);
void STK_voidStart(u32 copy_u32Value);
void STK_voidSetCallBack(void(*Copy_ptr)(void));

#endif