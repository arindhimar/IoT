#include<avr/io.h>
#include<avr/interrupt.h>

char ch;


void setup() {
  // put your setup code here, to run once:
    DDRB=0X20;
    PORTB=0X00;

    TCCR1A=0X00;
    TCCR1B=0X5;
    TCNT1=0X00;
    TIMSK1=0X01;

    UBRR0=0X67;
    UCSR0A=0X00;
    UCSR0B=0XD0;
    UDR0=0X00;

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
  }
  else if(ch=='b')
  {
    TCNT1=0X48E4;
    TIMSK1=0X01;
  }
}


ISR(TIMER1_OVF_vect)
{
  if(PORTB==0X20)
  {
    PORTB=0X00;
  }
  else
  {
    PORTB=0X20;
  }
  TIMSK1=0X00;
}
