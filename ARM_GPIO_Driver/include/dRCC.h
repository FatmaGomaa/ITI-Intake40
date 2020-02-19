

#ifndef DRCC_H_
#define DRCC_H_

#include "STD_TYPES.h"

#define HSI_SW           	        0b00
#define HSE_SW			 	        0b01
#define PLL_SW				        0b10

#define SYSCLK_DIVIDED_BY_2         0b1000
#define SYSCLK_DIVIDED_BY_4         0b1001
#define SYSCLK_DIVIDED_BY_8         0b1010
#define SYSCLK_DIVIDED_BY_16        0b1011
#define SYSCLK_DIVIDED_BY_64        0b1100
#define SYSCLK_DIVIDED_BY_128       0b1101
#define SYSCLK_DIVIDED_BY_256       0b1110
#define SYSCLK_DIVIDED_BY_512       0b1111

#define HCLK_DIVIDED_BY_2           0b100
#define HCLK_DIVIDED_BY_4           0b101
#define HCLK_DIVIDED_BY_8           0b110
#define HCLK_DIVIDED_BY_16          0b111

#define HCLK_DIVIDED_BY_2           0b100
#define HCLK_DIVIDED_BY_4           0b101
#define HCLK_DIVIDED_BY_8           0b110
#define HCLK_DIVIDED_BY_16          0b111

#define  PLL_INPUT_CLOCK_X_2      0x00000000
#define  PLL_INPUT_CLOCK_X_3      0x00040000
#define  PLL_INPUT_CLOCK_X_4      0x00080000
#define  PLL_INPUT_CLOCK_X_5      0x000C0000
#define  PLL_INPUT_CLOCK_X_6      0x00100000
#define  PLL_INPUT_CLOCK_X_7      0x00140000
#define  PLL_INPUT_CLOCK_X_8      0x00180000
#define  PLL_INPUT_CLOCK_X_9      0x001C0000
#define  PLL_INPUT_CLOCK_X_10     0x00200000
#define  PLL_INPUT_CLOCK_X_11     0x00240000
#define  PLL_INPUT_CLOCK_X_12     0x00280000
#define  PLL_INPUT_CLOCK_X_13     0x002C0000
#define  PLL_INPUT_CLOCK_X_14     0x00300000
#define  PLL_INPUT_CLOCK_X_15     0x00340000
#define  PLL_INPUT_CLOCK_X_16     0x00380000

#define PCLK2_DIVIDED_BY_2         0b00
#define PCLK2_DIVIDED_BY_4         0b01
#define PCLK2_DIVIDED_BY_6         0b10
#define PCLK2_DIVIDED_BY_8         0b11

#define MCOSRC_SYSTEMCLK           0b100
#define MCOSRC_HSI                 0b101
#define MCOSRC_HSE                 0b110
#define MCOSRC_PLL_DIVIDED_BY_2    0b111

#define PLL_CLOCK_DIVIDED_BY_ONE_AND_HALF	0b0
#define PLL_CLOCK_NOT_DIVIDED				0b1

#define RCC_APB2_CLOCK_PORT_A		0X00000004
#define RCC_APB2_CLOCK_PORT_B		0X00000008
#define RCC_APB2_CLOCK_PORT_C		0X00000010




typedef enum{
HSI_ON,
HSE_ON,
PLL_ON
}CLOCK_TYPE;

typedef enum{
ON,
OFF
}CLOCK_STATUS;

typedef enum{
PLLSRC_HSI_DIVIDED_BY_2,
PLLSRC_HSE,
PLLSRC_HSE_DIVIDED_BY_2
}PLL_SRC;

typedef enum {
	AHP,
	APB1,
	APB2
}BUS;

/*RCC_stdErrorControlClock enables or disables one of the three clocks based on the user input, which is one of the following:
 * first argument is an object of the CLOCK_TYPE enum with one of the following values:  HSI_ON			HSE_ON			PLL_ON
 * second argument is an object of the CLOCK_STATUS enum with one of the following values: ON				OFF
 * returns status of the operation whether it's ok or not*/
STD_ERROR RCC_stdErrorControlClock(u8 copy_u8ClockType, u8 copy_u8ClockStatus);

/*RCC_stdErrorSetSYSClock selects the system clock
 * {for HSI -> HSI_SW,  for HSE -> HSE_SW,  for PLL -> PLL_SW} */
STD_ERROR RCC_stdErrorSetSYSClock(u8 copy_u8SystemClock);

