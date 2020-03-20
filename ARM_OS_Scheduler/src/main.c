

#include "STD_TYPES.h"
#include "Sched.h"
#include "Sched_Config.h"
#include "dSTK.h"

	u8 i=200;

void fun1(void);
void fun2(void);
Task_t AppTask1 = {&fun1,200}; // third time  and  every tick
Task_t AppTask2 = {&fun2,400}; // Fifth time and every 2 ticks
void fun1(void){
	i++;
}
void fun2(void){
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


