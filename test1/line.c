/*
 * line.c
 *
 * Created: 11/18/2018 1:21:55 PM
 *  Author: mohamed
 */ 

#include "line.h"

char s;


void move_on()
{
	forward();
	rightmotor_speed(s);
	leftmotor_speed(20+s);
}

void back()
{
	backward();
	rightmotor_speed(s);
	leftmotor_speed(s+20);
	
}

void stop()
{
	forward();
	rightmotor_speed(0);
	leftmotor_speed(0);
}


void forward_right()
{
	forward();
	rightmotor_speed(0);
	leftmotor_speed(s);
	
}

void forward_left()
{
	forward();
	rightmotor_speed(s-20);
	leftmotor_speed(0);
}

void backward_right()
{
	backward();
	rightmotor_speed(0);
	leftmotor_speed(s);
}

void backward_left()
{
	backward();
	rightmotor_speed(s-20);
	leftmotor_speed(0);
}


void turn90right()
{
	reverse_right();
	rightmotor_speed(s);
	leftmotor_speed(s);
}

void turn90left()
{
	reverse_left();
	rightmotor_speed(s);
	leftmotor_speed(s);
}
