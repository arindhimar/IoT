#include<avr/io.h>
#include<avr/interrupt.h>

char ch;

char s1[7]="ledon\n";
char s2[7]="ledoff\n";

int ct=0,prt=0;


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

  TCNT1=0XFEC6;

  TIMSK1=0X01;
  
  
}

void loop() {
  // put your main code here, to run repeatedly:

}


ISR(USART_RX_vect)
{
  ch=UDR0;
  if(ch=='a')
  {
    PORTB=0X20;
    prt=1;
    TIMSK1=0X01;
  }
  else if(ch=='b')
  {
    PORTB=0X00;
    prt=2;
    TIMSK1=0X01;
  }
}


ISR(TIMER1_OVF_vect)
{
  UCSR0B=0XD8;
  TCNT1=0XFEC6;
  if(prt==1)
  {
    UDR0=s1[ct];
  }
  else if(prt==2)
  {
    UDR0=s2[ct];
  }
}


ISR(USART_TX_vect)
{
  ct=ct+1;

  if(ct==7)

  {
    ct=0;
    prt=0;
    UCSR0B=0XD0;
    TIMSK1=0X00;
  }
}
