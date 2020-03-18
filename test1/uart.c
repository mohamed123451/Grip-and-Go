/*
 * uart.c
 *
 * Created: 3/13/2019 6:59:51 PM
 *  Author: Mohamed
 */ 


#include "uart.h"


void USART_Transmit( unsigned char data )
{
	/* Wait for empty transmit buffer*/
	while( !( UCSRA & (1<<UDRE)) )
	;
	/* Put data into buffer, sends the data*/
	UDR = data;
}

unsigned char USART_Receive( void)
{
	/* Wait for data to be received*/
	while( !(UCSRA & (1<<RXC)) );
	/* Get and return received data from buffer*/
	return UDR;
}

void USART_Init( unsigned int b )
{
	/* Set baud rate*/
	unsigned int baud = 16000000/16/b-1;
	UBRRH = (unsigned char)(baud>>8);
	UBRRL = (unsigned char)baud;
	/* Enable receiver and transmitter*/
	UCSRB = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 2stop bit*/
	UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
}
