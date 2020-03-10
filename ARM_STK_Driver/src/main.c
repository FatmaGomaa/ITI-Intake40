#include "STD_TYPES.h"
#include "dSTK.h"


int main( void )
{
	STK_Init();
	STK_Start();
	STK_Stop();
	STK_SetPrescaler(STK_PRESCALER_AHB_DIVIDED_BY_8);
	STK_SetTime(500, RCC_CLOCK_SOURCE);
  while (1)
    {

    }
}

