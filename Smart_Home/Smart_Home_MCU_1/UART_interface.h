/*
 * UART_interface.h
 *
 *  Created on: Oct 4, 2019
 *      Author: Ahmed
 */



#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_




void vid_UART_vid_Initialize(void);

void vid_UART_vid_SendChar(u8 data);

u8 u8_UART_u8_GetChar(void);


#endif /* UART_INTERFACE_H_ */
