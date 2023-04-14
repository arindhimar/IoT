#include<avr/io.h>
#include<avr/interrupt.h>

char ch;

char s1[9]="ledon\n";
char s2[9]="ledoff\n";

int ct=0;


void setup() {
  // put your setup code here, to run once:

  DDRB=0X20;
  PORTB=0X00;

  UBRR0=0X67;
  UCSR0A=0X00;
  UCSR0B=0XD0;
  UDR0=0X00;

  TCCR1A=0X00;
  TCCR1B=0X05;
  TCNT1=0X00;
  TIMSK1=0X01;

}

void loop() {
  // put your main code here, to run repeatedly:

}

ISR(TIMER1_OVF_vect)
{
  UCSR0B=0XD8;
  if(PORTB==0X00)
  {
    UDR0=s1[ct];
  }
  else if(PORTB==0X20)
  {
    UDR0=s2[ct];
  }
  TCNT1=0XFEC6;
}

ISR(USART_TX_vect)
{
  ct=ct+1;

  if(ct==9)
  {
    ct=0;
    UCSR0B=0XD0;
    

    if(PORTB==0X20)
    {
      PORTB=0X00;
    }
    else
    {
      PORTB=0X20;
    }

    TCNT1=0XBDB;
  }
}
