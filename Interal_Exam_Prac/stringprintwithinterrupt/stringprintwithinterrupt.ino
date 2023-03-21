#include<avr/io.h>
#include<avr/interrupt.h>

char ch;
char s1[8]="arin\n";
char s2[8]="ashish\n";

int ck,i=0;

void setup() {
  // put your setup code here, to run once:
  TCCR1A=0X00;
  TCCR1B=0X00;
  TCNT1=0X00;
  TIMSK1=0X00;
  


  DDRB=0X20;
  PORTB=0X20;
  


  UBRR0=0X67;
  UCSR0B=0XD0;
  TCCR1B=0X05;
  TCNT1=0X85ED;

  interrupts();
  

}

void loop() {
  // put your main code here, to run repeatedly:

}

ISR(USART_TX_vect)
{
  i=i+1;

  if(i==8)
  {
    i=0;
    ck=0;
    UCSR0B=0XD0;
    TIMSK1=0X00;
  }
  
}




ISR(USART_RX_vect)
{
  ch=UDR0;
  //PORTB=0X00;
  if(ch=='a')
  {
    ck=1;
    UCSR0B=0XD8;
    TIMSK1=0X01;
    PORTB=0X00;
  }
  else if(ch=='b')
  {
    ck=2; 
    UCSR0B=0XD8;
    TIMSK1=0X01;
    PORTB=0X00;
  }
}

ISR(TIMER1_OVF_vect)
{
  if(ck==1)
  {
    UDR0=s1[i];
    PORTB=0X20;
  }
  else if(ck==2)
  {
    UDR0=s2[i];
    PORTB=0X20;
  }
  TCNT1=0X85ED;
}
