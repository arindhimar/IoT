#include<avr/io.h>
#include<avr/interrupt.h>

char ch;
char s1[5]="hi";
int i=0,k=0;
void setup() {
  // put your setup code here, to run once:
  DDRB=0X20;
  PORTB=0X00;


  UBRR0=0X67;
  UCSR0B=0XD0;
  UDR0=0;
  
  interrupts();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(k==1)
  {
    UDR0=s1[i];
    delay(2);
  }
}

ISR(USART_RX_vect)
{
  ch=UDR0;
  if(ch=='a')
  {
    PORTB=0X20;
    k=1;
    UCSR0B=0XD8;
  }
  else if(ch=='b')
  {
    PORTB=0X00;
    k=2;
    UCSR0B=0XD8;
  }
}


ISR(USART_TX_vect)
{
  i=i+1;
  if(i==6)
  {
    i=0;
    k=0;
    UCSR0B=0XD0;
  }
}
