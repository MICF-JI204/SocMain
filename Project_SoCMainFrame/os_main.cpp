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
	for(i=0;i<os_status.task_list_count;i++)
	{//Go Through Task List

		do
		{
			tevent=(*(os_status.tlist[i])).getTask(os_status.systime);
			if(tevent==ERRPTR)//No more Tasks In a task list
			{
			   os_remove_task_list(i);//Dispose Number i Task
			}else
			{
				event_list.addEvent(tevent);
			}
		}
		while(tevent!=NULL);
		
	}
	return 0;
	event_list.Execute_Event();
}

int os_add_task_list(Task_List* ntask_list){//ntask_list as in New Task List
    if(os_status.tasklist_count==MAX_TASK_LIST-1) return ERR_LIST_TASK_LIST_OVERFLOW; 
	//if no more space in the list of task_list
	os_status.task_list[os_status.tasklist_count]=ntask_list;	
	
	
	//Initialize the tasklist for further use
	ntask_list->t_pointer=0;
	(ntask_list->task[0]).time_set=os_status.systime+(ntask_list->task[i]).time_step
	//First term = Last term + time step
	for(i=1;i < (ntask_list->t_count);i++){
		(ntask_list->task[i]).time_set=(ntask_list->task[i-1]).time_set+(ntask_list->task[i]).time_step;
	}//This term = Last term + time step
	
	
	os_status.task_list_count++;
	return 0;
}

int os_remove_task_list(byte listnum,byte err_num){
	if(os_status.task_list[listnum]==NULL) return ERR_REMOVE_EMPTY_LIST;
	int (*tfunpt)(byte)=(*os_status.task_list[listnum]).disposeFunc;
	if(tfuncpt!=NULL)(*tfunpt)(err_num);
	//Try Disposing the functions,Make Sure Not NULL!!
	os_status.task_list[listnum]=os_status.task_list[os_status.task_list_count]; 
	//Moving Foward the last list
	os_status.taks_list_count--;
	os_status.task_list[os_status.task_list_count]=NULL;
	//Dispose the list
	return 0;
}

