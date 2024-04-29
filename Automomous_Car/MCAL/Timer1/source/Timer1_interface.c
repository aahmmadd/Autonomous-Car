
 #include "../headers/Timer1_interface.h"


/*-------TIMER1 INITIALIZATION-------*/
void Timer1_voidInit()
{
	/*-------SETTING PRESCALER VALUES-------*/
	
	
	#if Timer1_Pres == Timer1_Stop
	CLR_BIT(TCCR1B,0);CLR_BIT(TCCR1B,1);CLR_BIT(TCCR1B,2);
	
	#elif Timer1_Pres == Timer1_NoPres
	SET_BIT(TCCR1B,0);CLR_BIT(TCCR1B,1);CLR_BIT(TCCR1B,2);
	
	#elif Timer1_Pres == Timer1_Pres8
	CLR_BIT(TCCR1B,0);SET_BIT(TCCR1B,1);CLR_BIT(TCCR1B,2);
	
	#elif Timer1_Pres == Timer1_Pres64
	SET_BIT(TCCR1B,0);SET_BIT(TCCR1B,1);CLR_BIT(TCCR1B,2);
	
	#elif Timer1_Pres == Timer1_Pres256
	CLR_BIT(TCCR1B,0);CLR_BIT(TCCR1B,1);SET_BIT(TCCR1B,2);
	
	#elif Timer1_Pres == Timer1_Pres1024
	SET_BIT(TCCR1B,0);CLR_BIT(TCCR1B,1);SET_BIT(TCCR1B,2);
	
	#elif Timer1_Pres == Timer1_XclkFalling
	CLR_BIT(TCCR1B,0);SET_BIT(TCCR1B,1);SET_BIT(TCCR1B,2);
	
	#elif Timer1_Pres == Timer1_XclkRising
	SET_BIT(TCCR1B,0);SET_BIT(TCCR1B,1);SET_BIT(TCCR1B,2);
	
	#else 
	#error "INVALID PRESCALER VALUE"
	
	#endif
	
	
	
	
	
	
	
	
	/*-------SETTING WGM VALUES-------*/
	
	
	/*-------INCASE OF NORMAL MODE  VALUES-------*/
	
	#if Timer1_WGM == WGM_Normal
	CLR_BIT(TCCR1A,0);CLR_BIT(TCCR1A,1);CLR_BIT(TCCR1B,3);CLR_BIT(TCCR1B,4);
	
	
	/*-------INCASE OF PWM PHASE CORRECT 8 BIT MODE VALUES-------*/
	
	#elif Timer1_WGM == WGM_PWM_PhaseCorrect_8
	SET_BIT(TCCR1A,0);CLR_BIT(TCCR1A,1);CLR_BIT(TCCR1B,3);CLR_BIT(TCCR1B,4);
	
	/*-------INCASE OF PWM PHASE CORRECT 9 BIT MODE  VALUES-------*/
	
	#elif Timer1_WGM == WGM_PWM_PhaseCorrect_9
	CLR_BIT(TCCR1A,0);SET_BIT(TCCR1A,1);CLR_BIT(TCCR1B,3);CLR_BIT(TCCR1B,4);
	
	/*-------INCASE OF PWM PHASE CORRECT 10 BIT MODE  VALUES-------*/
	
	#elif Timer1_WGM == WGM_PWM_PhaseCorrect_10
	SET_BIT(TCCR1A,0);SET_BIT(TCCR1A,1);CLR_BIT(TCCR1B,3);CLR_BIT(TCCR1B,4);
	
	/*-------INCASE OF CTC OCR1A MODE  VALUES-------*/
	
	#elif Timer1_WGM == WGM_CTC_OCR1A
	CLR_BIT(TCCR1A,0);CLR_BIT(TCCR1A,1);SET_BIT(TCCR1B,3);CLR_BIT(TCCR1B,4);
	
	/*-------INCASE OF FAST PWM 8 BIT MODE  VALUES-------*/
	
	#elif Timer1_WGM == WGM_PWM_Fast_8
	SET_BIT(TCCR1A,0);CLR_BIT(TCCR1A,1);SET_BIT(TCCR1B,3);CLR_BIT(TCCR1B,4);
	
	/*-------INCASE OF FAST PWM 9 BIT MODE  VALUES-------*/
	
	#elif Timer1_WGM == WGM_PWM_Fast_9
	CLR_BIT(TCCR1A,0);SET_BIT(TCCR1A,1);SET_BIT(TCCR1B,3);CLR_BIT(TCCR1B,4);
	
	/*-------INCASE OF FAST PWM 10 BIT MODE  VALUES-------*/
	
	#elif Timer1_WGM == WGM_PWM_Fast_10
	SET_BIT(TCCR1A,0);SET_BIT(TCCR1A,1);SET_BIT(TCCR1B,3);CLR_BIT(TCCR1B,4);
	
	/*-------INCASE OF PWM PHASE AND FREQUENCY CORRECT ICR1 MODE  VALUES-------*/
	
	#elif Timer1_WGM == WGM_PWM_PhFrCorrect_ICR1
	CLR_BIT(TCCR1A,0);CLR_BIT(TCCR1A,1);CLR_BIT(TCCR1B,3);SET_BIT(TCCR1B,4);
	
	/*-------INCASE OF PWM PHASE AND FREQUENCY CORRECT OCR1A MODE  VALUES-------*/
	
	#elif Timer1_WGM == WGM_PWM_PhFrCorrect_OCR1A
	SET_BIT(TCCR1A,0);CLR_BIT(TCCR1A,1);CLR_BIT(TCCR1B,3);SET_BIT(TCCR1B,4);
	
	/*-------INCASE OF PWM PHASE CORRECT ICR1 MODE  VALUES-------*/
	
	#elif Timer1_WGM == WGM_PWM_PhaseCorrect_ICR1
	CLR_BIT(TCCR1A,0);SET_BIT(TCCR1A,1);CLR_BIT(TCCR1B,3);SET_BIT(TCCR1B,4);
	
	/*-------INCASE OF PWM PHASE CORRECT OCR1A MODE  VALUES-------*/
	
	#elif Timer1_WGM == WGM_PWM_PhaseCorrect_OCR1A
	SET_BIT(TCCR1A,0);SET_BIT(TCCR1A,1);CLR_BIT(TCCR1B,3);SET_BIT(TCCR1B,4);
	
	/*-------INCASE OF CTC ICR1A MODE  VALUES-------*/
	
	#elif Timer1_WGM == WGM_CTC_ICR1
	CLR_BIT(TCCR1A,0);CLR_BIT(TCCR1A,1);SET_BIT(TCCR1B,3);SET_BIT(TCCR1B,4);
	
	/*-------INCASE OF FAST PWM ICR1 MODE  VALUES-------*/
	
	#elif Timer1_WGM == WGM_PWM_Fast_ICR1
	CLR_BIT(TCCR1A,0);SET_BIT(TCCR1A,1);SET_BIT(TCCR1B,3);SET_BIT(TCCR1B,4);
	
	/*-------INCASE OF FAST PWM OCR1A MODE  VALUES-------*/
	
	#elif Timer1_WGM == WGM_PWM_Fast_OCR1A
	SET_BIT(TCCR1A,0);SET_BIT(TCCR1A,1);SET_BIT(TCCR1B,3);SET_BIT(TCCR1B,4);
	

	#else 
	#error "INVALID WGM VALUE"
	
	#endif
	
	
	
	
	
	
		
	/*-------SETTING COM1A VALUES-------*/
	
	
	/*-------INCASE OF NORMAL MODE  VALUES-------*/
	
	#if Timer1_COM1A == COM_Normal
	CLR_BIT(TCCR1A,6);CLR_BIT(TCCR1A,7);
	
	/*-------INCASE OF TOGGLE MODE  VALUES-------*/
	
	#elif Timer1_COM1A == COM_Toggle
	SET_BIT(TCCR1A,6);CLR_BIT(TCCR1A,7);
	
	/*-------INCASE OF CLEAR MODE  VALUES-------*/
	
	#elif Timer1_COM1A == COM_Clear
	CLR_BIT(TCCR1A,6);SET_BIT(TCCR1A,7);
	
	/*-------INCASE OF SET MODE  VALUES-------*/
	
	#elif Timer1_COM1A == COM_Set
	SET_BIT(TCCR1A,6);SET_BIT(TCCR1A,7);
	
	#else 
	#error "INVALID COM VALUE"
	
	#endif
	
	
	/*-------SETTING COM1B VALUES-------*/
		
		
	/*-------INCASE OF NORMAL MODE  VALUES-------*/
		
	#if Timer1_COM1B == COM_Normal
	CLR_BIT(TCCR1A,4);CLR_BIT(TCCR1A,5);
	
	/*-------INCASE OF TOGGLE MODE  VALUES-------*/
	
	#elif Timer1_COM1B == COM_Toggle
	SET_BIT(TCCR1A,4);CLR_BIT(TCCR1A,5);
	
	/*-------INCASE OF CLEAR MODE  VALUES-------*/
	
	#elif Timer1_COM1B == COM_Clear
	CLR_BIT(TCCR1A,4);SET_BIT(TCCR1A,5);
	
	/*-------INCASE OF SET MODE  VALUES-------*/
	
	#elif Timer1_COM1B == COM_Set
	SET_BIT(TCCR1A,4);SET_BIT(TCCR1A,5);
	
	#else
	#error "INVALID COM VALUE"
		
	#endif
	
	
	
	
	
	
	
	
	/*-------SETTING INTERRUPTS OF MODES VALUES-------*/
	
	
	/*-------SETTING TICIE1 VALUES-------*/
	#if TICIE1 == Enable
	SET_BIT(TIMSK,5);
	#elif TICIE1 == Disable
	CLR_BIT(TIMSK,5);
	#else  
	#error "INVALID TICIE1 VALUE"
	#endif
	
	
	/*-------SETTING OCIE1A VALUES-------*/
	#if OCIE1A == Disable
	CLR_BIT(TIMSK,4);
	#elif OCIE1A == Enable
	SET_BIT(TIMSK,4);
	#else  
	#error "INVALID OCIE1A VALUE"
	#endif
	
	
	/*-------SETTING OCIE1B VALUES-------*/
	#if OCIE1B == Disable
	CLR_BIT(TIMSK,3);
	#elif OCIE1B == Enable
	SET_BIT(TIMSK,3);
	#else
	#error "INVALID OCIE1B VALUE"
	#endif
	
	
	/*-------SETTING TOIE1 VALUES-------*/
	#if TOIE1 == Disable
	CLR_BIT(TIMSK,2);
	#elif TOIE1 == Enable
	SET_BIT(TIMSK,2);
	#else
	#error "INVALID TOIE1 VALUE"
	#endif
	
	/*--------------SETTING INTERRUPTS OF MODES VALUES*/
	
	
	/*-------SETTING ICES1 VALUES-------*/
	#if ICES1 == Falling
	CLR_BIT(TCCR1B,6);
	#elif ICES1 == Rising
	SET_BIT(TCCR1B,6);
	#else
	#error "INVALID FOC1A VALUE"
	#endif
	
	
	
	
	
	/*-------SETTING FOC1A VALUES-------*/
	#if FOC1A == Disable
	CLR_BIT(TCCR1A,3);
	#elif FOC1A == Enable
	SET_BIT(TCCR1A,3);
	#else
	#error "INVALID FOC1A VALUE"
	#endif
	
	
	/*-------SETTING FOC1B VALUES-------*/
	#if FOC1B == Disable
	CLR_BIT(TCCR1A,2);
	#elif FOC1A == Enable
	SET_BIT(TCCR1A,2);
	#else
	#error "INVALID FOC1B VALUE"
	#endif
	
	
}




