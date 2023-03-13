#include<avr/interrupt.h>
#include<avr/io.h>

char a;

int s=0;

void setup()
{

  TCCR1A=0;
  TCCR1B=0x05;//48E4- 3 sec A471 - 2 SEC prescaling selection

  DDRB=0X20;
  
  TCNT1=0X00;//DELAY

  TIMSK1=0X00;//timer 1 interrupt flag  1 = to start




  
  UCSR0A=0x00;
  UCSR0B=0xD0;//1101 0000 TRANS/REC
  UBRR0=0x67;//BAUD RATE SELECTION 
  UDR0=0;//what is udr0 and why set to 0?? also what is serial transfer and also ask where the data entered in monitor is stored in
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
    s=1;
    TIMSK1=0X01;
  }
  else if(a=='b')
  {
    //PORTB=0X00;
    s=2;
    TIMSK1=0X01;
  }

  //TIMSK1=0X00;
  
  //UCSR0B=0xd0;
  //delay(1000);
}


ISR(TIMER1_OVF_vect)
{
  if(s==1)
  {
    //delay(3000);
    TCNT1=0X48E4;
    PORTB=0X20;
    
    
  }
  else if (s==2)
  {
    //delay(2000);
    PORTB=0X00;
    TCNT1=0X85ED;
    PORTB=0X00;
  }
  s=0;
}
