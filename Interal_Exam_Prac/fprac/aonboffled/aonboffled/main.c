/*
 * aonboffled.c
 *
 * Created: 25-03-2023 05:26:55
 * Author : Arin Dhimar
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

char ch;
char s1[10]=" ledon\n";
char s2[10]=" ledoff\n";

int ck=0,k=0,i=0;

int main(void)
{
	cli();
	DDRB=0X20;
	PORTB=0X00;
	
	TCCR1A=0X00;
	TCCR1B=0X05;
	
	TCNT1=0XC2F6;
	TIMSK1=0X00;
	
	UCSR0B=0XD0;
	UCSR0C=0X06;
	
	UBRR0=0X67;
	UDR0=0;
	
	sei();
    /* Replace with your application code */
    while (1) 
    {
    }
}

ISR(USART0_TX_vect)
{
	i=i+1;
	
	if(i==9)
	{
		k=0;
		TIMSK1=0x01;
		i=0;
		UCSR0B=0XD0;
	}
}

ISR(USART0_RX_vect)
{
	ch=UDR0;
	if(ch=='a')
	{
		UCSR0B=0XD8;
		PORTB=0X20;
		k=1;
		TIMSK1=0X01;
		UDR0=0;	
		

	}
	else if(ch=='b')
	{
		UCSR0B=0XD8;
				PORTB=0X00;
				k=2;
		TIMSK1=0X01;
	UDR0=0;
		
	}
}


ISR(TIMER1_OVF_vect)
{
	
	
	if(k==1)
	{
		UDR0=s1[i];
	}
	else if(k==2)
	{
		UDR0=s2[i];
	}
	TCNT1=0XFF62;
}