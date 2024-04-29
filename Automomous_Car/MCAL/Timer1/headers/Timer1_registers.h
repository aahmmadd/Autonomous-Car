#ifndef TIMER1_REGISTERS_H
#define TIMER1_REGISTERS_H


/*-------TIMER0 REGISTERS ADDRESSES-------*/



#define TIMSK					(*(volatile uint8 *)(0X59))
#define TIFR					(*(volatile uint8 *)(0X58))
#define TCCR1A					(*(volatile uint8 *)(0X4F))
#define TCCR1B					(*(volatile uint8 *)(0X4E))
#define TCNT1H					(*(volatile uint8 *)(0X4D))
#define TCNT1L					(*(volatile uint8 *)(0X4C))
#define OCR1AH					(*(volatile uint8 *)(0X4B))
#define OCR1AL					(*(volatile uint8 *)(0X4A))
#define OCR1BH					(*(volatile uint8 *)(0X49))
#define OCR1BL					(*(volatile uint8 *)(0X48))
#define ICR1H					(*(volatile uint8 *)(0X47))
#define ICR1L					(*(volatile uint8 *)(0X46))


#endif