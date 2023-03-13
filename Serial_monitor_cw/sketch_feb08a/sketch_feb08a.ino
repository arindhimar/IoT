#include<avr/interrupt.h>
#include<avr/io.h>
char ch[10] = "vnsgu\n";
int cnt = 0X00, k = 0X00, j = 0X00, i;
void setup() {
  // put your setup code here, to run once:

  i = 0X00;
  TCCR1A = 0;
  TCCR1B = 0;
  DDRB = 0X20;
  TCNT1 = 0XA741;
  TCCR1B = 0X05;
  TIMSK1 = 0X01;


  UBRR0 = 0X19;
  UDR0 = 0x65;
  UCSR0A = 0X00;
  UCSR0B = 0XD0;
  UCSR0C = 0X06;
  interrupts();
  k = 0X00;
}

void loop() {

}


ISR(USART_RX_vect) {
  cnt = cnt + 1;
  k = 0X01;
  ch[j] = UDR0;
}

ISR(TIMER1_OVF_vect) {
  TCNT1 = 0XA741;
  if (cnt == 0X00) {
    PORTB = 0X00;
  }
  else {
    PORTB = 0X20;
    cnt = 0X00;
  }
}
