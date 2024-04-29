// THIS FILE SETS UNCHANGED VALUES FOR DIO

#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_


#include "../../../Basic_headers/STD_TYPES.h"
#include "../../../Basic_headers/BIT_MATH.h"

#include "DIO_register.h"

#define F_CPU									16000000UL
#include <util/delay.h>




//DEFINING THE 4 4GROUPS
#define DIO_u8GROUPA							0
#define DIO_u8GROUPB							1
#define DIO_u8GROUPC							2
#define DIO_u8GROUPD							3

//DEFINING MC PINS
#define DIO_u8PIN0								0
#define DIO_u8PIN1								1
#define DIO_u8PIN2								2
#define DIO_u8PIN3								3
#define DIO_u8PIN4								4
#define DIO_u8PIN5								5
#define DIO_u8PIN6								6
#define DIO_u8PIN7								7


//VALUES FOR PINS

//DEFINING INPUT AND OUTPUT VALUES FOR DDRS
#define DIO_u8PIN_INPUT							0
#define DIO_u8PIN_OUTPUT						1

//DEFINING WHETHER USING INTERNAL OR EXTERNAL RESISTORS INCASE OF INPUT
#define DIO_u8FLOAT								0
#define DIO_u8PULL_UP							1

//DEFINING THE VALUE OF THE PIN INCASE OF OUTPUT
#define DIO_u8PIN_LOW							0
#define DIO_u8PIN_HIGH							1


//A MACRO FOR CHANGING A WORD-SIZED VALUE ALL AT ONCE
#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0) 		0b##b7##b6##b5##b4##b3##b2##b1##b0
#define CONC(b7,b6,b5,b4,b3,b2,b1,b0) 			CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)

//NULL POINTER VALUE
#define NULL	((void*)0x00)

#endif
