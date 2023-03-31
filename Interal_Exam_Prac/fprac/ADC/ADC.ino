#include<avr/io.h>
#include<avr/interrupt.h>

int val,ck=0,cmp,i=0;
int fval,n1,n2,n3;
char s1[10];

int ct=0;

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
   TCCR1A=0X00;
  TCCR1B=0X05;
  TCNT1=0X00;
  TIMSK1=0X00;
  UBRR0=0X67;
  UCSR0B=0XD8;
  ADMUX=0X40;
  ADCSRA=0XEF;
  interrupts();
}

void loop() {
  // put your main code here, to run repeatedly:


    if(ck==1)
  {
    
    //Serial.println(val);
    n1=val/100;
    val=val/10;
    n2=val/10;
    val=val/10;
    n3=val;

    s1[0]=n1+'0';
    s1[1]=n2+'0';
    s1[2]=n3+'0';
    
    ck=0;
    cmp=1;
   TIMSK1=0X01; 
   ADCSRA=0XEF;
  }
    
  
}

ISR(USART_TX_vect)
{
  i=i+1;
  if(i==5)
  {
    i=0;
    ADCSRA=0XEF;
    TCNT1=0XF0BD;
  }
}

ISR(ADC_vect)
{

  ck=1;
  val=ADCL|(ADCH<<8);
  
}

ISR(TIMER1_OVF_vect)
{

  if(cmp==1)
  {
    UDR0=s1[i];
    cmp=0;
    ct=ct+1;
  }
  
 TCNT1=0XF0BD;
   UDR0=s1[i];

}
