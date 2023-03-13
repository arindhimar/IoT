int cnt=0;
void setup() {
  // put your setup code here, to run once:
  //i = 0X00;
  TCCR1A=0;
  TCCR1B=0;

  DDRB=0X20;
  
  TCNT1=0X00;
  TCCR1B=0X05;

  TIMSK1=0X01;
}

void loop() {
  // put your main code here, to run repeatedly:
}

ISR(TIMER1_OVF_vect){
  if(PORTB==0X20){
    
    //i=0X01;
    if(cnt==0)
    {
       TCNT1=0X0BDB;
        cnt=1;
    }
    else if(cnt==1)
    {
      TCNT1=0X0BDB;
      cnt=2;
      
    }
    else if(cnt==2)
    {
      TCNT1=0XC2F6;
      PORTB=0X00;
      cnt=0;
    }
  }
  else{
    if(cnt==0)
    {
      TCNT1=0X0BDB;
      cnt=1;
    }
    else if (cnt==1)
    {
      TCNT1=0XA471;
      PORTB=0X20;  
      cnt=0;
    }
  }
}
