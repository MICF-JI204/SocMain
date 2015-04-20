#include "Ardos.h"
#include "os_yuntai.h"
#include "Servo_MICF.h"
#define quick 5 //需要三个操作号，请更改
#define slow 6
#define stop 7


Servo Yuntai1;
Service_Yuntai Yuntai;
Task_List yuntai_task_list;

Service_Yuntai::Service_Yuntai()
{
	os_add_lib_init(&Service_Yuntai::yuntai_init_quick);
	return;
}
int Service_Yuntai::yuntai_init_quick()
{
	Yuntai1.attach(yuntai_IO);
	os_regist_event(quick, &Service_Yuntai::yuntai_quick);
	
	yuntai_task_list.addTask(17,quick,0,0,0);
	return 0;
}
int Service_Yuntai::yuntai_init_slow()
{
	Yuntai1.attach(yuntai_IO);
	os_regist_event(slow, &Service_Yuntai::yuntai_stop);
	
	yuntai_task_list.addTask(17,slow,0,0,0);
	return 0;
}
int Service_Yuntai::yuntai_init_stop()
{
	Yuntai1.attach(yuntai_IO);
	os_regist_event(stop, &Service_Yuntai::yuntai_stop);
	
	yuntai_task_list.addTask(17,stop,0,0,0);
	return 0;
}
int Service_Yuntai::yuntai_quick(int a,int b)
{
	int x=1470;
int c=x+a*b;//请传入一个a,b, a正负决定方向，b 与 0的大小关系决定速度
	Yuntai1.writeMicroseconds(c);
}
int Service_Yuntai::yuntai_slow(int a,int b)
{int x=1470;
int c=x+a*b/10;// 同上,但是这个慢
	Yuntai1.writeMicroseconds(a);
}

int Service_Yuntai::yuntai_stop(int a,int b)
{
	Yuntai1.writeMicroseconds(1470);
}