/*
 * Registers.h
 *
 *  Created on: Jan 30, 2020
 *      Author: Mohamed Ebead
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_


/************************ Group A Registers *********************/
#define PORTA_REG  (*((volatile u8*)0x3B))
#define DDRA_REG   (*((volatile u8*)0x3A))

/********************** Group B Registers ***********************/
#define PORTB_REG  (*((volatile u8*)0x38))
#define DDRB_REG   (*((volatile u8*)0x37))

/********************** Group C Registers ***********************/
#define PORTC_REG  (*((volatile u8*)0x35))
#define DDRC_REG   (*((volatile u8*)0x34))

/********************** Group D Registers ***********************/
#define PORTD_REG  (*((volatile u8*)0x32))
#define DDRD_REG   (*((volatile u8*)0x31))




/**************************** ADC ******************************/

#define SFIOR_REG   (*((volatile u8*)0x50))

#define ADMUX_REG   (*((volatile u8*)0x27))
#define ADCSRA_REG  (*((volatile u8*)0x26))

#define ADCH_REG    (*((volatile u8*)0x25))
#define ADCL_REG    (*((volatile u8*)0x24))

#define ADSC    6
#define ADIF 4

/*************************** Timer_1 ***************************/

#define TCCR1A_REG   (*((volatile u8*)0x4F))
#define TCCR1B_REG   (*((volatile u8*)0x4E))
#define TCNT1H_REG   (*((volatile u8*)0x4D))
#define TCNT1L_REG   (*((volatile u8*)0x4C))
#define OCR1AH_REG   (*((volatile u8*)0x4B))
#define OCR1AL_REG   (*((volatile u8*)0x4A))
#define OCR1BH_REG   (*((volatile u8*)0x49))
#define OCR1BL_REG   (*((volatile u8*)0x48))
#define ICR1H_REG    (*((volatile u8*)0x47))
#define ICR1L_REG    (*((volatile u8*)0x46))


#define TIMSK_REG    (*((volatile u8*)0x59))
#define TIFR_REG     (*((volatile u8*)0x58))







/*---------------------Timer0-------------------*/

#define OCR0_REG      (*((volatile u8*)0x5C))
#define TCCR0_REG     (*((volatile u8*)0x53))
#define TCNT0_REG     (*((volatile u8*)0x52))

/*---------------------Timer2-------------------*/

#define OCR2_REG      (*((volatile u8*)0x43))
#define TCCR2_REG     (*((volatile u8*)0x45))
#define TCNT2_REG     (*((volatile u8*)0x44))

/*--------------------- External Interrupt 0 -------------------*/

#define MCUCR_REG     (*((volatile u8*)0x55))
#define MCUCSR_REG    (*((volatile u8*)0x54))
#define GICR_REG      (*((volatile u8*)0x5B))
#define GIFR_REG      (*((volatile u8*)0x5A))

#define SREG_REG      (*((volatile u8*)0x5F))












#endif /* REGISTERS_H_ */
