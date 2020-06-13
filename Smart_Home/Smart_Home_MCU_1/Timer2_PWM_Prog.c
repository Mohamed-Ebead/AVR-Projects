/*
 * Timer1_PWM_Prog.c
 *
 *  Created on: Feb 5, 2020
 *      Author: Mohamed  Ebead
 */

#include "STD_TYPES.h"
#include "registers.h"

#include "Timer2_interface.h"


void vid_Timer2_vid_InitializePWM (void)  {

		TCCR2_REG=0b01100011 ;

		OCR2_REG = 0X00 ;

}

