#ifndef CLCD_PRIV_H_
#define CLCD_PRIV_H_

#include "../../../MCAL/DIO/headers/DIO_interface.h"


/*-----------DELAY TIME OF CLCD EIGIHT BIT POWER SETTINGS-----------*/

#define FUNCTION_SET			35
#define DISPLAY_CONTROL			45
#define DISPLAY_CLEAR			45
#define ENTRY_MODE_SET			2

/*-----------DISPLAY DIRECTION-----------*/
#define DISPLAY_RIGHT			0
#define DISPLAY_LEFT			1

/*-----------CURSOR DIRECTION-----------*/
#define CURSOR_RIGHT			0
#define CURSOR_LEFT				1


/*-----------SENDING NIPPLE AND DATA TO CLCD-----------*/
static void CLCD_voidWriteAndLatch(uint8 Copy_u8Nipple);
//CONVERTING INTEGER DIGIT TO CHARACTER
static uint8 CLCD_voidItoStr(uint8 u8Int);


#endif
