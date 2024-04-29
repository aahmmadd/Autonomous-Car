

#ifndef AUTO_INTERFACE_H_
#define AUTO_INTERFACE_H_

#include "Auto_config.h"


#include "../../MCAL/GIE/headers/GIE_interface.h"
#include "../../MCAL/Timer1/headers/Timer1_interface.h"

#include "../../HAL/LCD/headers/CLCD_interface.h"
#include "../../HAL/HCSR04/headers/HCSR04_interface.h"
#include "../../HAL/Servomotor/headers/Servo_interface.h"
#include "../../HAL/L293D/headers/L293D_interface.h"


//VARIABLES DECLARATIONS

uint8 Global_u8Distance,Global_u8Counter,Global_u8Flag;
uint16 Global_u16Time,Global_u16T1,Global_u16T2;



//FUNCTIONS DECLARATIONS

//CLCD FUNCS
void Print_welcome(void);
void Print_compare(uint8,uint8);
void Print_distance(uint8 Copy_u8Distance);


//ULTRA FUNCS
 uint16 Ultra_measure(void);
void Ultra_CaptCall(void);
void Ultra_OVFCall(void);

//CAR DIRECTIONS
void Car_Direction(Direction Copy_enuDirection);





#endif 