#include "../headers/Auto_interface.h"



//CLCD FUNCS

//PRINTS WELCOME MESSAGE AND OBSTACLE DISTANCE DETAILS
void Print_welcome(void)
{
	CLCD_voidSendPositionXY(4,0);
	CLCD_voidSendpcString("WELCOME");
	_delay_ms(300);
	CLCD_voidClearDisplay();
	
	CLCD_voidSendPositionXY(0,0);
	CLCD_voidSendpcString("Autonomous Car");
	CLCD_voidSendPositionXY(4,1);
	CLCD_voidSendpcString("Starting");
	_delay_ms(300);
	CLCD_voidClearDisplay();
	
	CLCD_voidSendPositionXY(0,0);
	CLCD_voidSendpcString("Obstacle Distance");
	CLCD_voidSendPositionXY(2,1);
	CLCD_voidSendpcString("Equal To ");
	CLCD_voidDisplayIntegerNum(OBSTACLE_DISTANCE);
	_delay_ms(300);
	CLCD_voidClearDisplay();
}

//PRINTS RIGHT AND LEFT DISTANCE
void Print_compare(uint8 Copy_u8Left,uint8 Copy_u8Right)
{
	CLCD_voidClearDisplay();
	CLCD_voidSendPositionXY(0,0);
	CLCD_voidSendpcString("Left = ");
	CLCD_voidDisplayIntegerNum(Copy_u8Left);
	CLCD_voidSendpcString(" cm");
	
	CLCD_voidSendPositionXY(0,1);
	CLCD_voidSendpcString("Right = ");
	CLCD_voidDisplayIntegerNum(Copy_u8Right);
	CLCD_voidSendpcString(" cm");
	
	_delay_ms(500);
	CLCD_voidClearDisplay();
}

//MEANT TO FOR PRINTING DISTANCE
void Print_distance(uint8 Copy_u8Distance)
{
	CLCD_voidClearDisplay();
	CLCD_voidDisplayIntegerNum(Copy_u8Distance);
	_delay_ms(300);
	CLCD_voidClearDisplay();
}


//ULTRA FUNCS

//FUNCTION TO CALCULATE DISTANCE OF OBSTACLE
uint16 Ultra_measure(void)
{
	Timer1_voidSetWGM(WGM_Normal);			//SETTING WGM TO NORMAL
	Global_u8Flag=0;						//SETTING FLAG TO ZERO
	Timer1_voidTICIE1Set(Enable);			//ENABLING INPUT CAPTURE INTERRUPT
	Timer1_voidTCNT1Set(0);					//SETTING OVERFLOW REGISTER TO ZERO
	HCSR04_voidSendPulse();					//SENDING PULSE ON ULTRASONIC
	
	while(GET_BIT(TIMSK,5));				//WAITING FOR INPUT CAPTURE INTERRUPT TO BE DISABLED
	Global_u16Time=(Global_u16T2-Global_u16T1)+((uint32)65535*Global_u8Counter);
	return(Global_u16Time/58);
}
//FUNCTION TO BE EXECUTED IN INPUT CAPTURE ISR
void Ultra_CaptCall(void)
{
	if(Global_u8Flag==0)
	{
		Global_u8Counter=0;							//SETTING COUNTER WITH ZERO
		Global_u16T1=Timer1_u16ICR1Get();			//ASSIGNING ICR1 INITIAL VALUE TO T1
		Timer1_voidICES1Set(Falling);				//CHANGING EDGE CAPTURED TO FALLING
 		Global_u8Flag++;							//INCREASING FLAG SO AS TO ACCESS ELSE IF CASE
	}
	else if(Global_u8Flag==1)
	{
		Global_u16T2= Timer1_u16ICR1Get();			//READING ICR1 FINAL VALUE
		Global_u8Flag++;							//INCREASING FLAG SO AS NOT TO ACCESS THE INTERRUPT FUNCTION
		Timer1_voidICES1Set(Rising);				//RESETTING EDGE CAPTURED TO RISING
		Timer1_voidTICIE1Set(Disable);				//DISABLING INPUT CAPTURE INTERRUPT
		
	}
}
//FUNCTION TO BE EXECUTED IN OVER FLOW ISR
void Ultra_OVFCall(void)
{
	Global_u8Counter++;
}


//CAR DIRECTIONS
//THE FUNCTION SETS CAR DIRECTION AND DISPLAYS CURRENT DIRECTION ON THE LCD
void Car_Direction(Direction Copy_enuDirection)
{
	switch(Copy_enuDirection)
	{
		case Stop:
		CLCD_voidClearDisplay();
		CLCD_voidSendpcString("Car Stopped");
		L293D_voidStop();
		break;
		
		case Forward:
		CLCD_voidClearDisplay();
		CLCD_voidSendpcString("Moving Forward");
		L293D_voidForward();
		break;
		
		case Backward:
		CLCD_voidClearDisplay();
		CLCD_voidSendpcString("Moving Backward");
		L293D_voidBackward();
		break;
		
		case Right:
		CLCD_voidClearDisplay();
		CLCD_voidSendpcString("Turning Right");
		L293D_voidRight();
		break;
		
		case Left:
		CLCD_voidClearDisplay();
		CLCD_voidSendpcString("Turning Left");
		L293D_voidLeft();
		break;
	}
}