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
  
  for(int i=0;i<lib_init_count)
  return 0;
}

int os_run(){//the main cycle of the system
	systime=millis();//Acquire System Time
	
	int* tevent=NULL; 
	for(int i=0;i<task_list_count;i++)
	{//Go Through Task List

		do
		{
			tevent=(*(tlist[i])).getTask(systime);
			if(tevent==ERRPTR)//No more Tasks In a task list
			{
			   os_remove_task_list(i);//Dispose Number i Task
			}else
			{
				event_list.Add_Event(tevent);
			}
		}
		while(tevent!=NULL);
		
	}
	return 0;
	event_list.Execute_Event();
}

int os_add_task_list(Task_List* ntask_list){//ntask_list as in New Task List
    if(task_list_count==MAX_TASK_LIST) return ERR_LIST_TASK_LIST_OVERFLOW; 
	//if no more space in the list of task_list
	tlist[task_list_count]=ntask_list;	
	
	
	//Initialize the tasklist for further usee
	(ntask_list->task[0]).time_set=systime+(ntask_list->task[i]).time_step
	//First term = Last term + time step
	for(int i=1;i < (ntask_list->t_count);i++){
		(ntask_list->task[i]).time_set=(ntask_list->task[i-1]).time_set+(ntask_list->task[i]).time_step;
	}//This term = Last term + time step
	
	
	task_list_count++;
	return 0;
}

int os_remove_task_list(byte listnum,byte err_num){
	if(task_list[listnum]==NULL) return ERR_REMOVE_EMPTY_LIST;
	int (*tfunpt)(byte)=(*task_list[listnum]).disposeFunc;
	if(tfuncpt!=NULL)(*tfunpt)(err_num);
	//Try Disposing the functions,Make Sure Not NULL!!
	task_list[listnum]=task_list[task_list_count]; 
	//Moving Foward the last list
	taks_list_count--;
	task_list[task_list_count]=NULL;
	//Dispose the list
	return 0;
}

int add_lib_init(int (*func)()){
	if(lib_init_count==MAX_INIT_LIB) return ERR_LIB_INIT_SEQ_OVERFLOW
	to_init[lib_init_count]=func;
	lib_init_count++;
	return 0;
}