/*-------SETTING PRESCALER VALUE-------*/
void Timer1_voidSetPres(uint8 pres)
{

	if(pres == Timer1_Stop)
	{
		CLR_BIT(TCCR1B,0);CLR_BIT(TCCR1B,1);CLR_BIT(TCCR1B,2);
	}
	else if(pres == Timer1_NoPres)
	{
		SET_BIT(TCCR1B,0);CLR_BIT(TCCR1B,1);CLR_BIT(TCCR1B,2);
	}
	else if(pres == Timer1_Pres8)
	{
		CLR_BIT(TCCR1B,0);SET_BIT(TCCR1B,1);CLR_BIT(TCCR1B,2);
	}
	else if(pres == Timer1_Pres64)
	{
		SET_BIT(TCCR1B,0);SET_BIT(TCCR1B,1);CLR_BIT(TCCR1B,2);
	}
	else if(pres == Timer1_Pres256)
	{
		CLR_BIT(TCCR1B,0);CLR_BIT(TCCR1B,1);SET_BIT(TCCR1B,2);
	}
	else if(pres == Timer1_Pres1024)
	{
		SET_BIT(TCCR1B,0);CLR_BIT(TCCR1B,1);SET_BIT(TCCR1B,2);
	}
	else if(pres == Timer1_XclkFalling)
	{
		CLR_BIT(TCCR1B,0);SET_BIT(TCCR1B,1);SET_BIT(TCCR1B,2);
	}
	else if(pres == Timer1_XclkRising)
	{
		SET_BIT(TCCR1B,0);SET_BIT(TCCR1B,1);SET_BIT(TCCR1B,2);
	}
}

