#ifndef TIMER1_INTERFACE_H
#define TIMER1_INTERFACE_H

#include "Timer1_priv.h"
#include "Timer1_config.h"


//CALL BACK FUNCS
void Timer1_CallBackFunCAPT(volatile void (*ptr)(void));
void Timer1_CallBackFunCOMP1A(volatile void (*ptr)(void));
void Timer1_CallBackFunCOMP1B(volatile void (*ptr)(void));
void Timer1_CallBackFunOVF(volatile void (*ptr)(void));

//INIT FUNCS
void Timer1_voidInit(void);

//PRESCALER SET FUNC
void Timer1_voidSetPres(uint8 pres);

//WGM SET FUNC
void Timer1_voidSetWGM(uint8 WGM);

//COM1A SET FUNC
void Timer1_voidSetCOM1A(uint8 COM1A);

//COM1B SET FUNC
void Timer1_voidSetCOM1B(uint8 COM1B);

//WRITING TO 16 BIT REGISTERS
void Timer1_voidTCNT1Set(uint16 TCNT1_value);
void Timer1_voidOCR1ASet(uint16 OCR1A_value);
void Timer1_voidOCR1BSet(uint16 OCR1B_value);
void Timer1_voidICR1Set(uint16 ICR1_value);

//READING FROM 16 BIT REGISTERS
uint16 Timer1_u16TCNT1Get(void);
uint16 Timer1_u16OCR1AGet(void);
uint16 Timer1_u16OCR1BGet(void);
uint16 Timer1_u16ICR1Get(void);

//ENABLING AND DISABLING INTERRUPTS
void Timer1_voidTICIE1Set(uint8 TICIE1_value);
void Timer1_voidTOIE1Set(uint8 TOIE1_value);
void Timer1_voidICES1Set(uint8 ICES1_value);

//SETTING FREQUENCY
uint16 Timer1_u16SetFreq(uint8 freq, uint8 pres);

//SETTING DUTY RATIO
uint16 Timer1_u16SetDutyRatio(f32 ratio);


#endif