/*
 * motor.c
 *
 * Created: 11/5/2018 10:36:24 PM
 *  Author: mohamed
 */ 

#include "motor.h"





motor_init()
{
	pin_write(motor_pins_dir,rightmotor_out1,output);
	pin_write(motor_pins_dir,rightmotor_out2,output);
	pin_write(motor_pins_dir,leftmotor_out1,output);
	pin_write(motor_pins_dir,leftmotor_out2,output);
	pin_write(motor_pins_val,rightmotor_out1,high);
	pin_write(motor_pins_val,rightmotor_out2,low);
	pin_write(motor_pins_val,leftmotor_out1,low);
	pin_write(motor_pins_val,leftmotor_out2,high);
	pin_write(DDRB,pin3,output);
	pin_write(DDRD,pin7,output);	
}



leftmotor_speed(char s)
{
	OCR0=s;
	TCCR0=(TCCR0&(~(1<<WGM01)))|(0<<WGM01);		// select mode ...
	pin_write(TCCR0,WGM00,high);				// mode -> fast pwm
	pin_write(TCCR0,CS02,low);					// clock selector
	pin_write(TCCR0,CS01,high);					//...
	pin_write(TCCR0,CS00,high);					// clk/64
	pin_write(TCCR0,COM00,low);					// compare output mode
	pin_write(TCCR0,COM01,high);				// non-inverted
		
}

rightmotor_speed(char s)
{
	
	OCR2=s;
	pin_write(TCCR2,WGM21,low);
	pin_write(TCCR2,WGM20,high);
	pin_write(TCCR2,CS22,high);
	pin_write(TCCR2,CS21,low);
	pin_write(TCCR2,CS20,low);
	pin_write(TCCR2,COM20,low);
	pin_write(TCCR2,COM21,high);
}



void forward()
{
	pin_write(motor_pins_val,rightmotor_out1,high);
	pin_write(motor_pins_val,rightmotor_out2,low);
	pin_write(motor_pins_val,leftmotor_out1,high);
	pin_write(motor_pins_val,leftmotor_out2,low);
}

void backward()
{
	pin_write(motor_pins_val,rightmotor_out1,low);
	pin_write(motor_pins_val,rightmotor_out2,high);
	pin_write(motor_pins_val,leftmotor_out1,low);
	pin_write(motor_pins_val,leftmotor_out2,high);
}

void reverse_right()
{
	pin_write(motor_pins_val,rightmotor_out1,low);
	pin_write(motor_pins_val,rightmotor_out2,high);
	pin_write(motor_pins_val,leftmotor_out1,high);
	pin_write(motor_pins_val,leftmotor_out2,low);
}

void reverse_left()
{
	pin_write(motor_pins_val,rightmotor_out1,high);
	pin_write(motor_pins_val,rightmotor_out2,low);
	pin_write(motor_pins_val,leftmotor_out1,low);
	pin_write(motor_pins_val,leftmotor_out2,high);
}