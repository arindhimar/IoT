void setup() {
  // put your setup code here, to run once:
  pinMode(12,INPUT_PULLUP);//INPUT_PULLUP is to intially set the pin high untill it recieve a signal from external src
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i=digitalRead(12);
  Serial.println(i);//print in new line
  digitalWrite(13,i);//only when external src is recived light will blink
}
