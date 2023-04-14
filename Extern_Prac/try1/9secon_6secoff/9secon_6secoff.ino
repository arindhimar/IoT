int ck=0;
void setup() {
  // put your setup code here, to run once:
  DDRB=0X20;
  PORTB=0X20;

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
  if(PORTB==0X00)
  {
    if(ck==0||ck==1||ck==2)
    {
      TCNT1=0X48E4;
      ck=ck+1;
      if(ck==2)
      {
        PORTB=0X20;
        ck=0;
        
      }
    }
  }
  else
  {
    if(ck==0||ck==1||ck==2||ck==3)
    {
      TCNT1=0X48E4;
      ck=ck+1;
      if(ck==3)
      {
        PORTB=0X00;
        ck=0;
      }
    }
  }
}
