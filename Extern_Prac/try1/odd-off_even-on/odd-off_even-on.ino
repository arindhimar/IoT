#include<avr/io.h>
#include<avr/interrupt.h>

char ch;




void setup() {
  // put your setup code here, to run once:

  DDRB=0X20;
  PORTB=0X00;

  UBRR0=0X67;
  UCSR0B=0XD0;
  UDR0=0X00;
    
  interrupts();
}

void loop() {
  // put your main code here, to run repeatedly:

}


ISR(USART_RX_vect)
{
  int val = UDR0 + '0';

  if(val%2==0)
  {
    PORTB=0X20;
  }
  else
  {
    PORTB=0X00;
  }
  
}
