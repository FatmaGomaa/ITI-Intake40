#ifndef		STD_TYPES_H
#define		STD_TYPES_H


#define		u8		unsigned	char
#define		s8		signed		char

#define		u16		unsigned	short	int
#define		s16		signed		short	int

#define		u32		unsigned	long	int
#define		s32		signed		long	int

#define		f32			float

#define		f64			double

#define		f96			long		double

#define HIGH								1
#define LOW									0

typedef enum{
 NOT_OK =0, OK=1
}STD_ERROR;

typedef enum{
	STATE_OK,
	STATE_NOK,
	STATE_BUSY
}ProcessState_t;

#define NULL 				((void*)0)


#endif
