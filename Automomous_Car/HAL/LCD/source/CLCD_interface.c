
#include "../headers/CLCD_interface.h"




/*-----------CLCD_PRIV_H FUNCTIONS IMPLEMENTATIONS-----------*/

//FUNCTION SENDS DATA AND ENABLE PULSE (WRITE AND LATCH FUNCTION)
 static void CLCD_voidWriteAndLatch(uint8 Copy_u8Nipple)
 {
	 //SETTING ENABLE PIN TO LOW
	 DIO_enuSetPinValue(EN_PORT,EN_PIN,DIO_u8PIN_LOW);
	 
	 if (Copy_u8Nipple == 0x28)
	 {
		 uint8 Local_u8RS_Val;
		 DIO_enuGetPinValue(RS_PORT, RS_PIN, &Local_u8RS_Val);

		 if (Local_u8RS_Val == DIO_u8PIN_LOW)
		 {
			 DIO_enuSetPinValue(D7_PORT, D7_PIN , ((Copy_u8Nipple>>7)&1));
			 DIO_enuSetPinValue(D6_PORT, D6_PIN , ((Copy_u8Nipple>>6)&1));
			 DIO_enuSetPinValue(D5_PORT, D5_PIN , ((Copy_u8Nipple>>5)&1));
			 DIO_enuSetPinValue(D4_PORT, D4_PIN , ((Copy_u8Nipple>>4)&1));

			 DIO_enuSetPinValue(EN_PORT, EN_PIN , DIO_u8PIN_HIGH);
			 _delay_ms(5);
			 DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8PIN_LOW);
			 _delay_ms(5);
		 }
	 }
	 
	 //SENDING FIRST HALF OF DATA
	 DIO_enuSetPinValue(D7_PORT,D7_PIN,((Copy_u8Nipple>>7)&1));
	 DIO_enuSetPinValue(D6_PORT,D6_PIN,((Copy_u8Nipple>>6)&1));
	 DIO_enuSetPinValue(D5_PORT,D5_PIN,((Copy_u8Nipple>>5)&1));
	 DIO_enuSetPinValue(D4_PORT,D4_PIN,((Copy_u8Nipple>>4)&1));
	 
	 //SENDING ENABLE PULSE
	 DIO_enuSetPinValue(EN_PORT,EN_PIN,DIO_u8PIN_HIGH);
	 _delay_ms(5);
	 DIO_enuSetPinValue(EN_PORT,EN_PIN,DIO_u8PIN_LOW);
	 _delay_ms(5);
	 
	  //SENDING SECOND HALF OF DATA
	  DIO_enuSetPinValue(D7_PORT,D7_PIN,((Copy_u8Nipple>>3)&1));
	  DIO_enuSetPinValue(D6_PORT,D6_PIN,((Copy_u8Nipple>>2)&1));
	  DIO_enuSetPinValue(D5_PORT,D5_PIN,((Copy_u8Nipple>>1)&1));
	  DIO_enuSetPinValue(D4_PORT,D4_PIN,((Copy_u8Nipple>>0)&1));
	  
	  //SENDING ENABLE PULSE
	  DIO_enuSetPinValue(EN_PORT,EN_PIN,DIO_u8PIN_HIGH);
	  _delay_ms(5);
	  DIO_enuSetPinValue(EN_PORT,EN_PIN,DIO_u8PIN_LOW);
	  _delay_ms(5);
 }
 
 //CONVERTS INTEGER DIGIT TO CHARACTER
 static uint8 CLCD_voidItoStr(uint8 u8Int)
 {
	 uint8 retvalue='0';
	 switch(u8Int)
	 {
		 case 0:
		 retvalue='0';
		 break;
		 case 1:
		 retvalue='1';
		 break;
		 case 2:
		 retvalue='2';
		 break;
		 case 3:
		 retvalue='3';
		 break;
		 case 4:
		 retvalue='4';
		 break;
		 case 5:
		 retvalue='5';
		 break;
		 case 6:
		 retvalue='6';
		 break;
		 case 7:
		 retvalue='7';
		 break;
		 case 8:
		 retvalue='8';
		 break;
		 case 9:
		 retvalue='9';
		 break;
	 }
	 return retvalue;
 }
 



