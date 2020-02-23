/*
 * dGPIO.h
 *
 *  Created on: Feb 8, 2020
 *      Author: FatmaGomaa
 */

#ifndef DGPIO_H_
#define DGPIO_H_

#define PORT_A		                            ((volatile PORT_REGISTERS*)0x40010800)
#define PORT_B		                            ((volatile PORT_REGISTERS*)0x40010C00)
#define PORT_C		                            ((volatile PORT_REGISTERS*)0x40011000)

#define PIN_0									0
#define PIN_1									1
#define PIN_2									2
#define PIN_3									3
#define PIN_4									4
#define PIN_5									5
#define PIN_6									6
#define PIN_7									7
#define PIN_8									8
#define PIN_9									9
#define PIN_10									10
#define PIN_11									11
#define PIN_12									12
#define PIN_13									13
#define PIN_14									14
#define PIN_15									15



typedef enum{
	INPUT_ANALOG_MODE							=0B0000,
	INPUT_FLOATING_MODE							=0B0100,
	INPUT_PULLUP_PULLDOWN_MODE					=0B1000,

	OUTPUT_GP_PUSH_PULL_10MHZ					=0B0001,
	OUTPUT_GP_PUSH_PULL_2MHZ					=0B0010,
	OUTPUT_GP_PUSH_PULL_50MHZ					=0B0011,

	OUTPUT_GP_OPEN_DRAIN_10MHZ                  =0B0101,
	OUTPUT_GP_OPEN_DRAIN_2MHZ                   =0B0110,
	OUTPUT_GP_OPEN_DRAIN_50MHZ                  =0B0111,

	OUTPUT_AF_PUSH_PULL_10MHZ                   =0B1001,
	OUTPUT_AF_PUSH_PULL_2MHZ                    =0B1010,
	OUTPUT_AF_PUSH_PULL_50MHZ                   =0B1011,

	OUTPUT_AF_OPEN_DRAIN_10MHZ                  =0B1101,
	OUTPUT_AF_OPEN_DRAIN_2MHZ                   =0B1110,
	OUTPUT_AF_OPEN_DRAIN_50MHZ                  =0B1111,

}GPIO_PIN_MOOD;


typedef struct{
	u32 GPIO_CRL;
	u32 GIPO_CRH;
	u32 GPIO_IDR;
	u32 GIPO_ODR;
	u32 GPIO_BSRR;
	u32 GIPO_BRR;
	u32 GIPO_LCKR;
}PORT_REGISTERS;

typedef struct{
	volatile PORT_REGISTERS* PORT;
	u32 PIN;
	u32 MOOD;

}GPIO_t;

typedef enum{
	LOW = 0,
	HIGH =1
}PIN_STATE;

/*The function takes a pointer to structure, the structure has
 * 3 main elements that the user chooses
 * 1. PORT in range PORT_A, PORT_B, PORT_C
 * 2. PIN in range PIN_0 .... PIN_15
 * 3. MOOD in range INPUT_X to OUTPUT_X
 *
 * and it returns Standard error whether the function did it job or failed*/
STD_ERROR GPIO_STD_ERROR_Config(GPIO_t * GPIO_Config);

/*The function takes a pointer to structure and output value to be written on the pin, the structure has
 * 3 main elements that the user chooses
 * 1. PORT in range PORT_A, PORT_B, PORT_C
 * 2. PIN in range PIN_0 .... PIN_15
 * 3. MOOD in range INPUT_X to OUTPUT_X
 * and it returns Standard error whether the function did it job or failed*/
STD_ERROR GPIO_STD_ERROR_writePin(GPIO_t * GPIO_Config, u8 OutputValue);

/*The function takes a pointer to the Port and output value to be written on the port.
 * the port has the following options:
 * PORT_X and X in range [A,B,C]
 * and it returns Standard error whether the function did it job or failed*/
STD_ERROR GPIO_STD_ERROR_writePort(PORT_REGISTERS * PORT, u8 OutputValue);

/*The function returns the value of the input pin*/
u8 GPIO_u8getPinValue(GPIO_t * GPIO_Config);

#endif /* DGPIO_H_ */


