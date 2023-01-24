#include<REG51.h>

main()
{
	IE = 0X82;
	TMOD = 0X08;
	TCON = 0X11;
	TH0=0XFF;
	TL0=0XF0;
	P1=0X00;
	
	while(1)
	{
		P1 = 0XFF;
	}
}

void interrupt_timer_isr0(void) interrupt 1 using 2
{
	TH0=0XFF;
	TL0=0XF0;
	P1=0X00;
}

void interrupt_ISR0(void) interrupt 0 using 2
{
	P1=0X00;
}

	