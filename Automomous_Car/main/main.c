


/*

- THIS CODE IS MEANT TO WELL SUITE PROTEUS SIMULATION
- THE CONTINIOUS DISTANCE DISPLAY IS FOR THE PREVIOUSLY MENTIONED PURPOSE

*/




	
#include "main.h"


int main()
{

 	//INITIALIZATION
 	Timer1_voidInit();
 	GIE_voidInit();
 	CLCD_voidInit();
 	HCSR04_voidInit();
 	Servo_voidInit();
 	L293D_voidInit();
 
 	//CALLBACK FUNCTIONS
 	Timer1_CallBackFunOVF(Ultra_OVFCall);
 	Timer1_CallBackFunCAPT(Ultra_CaptCall);
 
 	//WELCOME MESSAGE
 	Print_welcome();
 
 
 	while(1)
 	{
 		Servo_voidRotation(90);														//SERVO ROTATES TO 90 DEGREE (STEADY STATE)
 		
 		Global_u8Distance=Ultra_measure();											//CALCULATING AND ASSIGNING DISTANCE TO VAR
 		Print_distance(Global_u8Distance);											//PRINTING DETECTED DISTANCE
 		
 		if(Global_u8Distance>OBSTACLE_DISTANCE)
 			Car_Direction(Forward);													// CAR MOVES FORWARD
 		
 		else
 		{
 			Car_Direction(Stop);													//CAR STOPS
 			Servo_voidRotation(0);													//SERVO ROTATES LEFT
 			Global_u8RightDistance=Ultra_measure();									//DISTANCE MEASURED AND ASSIGNED TO VAR
 			
 			Servo_voidRotation(180);												//SERVO ROTATES RIGHT
 			Global_u8LeftDistance=Ultra_measure();									//DISTANCE MEASURED AND ASSIGNED TO VAR
 			
 			Servo_voidRotation(90);													//SERVO RETURNS TO STEADY STATE
 			Print_compare(Global_u8LeftDistance,Global_u8RightDistance);			//PRINTING LEFT AND RIGHT DISTANCE
 			
 			
 			if((Global_u8LeftDistance>OBSTACLE_DISTANCE)&&(Global_u8LeftDistance>Global_u8RightDistance))
			 {
				  Car_Direction(Left);												//ROTATING AND PRINTING CURRENT DIRECTION
				  Car_Direction(Stop);
			 }
			 

				 
 			 else if((Global_u8RightDistance>OBSTACLE_DISTANCE)&&(Global_u8RightDistance>Global_u8LeftDistance))
			  {
				  Car_Direction(Right);												//ROTATING AND PRINTING CURRENT DIRECTION  
				  Car_Direction(Stop);
			  }
				
			 else if((Global_u8RightDistance>OBSTACLE_DISTANCE)&&(Global_u8RightDistance==Global_u8LeftDistance))
			 {
				 Car_Direction(Right);												//ROTATING AND PRINTING CURRENT DIRECTION
				 Car_Direction(Stop);
			 }	 
 			else 																	//IF BOTH DIRECTIONS ARE LOWER THAN OBSTACLE DISTANCE
 			{
 				CLCD_voidSendpcString("Both Sides < Obstacle Distance");
 				_delay_ms(300);
 				CLCD_voidClearDisplay();
 			}
 		}
 	}
}