#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"EXIT_interface.h"
#include"EXIT_reg.h"




void EXIT_voidINT0Init(void)
{
	MCUCR |= (1<<1);

	GICR |=(1<<6);
	}
void EXIT_voidINT1Int(void)
{
	MCUCR |=(1<<3);

	GICR |=(1<<7);

}
void EXIT_voidEnableGlobal(void)
{
	SREG |=(1<<7);
}
