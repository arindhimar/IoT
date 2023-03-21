/*
 * FlameBirdSquare.c
 *
 * Created: 2/16/2023 10:15:43 AM
 * Author : alvf
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int ck=0;

void pinsetup()
{
	DDRA=0X0F;//to set the pins as output
	DDRL=0X18;//pwm i.e speed 
	PORTL=0X18;
	TCSR0B=0X05;
	T1MSK1=0X00;
	TCNT1=0X00;
}

void delay()
{
	T1MSK1=0X01;
	
}

ISR(TIMER1_OVF_vect)
{
	TXNT1=0X0BDB;
	T1MSK1=0X00;	
}



void forward()
{
	PORTA=0X06;
	//_delay_ms(4000);
	delay();
}

void backward()
{
	PORTA=0X09;
	//_delay_ms(4000);
	//stop();
	delay();
} 

void right()
{
	PORTA=0X0A;
	//_delay_ms(4000);
	//stop();	
	delay();
}

void left()
{
	PORTA=0X05;
	//_delay_ms(4000);
	//stop();
	delay();
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