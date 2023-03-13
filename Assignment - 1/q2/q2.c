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
	_delay_ms(2000);
}

void forward()
{
	PORTA=0X06;
	_delay_ms(4000);
	stop();
}

void backward()
{
	PORTA=0X09;
	_delay_ms(4000);
	stop();
} 

void right()
{
	PORTA=0X0A;
	_delay_ms(4000);
	stop();
}

void left()
{
	PORTA=0X05;
	_delay_ms(4000);
	stop();
}


int main(void)
{
    /* Replace with your application code */
	pinsetup();
	
	cli();
	sei();
	forward();
	left();
	right();
	backward();
}