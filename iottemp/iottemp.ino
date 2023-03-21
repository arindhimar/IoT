#include<avr/interrupt.h>
#include<avr/io.h>

void setup()
{
  DDRB=0X20;
  TCCR1A=0X00;
  TCCR1B=0X05;
  TCCR1C=0X00;
  TCNT1=0XA471;
  TIMSK1=0X01;
  //interrupts();

  
  
}

void loop()
{

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
  TCNT1=0XA471;
}
