#include<avr/io.h>
#include<avr/interrupt.h>

char ch;

int ck=0;

void setup() {
  // put your setup code here, to run once:

  DDRB=0X20;
  PORTB=0X00;
  
  UBRR0=0X67;

  UCSR0B=0XD0;
  UCSR0C=0X06;

  UDR0=0;

  TCCR1A=0X00;
  TCCR1B=0X05;

  TCNT1=0X00;
  TIMSK1=0X00;
  interrupts();
}

void loop() {
  // put your main code here, to run repeatedly:

}

ISR(USART_RX_vect)
{
  ch=UDR0;
  if(ch=='a')
  {
    TCNT1=0X48E4;
    TIMSK1=0X01;
    
    ck=1;
  }
  else if(ch=='b')
  {
    TCNT1=0X48E4;
    TIMSK1=0X01;
    
    ck=2;
  }
}

ISR(TIMER1_OVF_vect)
{
  if(ck==1)
  {
    PORTB=0X20;
  }
  else if(ck==2)
  {
    PORTB=0X00;
  }
  TIMSK1=0X00;
  ck=0;
}
