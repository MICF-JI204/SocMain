#include "Ardos.h"

buzzer_control Buzzer;

Task_List buzzer_task_list;

buzzer_control::buzzer_control()
{
	os_add_lib_init(&buzzer_control::buzzer_init);

	return ;
}

int buzzer_control::buzzer_init()
{
	os_regist_event(OP_BUZZER_ON,buzzer_control::buzzer_on);
	os_regist_event(OP_BUZZER_OFF,buzzer_control::buzzer_off);
	os_regist_event(OP_BUZZER_MOO,buzzer_control::buzzer_moo);
	
	buzzer_task_list.addTask(17,OP_BUZZER_ON,0,0,0);
	buzzer_task_list.addTask(17,OP_BUZZER_OFF,0,0,1000);
	buzzer_task_list.addTask(17,OP_BUZZER_ON,0,0,1000);
	buzzer_task_list.addTask(17,OP_BUZZER_OFF,0,0,1000);
	buzzer_task_list.disposeFunc=NULL;
	
	pinMode(BUZZER_IO,OUTPUT);
	digitalWrite(BUZZER_IO,LOW);
	
	return 0;
}

int buzzer_control::buzzer_on(int a, int b)
{
	digitalWrite(BUZZER_IO,HIGH);
	
	return 0;
}

int buzzer_control::buzzer_off(int a, int b)
{
	digitalWrite(BUZZER_IO,LOW);
	
	return 0;
	
}

int buzzer_control::buzzer_moo(int a, int b)
{
	os_add_task_list(&buzzer_task_list);
	
	return 0;
}