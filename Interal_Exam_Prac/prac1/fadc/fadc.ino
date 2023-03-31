#include<avr/io.h>
#include<avr/interrupt.h>

int val,ck=0,k=0;

char n1,n2,n3,nn='\n';


void setup() {
  // put your setup code here, to run once:

  UBRR0=0X67;
  UCSR0B=0XD0;
  UDR0=0x00;

  TCCR1B=0X05;
  TCNT1=0XC2F6;


  ADMUX=0X40;
  ADCSRA=0XEF;
  
  TIMSK1=0X00;  

  interrupts();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(ck==1)
  {
    TIMSK1=0X01;
    

  UDR0=(val%10)+'0';
  val=(int)val/10;
  UDR0=(val%10)+'0';
  val=(int)val/10;
  UDR0=(val%10)+'0';

  //Serial.println("\n");

  

  
  ck=0;

  delay(1000);
ADCSRA=0XEF;
    
  }
}

ISR(ADC_vect)
{
  val=ADCL|(ADCH<<8);
  ck=1;
}




ISR(TIMER1_OVF_vect)
{
  UCSR0B=0XD8;
  TCNT1=0XC2F6;


}
