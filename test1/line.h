/*
 * line.h
 *
 * Created: 11/18/2018 1:19:15 PM
 *  Author: mohamed
 */ 


#ifndef LINE_H_
#define LINE_H_

#include "motor.h"


void sensor_init();

void move_on();
void back();
void stop();
void forward_right();
void forward_left();
void backward_left();
void backward_right();
void turn90right();
void turn90left();




#endif /* LINE_H_ */