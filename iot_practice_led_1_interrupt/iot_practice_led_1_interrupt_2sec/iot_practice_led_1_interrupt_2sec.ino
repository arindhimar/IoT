int i;
void setup() {
  // put your setup code here, to run once:
  i = 0X00;
  TCCR1A=0;
  TCCR1B=0;

  DDRB=0X20;
  
  TCNT1=0X85ED;
  TCCR1B=0X05;

  TIMSK1=0X01;
}

void loop() {
  // put your main code here, to run repeatedly:
}

ISR(TIMER1_OVF_vect){
  TCNT1=0X85ED;

  if(i==0X00){
    PORTB=0X20;
    i=0X01;
  }
  else{
    PORTB=0X00;
    i=0X00;
  }
}
