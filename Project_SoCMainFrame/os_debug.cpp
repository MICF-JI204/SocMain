#include "Ardos.h" 

int os_debug_init()
{
	pinMode(LED_BUILTIN,OUTPUT);
	digitalWrite(LED_BUILTIN,LOW);
	return 0;
}

int os_debug_LED_blink(int a, int b)
{
	digitalWrite(LED_BUILTIN,HIGH);
	delay(a);
	digitalWrite(LED_BUILTIN,LOW);
	delay(b);
	
	return 0;
}


