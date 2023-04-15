/*
 * ldr.c
 *
 * Created: 15-04-2023 06:02:12
 * Author : Arin Dhimar
 */ 

#include <avr/io.h>
#include<avr/interrupt.h>

int val;


int main(void)
{
	cli();
	
	DDRB=0X20;
	PORTB=0X00;
	
	ADMUX=0X40;
	ADCSRA=0XEF;
	
	
	sei();
    /* Replace with your application code */
    while (1) 
    {
    }
}

ISR(ADC_vect)
{
	val = ADCL | ( ADCH << 8);
	if(val>1000)
	{
		PORTB=0X20;
	}	
	else
	{
		PORTB=0X00;
	}
}

