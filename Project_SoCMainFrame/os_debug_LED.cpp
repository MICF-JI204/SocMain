#include "Ardos.h"

LED_control LED_check;

Task_List LED_task_list;

LED_control::LED_control()
{
	os_add_lib_init(&LED_control::LED_init);
	
	return;
}

int LED_control::LED_init()
{
	os_regist_event(OP_LED_ON,LED_control::LED_on);
	os_regist_event(OP_LED_OFF,LED_control::LED_off);
	os_regist_event(OP_LED_BLINK,LED_control::LED_blink);
	
	LED_task_list.addTask(17,OP_LED_ON,0,0,0);
	LED_task_list.addTask(17,OP_LED_OFF,0,0,2000);
	LED_task_list.addTask(17,OP_LED_ON,0,0,2000);	
	LED_task_list.addTask(17,OP_LED_OFF,0,0,2000);
	LED_task_list.disposeFunc=NULL;

	pinMode(LED_IO,OUTPUT);
	digitalWrite(LED_IO,LOW);
	
	return 0;
}

int LED_control::LED_on(int a, int b)
{
	digitalWrite(LED_IO,HIGH);
	
	return 0;
}

int LED_control::LED_off(int a, int b)
{
	digitalWrite(LED_IO,LOW);
	
	return 0;
}

int LED_control::LED_blink(int a, int b)
{

	os_add_task_list(&LED_task_list);
	
	return 0;
}