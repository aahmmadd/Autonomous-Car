#include "../headers/L293D_interface.h"


/*-------INITIALIZING DRIVER PINS DIRECTIONS-------*/
void L293D_voidInit(void)
{
	
	/*-------SETTING PINS DIRECTIONS-------*/
	DIO_enuSetPinDirection(IN1_PORT,IN1_PIN,DIO_u8PIN_OUTPUT);
	DIO_enuSetPinDirection(IN2_PORT,IN2_PIN,DIO_u8PIN_OUTPUT);
	DIO_enuSetPinDirection(IN3_PORT,IN3_PIN,DIO_u8PIN_OUTPUT);
	DIO_enuSetPinDirection(IN4_PORT,IN4_PIN,DIO_u8PIN_OUTPUT);
	DIO_enuSetPinDirection(EN1_PORT,EN1_PIN,DIO_u8PIN_OUTPUT);
	DIO_enuSetPinDirection(EN2_PORT,EN2_PIN,DIO_u8PIN_OUTPUT);
	
	/*-------SETTING EN1,2-------*/
	DIO_enuSetPinValue(EN1_PORT,EN1_PIN,DIO_u8PIN_HIGH);
	DIO_enuSetPinValue(EN2_PORT,EN2_PIN,DIO_u8PIN_HIGH);
	
	/*-------DISABLING MOTORS-------*/
	
	/*-------MOTOR_A-------*/
	DIO_enuSetPinValue(IN1_PORT,IN1_PIN,DIO_u8PIN_LOW);
	DIO_enuSetPinValue(IN2_PORT,IN2_PIN,DIO_u8PIN_LOW);
	
	/*-------MOTOR_B-------*/
	DIO_enuSetPinValue(IN3_PORT,IN3_PIN,DIO_u8PIN_LOW);
	DIO_enuSetPinValue(IN4_PORT,IN4_PIN,DIO_u8PIN_LOW);

}



/*-------MOVING FORWARD-------*/
 void L293D_voidForward(void)
{
	/*-------MOTOR_A-------*/
	DIO_enuSetPinValue(IN1_PORT,IN1_PIN,DIO_u8PIN_HIGH);
	DIO_enuSetPinValue(IN2_PORT,IN2_PIN,DIO_u8PIN_LOW);
	
	/*-------MOTOR_B-------*/
	DIO_enuSetPinValue(IN3_PORT,IN3_PIN,DIO_u8PIN_HIGH);
	DIO_enuSetPinValue(IN4_PORT,IN4_PIN,DIO_u8PIN_LOW);

}

/*-------MOVING BACKWARD-------*/
void L293D_voidBackward(void)
{
	/*-------MOTOR_A-------*/
	DIO_enuSetPinValue(IN1_PORT,IN1_PIN,DIO_u8PIN_LOW);
	DIO_enuSetPinValue(IN2_PORT,IN2_PIN,DIO_u8PIN_HIGH);
	
	/*-------MOTOR_B-------*/
	DIO_enuSetPinValue(IN3_PORT,IN3_PIN,DIO_u8PIN_LOW);
	DIO_enuSetPinValue(IN4_PORT,IN4_PIN,DIO_u8PIN_HIGH);

}

/*-------ROTATING RIGHT-------*/
 void L293D_voidRight(void)
{
	/*-------MOTOR_A-------*/
	DIO_enuSetPinValue(IN1_PORT,IN1_PIN,DIO_u8PIN_LOW);
	DIO_enuSetPinValue(IN2_PORT,IN2_PIN,DIO_u8PIN_LOW);
	
	/*-------MOTOR_B-------*/
	DIO_enuSetPinValue(IN3_PORT,IN3_PIN,DIO_u8PIN_HIGH);
	DIO_enuSetPinValue(IN4_PORT,IN4_PIN,DIO_u8PIN_LOW);
	
	_delay_ms(1000);
}

/*-------ROTATING LEFT-------*/
void L293D_voidLeft(void)
{
	/*-------MOTOR_A-------*/
	DIO_enuSetPinValue(IN1_PORT,IN1_PIN,DIO_u8PIN_HIGH);
	DIO_enuSetPinValue(IN2_PORT,IN2_PIN,DIO_u8PIN_LOW);
	
	/*-------MOTOR_B-------*/
	DIO_enuSetPinValue(IN3_PORT,IN3_PIN,DIO_u8PIN_LOW);
	DIO_enuSetPinValue(IN4_PORT,IN4_PIN,DIO_u8PIN_LOW);
	_delay_ms(1000);

}

/*-------STOP-------*/
void L293D_voidStop()
{
 /*-------MOTOR_A-------*/
 DIO_enuSetPinValue(IN1_PORT,IN1_PIN,DIO_u8PIN_LOW);
 DIO_enuSetPinValue(IN2_PORT,IN2_PIN,DIO_u8PIN_LOW);
 
 /*-------MOTOR_B-------*/
 DIO_enuSetPinValue(IN3_PORT,IN3_PIN,DIO_u8PIN_LOW);
 DIO_enuSetPinValue(IN4_PORT,IN4_PIN,DIO_u8PIN_LOW);
}