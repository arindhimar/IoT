#include<avr/io.h>
#include<avr/interrupt.h>

char ch;
char s1[10]="LEDON\n";
char s2[10]="LEDOFF\n";

int ct=0,i=0,k=0;

void setup() {
  // put your setup code here, to run once:

  DDRB=0X20;
  PORTB=0X00;

  TCCR1A=0X00;
  TCCR1B=0X05;
  TCNT1=0X00;
  TIMSK1=0X00;

  UBRR0=0X67;
  UCSR0B=0XD0;
  UCSR0C=0X06;
  UDR0=0;

  
  interrupts();
}

void loop() {
  // put your main code here, to run repeatedly:

}

ISR(USART_TX_vect)
{
  i=i+1;
  TCNT1=0XF0BD;

  if(i==8)
  {
    i=0;
    k=0;
    TCNT1=0X00;
    TIMSK1=0X00;
    UCSR0B=0XD0;
  }
  
}


ISR(USART_RX_vect)
{
  ch=UDR0;
  if(ch=='a')
  {
    k=1;
    TCNT1=0XF0BD;
    TIMSK1=0X01;
    PORTB=0X20;
  }
  else if(ch=='b')
  {
    k=2;
    TCNT1=0XF0BD;
    TIMSK1=0X01;
    PORTB=0X00;
  }
  
}


ISR(TIMER1_OVF_vect)
{
  
  UCSR0B=0XD8;
  if(k==1)
  {
   UDR0=s1[i];
  }
  else if(k==2)
  {
    UDR0=s2[i];
  }
}
