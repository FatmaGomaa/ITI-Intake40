#define ADC_SUPPORTED_CHANNELS_RANGE			32

#define VREFERENCE_AREF						0b00000000
#define VREFERENCE_AVCC						0b01000000
#define VREFERENCE_INTERNAL_2_56			0b11000000

#define ADJUST_LEFT							0b00100000
#define ADJUST_RIGHT						0b00000000

#define ADC_SINGLE_ENDED_ADC0			0b00000000
#define ADC_SINGLE_ENDED_ADC1           	0b00000001
#define ADC_SINGLE_ENDED_ADC2           	0b00000010
#define ADC_SINGLE_ENDED_ADC3           	0b00000011
#define ADC_SINGLE_ENDED_ADC4           	0b00000100
#define ADC_SINGLE_ENDED_ADC5           	0b00000101
#define ADC_SINGLE_ENDED_ADC6           	0b00000110
#define ADC_SINGLE_ENDED_ADC7           	0b00000111

#define ADC_PRESCALER_2						0b00000001
#define ADC_PRESCALER_4						0b00000010
#define ADC_PRESCALER_8						0b00000011
#define ADC_PRESCALER_16					0b00000100
#define ADC_PRESCALER_32					0b00000101
#define ADC_PRESCALER_61					0b00000110
#define ADC_PRESCALER_128					0b00000111

#define ADC_READING_MODE			ADC_EIGHT_BIT_MODE

#define ADC_NUM_OF_CHAINS			2
#define ADC_NUM_OF_CHANNELS			2

typedef struct
{
		u8* Cahnnels;
		u8 ChainLength;
}ADCChain_t;

void ADC_Init(u8 ReferenceValue, u8 Prescaler, u8 Channel);
void ADC_Enable(void);
void ADC_startConversion(void);
ERROR_STATUS ADC_u8GetChannelReadingSynchronous(u8 Copy_u8Channel, u16 * Copy_u8Result);

ERROR_STATUS ADC_u8GetChannelReadingASynchronous(u8 Copy_u8Channel, u8 * Copy_u8Result, void(*Copy_pvCallBackNotification)(void));

ERROR_STATUS ADC_startChainConversionASynchronous(ADCChain_t Copy_Chain,u16* Copy_pu16Result, void(*Copy_pvCallBackNotification)(void) );

