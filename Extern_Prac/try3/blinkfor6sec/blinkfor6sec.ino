int ct=0;
void setup() {
  // put your setup code here, to run once:
  DDRB=0X20;
  PORTB=0X00;

  TCCR1A=0X00;
  TCCR1B=0X05;
  TCNT1=0X00;
  TIMSK1=0X01;
  
  
}

void loop() {
  // put your main code here, to run repeatedly:

}

ISR(TIMER1_OVF_vect)
{
  if(ct==0||ct==1||ct==2)
  {
    TCNT1=0X48E4;
    ct=ct+1;
    if(ct==2)
    {
      ct=0;
      if(PORTB==0X00)
      {
        PORTB=0X20;
      }
      else
      {
        PORTB=0X00;
      }
    }
  }
}
