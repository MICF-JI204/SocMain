#ifndef __wheel_h__
#define __wheel_h__

#include "Ardos.h"

#define IO_LEFT_WHEEL_IN1 4 
#define IO_LEFT_WHEEL_IN2 5
#define IO_LEFT_WHEEL_EN 6
#define IO_RIGHT_WHEEL_IN1 7
#define IO_RIGHT_WHEEL_IN2 8
#define IO_RIGHT_WHEEL_EN 9

#define OP_WHEEL_GO 160
#define OP_WHEEL_TURN_LEFT 192
#define OP_WHEEL_TURN_RIGHT 193
#define OP_WHEEL_STOP 196
#define OP_WHEEL_GO_AHEAD 200

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
		
		private:
	
};







#endif