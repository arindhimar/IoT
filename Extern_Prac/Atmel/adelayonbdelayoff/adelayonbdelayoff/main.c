/*
 * adelayonbdelayoff.c
 *
 * Created: 15-04-2023 05:45:37
 * Author : Arin Dhimar
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

char ch;


int main(void)
{
	cli();
	DDRB=0X20;
	PORTB=0X00;
	
	TCCR1A=0X00;
	TCCR1B=0X05;
	TCNT1=0X00;
	TIMSK1=0X00;
	
	UBRR0=0X67;
	UCSR0A=0X00;
	UCSR0B=0XD0;
	UDR0=0X00;
	sei();
    /* Replace with your application code */
    while (1) 
    {
    }
}

ISR(USART_RX_vect)
{
	ch=UDR0;
	
	if(ch=='a')
	{
		TCNT1=0X48E4;
		TIMSK1=0X01;
		
	}
	else if(ch=='b')
	{
		TCNT1=0X48E4;
		TIMSK1=0X01;
	}
}


ISR(TIMER1_OVF_vect)
{
	if(ch=='a')
	{
		PORTB=0X20;
		TCNT1=0X00;
		TIMSK1=0X00;
	}
	else if(ch=='b')
	{
		PORTB=0X00;
		TCNT1=0X00;
		TIMSK1=0X00;
	}
}