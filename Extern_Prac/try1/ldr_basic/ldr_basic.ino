#include<avr/io.h>
#include<avr/interrupt.h>


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  
  DDRB=0X20;
  PORTB=0X00;


  //delay(4000);
  
  ADMUX=0X40;

  ADCSRA=0XEF;

  

  interrupts();

}

void loop() {
  // put your main code here, to run repeatedly:

}


ISR(ADC_vect)
{
  int val = ADCL | ( ADCH << 8 );

  Serial.println(val);
  
  if(val>1020)
  {
    PORTB=0X20;
  }
  else
  {
    PORTB=0X00;
  }
}

