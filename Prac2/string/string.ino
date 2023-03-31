#include<avr/io.h>
#include<avr/interrupt.h>

char ch;

char s1[7]="vnsgu\n";// v0 n1 s2 g3 u4
char s2[7]="india\n";

int ck=0,i=0,k=0;

void setup() {

  DDRB=0X20;
  PORTB=0X00;

  TCCR1B=0X05;

  TCNT1=0XC2F6;

  TIMSK1=0X00;
  
  // put your setup code here, to run once:
  UCSR0B=0XD0;
  UBRR0=0X67;
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

  if(i==7)
  {
    i=0;
    TIMSK1=0X00;
    UCSR0B=0XD0;

    ck=0;
  }
}


ISR(USART_RX_vect)
{
  ch=UDR0;
  if(ch=='a')
  {
    TIMSK1=0X01;
    PORTB=0X20;
    UCSR0B=0XD8;
    ck=1; 
  }
  else if(ch=='b')
  {
    TIMSK1=0X01;
    PORTB=0X00;
    UCSR0B=0XD8;
    ck=2;
  }
}


ISR(TIMER1_OVF_vect)
{
  TCNT1=0XC2F6;
  if(ck==1)
  {
    UDR0=s1[i];
  }
  else if(ck==2)
  {
    UDR0=s2[i];
  }
}