//WGM SET FUNC
void Timer1_voidSetWGM(uint8 WGM)
{
	switch(WGM)
	{
		case WGM_Normal:
		CLR_BIT(TCCR1A,0);CLR_BIT(TCCR1A,1);CLR_BIT(TCCR1B,3);CLR_BIT(TCCR1B,4);
		break;
		
		case WGM_PWM_PhaseCorrect_8:
		SET_BIT(TCCR1A,0);CLR_BIT(TCCR1A,1);CLR_BIT(TCCR1B,3);CLR_BIT(TCCR1B,4);
		break;
		
		case WGM_PWM_PhaseCorrect_9:
		CLR_BIT(TCCR1A,0);SET_BIT(TCCR1A,1);CLR_BIT(TCCR1B,3);CLR_BIT(TCCR1B,4);
		break;
		
		case WGM_PWM_PhaseCorrect_10:
		SET_BIT(TCCR1A,0);SET_BIT(TCCR1A,1);CLR_BIT(TCCR1B,3);CLR_BIT(TCCR1B,4);
		break;
		
		case WGM_CTC_OCR1A:
		CLR_BIT(TCCR1A,0);CLR_BIT(TCCR1A,1);SET_BIT(TCCR1B,3);CLR_BIT(TCCR1B,4);
		break;
		
		case  WGM_PWM_Fast_8:
		SET_BIT(TCCR1A,0);CLR_BIT(TCCR1A,1);SET_BIT(TCCR1B,3);CLR_BIT(TCCR1B,4);
		break;
		
		case WGM_PWM_Fast_9:
		CLR_BIT(TCCR1A,0);SET_BIT(TCCR1A,1);SET_BIT(TCCR1B,3);CLR_BIT(TCCR1B,4);
		break;
		
		case WGM_PWM_Fast_10:
		SET_BIT(TCCR1A,0);SET_BIT(TCCR1A,1);SET_BIT(TCCR1B,3);CLR_BIT(TCCR1B,4);
		break;
		
		case WGM_PWM_PhFrCorrect_ICR1:
		CLR_BIT(TCCR1A,0);CLR_BIT(TCCR1A,1);CLR_BIT(TCCR1B,3);SET_BIT(TCCR1B,4);
		break;
		
		case WGM_PWM_PhFrCorrect_OCR1A:
		SET_BIT(TCCR1A,0);CLR_BIT(TCCR1A,1);CLR_BIT(TCCR1B,3);SET_BIT(TCCR1B,4);
		break;
		
		case WGM_PWM_PhaseCorrect_ICR1:
		CLR_BIT(TCCR1A,0);SET_BIT(TCCR1A,1);CLR_BIT(TCCR1B,3);SET_BIT(TCCR1B,4);
		break;
		
		case WGM_PWM_PhaseCorrect_OCR1A:
		SET_BIT(TCCR1A,0);SET_BIT(TCCR1A,1);CLR_BIT(TCCR1B,3);SET_BIT(TCCR1B,4);
		break;
		
		case WGM_CTC_ICR1:
		CLR_BIT(TCCR1A,0);CLR_BIT(TCCR1A,1);SET_BIT(TCCR1B,3);SET_BIT(TCCR1B,4);
		break;
		
		case  WGM_PWM_Fast_ICR1:
		CLR_BIT(TCCR1A,0);SET_BIT(TCCR1A,1);SET_BIT(TCCR1B,3);SET_BIT(TCCR1B,4);
		break;
		
		case WGM_PWM_Fast_OCR1A:
		SET_BIT(TCCR1A,0);SET_BIT(TCCR1A,1);SET_BIT(TCCR1B,3);SET_BIT(TCCR1B,4);
		break;
	}
}

