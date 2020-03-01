#include "STD_TYPES.h"
#include "dNVIC.h"

int main()
{
	u8 local=1;

	NVIC_controlIRQ(14, IRQ_ON);
	//NVIC_controlPendingIRQ(14, IRQ_ON);
	NVIC_controlPendingIRQ(14, IRQ_OFF);
	NVIC_getPendingFlag (14, &local);
	NVIC_controlIRQ(14, IRQ_OFF);
	NVIC_setPriority(16, 0x40);
	NVIC_setPriorityGroup(PRIORITY_GROUP_4_sub0to4);
	NVIC_ControlBASEPRI(5);
	NVIC_ControlFAULTMASK(PRIMASK_DISABLE_ALL);
	NVIC_ControlFAULTMASK(PRIMASK_ENABLE_ALL);

  while (1)
    {
    }
}

