#ifndef __wheel_h__
#define __wheel_h__

#include "Ardos.h"

#define IO_LEFT_WHEEL_IN1 35
#define IO_LEFT_WHEEL_IN2 37
#define IO_LEFT_WHEEL_EN 39
#define IO_RIGHT_WHEEL_IN1 41
#define IO_RIGHT_WHEEL_IN2 43
#define IO_RIGHT_WHEEL_EN 45

#define OP_WHEEL_GO 160
#define OP_WHEEL_TURN_LEFT 192
#define OP_WHEEL_TURN_RIGHT 193
#define OP_WHEEL_STOP 196
#define OP_WHEEL_GO_AHEAD 200

class Wheel_control
{
		public:
			Wheel_control();
			static long long int wheel_init();
			static long long int wheel_go_ahead(long long int a, long long int b);
			static long long int wheel_go(long long int a, long long int b);
			static long long int wheel_turn_left(long long int a, long long int b);
			static long long int wheel_turn_right(long long int a, long long int b);
			static long long int wheel_stop(long long int a, long long int b);
		
		private:
	
};







#endif