/*RCC_stdErrorGetSYSClock returns the selected system clock*/
STD_ERROR RCC_stdErrorGetSYSClock(u8 *copy_u8SystemClock);

/*RCC_stdErrorConfigPLL takes one of the following values for
 * first argument:
 * RCC_stdErrorSetPLLSRC chooses the clock for PLL entry. The inputs are:
 * PLLSRC_HSI_DIVIDED_BY_2
 * PLLSRC_HSE
 * PLLSRC_HSE_DIVIDED_BY_2
 *
 * second argument:
 *PLL_INPUT_CLOCK_X_N -and N is from 2 to 16 which is the value of PLL Multiplication- */
STD_ERROR RCC_stdErrorConfigPLL(u8 copy_u8PLLClockSource, u32 copy_u8PLLMultiplicationFactor);

/*RCC_stdErrorControlPerihperal enables the clock on the selected peripheral
 * the first argument is one of the following: AHP, APB1, APB2
 * the second argument is the peripheral to be selected
 * RCC_APB2_CLOCK_PORT_X -and X is one of the following A,B,C-
 * the third argument is the status of the Clock: ON or OFF*/
STD_ERROR RCC_stdErrorControlPerihperal(u8 copy_u8Bus, u32 copy_u32Peripheral, u8 status);

/**********************************Not Implemented Yet*********************************************/
/*RCC_stdErrorEnableHSEBYP enables the Bypass feature of the HSE Clock and returns status of the operation whether it's ok or not*/
STD_ERROR RCC_stdErrorEnableHSEBYP(void);

/*RCC_stdErrorEnableCSSON enables Clock security system and returns status of the operation whether it's ok or not*/
STD_ERROR RCC_stdErrorEnableCSSON(void);

/*RCC_stdErrorSetHSITRIMValue sets the value of the Trimming Value of the HSI and
 *The trimming step (Fhsitrim) is around 40 kHz between two consecutive HSICAL steps and The default value is 16.*/
STD_ERROR RCC_stdErrorSetHSITRIMValue(u8 copy_u8TrimValue);

/*RCC_stdErrorSetAHBPrescaler takes one of the following inputs
 *  {SYSCLK_DIVIDED_BY_2, SYSCLK_DIVIDED_BY_4, SYSCLK_DIVIDED_BY_8, SYSCLK_DIVIDED_BY_16, SYSCLK_DIVIDED_BY_64
	SYSCLK_DIVIDED_BY_128, SYSCLK_DIVIDED_BY_256, SYSCLK_DIVIDED_BY_512 } */
STD_ERROR RCC_stdErrorSetAHBPrescaler(u8 copy_u8PrescalerValue);

/*RCC_stdErrorSetAPB1Prescaler takes one of the following inputs
 * {HCLK_DIVIDED_BY_2, HCLK_DIVIDED_BY_4, HCLK_DIVIDED_BY_8, HCLK_DIVIDED_BY_16}*/
STD_ERROR RCC_stdErrorSetAPB1Prescaler(u8 copy_u8PrescalerValue);


/*RCC_stdErrorSetAPB1Prescaler takes one of the following inputs
 *{HCLK_DIVIDED_BY_2, HCLK_DIVIDED_BY_4, HCLK_DIVIDED_BY_8, HCLK_DIVIDED_BY_16}*/
STD_ERROR RCC_stdErrorSetAPB2Prescaler(u8 copy_u8PrescalerValue);

/*RCC_stdErrorSetADCPRE selects the ADC pre-scaler Value of one of the following inputs
PCLK2_DIVIDED_BY_2, PCLK2_DIVIDED_BY_4, PCLK2_DIVIDED_BY_6, PCLK2_DIVIDED_BY_8 */
STD_ERROR RCC_stdErrorSetADCPRE(u8 copy_u8ADCPreScaler);

/*RCC_stdErrorSetMCO provide clock for other source on that pin and it's provided by one of the following clock sources
MCOSRC_SYSTEMCLK, MCOSRC_HSI, MCOSRC_HSE, MCOSRC_PLL_DIVIDED_BY_2
*/
STD_ERROR RCC_stdErrorSetMCO(u8 copy_u8MCOClockOutput);

/* RCC_stdErrorSetUSBPRE sets the USB prescaler value
PLL_CLOCK_DIVIDED_BY_ONE_AND_HALF, PLL_CLOCK_NOT_DIVIDED
*/
STD_ERROR RCC_stdErrorSetUSBPRE(u8 copy_u8USBPrescaler);

#endif /* DRCC_H_ */
