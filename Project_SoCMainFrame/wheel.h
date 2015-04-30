#ifndef __wheel_h__
#define __wheel_h__

#include "Ardos.h"

#define IO_LEFT_WHEEL_IN1 30
#define IO_LEFT_WHEEL_IN2 31
#define IO_LEFT_WHEEL_EN 7
#define IO_RIGHT_WHEEL_IN1 32
#define IO_RIGHT_WHEEL_IN2 33
#define IO_RIGHT_WHEEL_EN 6

#define OP_WHEEL_GO 160
#define OP_WHEEL_TURN_LEFT 192
#define OP_WHEEL_TURN_RIGHT 193
#define OP_WHEEL_STOP 196
#define OP_WHEEL_GO_AHEAD 200


//#define IO_ZZZZ 12
//#define OP_ZZZZ 0x80


class Wheel_control
{
		public:
			Wheel_control();
			static int wheel_init();
			static int wheel_go_ahead(int a, int b);
			static int wheel_go(int a, int b);
			static int wheel_turn_left(int a, int b);
			static int wheel_turn_right(int a, int b);
			static int wheel_stop(int a, int b);
			//static int zzzz(int a, int b);
		
		private:
	
};







#endif