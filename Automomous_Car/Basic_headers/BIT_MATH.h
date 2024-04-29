/* BIT_MATH LIBRARY */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(VAL,BIT)		VAL|=(1<<BIT)
#define CLR_BIT(VAL,BIT)		VAL&=(~(1<<BIT))
#define TOG_BIT(VAL,BIT)		VAL^=(1<<BIT)
#define GET_BIT(VAL,BIT)		(VAL>>BIT)&1

#endif
