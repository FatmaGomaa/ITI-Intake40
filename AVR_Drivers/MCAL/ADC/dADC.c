#include "STD_TYPES.h"
#include "dADC.h"

#define	ADC_ADMUX							*((volatile u8 *)0x27   )
#define	ADC_ADCSRA      					*((volatile u8 *)0x26   )
#define	ADC_ADCL        					*((volatile u8 *)0x24   )
#define	ADC_ADCH        					*((volatile u8 *)0x25   )
#define ADC_ADC								*((volatile u16 *)0x24  )
#define	ADC_SFIOR       					*((volatile u8 *)0x50   )

#define VREFERENCE_M						0b11000000


#define ADC_MUX_M							0b00011111
#define ADC_MUX_CLEAR_M							0b11100000

#define ADC_ADPS2_M							0b00000111


#define ADC_ADCSRA_ADEN						0b10000000
#define ADC_ADCSRA_ADSC						0b01000000
#define ADC_ADCSRA_ADIF						0b00010000
#define ADC_ADCSRA_ADIE						0b00001000

#define ADJUSTMENT							ADJUST_LEFT
#define ADC_SYNCHRONOUS_TIME_OUT				1000ul

#define ADC_EIGHT_BIT_MODE					1
#define ADC_TEN_BIT_MODE					2

#define ADC_CHANNEL_IDLE						0
#define ADC_CHANNEL_BUSY						1

#define ADC_CHAIN_IDLE						0
#define ADC_CHAIN_BUSY						1

#define ADC_CONVERT_CHAIN					0
#define ADC_CONVERT_CHANNEL					0


static u16* ADC_pu16Result=NULL;
static void (*ADC_pvCallBackNotification)(void)=NULL;
static u8 ADC_u8ChannelState=ADC_CHANNEL_IDLE;
static u8 ADC_u8ChainState=ADC_CHAIN_IDLE;
static u8 ADC_u8ConversionMode=ADC_CONVERT_CHANNEL;
static u8 ADC_u8ChainLength;

ADCChain_t Global_ADCChain;

void ADC_Init(u8 ReferenceValue, u8 Prescaler, u8 Channel){
	u8 ADC_ADMUX_TEMP = ADC_ADMUX;
	u8 ADC_ADCSRA_TEMP = ADC_ADCSRA;
	//ADC_ADMUX_TEMP &= (~ (VREFERENCE_M | ADJUST_LEFT | ADC_MUX_M));
	ADC_ADMUX_TEMP=0;
	ADC_ADMUX_TEMP |= ReferenceValue | ADJUSTMENT | Channel;
	ADC_ADMUX = ADC_ADMUX_TEMP;

	ADC_ADCSRA_TEMP &=~ ADC_ADPS2_M;
	ADC_ADCSRA_TEMP = Prescaler;
	ADC_ADCSRA = ADC_ADCSRA_TEMP;
}

void ADC_Enable(void){
	/*Enable ADC */
	ADC_ADCSRA |= ADC_ADCSRA_ADEN;
}

void ADC_EnableInterrupt(void){
	 /*Enable ADC Interrupt*/
	ADC_ADCSRA |= ADC_ADCSRA_ADIE;
}

void ADC_startConversion(void){
	ADC_ADCSRA |= ADC_ADCSRA_ADSC;
}

u8 ADC_u8GetChannelReading(u8 channel){
	//u16 channelReading=0;
	u8 channelReading=0;
	ADC_startConversion();
	#if ADJUSTMENT == ADJUST_LEFT
		//channelReading = ((ADC_ADCH << 2) & (ADC_ADCL >> 6));
		//channelReading = ADC_ADC;
		while(! (ADC_ADCSRA & ADC_ADCSRA_ADIF ));
		channelReading = ADC_ADCH;
		return channelReading;
	#elif ADJUSTMENT == ADJUST_RIGHT
		//channelReading = ((ADC_ADCH << 8) & (ADC_ADCL));
		channelReading = ADC_ADC;
		return channelReading;
	#endif

}

ERROR_STATUS ADC_u8GetChannelReadingSynchronous(u8 Copy_u8Channel, u16 * Copy_u8Result){
	ERROR_STATUS Local_ErrorStatus = NOT_OK;
	u32 Local_u8Counter = 0;
	if( (Copy_u8Channel < ADC_SUPPORTED_CHANNELS_RANGE) && (Copy_u8Result != NULL) ){
		/*Choosing Channel in ADCMUX*/
		u8 ADC_ADMUX_TEMP = ADC_ADMUX;
		ADC_ADMUX_TEMP &= (ADC_MUX_CLEAR_M);
		ADC_ADMUX_TEMP |= Copy_u8Channel;
		ADC_ADMUX = ADC_ADMUX_TEMP;
		/*starting the conversion on the selected channel*/
		ADC_startConversion();

		/*polling till the conversion flag is raised*/
		while( ((ADC_ADCSRA & ADC_ADCSRA_ADIF) == 0) && (Local_u8Counter <ADC_SYNCHRONOUS_TIME_OUT) ){
			Local_u8Counter++;
		}
		if( (ADC_ADCSRA & ADC_ADCSRA_ADIF) == 1 ){
			/*Clear ADC Flag because the result is handled in the function itself*/
			ADC_ADCSRA |= ADC_ADCSRA_ADIF;
			#if ADC_READING_MODE == ADC_EIGHT_BIT_MODE
				*Copy_u8Result = ADC_ADCH;
				if(*Copy_u8Result == ADC_ADCH){
					Local_ErrorStatus = OK;
				}
			#elif ADC_READING_MODE == ADC_TEN_BIT_MODE
				*Copy_u8Result = ADC_ADC;
				if(*Copy_u8Result == ADC_ADC){
					Local_ErrorStatus = OK;
				}
			#endif

		}
	}

	return Local_ErrorStatus;
}

