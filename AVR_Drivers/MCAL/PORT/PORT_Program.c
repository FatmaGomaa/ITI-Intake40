#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PORT_Interface.h"
#include "PORT_Register.h"
#include "PORT_Config.h"
#include "PORT_Private.h"

void PortInitialize(void){
	
	DDRA = PORTA_DIR;
	DDRB = PORTB_DIR;
	DDRC = PORTC_DIR;
	DDRD = PORTD_DIR;

	PORTA = PORTA_INITIAL_VALUE;
	PORTB = PORTB_INITIAL_VALUE;
	PORTC = PORTC_INITIAL_VALUE;
	PORTD = PORTD_INITIAL_VALUE;

}
