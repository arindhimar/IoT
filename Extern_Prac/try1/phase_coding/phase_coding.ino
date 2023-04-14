#include<avr/io.h>
#include<avr/interrupt.h>

char s1[7]="ledon\n";
char s2[7]="ledoff\n";

int ct,pt,ph=0;

void setup() {
  // put your setup code here, to run once:
  DDRB=0X20;
  PORTB=0X00;

  


  TCCR1A=0X00;
  TCCR1B=0X05;
  TCNT1=0X85ED;
  TIMSK1=0X01;

  ph=2;

  UCSR0B=0XD0;
  UBRR0=0X67;
  UDR0=0X00;
  ct=0,pt=1;
  interrupts();
}

void loop() {
  // put your main code here, to run repeatedly:

}

ISR(TIMER1_OVF_vect)
{
  if(ph==1)
  {
    if(PORTB==0X00)
    {
      PORTB=0X20;//ON
      pt=1;
      ph=2;
      TCNT1=0XFEC6;
    }
    else if(PORTB==0X20)
    {
      PORTB=0X00;//OFF
      pt=2;
      ph=2;
      TCNT1=0XFEC6;
    }
  }
  else
  {
    if(pt==1)
    {
      UCSR0B=0XD8;
      UDR0=s1[ct];   
      TCNT1=0XFEC6;
    }
    else if(pt==2)
    {
      UCSR0B=0XD8;
      TCNT1=0XFEC6;
      UDR0=s2[ct];
    }
  
  }

}

ISR(USART_TX_vect)
{
  ct=ct+1;

  if(ct==7)
  {
    ph=1;
    pt=0;
    TCNT1=0X85ED;
    ct=0;
  }
}