ERROR_STATUS ADC_u8GetChannelReadingASynchronous(u8 Copy_u8Channel, u8 * Copy_u8AsynchronousResult, void(*Copy_pvCallBackNotification)(void)){
	ERROR_STATUS Local_ErrorStatus = NOT_OK;


	if( (ADC_u8ChannelState==ADC_CHANNEL_IDLE) && (Copy_u8Channel < ADC_SUPPORTED_CHANNELS_RANGE) && (Copy_u8AsynchronousResult != NULL)  && (Copy_pvCallBackNotification != NULL) ){
		ADC_u8ConversionMode=ADC_CONVERT_CHANNEL;
		ADC_EnableInterrupt();

		ADC_u8ChannelState=ADC_CHANNEL_BUSY;

		/*Choosing Channel in ADCMUX*/
		u8 ADC_ADMUX_TEMP = ADC_ADMUX;
		ADC_ADMUX_TEMP &= (ADC_MUX_CLEAR_M);
		ADC_ADMUX_TEMP |= Copy_u8Channel;
		ADC_ADMUX = ADC_ADMUX_TEMP;

		/*starting the conversion on the selected channel*/
		ADC_startConversion();

		ADC_pu16Result = Copy_u8AsynchronousResult;
		ADC_pvCallBackNotification = Copy_pvCallBackNotification;

		Local_ErrorStatus = OK;
	}

	return Local_ErrorStatus;
}

ERROR_STATUS ADC_startChainConversionASynchronous(ADCChain_t Copy_Chain,u16* Copy_u8AsynchronousResult, void(*Copy_pvCallBackNotification)(void) ){
	ERROR_STATUS Local_ErrorStatus = NOT_OK;
	if((ADC_u8ChannelState==ADC_CHANNEL_IDLE) &&  (ADC_u8ChainState==ADC_CHAIN_IDLE) && (Copy_Chain.Cahnnels != NULL)  && (Copy_pvCallBackNotification != NULL) ){
		//TODO:Revise this added piece of code about Global_ADCChain
		Global_ADCChain = Copy_Chain;

		ADC_u8ConversionMode=ADC_CONVERT_CHAIN;
		ADC_u8ChainLength=Copy_Chain.ChainLength;

		ADC_EnableInterrupt();

		ADC_u8ChannelState=ADC_CHANNEL_BUSY;
		ADC_u8ChainState=ADC_CHAIN_BUSY;

		/*Choosing Channel in ADCMUX*/
		u8 ADC_ADMUX_TEMP = ADC_ADMUX;
		ADC_ADMUX_TEMP &= (ADC_MUX_CLEAR_M);
		ADC_ADMUX_TEMP |= Copy_Chain.Cahnnels[0];
		ADC_ADMUX = ADC_ADMUX_TEMP;

		/*starting the conversion on the selected channel*/
		ADC_startConversion();

		ADC_pu16Result = Copy_u8AsynchronousResult;
		ADC_pvCallBackNotification = Copy_pvCallBackNotification;

		Local_ErrorStatus = OK;
	}
	return Local_ErrorStatus;
}

/*ADC Coversion Complete ISR*/
void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
	static u8 Copy_u8ChannelIDX=0;

	if(ADC_u8ConversionMode=ADC_CONVERT_CHANNEL){
		#if ADC_u8_REGISTER_LENGTH == ADC_EIGHT_BIT_MODE
			/* get result */
			*ADC_pu16Result=ADCH;

		#elif ADC_u8_REGISTER_LENGTH == ADC_TEN_BIT_MODE
			/* get result */
			*ADC_pu16Result=ADC;
		#endif

			/*Make the adc state be IDLE*/
			ADC_u8ChannelState=ADC_CHANNEL_IDLE;

			/*Invoke the call back notification function*/
			ADC_pvCallBackNotification();

	}else if(ADC_u8ConversionMode=ADC_CONVERT_CHAIN){
		#if ADC_u8_REGISTER_LENGTH == ADC_EIGHT_BIT_MODE
			/* get result */
			*ADC_pu16Result[Copy_u8ChannelIDX]=ADCH;

		#elif ADC_u8_REGISTER_LENGTH == ADC_TEN_BIT_MODE
			/* get result */
			*ADC_pu16Result[Copy_u8ChannelIDX]=ADC;
		#endif
			Copy_u8ChannelIDX++;
			/*Make the adc state be IDLE*/
			ADC_u8ChannelState=ADC_CHANNEL_IDLE;

		if(Copy_u8ChannelIDX==ADC_u8ChainLength)
		{
			/*Make ADC in Idle State*/
			ADC_u8ChainState=ADC_CHAIN_IDLE;

			/*Disable ADC Conversion Complete Interrupt*/
			ADC_ADCSRA &=~ ADC_ADCSRA_ADIE;

			/*Invoke the callback notification Function*/
			ADC_pvCallBackNotification();
		}
		else
		{
		/*Choosing Channel in ADCMUX*/
		u8 ADC_ADMUX_TEMP = ADC_ADMUX;
		ADC_ADMUX_TEMP &= (ADC_MUX_CLEAR_M);
		ADC_ADMUX_TEMP |= Global_ADCChain.Cahnnels[0];
		ADC_ADMUX = ADC_ADMUX_TEMP;

		/*starting the conversion on the selected channel*/
		ADC_startConversion();
		}


	}
}

