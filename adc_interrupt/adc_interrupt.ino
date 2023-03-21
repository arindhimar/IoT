byte readflag = 0;
int analogval = 0, analogval1 = 0, analogval2 = 0;

void setup() {
  UBRR0 = 0x19; // Set baud rate to 19200

  // Initialize USART registers
  UCSR0A = 0x00;
  UCSR0B = 0xD8; // Enable receiver and transmitter

  // Initialize ADC registers
  ADMUX = 0x40; // Select ADC0 as input
  ADCSRB = 0x00; // Set free running mode

  readflag = 0;
  ADCSRA = 0xEF; // Enable ADC with prescaler of 128

  interrupts(); // Enable interrupts
}

void loop() {
  if (readflag == 1) {
    int val = analogval;
    UCSR0B = 0xD8; // Enable transmitter
    UDR0 = val + '0'; // Send value over serial communication
    ADCSRA = 0xEF; // Start another analog to digital conversion
    readflag = 0; // Reset read flag
  }
}

ISR(ADC_vect) {
  analogval1 = ADCL; // Store lower 8 bits of ADC value
  analogval2 = ADCH << 8; // Shift and store upper 2 bits of ADC value
  analogval = analogval1 | analogval2; // Combine upper and lower bits
  readflag = 1; // Set read flag
}