//COM1A SET FUNC
void Timer1_voidSetCOM1A(uint8 COM1A)
{
	switch(COM1A)
	{
		case COM_Normal:
		CLR_BIT(TCCR1A,6);CLR_BIT(TCCR1A,7);
		break;
		
		case COM_Toggle:
		SET_BIT(TCCR1A,6);CLR_BIT(TCCR1A,7);
		break;
		
		case COM_Clear:
		CLR_BIT(TCCR1A,6);SET_BIT(TCCR1A,7);
		break;
		
		case COM_Set:
		SET_BIT(TCCR1A,6);SET_BIT(TCCR1A,7);
		break;
	}

}

//COM1B SET FUNC
void Timer1_voidSetCOM1B(uint8 COM1B)
{
	switch(COM1B)
	{
		case COM_Normal:
		CLR_BIT(TCCR1A,4);CLR_BIT(TCCR1A,5);
		break;
		
		case COM_Toggle:
		SET_BIT(TCCR1A,4);CLR_BIT(TCCR1A,5);
		break;
		
		case COM_Clear:
		CLR_BIT(TCCR1A,4);SET_BIT(TCCR1A,5);
		break;
		
		case COM_Set:
		SET_BIT(TCCR1A,4);SET_BIT(TCCR1A,5);
		break;
	}
}


