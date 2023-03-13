#include<avr/interrupt.h>
#include<avr/io.h>

int i=0,j=0,k=0;
char a;
char a1[10]="vnsgu\n";
char a2[10]="india\n";

void setup()
{
  UCSR0A=0x00;
  UCSR0B=0xD0;
  UBRR0=0x67;
  UDR0=0;
  interrupts();
}

void loop()
{
  if(k==1)
  {
    UDR0=a1[j];
    UCSR0B=0xD8;
    delay(1000);
  }
  else if(k==2)
  {
    UDR0=a2[j];
    UCSR0B=0xD8;
    delay(1000);
  }
}

ISR(USART_TX_vect)//ask when triggered both interrupt
{
  UCSR0A=0;
  UCSR0B=0xD0;
  j=j+1;
  if(j==0x0a){//0a=10
    j=0;
    k=0;
  }
}

ISR(USART_RX_vect)
{
  a=UDR0;
  UCSR0B=0xD8;
  //delay(1000);
  if(a=='a'){
    k=1;
  }
  else if(a=='b'){
    k=2;
  }

}
