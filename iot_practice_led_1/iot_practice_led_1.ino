void setup() {
  // put your setup code here, to run once:
  DDRB=0X20;
  
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTB=0X20;
  delay(1000);
  PORTB=0X00;
  delay(1000);
}
