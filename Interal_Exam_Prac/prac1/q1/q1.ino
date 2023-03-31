#include<avr/io.h>
#include<avr/interrupt.h>

char ch='Y';
int i=0;
void setup() {
  // put your setup code here, to run once:
  
  UBRR0=0X019F;
  UCSR0B=0XC8;
  
  interrupts();
}

void loop() {
  // put your main code here, to run repeatedly:
UDR0=ch;
}

ISR(USART_TX_vect)
{

}
