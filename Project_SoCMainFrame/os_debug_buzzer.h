#ifndef __os_debug_buzzer_h__
#define __os_debug_buzzer_h__

#include "Ardos.h"

#define OP_BUZZER_ON 5
#define OP_BUZZER_OFF 6
#define OP_BUZZER_MOO 2
#define BUZZER_IO 13

//以上分别定义了操作号还有buzzer的IO口

class buzzer_control
{
	public:
		buzzer_control();
		static int buzzer_init();
		static int buzzer_on(int a, int b);
		static int buzzer_off(int a, int b);
		static int buzzer_moo(int a, int b);
	
	private:
};//注意如果一个类里的操作要能被引用地址，必须加上static

#endif