#ifndef __os_debug_LED_h__
#define __os_debug_LED_h__

#include "Ardos.h"

#define OP_LED_ON 3
#define OP_LED_OFF 4
#define OP_LED_BLINK 1
#define LED_IO 53

class LED_control
{
	public:
		LED_control();
		static int LED_init();
		static int LED_on(int a, int b);
		static int LED_off(int a, int b);
		static int LED_blink(int a, int b);
		
	private:
};

#endif

