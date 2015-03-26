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




int os_init(){//Initialization process of the system
  
  return 0;
}

int os_run(){//the main cycle of the system
	os_status.systime=millis();//Acquire System Time
	
	int* tevent=NULL; 
	for(i=0;i<os_status.task_list_count;i++){//Go Through Task List
		do{
			tevent=(*(os_status.tlist[i])).getTask(os.status.systime);
			//==========! EventList.addEvent(tevent);
		}while(tevent!=NULL);
	}
	return 0;
	//==============! ExcuteEvent();
}

int os_add_task_list(Task_List* ntask_list){//ntask_list as in New Task List
	os_status.task_list_count++;
	os_status.task_list[os_status.tasklist_count]=ntask_list;
	return 0;
}

int os_remove_task_list(){
	return 0;
}
