/*
 * Timer1_interface.h
 *
 *  Created on: Feb 5, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

/**********************************************************/

void vid_Timer0_vid_InitializePWM (void) ;
/* Timer_0 Initialization :
 * mode 1 : PWM, Phase Correct
 *Clear OC0 on compare match when up-counting.
 *Set OC0 on compare match when downcounting.
 * i/p clk / 64   from prescaler
 *
 */

/**********************************************************/
#endif /* TIMER0_INTERFACE_H_ */
