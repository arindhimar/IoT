/*
 * FlameBirdSquare.c
 *
 * Created: 2/16/2023 10:15:43 AM
 * Author : alvf
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void pinsetup()
{
	DDRA=0X0F;//to set the pins as output
	DDRL=0X18;//pwm i.e speed 
	PORTL=0X18;
}

void stop()
{
	PORTA=0X00;
	_delay_ms(5000);
}

void forward()
{
	PORTA=0X06;
	_delay_ms(20000);
	stop();
}

void backward()
{
	PORTA=0X09;
	_delay_ms(20000);
	stop();
} 


int main(void)
{
    /* Replace with your application code */
	pinsetup();
	
	cli();
	sei();
	forward();	
	backward();
	return 0;
}