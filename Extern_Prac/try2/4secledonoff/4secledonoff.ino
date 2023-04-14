void setup() {
  // put your setup code here, to run once:
  DDRB=0X20;
  PORTB=0X00;

  
  TCCR1A=0X00;
  TCCR1B=0X05;
  TCNT1=0X00;
  TIMSK1=0X01;

  interrupts();
}

void loop() {
  // put your main code here, to run repeatedly:

}

ISR(TIMER1_OVF_vect)
{
  TCNT1=0XBDB;
  if(PORTB==0X20)
  {
    PORTB=0X00;
  }
  else
  {
    PORTB=0X20;
  }
}
