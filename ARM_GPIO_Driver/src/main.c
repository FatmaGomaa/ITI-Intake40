
#include "STD_TYPES.h"
#include "dGPIO.h"
#include "dRCC.h"

int main()
{
	RCC_stdErrorControlPerihperal(APB2,RCC_APB2_CLOCK_PORT_C,ON);
	GPIO_t LedPin;
	LedPin.PORT = PORT_C;
	LedPin.PIN = PIN_13;
	LedPin.MOOD = OUTPUT_GP_PUSH_PULL_2MHZ;
	GPIO_STD_ERROR_Config(&LedPin);
	GPIO_STD_ERROR_writePin(&LedPin,HIGH);
	GPIO_STD_ERROR_writePin(&LedPin,LOW);

  while (1)
    {
       // Add your code here.
    }
}
