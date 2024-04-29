#ifndef TIMER1_PRIV_H
#define TIMER1_PRIV_H


#include "Timer1_registers.h"
#include "../../DIO/headers/DIO_interface.h"
#include "Interrupt_vectable.h"

/*-------TIMER1_PRES_VALUES-------*/

#define Timer1_Stop							0
#define Timer1_NoPres						1
#define Timer1_Pres8						2
#define Timer1_Pres64						3
#define Timer1_Pres256						4
#define Timer1_Pres1024						5
#define Timer1_XclkFalling					6
#define Timer1_XclkRising					7


/*-------TIMER1_WGM_VALUES-------*/

#define WGM_Normal								0

#define WGM_PWM_PhaseCorrect_8					1
#define WGM_PWM_PhaseCorrect_9					2
#define WGM_PWM_PhaseCorrect_10					3

#define WGM_CTC_OCR1A							4

#define WGM_PWM_Fast_8							5
#define WGM_PWM_Fast_9							6
#define WGM_PWM_Fast_10							7

#define WGM_PWM_PhFrCorrect_ICR1				8
#define WGM_PWM_PhFrCorrect_OCR1A				9

#define WGM_PWM_PhaseCorrect_ICR1				10
#define WGM_PWM_PhaseCorrect_OCR1A				11

#define WGM_CTC_ICR1							12

//13TH DIGIT VALUE IS RESERVED					13

#define WGM_PWM_Fast_ICR1						14
#define WGM_PWM_Fast_OCR1A						15


/*-------TIMER1_COM_VALUES-------*/
#define COM_Normal								0
#define COM_Toggle								1
#define COM_Clear								2 //INVERTING
#define COM_Set									3 //NON-INVERTING

/*-------TIMER1_INTERRUPTS_AND_FOC_VALUES-------*/

#define Disable									0
#define Enable									1



/*-------TIMER1_ICES_VALUES-------*/

#define Falling									0
#define Rising									1


#endif