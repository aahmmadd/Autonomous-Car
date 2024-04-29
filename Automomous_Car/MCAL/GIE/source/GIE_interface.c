#include "../headers/GIE_interface.h"


void GIE_voidInit(void)
{
	#if GIE_State == GIE_Enable
	SET_BIT(SREG,7);
	#elif GIE_State == GIE_Disable
	CLR_BIT(SREG,7);
	#else
	#error "INVALID GIE STATE"
	#endif
}
