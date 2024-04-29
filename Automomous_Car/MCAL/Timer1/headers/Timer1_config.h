#ifndef TIMER1_CONFIG_H
#define TIMER1_CONFIG_H

//PRESCALER INIT
#define Timer1_Pres							Timer1_Pres8

//WAVE GENERATION MODE INIT
#define Timer1_WGM							/*WGM_PWM_Fast_OCR1A*/WGM_Normal

//COMPARE OUTPUT MODES INIT
#define Timer1_COM1A						COM_Normal
#define Timer1_COM1B						COM_Clear

//INPUT CAPTURE EDGE SELECT INIT
#define ICES1								Rising

//FORCE OUTPUT COMPARE INIT
#define FOC1A								Disable
#define FOC1B								Disable

//INTERRUPTS INIT
#define TICIE1								Enable
#define OCIE1A								Disable
#define OCIE1B								Disable
#define TOIE1								Enable

#endif