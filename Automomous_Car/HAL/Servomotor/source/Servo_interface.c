#include "../headers/Servo_interface.h"

//SETTING SERVO SIGNAL PIN DIRECTION AS OUTPUT AND VALUE TO LOW
void Servo_voidInit(void)
{
	DIO_enuSetPinDirection(Servo_Signal_PORT,Servo_Signal_PIN,DIO_u8PIN_OUTPUT);
	DIO_enuSetPinValue(Servo_Signal_PORT,Servo_Signal_PIN,DIO_u8PIN_LOW);
}

//SETTING ROTATION ANGLE OF THE SERVO (0,90,180) WHERE 90 IS THE STEADY STATE
//THE ROTATION DEPENDS UPON THE FREQUENCY, PRESCALER OF TIMER1, AND THE DUTY RATIO
//ALSO WAVE GENERATION MODE SHOULD BE RESETTED TO FAST PWM WITH OCR1A REGISTER TOP
void Servo_voidRotation(uint8 Copy_u8Angle)
{
	Timer1_voidSetWGM(WGM_PWM_Fast_OCR1A);
	Timer1_voidOCR1ASet(Timer1_u16SetFreq(50,8));
	switch(Copy_u8Angle)
	{
		case 0: Timer1_voidOCR1BSet(Timer1_u16SetDutyRatio(0.1));break;
		case 90: Timer1_voidOCR1BSet(Timer1_u16SetDutyRatio(0.07499));break;
		case 180: Timer1_voidOCR1BSet(Timer1_u16SetDutyRatio(0.049));break;
	}
	_delay_ms(1000);
}