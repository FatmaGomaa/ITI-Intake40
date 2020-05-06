/*
 * Timer.h
 *
 *  Created on: Apr 29, 2020
 *      Author: FatmaGomaa
 */

#ifndef TIMER_H_
#define TIMER_H_

#define TIMER_WAVEFORM_NORMAL				    0b00000000
#define TIMER_WAVEFORM_PWM_PHASE_CORRECT		0b01000000
#define TIMER_WAVEFORM_CTC				        0b00001000
#define TIMER_WAVEFORM_FAST_PWM			        0b01001000
/*for None PWM*/
#define TIMER_COMPARE_MODE_NORMAL			    0b00000000
#define TIMER_COMPARE_MODE_OC0_TOGGLE		    0b00010000
#define TIMER_COMPARE_MODE_OC0_CLEAR		    0b00100000
#define TIMER_COMPARE_MODE_OC0_SET			    0b00110000
/*for compare output mode, fast pwm mode*/
/*for compare output mode, phase correct pwm mode*/
#define TIMER_COMPARE_MODE_NON_INVERTING		0b00100000
#define TIMER_COMPARE_MODE_INVERTING			0b00110000

#define TIMER_NO_CLOCK				0x00
#define TIMER_CLOCK_OVER_1			0x01
#define TIMER_CLOCK_OVER_8			0x02
#define TIMER_CLOCK_OVER_64			0x03
#define TIMER_CLOCK_OVER_256		0x04
#define TIMER_CLOCK_OVER_1024		0x05
#define TIMER_CLOCK_EXT_FALLING		0x06
#define TIMER_CLOCK_EXT_RISING		0x07

#define TIMER0_PRELOAD_VALUE				26
#define TIMER0_COMPARE_MATCH_VALUE			50
#define TIMER0_NUM_OF_OVERFLOWS				4000

#define TIMER0_PRESCALER_VALUE				TIMER_CLOCK_OVER_8
#define TIMER0_WAVEFORM_MODE				TIMER_WAVEFORM_PWM_PHASE_CORRECT
#define TIER0_COMPARE_MODE					TIMER_COMPARE_MODE_NON_INVERTING

void Timer_Init(void);
void Timer_SetCallBack(void(*CBF)(void));
void Timer_Start(void);
void Timer_Stop(void);

#endif /* TIMER_H_ */
