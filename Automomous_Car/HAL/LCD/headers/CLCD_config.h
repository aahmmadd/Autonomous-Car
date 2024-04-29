#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_



#include "CLCD_priv.h"



/*-----------CONTROL PINS-----------*/

#define CLCD_CTRL_PORT			DIO_u8GROUPA

#define RS_PORT					DIO_u8GROUPA
#define RS_PIN					DIO_u8PIN1

#define RW_PORT 				DIO_u8GROUPA
#define RW_PIN  				DIO_u8PIN2

#define EN_PORT 				DIO_u8GROUPA
#define EN_PIN  				DIO_u8PIN3


/*-----------DATA PINS-----------*/

#define CLCD_DATA_PORT		DIO_u8GROUPA

#define D7_PORT				DIO_u8GROUPA
#define D7_PIN				DIO_u8PIN7

#define D6_PORT 			DIO_u8GROUPA
#define D6_PIN  			DIO_u8PIN6

#define D5_PORT        		DIO_u8GROUPA
#define D5_PIN     			DIO_u8PIN5

#define D4_PORT 	        DIO_u8GROUPA
#define D4_PIN      	    DIO_u8PIN4


/*-----------LINES ADDRESSES BORDERS-----------*/

#define FIRST_LINE			0x80
#define FIRST_LINE_END		0x8f
#define SECOND_LINE			0xc0
#define SECOND_LINE_END		0xcf

#endif
