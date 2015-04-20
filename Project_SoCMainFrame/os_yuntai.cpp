#include "Ardos.h"
#include "os_yuntai.h"
#include "Servo_MICF.h"

Servo Yuntai1;
Service_Yuntai Yuntai;
//Task_list yuntai_task_list;
int time;

Service_Yuntai::Service_Yuntai()
{
	os_add_lib_init(&Service_Yuntai::yuntai_init);
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
int Service_Yuntai::yuntai_right(int a)
{
	Yuntai1.writeMIcroseconds(a);
}
int Service_Yuntai::yuntai_right_slowly(int a)
{
	Yuntai1.writeMIcroseconds(a);
}
int Service_Yuntai::yuntai_left(int a)
{
	Yuntai1.writeMIcroseconds(a);
}
int Service_Yuntai::yuntai_left_slowly(int a)
{
	Yuntai1.writeMIcroseconds(a);
}
int Service_Yuntai::yuntai_stop(int a)
{
	Yuntai1.writeMIcroseconds(1500);
}