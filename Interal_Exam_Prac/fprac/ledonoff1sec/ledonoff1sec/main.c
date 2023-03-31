/*
 * ledonoff1sec.c
 *
 * Created: 25-03-2023 05:21:22
 * Author : Arin Dhimar
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	cli();
	DDRB=0X20;
	PORTB=0X20;
	
	TCCR1A=0X00;
	TCCR1B=0X05;
	
	TCNT1=0XC2F6;
	
	TIMSK1=0X01;
	sei();
    /* Replace with your application code */
    while (1) 
    {
		
    }
}

ISR(TIMER1_OVF_vect)
{
	
	if(PORTB==0X00)
	{
		PORTB=0X20;
	}
	else
	{
		PORTB=0X00;
	}
	TCNT1=0XC2F6;
}

