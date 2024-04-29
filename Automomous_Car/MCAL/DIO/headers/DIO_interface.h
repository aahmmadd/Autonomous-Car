
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H




#include "DIO_priv.h"
#include "DIO_config.h"

/*INITIALIZE DIRECTION AND VALUE OF PORTS*/
void DIO_enuInit(void);

/*SET PIN DIRECTION*/
void DIO_enuSetPinDirection(uint8 Copy_u8PortID,uint8 Copy_u8PinID,uint8 Copy_u8Direction);

/*SET PIN VALUE*/
void DIO_enuSetPinValue(uint8 Copy_u8PortID,uint8 Copy_u8PinID,uint8 Copy_u8Value);

/*TOGGLE PIN VALUE*/
void DIO_enuTogglePinValue(uint8 Copy_u8PortID,uint8 Copy_u8PinID);

/*GET PIN VALUE*/
void DIO_enuGetPinValue(uint8 Copy_u8PortID,uint8 Copy_u8PinID,uint8 *Copy_pu8Value);


#endif
