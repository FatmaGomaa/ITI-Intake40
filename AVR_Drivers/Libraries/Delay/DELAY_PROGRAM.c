#include "STD_TYPES.h"
#include "DELAY_INTERFACE.h"
//#include "DIO_Register.h"
#define t1 (0.00539875f)
#define tm (0.634125f)

/* for loop time          t1 = 5.39875 us */
/* calculation time       t2 = 627.875 us */
/* context switching into t3 = 3.995 us */
/* context switching out  t4 = 2.255 us */

void Delay_ms(u32 Value)
{

	 u32 i;
	 u32 count = (u32)((float)Value-tm)/t1;

	for(i=0 ; i<count ; i++)
	{
		asm("NOP");
	}
}

