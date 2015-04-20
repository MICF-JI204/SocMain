#include "Ardos.h"
#include "os_yuntai.h"
#include "Servo_MICF.h"
#define quick 0xE2 
#define slow 0xE1
#define stop 0xE3


Servo Yuntai1;
Service_Yuntai Yuntai;

Service_Yuntai::Service_Yuntai()
{
	os_add_lib_init(&Service_Yuntai::yuntai_init);
	return;
}
int Service_Yuntai::yuntai_init()
{
	Yuntai1.attach(yuntai_IO);
	os_regist_event(quick, &Service_Yuntai::yuntai_quick);
	os_regist_event(slow, &Service_Yuntai::yuntai_slow);
	os_regist_event(stop, &Service_Yuntai::yuntai_stop);
	return 0;
}

int Service_Yuntai::yuntai_quick(int a,int b)
{ int c;
	int x=1470;
	if(a==1)
		 c=x-b;
	if(a==2)
		c=x+b;
	//请传入一个a,b, a正负决定方向，b 与 0的大小关系决定速度
	Yuntai1.writeMicroseconds(c);
}
int Service_Yuntai::yuntai_slow(int a,int b)
{	int c;
	int x=1470;
	if(a==2)
	c=x+b/10;
    if(a==1)
    c=x-b/10;
// 同上,但是这个慢
	Yuntai1.writeMicroseconds(c);
}

int Service_Yuntai::yuntai_stop(int a,int b)
{   
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
	
}