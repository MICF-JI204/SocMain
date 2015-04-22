#include "Ardos.h"
#include "xipan.h"

#define d2slow 0xE6
#define d2stop 0xE7
Service_xipan xipan_shu;

Service_xipan::Service_xipan()
{
	os_add_lib_init(&Service_xipan::xipan_init);
	return;
}
int Service_xipan::xipan_init()
{
	pinMode(xipan_pin1,OUTPUT);
	pinMode(xipan_pin2,OUTPUT);
	pinMode(xipan_speed,OUTPUT);

	os_regist_event(d2slow, &Service_xipan::xipan_move);
	os_regist_event(d2stop, &Service_xipan::xipan_stop);
	
	return 0;
}


int Service_xipan::xipan_move(int a,int b)
{ 
	analogWrite(xipan_speed,a);//a 决定速度 
	if(b==1)
	{
	digitalWrite(xipan_pin1,LOW);
	digitalWrite(xipan_pin2,HIGH);
	}
	if(b==2)
	{
		digitalWrite(xipan_pin1,HIGH);
	digitalWrite(xipan_pin2,LOW);
	}//b值决定方向
		return 0;
		}
		int Service_xipan::xipan_stop(int a,int b)
{
	
	digitalWrite(xipan_pin1,HIGH);
	digitalWrite(xipan_pin2,HIGH);
	return 0;
		}