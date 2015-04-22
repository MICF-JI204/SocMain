#include "Ardos.h"
#include "diaobi_updown.h"

#define d1slow 0xE4
#define d1stop 0xE5
Service_diaobi diaobi_shu;

Service_diaobi::Service_diaobi()
{
	os_add_lib_init(&Service_diaobi::diaobi_init);
	return;
}
int Service_diaobi::diaobi_init()
{
	pinMode(diaobi_pin1,OUTPUT);
	pinMode(diaobi_pin2,OUTPUT);
	pinMode(diaobi_speed,OUTPUT);

	os_regist_event(d1slow, &Service_diaobi::diaobi_slow);
	os_regist_event(d1stop, &Service_diaobi::diaobi_stop);
	return 0;
}


int Service_diaobi::diaobi_slow(int a,int b)
{  
	analogWrite(diaobi_speed,a);
	if(b==1)
	{
	digitalWrite(diaobi_pin1,LOW);
	digitalWrite(diaobi_pin2,HIGH);
	}
	if(b==2)
	{
		digitalWrite(diaobi_pin1,HIGH);
	digitalWrite(diaobi_pin2,LOW);
	}
		
		}
	int Service_diaobi::diaobi_stop(int a,int b)
{
	
	digitalWrite(diaobi_pin1,HIGH);
	digitalWrite(diaobi_pin2,HIGH);

		}