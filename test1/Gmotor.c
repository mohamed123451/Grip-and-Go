/*
 * Gmotor.c
 *
 * Created: 3/16/2019 8:55:42 PM
 *  Author: Mohamed
 */ 

#include "Gmotor.h"
#include "port.h"

void gmotor_init()
{
	TCCR1A |= (1<<COM1B1) | (1<<WGM10);					//NON INVERTING MODE
	//TCCR1A &= ~(1<<COM1B0);							// åì ßÏÇ ßÏÇ ÕÝÑ æ ÈÇáÊÇáì ããßä ãßÊÈåÇÔ
	TCCR1B |= (1<<CS10) | (1<<CS11) | (1<<WGM12);		//PRESCALER=64	
	//TCCR1B &= ~(1<<CS12);								// åì ßÏÇ ßÏÇ ÕÝÑ æ ÈÇáÊÇáì ããßä ãßÊÈåÇÔ
	
	
	
	pin_write(motor_pins_dir, Gmotor_out1, output);
	pin_write(motor_pins_dir, Gmotor_out2, output);
	pin_write(motor_pins_val, Gmotor_out1, high);
	pin_write(motor_pins_val, Gmotor_out2, low);
	
	DDRD |= 1<<PD4 ;	
}

void gmotor_speed(int s)
{
	OCR1B = s;
}

void open()
{
	pin_write(motor_pins_val, Gmotor_out1, high);
	pin_write(motor_pins_val, Gmotor_out2, low);
}

void close()
{
	pin_write(motor_pins_val, Gmotor_out1, low);
	pin_write(motor_pins_val, Gmotor_out2, high);
}