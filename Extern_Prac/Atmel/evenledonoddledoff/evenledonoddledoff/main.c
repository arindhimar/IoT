/*
 * evenledonoddledoff.c
 *
 * Created: 15-04-2023 05:41:43
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
	int val = UDR0 + '0';
	
	if(val%2==0)
	{
		PORTB=0X20;
	}
	else
	{
		PORTB=0X00;
	}
}