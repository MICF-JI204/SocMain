#include "Ardos.h"
#include <Servo.h>

Servo Yuntai;
Service_Yuntai Yuntai;
//Task_list yuntai_task_list;
int time;

Service_Yuntai::yuntai_control()
{
	os_add_lib_init(yuantai_init);
	return;
}
int Service_Yuntai::yuantai_init_left;
{
	Yuntai.attach(yuntai_IO);
	os_regist_event(yuntai_left, Service_Yuntai::yuntai_left);
	os_regist_event(yuntai_left, Service_Yuntai::yuntai_left_slowly);
	os_regist_event(yuntai_left, Service_Yuntai::yuntai_right_slowly);
	os_regist_event(yuntai_right, Service_Yuntai::yuntai_right);
	os_regist_event(yuntai_stop, Service_Yuntai::yuntai_stop);
	return 0;
}
int yuntai_control::yuntai_right(int a)
{
	Yuntai.writeMIcroseconds(a);
}
int yuntai_control::yuntai_right_slowly(int a)
{
	Yuntai.writeMIcroseconds(a);
}
int yuntai_control::yuntai_left(int a)
{
	Yuntai.writeMIcroseconds(a);
}
int yuntai_control::yuntai_left_slowly(int a)
{
	Yuntai.writeMIcroseconds(a);
}
int yuntai_control::yuntai_stop(int a)
{
	Yuntai.writeMIcroseconds(1500);
}