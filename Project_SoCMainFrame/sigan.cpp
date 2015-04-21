#include "Ardos.h"

#include "sigan.h"
sigan_control sigan_test;


 sigan_control::sigan_control()
{
	os_add_lib_init(&sigan_control::sigan_init);

	return;
 }


 int sigan_control::sigan_init()
{
 	os_regist_event(OP_sigan_ON,sigan_control::sigan_on);
	os_regist_event(OP_sigan_OFF,sigan_control::sigan_off);
	os_regist_event(OP_sigan_RON,sigan_control::sigan_ron);

    //Serial.begin(9600);
 	pinMode(sigan_IO,OUTPUT);
 	digitalWrite(sigan_IO,LOW);
 	pinMode(sigan_IOe,OUTPUT);
 	digitalWrite(sigan_IOe,LOW);
 	return 0;
}


int sigan_control::sigan_on(int a, int b)
 {
    digitalWrite(sigan_IOe,HIGH);
    digitalWrite(sigan_IO,HIGH);
	//Serial.print('D');
 	return 0;
 }


int sigan_control::sigan_off(int a, int b)
{
    digitalWrite(sigan_IOe,LOW);
	//Serial.print('S');
 	return 0;
 }


 int sigan_control::sigan_ron(int a, int b)
{
    digitalWrite(sigan_IOe,HIGH);
    digitalWrite(sigan_IO,LOW);
    //Serial.print('U');
	//os_add_task_list(&LED_task_list);
 	return 0;
 }

