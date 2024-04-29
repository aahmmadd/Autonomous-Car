#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

#include "CLCD_priv.h"
#include "CLCD_config.h"


//INITIALIZES DATA PINS DIRECTIONS AND POWER SETTINGS
void CLCD_voidInit(void);


//SENDING DATA
void CLCD_voidSendData(uint8 Copy_u8Data);
//SENDING COMMAND
void CLCD_voidSendCommand(uint8 Copy_u8Command);


//CLEARING DISPLAY
void CLCD_voidClearDisplay(void);
//RETURN HOME
void CLCD_voidReturnHome(void);
//DISPLAY SHIFT
void CLCD_voidShiftDisplay(uint8 Copy_u8Direction);
//CURSOR SHIFT
void CLCD_voidShiftCursor(uint8 Copy_u8Direction);


//SENDING STRING
void CLCD_voidSendpcString(const char *Copy_pcstring);
//SENDING INTEGER NUMBER
void CLCD_voidDisplayIntegerNum(sint32 Copy_s32Num);
//SENDING FLOAT NUMBER
void CLCD_voidDisplayFloatNum(f32 Copy_f32Num);


//SEND X,Y POSITION
void CLCD_voidSendPositionXY(uint8 x,uint8 y);

 


#endif
