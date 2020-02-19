
#include "dRCC.h"
#include "STD_TYPES.h"

#define RCC_BASE_ADDRESS		0x40021000
#define	RCC_CR					*((volatile u32*)(RCC_BASE_ADDRESS + 0X00))
#define	RCC_CFGR				*((volatile u32*)(RCC_BASE_ADDRESS + 0X04))
#define	RCC_CIR					*((volatile u32*)(RCC_BASE_ADDRESS + 0X08))
#define	RCC_APB2RSTR			*((volatile u32*)(RCC_BASE_ADDRESS + 0X0C))
#define	RCC_APB1RSTR			*((volatile u32*)(RCC_BASE_ADDRESS + 0X10))
#define	RCC_AHBENR				*((volatile u32*)(RCC_BASE_ADDRESS + 0X14))
#define	RCC_APB2ENR				*((volatile u32*)(RCC_BASE_ADDRESS + 0X18))
#define	RCC_APB1ENR				*((volatile u32*)(RCC_BASE_ADDRESS + 0X1C))
#define	RCC_BDCR				*((volatile u32*)(RCC_BASE_ADDRESS + 0X20))
#define	RCC_CSR					*((volatile u32*)(RCC_BASE_ADDRESS + 0X24))

/*these values will be each clock type MASK*/
#define RCC_CR_HSI_ON_MASK					0x00000001
#define RCC_CR_HSI_RDY_MASK					0x00000002
#define RCC_CR_HSITRIM_MASK					0x000000F8
#define RCC_CR_HSE_ON_MASK					0x00010000
#define RCC_CR_HSE_RDY_MASK					0x00020000
#define RCC_CR_HSE_BYP_MASK					0x00040000
#define RCC_CR_CSS_ON_MASK					0x00080000
#define RCC_CR_PLL_ON_MASK					0x01000000
#define RCC_CR_PLL_RDY_MASK					0x02000000

#define RCC_CFGR_SW_MASK		    		0X00000003
#define RCC_CFGR_SW_CLEAR_MASK		    	0XFFFFFFFC
#define RCC_CFGR_SWS_MASK		    		0X0000000C
#define RCC_CFGR_HPRE_MASK		    		0X000000F0
#define RCC_CFGR_HPRE_CLEAR_MASK		    0XFFFFFF0F
#define RCC_CFGR_PPRE1_MASK		    		0X00000700
#define RCC_CFGR_PPRE1_CLEAR_MASK		    0XFFFFF8FF
#define RCC_CFGR_PPRE2_MASK		    		0X00003800
#define RCC_CFGR_PPRE2_CLEAR_MASK		    0XFFFFC7FF
#define RCC_CFGR_ADCPRE_MASK		    	0X0000C000
#define RCC_CFGR_ADCPRE_CLEAR_MASK		    0XFFFF3FFF
#define RCC_CR_PLL_SRC_MASK					0x00010000
#define RCC_CR_PLL_XTPRE_MASK				0x00020000
#define RCC_CR_PLL_MUL_MASK					0x003C0000
#define RCC_CR_PLL_MUL_CLEAR_MASK			0xFFC3FFFF
#define RCC_CR_USB_PRE_MASK					0x00400000
#define RCC_CR_PLL_MCO_MASK					0x07000000
#define RCC_CR_PLL_MCO_CLEAR_MASK			0xF8FFFFFF

/*RCC_stdErrorControlClock enables one of the three clocks based on the user input, which is one of the following:
 * RCC_CR_HSI_ON_MASK			RCC_CR_HSE_ON_MASK				RCC_CR_PLL_ON_MASK
 * returns status of the operation whether it's ok or not*/
STD_ERROR RCC_stdErrorControlClock(u8 copy_u8ClockType, u8 copy_u8ClockStatus){
	STD_ERROR ControlClockReturn = NOT_OK;
	switch(copy_u8ClockType){
	case HSI_ON:
			if(copy_u8ClockStatus == ON){
				RCC_CR |= RCC_CR_HSI_ON_MASK;
				while(!(RCC_CR & RCC_CR_HSI_RDY_MASK));
					return OK;

			}else if(copy_u8ClockStatus == OFF) {
				RCC_CR &=~ RCC_CR_HSI_ON_MASK;
				while((RCC_CR & RCC_CR_HSI_RDY_MASK));
					return OK;
			}
		break;
	case HSE_ON:
		if(copy_u8ClockStatus == ON){
			RCC_CR |= RCC_CR_HSE_ON_MASK;
			while( !(RCC_CR & RCC_CR_HSE_RDY_MASK) );
			return OK;
		}else{
			RCC_CR &=~ RCC_CR_HSE_ON_MASK;
			while( (RCC_CR & RCC_CR_HSE_RDY_MASK) );
			return OK;
		}
		break;
	case PLL_ON:
		if(copy_u8ClockStatus == ON){
			RCC_CR |= RCC_CR_PLL_ON_MASK;
			while( !(RCC_CR & RCC_CR_PLL_RDY_MASK) );
			return OK;
		}else{
			RCC_CR &=~ RCC_CR_PLL_ON_MASK;
			while( (RCC_CR & RCC_CR_PLL_RDY_MASK) );
			return OK;
		}
		break;

	}
	return NOT_OK;
}


