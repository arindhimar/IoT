void setup() {
  // put your setup code here, to run once:
  //To begin serial connection
  Serial.begin(9600);//9600-Baudrate 

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()==1)//to check if any data is previously shared or not i.e to prevent garbage value
  {
    char ch=Serial.read();
    Serial.print(ch);
  }
}
