#include<avr/io.h>
#include<avr/interrupt.h>

char ch;

void setup() {
  // put your setup code here, to run once:
  UBRR0=0X19;

  UCSR0B=0XD0;
  UCSR0C=0X06;

  DDRB=0X20;

  PORTB=0X00;

    UDR0=0;
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
  }
  else if(ch=='b')
  {
    PORTB=0X00;
  }
}