/*RCC_stdErrorSetSYSClock selects the system clock
 * {for HSI -> HSI_SW,  for HSE -> HSE_SW,  for PLL -> PLL_SW}
 * */
STD_ERROR RCC_stdErrorSetSYSClock(u8 copy_u8SystemClock){
	STD_ERROR ControlClockReturn = NOT_OK;
	u8 local_temp = RCC_CFGR;
	local_temp &=RCC_CFGR_SW_CLEAR_MASK;
	local_temp |= copy_u8SystemClock;
	RCC_CFGR = local_temp;
	if( (RCC_CFGR & RCC_CFGR_SW_MASK)  ==  copy_u8SystemClock){
		return OK;
	}
	return NOT_OK;
}

/*RCC_stdErrorGetSYSClock returns the selected system clock*/
STD_ERROR RCC_stdErrorGetSYSClock(u8 *copy_u8SystemClock){
	STD_ERROR ControlClockReturn = NOT_OK;
	*copy_u8SystemClock = (u8)(RCC_CFGR & RCC_CFGR_SW_MASK);
	if(*copy_u8SystemClock == (RCC_CFGR & RCC_CFGR_SW_MASK) ){
		trace_printf("%d         hi",*copy_u8SystemClock);
		return OK;
	}
	return NOT_OK;
}

/*RCC_stdErrorConfigPLL takes one of the following values for
 * first argument:
 * RCC_stdErrorSetPLLSRC chooses the clock for PLL entry. The inputs are:
 * PLLSRC_HSI_DIVIDED_BY_2
 * PLLSRC_HSE
 * PLLSRC_HSE_DIVIDED_BY_2
 *
 * second argument:
 *PLL_INPUT_CLOCK_X_2, PLL_INPUT_CLOCK_X_3, PLL_INPUT_CLOCK_X_4,PLL_INPUT_CLOCK_X_5, PLL_INPUT_CLOCK_X_6
PLL_INPUT_CLOCK_X_7, PLL_INPUT_CLOCK_X_8, PLL_INPUT_CLOCK_X_9, PLL_INPUT_CLOCK_X_10, PLL_INPUT_CLOCK_X_11
PLL_INPUT_CLOCK_X_12, PLL_INPUT_CLOCK_X_13, PLL_INPUT_CLOCK_X_14, PLL_INPUT_CLOCK_X_15, PLL_INPUT_CLOCK_X_16
PLL_INPUT_CLOCK_X_16 */

STD_ERROR RCC_stdErrorConfigPLL(u8 copy_u8PLLClockSource, u32 copy_u8PLLMultiplicationFactor){
	STD_ERROR ControlClockReturn = NOT_OK;
	u32 local_temp;

	switch(copy_u8PLLClockSource){
	case PLLSRC_HSI_DIVIDED_BY_2:
		RCC_CFGR &=~ RCC_CR_PLL_SRC_MASK;
		local_temp = RCC_CFGR;
		local_temp &= RCC_CR_PLL_MUL_CLEAR_MASK;
		local_temp |= (copy_u8PLLMultiplicationFactor);
		RCC_CFGR = local_temp;
		//if((RCC_CFGR & RCC_CR_PLL_MUL_MASK) == (copy_u8PLLMultiplicationFactor)){
			   trace_printf("PLL Configured with %d \n", copy_u8PLLMultiplicationFactor);
			return OK;
		//}

		break;
	case PLLSRC_HSE:
		RCC_CFGR |= RCC_CR_PLL_SRC_MASK;
		local_temp = RCC_CFGR;
		local_temp &=RCC_CR_PLL_MUL_CLEAR_MASK;
		local_temp |= copy_u8PLLMultiplicationFactor;
		RCC_CFGR = local_temp;
		if((RCC_CFGR & RCC_CR_PLL_MUL_MASK) == copy_u8PLLMultiplicationFactor){
			return OK;
		}
		break;
	case PLLSRC_HSE_DIVIDED_BY_2:
		RCC_CFGR |= RCC_CR_PLL_XTPRE_MASK;
		RCC_CFGR |= RCC_CR_PLL_SRC_MASK;
		local_temp = RCC_CFGR;
		local_temp &=RCC_CR_PLL_MUL_CLEAR_MASK;
		local_temp |= copy_u8PLLMultiplicationFactor;
		RCC_CFGR = local_temp;
		if((RCC_CFGR & RCC_CR_PLL_MUL_MASK) == copy_u8PLLMultiplicationFactor){
			return OK;
		}
		break;

	}
	return NOT_OK;
}

STD_ERROR RCC_stdErrorControlPerihperal(u8 copy_u8Bus, u32 copy_u32Peripheral, u8 status){
	switch(copy_u8Bus){
	case AHP:
	break;
	case APB1:
	break;
	case APB2:
		if(status == ON){
		RCC_APB2ENR |= copy_u32Peripheral;
		}else if(status == OFF){
		RCC_APB2ENR &=~ copy_u32Peripheral;
		}
	break;
	}


}

