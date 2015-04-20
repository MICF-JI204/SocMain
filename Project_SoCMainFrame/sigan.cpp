#include "Ardos.h"


sigan_control sigan_test;


Task_List sigan_task_list;


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

	/*sigan_task_list.addTask(17,OP_sigan_ON,0,0,0);
 	sigan_task_list.addTask(17,OP_sigan_OFF,0,0,2000);
 	sigan_task_list.addTask(17,OP_sigan_ON,0,0,2000);
 	sigan_task_list.addTask(17,OP_sigan_OFF,0,0,2000);
	sigan_task_list.disposeFunc=NULL;*/

    Serial.begin(9600);
 	//pinMode(sigan_IO,OUTPUT);
 	//digitalWrite(sigan_IO,LOW);

 	return 0;
}


int sigan_control::sigan_on(int a, int b)
 {
	Serial.print('D');
 	return 0;
 }


int sigan_control::sigan_off(int a, int b)
{
	Serial.print('S');
 	return 0;
 }


 int sigan_control::sigan_ron(int a, int b)
{
    Serial.print('U');
	//os_add_task_list(&LED_task_list);
 	return 0;
 }

