#include "Ardos.h"
#include "chouban.h"
chouban_control chouban_test;
chouban_control::chouban_control()
{
	os_add_lib_init(&chouban_control::chouban_init);

	return;
 }


 int chouban_control::chouban_init()
{
 	os_regist_event(OP_chouban_ON,chouban_control::chouban_on);
	os_regist_event(OP_chouban_OFF,chouban_control::chouban_off);

	//pinMode(chouban_IO_EN,OUTPUT);
	pinMode(chouban_IO_IN1,OUTPUT);
	pinMode(chouban_IO_IN2,OUTPUT);
	
 	digitalWrite(chouban_IO_IN1,HIGH);
	digitalWrite(chouban_IO_IN2,HIGH);
	analogWrite(chouban_IO_EN,0);
	
 	return 0;
}


int chouban_control::chouban_on(int a, int b)
 {
    analogWrite(chouban_IO_EN,a);
	if (b==0)
	{
		digitalWrite(chouban_IO_IN1,HIGH);
		digitalWrite(chouban_IO_IN2,LOW);
	}
	else
	{
		digitalWrite(chouban_IO_IN1,LOW);
		digitalWrite(chouban_IO_IN2,HIGH);		
	}
 	return 0;
 }


int chouban_control::chouban_off(int a, int b)
{
	analogWrite(chouban_IO_EN,0);
	digitalWrite(chouban_IO_IN1,HIGH);
	digitalWrite(chouban_IO_IN2,HIGH);
 	return 0;
 }



