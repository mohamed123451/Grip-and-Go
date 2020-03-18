#ifndef _m_h
#define _m_h


#define F_CPU	16000000UL
#include <avr/io.h>
#include <util/delay.h>


/*********         for FUNCTIONS         *********/
#define	pin_write(reg,ind,val)	reg=(reg&(~(1<<ind)))|(val<<ind)
#define git_bit(reg,ind)			((reg>>ind)&0x01)
#define lnumber(reg,val)			reg=(reg&(0xf0))|val
#define hnumber(reg,val)			reg=(reg&(0x0f))|val<<4
//******end functions


/*********         for pins         *********/
#define		pin0	   0
#define		pin1	   1
#define		pin2	   2
#define		pin3	   3
#define		pin4	   4
#define		pin5	   5
#define		pin6	   6
#define		pin7	   7
//******end pin






#define     input       0
#define     output      1
#define     high        1
#define     low         0
#define		black		0
#define		white		1
#define		blackk		1
#define		whitee		0

#endif