/*
 * UART_prog.c
 *
 *  Created on: Oct 4, 2019
 *      Author: Mohamed  Ebead
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_interface.h"
#include "UART_private.h"



/******************************************************************/

void UART_Init(void)
{
  // Set BaudRate -> 9600/8MhZ
  UBRRL = 51;
  UBRRH = 0;
  // Set Frame Format -> 8 data, 1 stop, No Parity
  UCSRC = 0b10000110;
  // Enable RX and TX
  UCSRB = 0b00011000;
}


/******************************************************************/

void UART_SendChar(u8 data)
{
  // Wait until transmission Register Empty
  while(!(UCSRA&0b00100000));
  UDR = data;
}

/******************************************************************/

u8 UART_GetChar(void)
{
  // Wait until Reception Complete
  while(!(UCSRA&0b10000000));

  return UDR;
}

/******************************************************************/
