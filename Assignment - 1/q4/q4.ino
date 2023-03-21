#include<avr/interrupt.h>
#include<avr/io.h>

char a;

void setup()
{

  DDRB=0X20;
  UCSR0A=0x00;
  UCSR0B=0xD0;//1101 0000 TRANS/REC
  UBRR0=0x07;//BAUD RATE SELECTION Formula = (crystal freq/16 * bdgen) - 1 this one is for 115200
  UDR0=0;//what is udr and why set to 0?? also what is serial transfer and also ask where the data entered in monitor is stored in
  interrupts();
}

void loop()
{

}

//ISR(USART_TX_vect)
//{
//  //UCSR0A=0X00;
//  //UCSR0B=0xD0;//SET AS RECIVER
//}

ISR(USART_RX_vect)
{
  a=UDR0;
  if(a=='a')
  {
    PORTB=0X20;
  }
  else if(a=='b')
  {
    PORTB=0X00;
  }
  
  //UCSR0B=0xd0;
  //delay(1000);
}
