#include "STD_TYPES.h"

#include "dRCC.h"
#include "dGPIO.h"
#include "hLED.h"



void main(void){
	HLed_Init();
	 HLed_writeLedState(LED_1, HIGH);
	while(1){

	}
}

