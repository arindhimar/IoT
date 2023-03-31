/*
 * GccApplication1.c
 *
 * Created: 22-03-2023 09:54:15
 * Author : Arin Dhimar
 */ 

#include<avr/io.h>
#include<avr/interrupt.h>

char ch;

char s1[7]="vnsgu\n";// v0 n1 s2 g3 u4
char s2[7]="india\n";
int readFlag =0;
int analogVal =0,analogVal1=0,analogVal2=0;

int ck=0,i=0,k=0;

int main(void)
{
	cli();	
  // put your setup code here, to run once:
  // Serial.begin(9600);
  UDR0 = 0x00;
  UBRR0 = 0x33;// 19200 baud rate
  UCSR0B = 0xD8;
  ADMUX=0x45;// for pin A5
  ADCSRB=0x00;
  sei();
  readFlag=0;
  ADCSRA=0xEF;
  sei();
    /* Replace with your application code */
    while (1) 
    {
		  if(readFlag==1)
		  {
			  int val = analogVal;
			  // Serial.println(val);
			  UDR0=val;
			  readFlag=0;
		  }
    }
}


ISR(USART_TX_vect)
{
	i=i+1;

	if(i==7)
	{
		i=0;
		TIMSK1=0X00;
		UCSR0B=0XD0;

		ck=0;
	}
}


ISR(ADC_vect)
{
	readFlag=1;
	analogVal1=ADCL;
	analogVal2=ADCH<<8;
	analogVal=analogVal1;
	analogVal=analogVal|analogVal2;

	//analogVal=ADCL | (ADCH <<8);//alway read to LOW by
}


ISR(USART_RX_vect)
{
	ch=UDR0;
	if(ch=='a')
	{
		TIMSK1=0X01;
		PORTB=0X20;
		UCSR0B=0XD8;
		ck=1;
	}
	else if(ch=='b')
	{
		TIMSK1=0X01;
		PORTB=0X00;
		UCSR0B=0XD8;
		ck=2;
	}
}


ISR(TIMER1_OVF_vect)
{
	TCNT1=0XC2F6;
	if(ck==1)
	{
		UDR0=s1[i];
	}
	else if(ck==2)
	{
		UDR0=s2[i];
	}
}

