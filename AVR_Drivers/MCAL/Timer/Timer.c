/*
 * Timer.c
 *
 *  Created on: Apr 29, 2020
 *      Author: FatmaGomaa
 */

#include "STD_TYPES.h"
#include "Timer.h"

#define SREG 				*((volatile u8*)(0x5F))
#define TCCR0 				*((volatile u8*)(0x53))
#define TCNT0 				*((volatile u8*)(0x52))
#define TIMSK 				*((volatile u8*)(0x59))
#define OCR0 				*((volatile u8*)(0x5C))

#define TCCR0_FOC0					0b10000000
#define TCCR0_WGM_M					0b01001000
#define TCCR0_WGM_CLR_M				0b10110111
#define TCCR0_COM_M					0b00110000
#define TCCR0_COM_CLR_M				0b11001111
#define TCCR0_CS_M					0b00000111
#define TCCR0_CS_CLR_M				0b11111000

#define TIMSK_OCIE2					0b10000000
#define TIMSK_TOIE2					0b01000000
#define TIMSK_TICIE1				0b00100000
#define TIMSK_OCIE1A				0b00010000
#define TIMSK_OCIE1B				0b00001000
#define TIMSK_TOIE1					0b00000100
#define TIMSK_OCIE0					0b00000010
#define TIMSK_TOIE0					0b00000001

#define TIFR_OCF2                  0b10000000
#define TIFR_TOV2                  0b01000000
#define TIFR_ICF1                  0b00100000
#define TIFR_OCF1A                 0b00010000
#define TIFR_OCF1B                 0b00001000
#define TIFR_TOV1                  0b00000100
#define TIFR_OCF0                  0b00000010
#define TIFR_TOV0                  0b00000001

#define ENABLED_INTERRUPTS		   0x00

/*Timer 1 Masks*/
#define TCCR1A_COM1A_M						0b11000000
#define TCCR1A_COM1A_CLR_M					0b00111111
#define TCCR1A_COM1B_M						0b00110000
#define TCCR1A_COM1B_CLR_M					0b11001111
#define TCCR1A_FOC1A						0b00001000
#define TCCR1A_FOC1B						0b00000100
#define TCCR1A_WGM_M						0b00000011
#define TCCR1A_WGM_CLR_M					0b11111100

#define WGM1011_NORMAL							0b00000000
#define WGM1011_PHASE_CORRECT_8					0b00000001
#define WGM1011_PHASE_CORRECT_9					0b00000010
#define WGM1011_PHASE_CORRECT_10				0b00000011
#define WGM1011_CTC								0b00000000
#define WGM1011_FAST_PWM_8						0b00000001
#define WGM1011_FAST_PWM_9						0b00000010
#define WGM1011_FAST_PWM_10						0b00000011
#define WGM1011_PHASE_CORRECT_MODE_8			0b00000000
#define WGM1011_PHASE_CORRECT_MODE_9			0b00000001
#define WGM1011_PHASE_CORRECT_MODE_10			0b00000010
#define WGM1011_PHASE_CORRECT_MODE_11			0b00000011
#define WGM1011_CTC_MODE_12						0b00000000
#define WGM1011_FAST_PWM_MODE_14				0b00000010
#define WGM1011_FAST_PWM_MODE_15				0b00000011

#define WGM1213_NORMAL							0b00000000
#define WGM1213_PHASE_CORRECT_8					0b00000000
#define WGM1213_PHASE_CORRECT_9					0b00000000
#define WGM1213_PHASE_CORRECT_10				0b00000000
#define WGM1213_CTC								0b00001000
#define WGM1213_FAST_PWM_8						0b00001000
#define WGM1213_FAST_PWM_9						0b00001000
#define WGM1213_FAST_PWM_10						0b00001000
#define WGM1213_PHASE_CORRECT_MODE_8			0b00010000
#define WGM1213_PHASE_CORRECT_MODE_9			0b00010000
#define WGM1213_PHASE_CORRECT_MODE_10			0b00010000
#define WGM1213_PHASE_CORRECT_MODE_11			0b00010000
#define WGM1213_CTC_MODE_12						0b00011000
#define WGM1213_FAST_PWM_MODE_14				0b00011000
#define WGM1213_FAST_PWM_MODE_15				0b00011000



static void(*Timer_CBF)(void) = NULL;

void Timer_Init(void){
	u8 RegTemp=0;
	/*Timer Normal Mode*/
	RegTemp = TIMER0_WAVEFORM_MODE | TIER0_COMPARE_MODE ;
	TCCR0 = RegTemp;

#if TIMER0_WAVEFORM_MODE != TIMER_WAVEFORM_NORMAL
	OCR0 = TIMER0_COMPARE_MATCH_VALUE;
#elif TIMER0_WAVEFORM_MODE == TIMER_WAVEFORM_NORMAL
	/*Set Timer Counter to Preload Value*/
	TCNT0 = TIMER0_PRELOAD_VALUE;
#endif
	/*Enable OVF Interrupt*/
	TIMSK |= ENABLED_INTERRUPTS;

	/*Enable Global Interrupt*/
	SREG |= 0x80;
}

void Timer_Start(void){
	u8 RegTemp = TCCR0;
	/*Set prescaler Value */
	RegTemp &= TCCR0_CS_CLR_M;
	RegTemp	|= TIMER0_PRESCALER_VALUE;
	TCCR0 = RegTemp;
}

void Timer_Stop(void){
	/*clear prescaler Value */
	TCCR0 &= TCCR0_CS_CLR_M;
}

void Timer_SetCallBack(void(*CBF)(void)){
	if(CBF){
		Timer_CBF = CBF;
	}
}

void __vector_11(void) __attribute__((signal));
void __vector_11(void){

#if TIMER0_WAVEFORM_MODE == TIMER_WAVEFORM_NORMAL
	static u16 Counter=0;
	Counter++;
	if(Counter == TIMER0_NUM_OF_OVERFLOWS){
		TCNT0 = 0;
		Counter = 0;
		if(Timer_CBF){
			Timer_CBF();
		}
	}
#endif

}