//INPUT CAPTURE INTERRUPT ENABLE/DISABLE
void Timer1_voidTICIE1Set(uint8 TICIE1_value)
{
	switch(TICIE1_value)
	{
		case Enable: SET_BIT(TIMSK,5);break;
		case Disable: CLR_BIT(TIMSK,5);break;
	}
}
//OVER FLOW INTERRUPT ENABLE/DISABLE
void Timer1_voidTOIE1Set(uint8 TOIE1_value)
{
	switch(TOIE1_value)
	{
		case Enable: SET_BIT(TIMSK,2);break;
		case Disable: CLR_BIT(TIMSK,2);break;
	}
}




/*-------SETTING ICES1 VALUES-------*/
void Timer1_voidICES1Set(uint8 ICES1_value)
{
	switch(ICES1_value)
	{
		case Rising: SET_BIT(TCCR1B,6);break;
		case Falling: CLR_BIT(TCCR1B,6);break;
	}
}




/*-------SETTING TCNT1 VALUES-------*/
void Timer1_voidTCNT1Set(uint16 TCNT1_value)
{
	TCNT1H = (TCNT1_value & 0xFF00)>>8;
	TCNT1L = (TCNT1_value & 0x00FF);
}
/*-------SETTING OCR1A VALUE-------*/ // READ FROM LOW FIRST - WRITE ON HIGH FIRST
void Timer1_voidOCR1ASet(uint16 OCR1A_value)
{

	OCR1AH = (OCR1A_value & 0xFF00)>>8;
	OCR1AL = (OCR1A_value & 0x00FF);
}
/*-------SETTING OCR1B VALUE-------*/
void Timer1_voidOCR1BSet(uint16 OCR1B_value)
{

	OCR1BH = (OCR1B_value & 0xFF00)>>8;
	OCR1BL = (OCR1B_value & 0x00FF);
}
/*-------SETTING ICR1 VALUE-------*/
void Timer1_voidICR1Set(uint16 ICR1_value)
{
	ICR1H = (ICR1_value & 0xFF00)>>8;
	ICR1L = (ICR1_value & 0x00FF);
}



