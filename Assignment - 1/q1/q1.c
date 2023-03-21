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
	TCCR1A=0X00;
	TCCR1B=0X05;
	T1MSK1=0X00;
	TCNT1=0X00;
}

void delay()
{	
	T1MSK1=0X01;
	ck=1;
}

ISR(TIMER1_OVF_vect)
{
	if(ck==1||ck==2||ck==3||ck==4||ck==5){
		TCNT1=0X0BDB;
		ck=ck+1;
	}
	if(ck==6)
	{
		ck=0;
		T1MSK1=0X00;
	}
}

void stop()
{
	PORTA=0X00;
	//_delay_ms(5000);
	delay();
}

void forward()
{
	PORTA=0X06;
	//_delay_ms(20000);
	delay();
	stop();
}

void backward()
{
	PORTA=0X09;
	//_delay_ms(20000);
	delay();
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