/*-----------CLCD_INTERFACE_H FUNCTIONS IMPLEMENTATIONS-----------*/

//INITIALIZES DATA PINS DIRECTIONS AND POWER SETTINGS
void CLCD_voidInit(void)
{

	//INITIALIZING LCD PIN DIRECTION
	//CONTROL PINS
	DIO_enuSetPinDirection(RS_PORT,RS_PIN,DIO_u8PIN_OUTPUT);
	DIO_enuSetPinDirection(RW_PORT,RW_PIN,DIO_u8PIN_OUTPUT);
	DIO_enuSetPinDirection(EN_PORT,EN_PIN,DIO_u8PIN_OUTPUT);
	//DATA PINS
	DIO_enuSetPinDirection(D7_PORT,D7_PIN,DIO_u8PIN_OUTPUT);
	DIO_enuSetPinDirection(D6_PORT,D6_PIN,DIO_u8PIN_OUTPUT);
	DIO_enuSetPinDirection(D5_PORT,D5_PIN,DIO_u8PIN_OUTPUT);
	DIO_enuSetPinDirection(D4_PORT,D4_PIN,DIO_u8PIN_OUTPUT);

	//SENDING INITIALIZATION COMMANDS TO LCD

	//DELAY TIME OF 35ms FOR FUNCTION SET COMMAND 7654NFxx
	_delay_ms(FUNCTION_SET);
	CLCD_voidSendCommand(0x28);
	//DELAY TIME OF 45us FOR DISPLAY CONTROL COMMAND 76543DCB
	_delay_ms(DISPLAY_CONTROL);
	CLCD_voidSendCommand(0x0F);
	//DELAY TIME OF 45us FOR DISPLAY CLEAR COMMAND 76543210
	_delay_ms(DISPLAY_CLEAR);
	CLCD_voidSendCommand(0x01);
	//DELAY TIME OF 2ms FOR ENTRY MODE COMMAND 765432I/DSH
	_delay_ms(ENTRY_MODE_SET);
	CLCD_voidSendCommand(0x06);
}



//SENDING DATA
void CLCD_voidSendData(uint8 Copy_u8Data)
{

	//SET RS PIN TO HIGH FOR SENDING DATA
	DIO_enuSetPinValue(RS_PORT,RS_PIN,DIO_u8PIN_HIGH);

	//SET RW PIN TO LOW  IN ORDER TO WRITE
	DIO_enuSetPinValue(RW_PORT,RW_PIN,DIO_u8PIN_LOW);

	CLCD_voidWriteAndLatch(Copy_u8Data);

}

//SENDING COMMAND
void CLCD_voidSendCommand(uint8 Copy_u8Command)
{

	//SET RS PIN TO LOW FOR A COMMAND
	DIO_enuSetPinValue(RS_PORT,RS_PIN,DIO_u8PIN_LOW);

	//SET RW PIN TO LOW  IN ORDER TO WRITE
	DIO_enuSetPinValue(RW_PORT,RW_PIN,DIO_u8PIN_LOW);

	CLCD_voidWriteAndLatch(Copy_u8Command);
}


//CLEARING DISPLAY
void CLCD_voidClearDisplay(void)
{
	CLCD_voidSendCommand(0x01);
}	

//RETURN HOME
void CLCD_voidReturnHome(void)
{
	CLCD_voidSendCommand(0x02);
}

//DISPLAY SHIFT
//0X1C SCREEN RIGHT | 0X18 SCREEN LEFT | 0X14 CURSOR RIGHT | 0X10 CURSOR LEFT
void CLCD_voidShiftDisplay(uint8 Copy_u8Direction)
{
	if(Copy_u8Direction==DISPLAY_RIGHT)
	CLCD_voidSendCommand(0x1C);
	else if(Copy_u8Direction==DISPLAY_LEFT)
	CLCD_voidSendCommand(0x18);
}

