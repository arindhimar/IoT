#include<avr/interrupt.h>
#include<avr/io.h>

char ch;
char s1[7]="vnsgu\n";
char s2[7]="india\n";

int i,k;

void setup() {
  // put your setup code here, to run once:
  UBRR0=0X67;
  UCSR0B=0XD0;
  UDR0=0X00;
  DDRB=0X20;
}

void loop() {
  // put your main code here, to run repeatedly:

  if(k==1)
  {
    
    UCSR0B=0XD8;
    UDR0=s1[i];
    PORTB=0X20;
    delay(1000);
  }
  else if(k==2)
  {
    
    UCSR0B=0XD8;
    UDR0=s2[i];
    PORTB=0X20;
    delay(1000);
  }

}

ISR(USART_TX_vect)
{
  UCSR0B=0XD0;
  i=i+1;
  if(i==6){
  i=0;
  k=0;
  }
}


ISR(USART_RX_vect)
{
  ch=UDR0;

  if(ch=='a')
  {
    k=1;
  }
  else if(ch=='b')
  {
    k=2;
  }
  
}
