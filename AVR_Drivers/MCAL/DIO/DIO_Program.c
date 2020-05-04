#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_register.h"
#include "DIO_private.h"
#include "DIO_config.h"

void DIO_SetPinDir(u8 Port,u8 Pin,u8 Dir)
{
	switch(Port)
	{
		case 'A':
			if(Dir==0)
			{
				//DDRA &=~(1<<Pin);
				CLEAR_BIT(DDRA,Pin);
			}
			else
			{
				//DDRA |=(1<<Pin);
				SET_BIT(DDRA,Pin);
			}
			break;
		case 'B':
			if(Dir==0)
			{
				//DDRB &=~(1<<Pin);
				CLEAR_BIT(DDRB,Pin);
			}
			else
			{
				//DDRB |=(1<<Pin);
				SET_BIT(DDRB,Pin);
			}
			break;
		case 'C':
			if(Dir==0)
			{
				//DDRC &=~(1<<Pin);
				CLEAR_BIT(DDRC,Pin);
			}
			else
			{
				//DDRC |=(1<<Pin);
				SET_BIT(DDRC,Pin);
			}
			break;
		case 'D':
			if(Dir==0)
			{
				//DDRD &=~(1<<Pin);
				CLEAR_BIT(DDRD,Pin);
			}
			else
			{
				//DDRD |=(1<<Pin);
				SET_BIT(DDRD,Pin);
			}
			break;
	}
}

void DIO_SetPinValue(u8 Port,u8 Pin,u8 Val)
{
	switch(Port)
	{
		case 'A':
			if(Val==0)
			{
				//PORTA &=~(1<<Pin);
				CLEAR_BIT(PORTA,Pin);
			}
			else
			{
				//PORTA |=(1<<Pin);
				SET_BIT(PORTA,Pin);
			}
			break;
		case 'B':
			if(Val==0)
			{
				//PORTB &=~(1<<Pin);
				CLEAR_BIT(PORTB,Pin);
			}
			else
			{
				//PORTB |=(1<<Pin);
				SET_BIT(PORTB,Pin);
			}
			break;
		case 'C':
			if(Val==0)
			{
				//PORTC &=~(1<<Pin);
				CLEAR_BIT(PORTC,Pin);
			}
			else
			{
				//PORTC |=(1<<Pin);
				SET_BIT(PORTC,Pin);
			}
			break;
		case 'D':
			if(Val==0)
			{
				//PORTD &=~(1<<Pin);
				CLEAR_BIT(PORTD,Pin);
			}
			else
			{
				//PORTD |=(1<<Pin);
				SET_BIT(PORTD,Pin);
			}
			break;
	}
}

u8 DIO_GetPinValue(u8 Port,u8 Pin)
{
	switch(Port)
	{
		case 'A':
			return CHECK_BIT(PINA,Pin);
			break;
		case 'B':
			return CHECK_BIT(PINB,Pin);
			break;
		case 'C':
			return CHECK_BIT(PINC,Pin);
			break;
		case 'D':
			return CHECK_BIT(PIND,Pin);
			break;
	}
	return 0;
}
