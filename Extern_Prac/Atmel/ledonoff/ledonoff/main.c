/*
 * ledonoff.c
 *
 * Created: 15-04-2023 05:00:29
 * Author : Arin Dhimar
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

int ck=0;

int main(void)
{
	cli();
	DDRB=0X20;
	PORTB=0X00;
	
	TCCR1A=0X00;
	TCCR1B=0X05;
	TCNT1=0X00;
	TIMSK1=0X01;
	
	sei();
    /* Replace with your application code */
    while (1) 
    {
    }
}

ISR(TIMER1_OVF_vect)
{
	TCNT1=0X48E4;
	
	if(ck==0||ck==1||ck==2)
	{
		if(ck==2)
		{
			if(PORTB==0x20)
			{
				PORTB=0x00;
				ck=0;
			}
			else if(PORTB==0X00)
			{
				PORTB=0X20;
				ck=0;
			}
		}
		ck=ck+1;
	}
}