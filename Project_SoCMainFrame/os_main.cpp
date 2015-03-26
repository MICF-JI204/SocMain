#include "Arduino.h"
#include "Ardos.h"

/*This is the Main File of Ardos.
  Ardos is an NOT-SO-GENERAL purpose operating system 
  for Arduino Boards, samll and light weight enough to 
  be put into arduino uno.
  This operating system features a simple event driven
  model, and a simple timer for NOT-REAL-TIME timer.
  (Multithresding)
*/

Task_List* tlist[10]; //instantiate a mission list

int os_init(){
  
  return 0;
}

int os_run(){//the main cycle of the system
	os_status.systime=millis();//Acquire System Time
	for(i=0;i<os_status.task_list_count;i++){//Go Through Task List
		(*tlist[i]).getTask(os.status.systime);
	}
	return 0;
}

int os_add_task_list(){
	return 0;
}

int os_remove_task_list(){
	return 0;
}

