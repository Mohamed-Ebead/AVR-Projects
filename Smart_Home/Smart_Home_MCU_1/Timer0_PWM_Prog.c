/*
 * Timer1_PWM_Prog.c
 *
 *  Created on: Feb 5, 2020
 *      Author: Mohamed  Ebead
 */

#include "STD_TYPES.h"
#include "registers.h"


#include "Timer0_interface.h"


void vid_Timer0_vid_InitializePWM (void)  {

		TCCR0_REG=0b01100011 ;
		OCR0_REG = 0X00 ;

}

