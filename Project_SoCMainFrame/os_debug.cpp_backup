#include "Ardos.h" 

int os_debug_init()
{
	pinMode(LED_BUILTIN,OUTPUT);
	digitalWrite(LED_BUILTIN,LOW);
	pinMode(8,OUTPUT);
	digitalWrite(8,LOW);
	
	event_list.Regist_Event(2,&os_debug_LED1);
	event_list.Regist_Event(1,&os_debug_LED_blink);
	
	return 0;
}

int os_debug_LED_blink(int a, int b)
{
	digitalWrite(LED_BUILTIN,HIGH);
	delay(a);
	digitalWrite(LED_BUILTIN,LOW);
	delay(b);
	digitalWrite(LED_BUILTIN,HIGH);
	delay(a);
	digitalWrite(LED_BUILTIN,LOW);
	delay(b);
	digitalWrite(LED_BUILTIN,HIGH);
	delay(a);
	digitalWrite(LED_BUILTIN,LOW);
	delay(b);
	digitalWrite(LED_BUILTIN,HIGH);
	delay(a);
	digitalWrite(LED_BUILTIN,LOW);
	delay(b);
	
	return 0;
}

int os_debug_LED1(int a, int b)
{
	int i;
	digitalWrite(8,HIGH);
	delay(3000);
	digitalWrite(8,LOW);
	delay(3000);
	for (i=1; i<=a+b; i++)
	{
		digitalWrite(8,HIGH);
		delay(400);
		digitalWrite(8,LOW);
		delay(400);
	}
	
	return 0;
}

