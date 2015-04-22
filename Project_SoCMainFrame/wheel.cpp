#include "Ardos.h"
#include "wheel.h"

Wheel_control wheel;

Wheel_control::Wheel_control()
{
	os_add_lib_init(&Wheel_control::wheel_init);
	
	return;
}

long long int Wheel_control::wheel_init()
{
	os_regist_event(OP_WHEEL_GO,Wheel_control::wheel_go);
	os_regist_event(OP_WHEEL_TURN_LEFT,Wheel_control::wheel_turn_left);
	os_regist_event(OP_WHEEL_TURN_RIGHT,Wheel_control::wheel_turn_right);
	os_regist_event(OP_WHEEL_STOP,Wheel_control::wheel_stop);
	os_regist_event(OP_WHEEL_GO_AHEAD,Wheel_control::wheel_go_ahead);

	digitalWrite(IO_LEFT_WHEEL_IN1,HIGH);
	digitalWrite(IO_LEFT_WHEEL_IN2,HIGH);
	digitalWrite(IO_RIGHT_WHEEL_IN1,HIGH);
	digitalWrite(IO_RIGHT_WHEEL_IN2,HIGH);
	
	return 0;
}

long long int Wheel_control::wheel_go_ahead(long long int a, long long int b)
{
	long long int temp;
	temp=2*(b-128); 
	if (temp<0) temp=-temp;
	
	if (a==0) 
	{
		analogWrite(IO_LEFT_WHEEL_EN, temp);
		if (b==128) 
		{
			digitalWrite(IO_LEFT_WHEEL_IN1,HIGH);
			digitalWrite(IO_LEFT_WHEEL_IN2,HIGH);
		}
		if (b<128)
		{
			digitalWrite(IO_LEFT_WHEEL_IN1,HIGH);
			digitalWrite(IO_LEFT_WHEEL_IN2,LOW);
		}
		if (b>128)
		{
			digitalWrite(IO_LEFT_WHEEL_IN1,LOW);
			digitalWrite(IO_LEFT_WHEEL_IN2,HIGH);
		}
	}
	else
	{
		analogWrite(IO_RIGHT_WHEEL_EN, temp);
		if (b==128) 
		{
			digitalWrite(IO_RIGHT_WHEEL_IN1,HIGH);
			digitalWrite(IO_RIGHT_WHEEL_IN2,HIGH);
		}
		if (b<128)
		{
			digitalWrite(IO_RIGHT_WHEEL_IN1,HIGH);
			digitalWrite(IO_RIGHT_WHEEL_IN2,LOW);
		}
		if (b>128)
		{
			digitalWrite(IO_RIGHT_WHEEL_IN1,LOW);
			digitalWrite(IO_RIGHT_WHEEL_IN2,HIGH);
		}
	}
	
	return 0;
}

long long int Wheel_control::wheel_go(long long int a, long long int b)
{
	wheel.wheel_go_ahead(0,a);
	wheel.wheel_go_ahead(1,b);
	
	return 0;
}

long long int Wheel_control::wheel_turn_left(long long int a, long long int b)
{
	wheel.wheel_go_ahead(0,64);  
	wheel.wheel_go_ahead(1,192); 
	
	return 0;
}

long long int Wheel_control::wheel_turn_right(long long int a, long long int b)
{
	wheel.wheel_go_ahead(0,192);
	wheel.wheel_go_ahead(1,64);
	
	return 0;
}

long long int Wheel_control::wheel_stop(long long int a, long long int b)
{
	wheel.wheel_go_ahead(0,128);
	wheel.wheel_go_ahead(1,128);
	
	return 0;
}