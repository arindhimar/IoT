#include<avr/interrupt.h>
#include<avr/io.h>

char ch;

void setup() {
  // put your setup code here, to run once:
  //ch="";

  UBRR0=0x67;

  UCSR0B=0XD0;

  UDR0=0X00;

  DDRB=0X20;

}

void loop() {
  // put your main code here, to run repeatedly:

}


ISR(USART_RX_vect)
{
  ch=UDR0;

  if(ch=='a')
  PORTB=0X20;
  else if(ch=='b')
  PORTB=0X00;
}