/*-------GETTING TCNT1 VALUE-------*/
uint16 Timer1_u16TCNT1Get(void)
{
	return (TCNT1L|((uint16)(TCNT1H<<8)));
}
/*-------GETTING OCR1A VALUE-------*/
uint16 Timer1_u16OCR1AGet(void)
{
	return (OCR1AL|((uint16)(OCR1AH<<8)));
}
/*-------GETTING OCR1B VALUE-------*/
uint16 Timer1_u16OCR1BGet(void)
{
	return (OCR1BL|((uint16)(OCR1BH<<8)));
}
/*-------GETTING ICR1 VALUE-------*/
uint16 Timer1_u16ICR1Get(void)
{
	return (ICR1L|((uint16)(ICR1H<<8)));
}



//THIS FUNCTION RETURNS THE OCR1A VALUE IN ACCORDANCE WITH THE DESIRED FREQUENCY USING THE FOLLOWING EQUATION
//PWM FREQ = SYS FREQ / (COUNTS * PRESCALER)
uint16 Timer1_u16SetFreq(uint8 freq, uint8 pres)
{
	return ((16000000)/(freq*pres));
}

//THIS FUNCTION RETURNS THE VALUE OF OCR1B TO MANIPULATE ON TIME OF WAVE USING THE DUTY RATIO EQUATION
//RATIO = TON / (TOTAL + 1)
uint16 Timer1_u16SetDutyRatio(f32 ratio)
{
	return (ratio*(Timer1_u16SetFreq(50,8)+1));
}



/*-------GLOBAL ARRAY OF POINTERS TO FUNCTIONS TO GIVE ACCESS OF FUNCTIONS IN MAIN TO ISR-------*/
static volatile void (*GpISRFun[4])(void)=
{
	NULL,	//CAPT
	NULL,	//COMPA
	NULL,	//COMPB
	NULL	//TOV
};




/*-------CALL BACK FUNCTIONS PROVIDES ACCESS FOR MAIN TO GLOBAL POINTERS TO FUNCTION-------*/

void Timer1_CallBackFunCAPT(volatile void (*ptr)(void))
{
	if(ptr!=NULL)
	GpISRFun[0]=ptr;
}
void Timer1_CallBackFunCOMP1A(volatile void (*ptr)(void))
{
	if(ptr!=NULL)
	GpISRFun[1]=ptr;
}
void Timer1_CallBackFunCOMP1B(volatile void (*ptr)(void))
{
	if(ptr!=NULL)
	GpISRFun[2]=ptr;
}
void Timer1_CallBackFunOVF(volatile void (*ptr)(void))
{
	if(ptr!=NULL)
	GpISRFun[3]=ptr;
}






/*-------ISR FUNCTIONS-------*/

ISR(VECT_Timer1_CAPT)
{
	if(GpISRFun[0]!=NULL)
	GpISRFun[0]();
}
ISR(VECT_Timer1_COMPA)
{
	if(GpISRFun[1]!=NULL)
	GpISRFun[1]();
}
ISR(VECT_Timer1_COMPB)
{
	if(GpISRFun[2]!=NULL)
	GpISRFun[2]();
}
ISR(VECT_Timer1_OVF)
{
	if(GpISRFun[3]!=NULL)
	GpISRFun[3]();
}
