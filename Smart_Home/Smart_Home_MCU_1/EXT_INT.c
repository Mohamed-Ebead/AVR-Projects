/*
 * EXT_INT0.c
 *
 *  Created on: Feb 8, 2020
 *      Author: Mohamed  Ebead
 */



#include "avr/interrupt.h"
#include "util/delay.h"
#include "STD_Types.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "registers.h"
#include "Configuration.h"
#include "BIT_MATH.h"
#include "EXT_INT_INTERFACE.H"


void vid_ExtInt0_vid_InitializeExtInt (void) {

	CLR_BIT(MCUCR_REG,0) ;        // falling edge generates an interrupt
	SET_BIT(MCUCR_REG,1) ;

	 SET_BIT(GICR_REG,6) ;         // enable INT 0

   // SET_BIT (SREG_REG,7) ;

	 asm ("SEI") ;   //ENABLE GLOBAL INTERRUPT

}


void vid_ExtInt1_vid_InitializeExtInt (void) {

	CLR_BIT(MCUCR_REG,2) ;
	SET_BIT(MCUCR_REG,3) ;

	 SET_BIT(GICR_REG,7) ;     // enable INT 1


	 asm ("SEI") ;   //ENABLE GLOBAL INTERRUPT

}

/*
void vid_ExtInt2_vid_InitializeExtInt (void) {

	SET_BIT(MCUCSR_REG,6) ;        // RISING edge generates interrupt

	 SET_BIT(GICR_REG,5) ;        // enable INT 2


	 asm ("SEI") ;   //ENABLE GLOBAL INTERRUPT

}
*/