//CURSOR SHIFT
//0X1C SCREEN RIGHT | 0X18 SCREEN LEFT | 0X14 CURSOR RIGHT | 0X10 CURSOR LEFT
void CLCD_voidShiftCursor(uint8 Copy_u8Direction)
{
	if(Copy_u8Direction==CURSOR_RIGHT)
	CLCD_voidSendCommand(0x14);
	else if(Copy_u8Direction==CURSOR_LEFT)
	CLCD_voidSendCommand(0x10);
}



//SENDING STRING USING CONSTANT POINTER
void CLCD_voidSendpcString(const char *Copy_pcstring)
{
	uint8 x=0;			//X HERE INCREMENTED BY ONE EVERY TIME A CHARACTER IS DISPLAYED TILL REACHES 16 (THE VISIBLE RANGE) 
	if(Copy_pcstring!=NULL)
	{
		while(*Copy_pcstring!='\0')
		{
			if(x>=16)
			{
				 CLCD_voidShiftDisplay(DISPLAY_LEFT);
			}
			CLCD_voidSendData(*Copy_pcstring);
			Copy_pcstring++;
			x++;
		}
	}
}

//SENDING INTEGER VALUE GIVING DUE CARE TO NEGATIVE SIGN
 void CLCD_voidDisplayIntegerNum(sint32 Copy_s32Num)
 {
 	sint32 Local_s32Counter;
 	uint8 Local_u8Character=0;
 	if(Copy_s32Num<0)
 	{
 		Copy_s32Num*=-1;
 		CLCD_voidSendData('-');
 	}
 	for(Local_s32Counter=1000000000;Local_s32Counter>=1;Local_s32Counter/=10)
 	{
		 if(Local_u8Character==0)
		 {
			if(((Copy_s32Num/Local_s32Counter)%10)==0) continue; 
		 }
 		
 		Local_u8Character=CLCD_voidItoStr((uint8)((Copy_s32Num/Local_s32Counter)%10));
 		CLCD_voidSendData(Local_u8Character);
 	}
 }

 //PRINTING FLOAT VALUE GIVING DUE CARE TO NEGATIVE SIGN AND PRINTING ONLY THREE FLOAT DIGITS
 void CLCD_voidDisplayFloatNum(f32 Copy_f32Num)
 {
	 //VARIABLES DECLARATION
	 sint32 Local_s32Counter;
	 uint8 Local_u8Character=0;
	 
	 //DECLARING AND ASSIGNING THE INTEGER PART
	 sint32 Local_s32Num=(sint32)(Copy_f32Num);
	 
		 //CHECKING IF THE VALUE IS SIGNED OR NOT
		 if(Local_s32Num<0)
		 {
			 Copy_f32Num*=-1;
			 
			 //PRINTING THE NEGATIVE SIGN
			 CLCD_voidSendData('-');	
		 }
		 
		 //PRINTING THE INTEGER DIGITS
		 for(Local_s32Counter=1000000000;Local_s32Counter>=1;Local_s32Counter/=10)
		 {
			 if(Local_u8Character==0)
			 {
				if(((Local_s32Num/Local_s32Counter)%10)==0) continue; 
			 }
			 Local_u8Character=CLCD_voidItoStr((uint8)((Local_s32Num/Local_s32Counter)%10));
			 CLCD_voidSendData(Local_u8Character);
		 }
		 
		 //PRINTING THE DOT SIGN
		 CLCD_voidSendData('.');
		 
		 //ASSIGNING THE FLOAT VALUE
		 Local_s32Num=(Copy_f32Num-Local_s32Num)*100000;
		 
		 //PRINTING THE FLOAT VALUE
		 for(Local_s32Counter=10000;Local_s32Counter>=1;Local_s32Counter/=10)
		 {
			 Local_u8Character=CLCD_voidItoStr((uint8)((Local_s32Num/Local_s32Counter)%10));
			 CLCD_voidSendData(Local_u8Character);
		 }
	
 }
 
 
 
 
 //SENDING STRING TO X,Y POSITION
 void CLCD_voidSendPositionXY(uint8 x,uint8 y)
 {
	 //SHIFTING CURSOR TO XY POSITION
	 if(x<16 && y==0)
	 CLCD_voidSendCommand(x|FIRST_LINE);
	 else if(x<16 && y==1)
	 CLCD_voidSendCommand(x|SECOND_LINE);
 }
 