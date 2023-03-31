/*
 * Ldd.c
 *
 * Created: 25-03-2023 05:48:40
 * Author : Arin Dhimar
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

int val;
int ck=0;


int main(void)
{
	UCSR0B=0XD8;
	UBRR0=0X67;
	ADMUX=0X40;
	DDRB=0X20;
	ADCSRA=0XEF;
    /* Replace with your application code */
    while (1) 
    {
		if(ck==1)
		{
			printf("%d",val);
			ADCSRA=0XEF;
			ck=0;
			PORTB=0X00;	
		}
		
    }
}

ISR(ADC_vect)
{
	ck=1;
	val=ADCL|(ADCH<<8);
}

