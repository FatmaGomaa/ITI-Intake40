#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GlobalINT_Interface.h"
#include "GlobalINT_Config.h"
#include "GlobalINT_Private.h"
#include "GlobalINT_Register.h"


void INT_voidEnableGlobalInterrupt(void){
	SET_BIT(SREG,SREG_I);
}
void INT_voidDisableGlobalInterrupt(void){
	CLEAR_BIT(SREG,SREG_I);
}
