#ifndef INTERRUPT_VECTABLE_H
#define INTERRUPT_VECTABLE_H

/*--------INTERRUPT VECTOR TABLE--------*/

#define ISR(vect_num)			void vect_num (void)__attribute__((signal));\
								void vect_num (void)						
								

#define VECT_Timer1_CAPT				__vector_6
#define VECT_Timer1_COMPA				__vector_7
#define VECT_Timer1_COMPB				__vector_8
#define VECT_Timer1_OVF					__vector_9

#endif
