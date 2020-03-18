/*
 * motor.h
 *
 * Created: 11/5/2018 10:34:25 PM
 *  Author: mohamed
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

#include "port.h"



extern char s;

void motor_init();
void leftmotor_speed(char);
void rightmotor_speed(char);
void forward();
void backward();
void reverse_right();
void reverse_left();




#endif /* MOTOR_H_ */