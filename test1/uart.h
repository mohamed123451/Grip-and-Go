/*
 * uart.h
 *
 * Created: 3/13/2019 6:59:29 PM
 *  Author: Mohamed
 */ 


#ifndef UART_H_
#define UART_H_

#include "micro.h"



void USART_Transmit( unsigned char data );
unsigned char USART_Receive( void);
void USART_Init( unsigned int b );





#endif /* UART_H_ */