/*
 * Grip_and_Go.c
 *
 * Created: 3/15/2019 8:04:16 PM
 *  Author: Mohamed
 *  
 *
 *	content :-
			bleutooth
			three motors
			one servo
 *
 *
 */ 


#include "uart.h"
#include "servo.h"
#include "line.h"
#include "Gmotor.h"



int main(void)
{
	int position = 316;
	
	USART_Init(9600);
	motor_init();
	servo_init();
	unsigned char d;
	DDRA = 255;
	
	OCR1A = 316 ;
	s=0;
	int x = 30 ;		//for gmotor   Griper
	int ba=320;
	
    while(1)
    {		
		d = USART_Receive();
		
		////**** Test Bleutooth ****////
		if (d == 'U')
		{
			PORTA=1;
		}
		else if (d == 'u')
		{
			PORTA=0;
		}
		else if ( d == 'I')
		{
			PORTA = 2;
		}
		else if ( d == 'i')
		{
			PORTA = 0;
		}
		////**** End Test Bleutooth ****////
		
		
		///////*** MOVING ***////////
		if ( d == 'Q')
		{
			move_on();
		}
		else if ( d == 'q')
		{
			back();
		}
		else if ( d == 'e')
		{
			forward_left();
		}
		else if ( d == 'E')
		{
			forward_right();
		}
		else if ( d == 'r')
		{
			backward_left();
		}
		else if ( d == 'R')
		{
			backward_right();
		}
		else if ( d == 'w')
		{
			turn90left();
		}
		else if ( d == 'W')
		{
			turn90right();
		}
		else if ( d == 'a' )
		{
			stop();
		}
		/////////*** END MOVING ***//////
		
		
		///////*** speed
		if ( d == 'T')
		{
			s = 255;
		} 
		else if( d == 't')
		{
			s = 200;
		}
		else if ( d == 'Y')
		{
			s = 150;
		}
		else if ( d == 'y')
		{
			s = 100;
		}
		///////*** end speed
		
		
		////////**** Griper ****///////
		if ( d == 'O')
		{
			
			angle(535);
			position = 525;
			
		}
		else if ( d == 'o')
		{
			angle(100);
			position = 100;
			/*
			int y = position ;
			while(d!='y')
			{
				y-=10;
				position = y;
				angle(position);
				
			}
			//position=200;
			*/
		}
		else if ( d == 'P')
		{
			angle(425);
			position = 425;
		}
		else if ( d =='p')
		{
			angle(200);
			position = 200;
		}
		else if ( d == 'A')
		{
			angle(316);
			position = 316;
		}
		////////**** End Griper
		
		
		
		//////////********test servo
		
		if (d=='D')
		{
			position+=5;
			angle(position);
		}
		else if (d=='d')
		{
			position-=5;
			angle(position);
		}
		else if (d=='F')
		{
			position+=10;
			angle(position);
		}
		else if (d=='f')
		{
			position-=10;
			angle(position);
		}
		else if (d=='G')
		{
			position+=20;
			angle(position);
		}
		else if (d=='g')
		{
			position-=20;
			angle(position);
		}
		else if (d=='H')
		{
			position+=30;
			angle(position);
		}
		else if (d=='h')
		{
			position-=30;
			angle(position);
		}
		else if (d=='J')
		{
			position+=40;
			angle(position);
		}
		else if (d=='j')
		{
			position-=40;
			angle(position);
		}
		else if (d=='K')
		{
			position+=50;
			angle(position);
		}
		else if (d=='k')
		{
			position-=50;
			angle(position);
		}
		
		
		/////////******* end test servo
		
		
		/////***** Griper
		if ( d == 'Z')
		{
			x = 180;
		} 
		else if ( d == 'z')
		{
			x = 150;
		}
		else if ( d == 'X')
		{
			x = 120;
		}
		else if ( d == 'x')
		{
			x = 90;
		}
		else if ( d == 'C')
		{
			x = 200;
		}
		else if ( d == 'c')
		{
			x = 50;
		}
		
		
		
		if ( d == 'L')
		{
			open();
			gmotor_speed(2000);
		} 
		else if ( d == 'l')
		{
			close();
			gmotor_speed(2000);
		}
		else if ( d == 'V')
		{
			gmotor_speed(0);
		}
				
		/////**** end Griper
		   
		
		/////**** sss
		if ( d =='S')
		{
			s=0;
			x=0;
			angle(150);
			PORTA = 2 ;
			_delay_ms(500);
			PORTA=0;
			
		} 
		else if ( d == 's')
		{
			s=50;
			x=30;
			angle(450);
			PORTA = 2 ;
			_delay_ms(500);
			PORTA=0;
			_delay_ms(500);
			PORTA = 2 ;
			_delay_ms(500);
			PORTA=0;
			
		}
		////**** end sss   
		
		
		
		////**** angle 
		
		if (position>ba)
		{
			PORTA = 2;			
		}
		else
		{
			pin_write(PORTA, pin1, 0);
		}
		
		
		if ( d == 'B')
		{
			ba+=10;
			PORTA = 2;
			_delay_ms(300);
			PORTA = 0;
		}
		else if ( d == 'b')
		{
			ba-=10;
			PORTA = 2;
			_delay_ms(300);
			PORTA = 0;
		}
					
				
		////**** end angle    
			   
			   
		
			   
    }
}