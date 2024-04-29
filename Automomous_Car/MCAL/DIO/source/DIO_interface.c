
#include"../headers/DIO_interface.h"


/*INITIALIZE DIRECTION AND VALUE OF PINS*/
void DIO_enuInit(void)
{
	 DDRA=CONC(DIO_u8PA7_DIR,DIO_u8PA6_DIR,DIO_u8PA5_DIR,DIO_u8PA4_DIR,DIO_u8PA3_DIR,DIO_u8PA2_DIR,DIO_u8PA1_DIR,DIO_u8PA0_DIR);
	 PORTA=CONC(DIO_u8PA7_VALUE, DIO_u8PA6_VALUE,DIO_u8PA5_VALUE,DIO_u8PA4_VALUE,DIO_u8PA3_VALUE,DIO_u8PA2_VALUE,DIO_u8PA1_VALUE,DIO_u8PA0_VALUE);
}

/*SET PIN DIRECTION*/
void DIO_enuSetPinDirection(uint8 Copy_u8PortID,uint8 Copy_u8PinID,uint8 Copy_u8Direction)
{

	if(Copy_u8PinID<=DIO_u8PIN7)
	{
		if(Copy_u8Direction==DIO_u8PIN_INPUT)
		{
			switch(Copy_u8PortID)
			{
				case DIO_u8GROUPA:{CLR_BIT(DDRA,Copy_u8PinID);break;}
				case DIO_u8GROUPB:{CLR_BIT(DDRB,Copy_u8PinID);break;}
				case DIO_u8GROUPC:{CLR_BIT(DDRC,Copy_u8PinID);break;}
				case DIO_u8GROUPD:{CLR_BIT(DDRD,Copy_u8PinID);break;}
			}
		}

		else if(Copy_u8Direction==DIO_u8PIN_OUTPUT)
		{
			switch(Copy_u8PortID)
			{
				case DIO_u8GROUPA:{SET_BIT(DDRA,Copy_u8PinID);break;}
				case DIO_u8GROUPB:{SET_BIT(DDRB,Copy_u8PinID);break;}
				case DIO_u8GROUPC:{SET_BIT(DDRC,Copy_u8PinID);break;}
				case DIO_u8GROUPD:{SET_BIT(DDRD,Copy_u8PinID);break;}
			}

		}

	}
}


/*SET PIN VALUE*/
void DIO_enuSetPinValue(uint8 Copy_u8PortID,uint8 Copy_u8PinID,uint8 Copy_u8Value)
{
		if(Copy_u8PinID<=DIO_u8PIN7)
		{
			if(Copy_u8Value==DIO_u8PIN_LOW)
			{
				switch(Copy_u8PortID)
				{
					case DIO_u8GROUPA:{CLR_BIT(PORTA,Copy_u8PinID);break;}
					case DIO_u8GROUPB:{CLR_BIT(PORTB,Copy_u8PinID);break;}
					case DIO_u8GROUPC:{CLR_BIT(PORTC,Copy_u8PinID);break;}
					case DIO_u8GROUPD:{CLR_BIT(PORTD,Copy_u8PinID);break;}
				}
			}

			else if(Copy_u8Value==DIO_u8PIN_HIGH)
			{
				switch(Copy_u8PortID)
				{
					case DIO_u8GROUPA:{SET_BIT(PORTA,Copy_u8PinID);break;}
					case DIO_u8GROUPB:{SET_BIT(PORTB,Copy_u8PinID);break;}
					case DIO_u8GROUPC:{SET_BIT(PORTC,Copy_u8PinID);break;}
					case DIO_u8GROUPD:{SET_BIT(PORTD,Copy_u8PinID);break;}
				}
			}
		}
}


/*TOGGLE PIN VALUE*/
void DIO_enuTogglePinValue(uint8 Copy_u8PortID,uint8 Copy_u8PinID)
{
	if(Copy_u8PinID<=DIO_u8PIN7)
	{
		switch(Copy_u8PortID)
		{
			case DIO_u8GROUPA:{TOG_BIT(PORTA,Copy_u8PinID);break;}
			case DIO_u8GROUPB:{TOG_BIT(PORTB,Copy_u8PinID);break;}
			case DIO_u8GROUPC:{TOG_BIT(PORTC,Copy_u8PinID);break;}
			case DIO_u8GROUPD:{TOG_BIT(PORTD,Copy_u8PinID);break;}
		}
	}
}

/*GET PIN VALUE*/
void DIO_enuGetPinValue(uint8 Copy_u8PortID,uint8 Copy_u8PinID,uint8 *Copy_pu8Value)
{
	if(Copy_pu8Value!=NULL)
	{
		if(Copy_u8PinID<=DIO_u8PIN7)
		{
	    	switch(Copy_u8PortID)
	    	{
	    		case DIO_u8GROUPA:{*Copy_pu8Value=GET_BIT(PINA,Copy_u8PinID);break;}
	    		case DIO_u8GROUPB:{*Copy_pu8Value=GET_BIT(PINB,Copy_u8PinID);break;}
	    		case DIO_u8GROUPC:{*Copy_pu8Value=GET_BIT(PINC,Copy_u8PinID);break;}
	    		case DIO_u8GROUPD:{*Copy_pu8Value=GET_BIT(PIND,Copy_u8PinID);break;}

	    	}
	    }
	}
}
