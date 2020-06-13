/*
 * ADC_Interface.h
 *
 *  Created on: Feb 5, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


/**********************************************************/

void vid_ADC_vid_Initialize (void) ;
/* Initialize ADC :
 *
 * voltage reference : AVCC with external capacitor at AREF pin
 * ADC Left Adjust Result
 * disable ADC Auto Trigger
 * ADC Interrupt disable
 * ADC Prescaler = 2
 *  *
 */


/**********************************************************/

/**********************************************************/

void U8_ADC_U8_Read (u8 channel) ;

/*  ADC_Read :
 * it takes u8 channel ( the target channel) to which you
 * connect the hardware analog input
 * we have 8 ADC Channels A0...A7
 * so we must make sure that token channel value = 0 ... 7
 * other wise return error status or ( -1  )
 *
 * if token in logic so add it to lower 5 bits
 * in register ADMUX and start conversion
 *
 *
 * then return ADCH as the result is left adjusted
 * so you neglect lower two bits that are in ADCL
 *
 * */



/**********************************************************/


#endif /* ADC_INTERFACE_H_ */
