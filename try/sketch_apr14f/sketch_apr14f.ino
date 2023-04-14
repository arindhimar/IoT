void setup() {
  // Set baud rate to 9600
  UBRR0 = 0X67; // 16MHz / (16 * 9600) - 1

  // Enable transmitter and receiver
  UCSR0B=0XD8;
}

void loop() {
  // Send 'u' character
  UDR0 = 'u';
  exit(0);
}
