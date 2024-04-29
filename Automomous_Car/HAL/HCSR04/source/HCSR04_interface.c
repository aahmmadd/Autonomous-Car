#include "../headers/HCSR04_interface.h"

void HCSR04_voidInit(void)
{
	DIO_enuSetPinDirection(TRIG_PORT,TRIG_PIN,DIO_u8PIN_OUTPUT);
	DIO_enuSetPinDirection(ECHO_PORT,ECHO_PIN,DIO_u8PIN_INPUT);
	
	DIO_enuSetPinValue(TRIG_PORT,TRIG_PIN,DIO_u8PIN_LOW);
	DIO_enuSetPinValue(ECHO_PORT,ECHO_PIN,DIO_u8PULL_UP);
}

void HCSR04_voidSendPulse(void)
{
	DIO_enuSetPinValue(TRIG_PORT,TRIG_PIN,DIO_u8PIN_HIGH);
	_delay_us(10);
	DIO_enuSetPinValue(TRIG_PORT,TRIG_PIN,DIO_u8PIN_LOW);
}
