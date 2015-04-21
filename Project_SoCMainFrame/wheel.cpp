#include "Ardos.h"
#include "wheel.h"

Wheel_control wheel;

Task_List turn_back_left;
Task_List turn_back_right;

Servo wheel_motor[2];


int speed[2]={128,128};

Wheel_control::Wheel_control()
{
	os_add_lib_init(&Wheel_control::wheel_init);
	
	return;
}

int Wheel_control::Wheel_init()
{
	os_regist_event(OP_WHEEL_GO,Wheel_control::wheel_go);
	os_regist_event(OP_WHEEL_TURN_LEFT,Wheel_control::wheel_turn_left);
	os_regist_event(OP_WHEEL_TURN_RIGHT,Wheel_control::wheel_turn_right);
	os_regist_event(OP_WHEEL_STOP,Wheel_control::wheel_stop);
	
	turn_back_left.addTask(17,OP_WHEEL_GO_AHEAD,0,100,0);
	turn_back_left.addTask(17,OP_WHEEL_GO_AHEAD,0,128,0);
	turn_back_left.addTask(17,OP_WHEEL_GO_AHEAD,0,100,200);
	turn_back_left.disposeFunc=NULL;
	
	turn_back_right.addTask(17,OP_WHEEL_GO_AHEAD,1,100,0);
	turn_back_right.addTask(17,OP_WHEEL_GO_AHEAD,1,128,0);
	turn_back_right.addTask(17,OP_WHEEL_GO_AHEAD,1,100,200);
	turn_back_right.disposeFunc=NULL;
	
	wheel_motor[0].attach(IO_LEFT_WHEEL);
	wheel_motor[1].attach(IO_RIGHT_WHEEL);

	return 0;
}

int Wheel_control::wheel_set(int a, int b)
{
	if (( b < 128 ) && ( speed[a]>128 )) 
	{
		if (a==0)
		{
			turn_back_left.task[2].para[1]=b;
			os_add_task_list(&turn_back_left);
		}
	    else
		{
			turn_back_right.task[2].para[1]=b;
			os_add_task_list(&turn_back_right);
		}
	}
	else
	{
		speed[a]=b;
		wheel_motor[a].writeMicroseconds(900+4*b);
	}
	
	return 0;
}

int Wheel_control::wheel_go_ahead(int a, int b)
{
	speed[a]=b;
	motor[a].writeMicroseconds(900+4*b);
}

int Wheel_control::wheel_go(int a, int b)
{
	speed[0]=a;
	wheel.wheel_set(0,a);
	speed[1]=b;
	wheel.wheel_set(1,b);
	
	return 0;
}

int Wheel_control::wheel_turn_left(int a, int b)
{
	speed[0]=95;
	wheel.wheel_set(0,95);  // 95, the speed of -7V
	speed[1]=190;
	wheel.wheel_set(1,190); // 190, the speed of 7V
	
	return 0;
}

int Wheel_control::wheel_turn_right(int a, int b)
{
	speed[0]=190;
	wheel.wheel_set(0,190);
	speed[1]=95;
	wheel.wheel_set(1,95);
	
	return 0;
}

int Wheel_control::wheel_stop(int a, int b)
{
	speed[0]=128;
	wheel.wheel_go(0,128);
	speed[1]=128
	wheel.wheel_go(1,128);
	
	return 0;
}