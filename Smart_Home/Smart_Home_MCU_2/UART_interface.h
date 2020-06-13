/*
 * UART_prog.c
 *
 *  Created on: Oct 4, 2019
 *      Author: Mohamed  Ebead
 */



#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_




void UART_Init(void);

void UART_SendChar(u8 data);

u8 UART_GetChar(void);


#endif /* UART_INTERFACE_H_ */
