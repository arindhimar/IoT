#include<avr/io.h>
#include<avr/interrupt.h>
int val,flag=0;
void setup() {
  // put your setup code here, to run once:
  DDRB=0X20;
  PORTB=0X00;
  ADMUX=0X40;
  ADCSRA=0XEF;
  Serial.begin(9600);

  interrupts();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(flag==1)
  {
    Serial.println(val);
    flag=0;
    if(val>500)
    {
      PORTB=0X20;
    }
    else
    {
      PORTB=0X00;
    }
  }
}

ISR(ADC_vect)
{
  flag=1;
  val=ADCL|(ADCH<<8);
}
