/*
 * twophasetimer.c
 *
 * Created: 15-04-2023 06:21:54
 * Author : Arin Dhimar
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

char ch;

char s1[9]="ledon\n";
char s2[9]="ledoff\n";

int ct=0;

int main(void)
{
	cli();
	
	DDRB=0X20;
	PORTB=0X20;
	
	UBRR0=0X67;
	UCSR0A=0X00;
	UCSR0B=0XD0;
	UDR0=0X00;
	
	TCNT1=0X00;
	TCCR1A=0X00;
	TCCR1B=0X05;
	TIMSK1=0X01;
	
	
	
	sei();
    /* Replace with your application code */
    while (1) 
    {
    }
}


ISR(TIMER1_OVF_vect)
{
	if(PORTB==0X20)
	{
		UCSR0B=0XD8;
		TCNT1=0XF3C6;
		UDR0=s1[ct];
	}
	else
	{
		UCSR0B=0XD8;
		TCNT1=0XF3C6;
		UDR0=s2[ct];
	}
}

ISR(USART_TX_vect)
{
	ct=ct+1;
	
	if(ct==9)
	{
		ct=0;
		UDR0=0X00;
		UCSR0B=0XD0;
		TCNT1=0X48E4;
		
		if(PORTB==0X20)
		{
			PORTB=0X00;
		}
		else
		{
			PORTB=0X20;
		}
		
	}
}

