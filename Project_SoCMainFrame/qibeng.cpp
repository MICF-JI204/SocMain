#include "Ardos.h"
#include"qibeng.h"
    qibeng_control qibeng_test;
    qibeng_control::qibeng_control()
{
	os_add_lib_init(&qibeng_control::qibeng_init);

	return;
 }


 int qibeng_control::qibeng_init()
{
 	os_regist_event(OP_qibeng_ON,qibeng_control::qibeng_on);
	os_regist_event(OP_qibeng_OFF,qibeng_control::qibeng_off);

	pinMode(qibeng_IO,OUTPUT);
	digitalWrite(qibeng_IO,LOW);

 	return 0;
}


int qibeng_control::qibeng_on(int a, int b)
 {
    digitalWrite(qibeng_IO,HIGH);
 	return 0;
 }


int qibeng_control::qibeng_off(int a, int b)
{
	digitalWrite(qibeng_IO,LOW);
 	return 0;
 }



