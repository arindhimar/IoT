/*
 * adctry.c
 *
 * Created: 24-03-2023 20:41:13
 * Author : Arin Dhimar
 */ 

#include <avr/io.h>
#include<avr/interrupt.h>

int i;


int main(void)
{
	cli();
	  i = 0X00;
	  TCCR1A=0X00;
	  TCCR1B=0X00;

	  DDRB=0X20;
	  
	  TCNT1=0X85ED;
	  TCCR1B=0X05;

	  TIMSK1=0X01;
	  
	  PORTB=0X00;
	sei();
    /* Replace with your application code */
    while (1) 
    {
    }
}

ISR(TIMER1_OVF_vect){
	

	if(PORTB==0X00){
		PORTB=0X20;
	}
	else{
		PORTB=0X00;
	}
	TCNT1=0X85ED;
}
