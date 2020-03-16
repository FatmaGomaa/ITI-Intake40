

#include "STD_TYPES.h"
#include "Sched.h"
#include "Sched_Config.h"
#include "dSTK.h"


void fun1(void);
void fun2(void);
Task_t AppTask1 = {&fun1,200};
Task_t AppTask2 = {&fun2,400};
void fun1(void){
	u8 i=0;
	i++;
}
void fun2(void){
	u8 i=250;
	i--;
}

void main(void)
{
	Sched_Init();
	Sched_Start();

  while (1)
    {
    }
}


