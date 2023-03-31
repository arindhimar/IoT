// Define the pin number for the LDR
#define LDR_PIN A0
#include<avr/io.h>
#include<avr/interrupt.h>
void setup() {

UBRR0=0X67;

UCSR0B=0XD8;

UDR0=5+'0';

  
}

void loop() {
  // Set the ADC channel to read from ADC0 (LDR_PIN)
  
}
