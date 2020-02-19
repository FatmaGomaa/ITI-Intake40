
#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"

#include "STD_TYPES.h"
#include "dRCC.h"

int main(void)
{
	STD_ERROR result = NOT_OK;
	u8 sysClock;
   while (1)
    {
	   RCC_stdErrorSetSYSClock(HSI_SW);
	   RCC_stdErrorGetSYSClock(&sysClock);
	   result= RCC_stdErrorControlClock(PLL_ON,OFF);
	   if ( result == OK ){
	   trace_printf("PLL_OFF\n");
	   Delay_ms(4000);
	   }else{
		   trace_printf("PLL_OFF failed\n");

	   }
	   Delay_ms(1000);
	   result =  RCC_stdErrorConfigPLL(PLLSRC_HSE_DIVIDED_BY_2,  PLL_INPUT_CLOCK_X_3);
	   if (result == OK){
	   trace_printf("PLL Configured\n");
	   Delay_ms(4000);
	   }else{
		   trace_printf("PLL Configuration failed\n");

	   }
	   result= RCC_stdErrorControlClock(PLL_ON,ON);
	   if (result == OK){
	   trace_printf("PLL_ON\n");
	   Delay_ms(4000);
	   }else{
		   trace_printf("PLL_ON failed\n");

	   }

	   RCC_stdErrorControlPerihperal(APB2,RCC_APB2_CLOCK_PORT_A,ON);
	   RCC_stdErrorControlPerihperal(APB2,RCC_APB2_CLOCK_PORT_A,OFF);

    }
}


