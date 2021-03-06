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
  os_init_arduino();
  
  for(int i=0;i<lib_init_count;i++) (*to_init[i])(); //Execute Each Init Functions

  //os_debug_LED_blink(For_check,500);
  //regist all the operations 
  //================
  
  
  return 0;
}

int os_run(){//the main cycle of the system
	systime=millis();//Acquire System Time

	struct Task* tevent=NULL; 
	
	over_time=MAXINT;
	
	for(int i=0;i<thread_count;i++)
	{//Go Through Task List

		do
		{
			if (i>=thread_count) break;
			tevent=(*(thread_list[i])).getTask(systime);
			if (tevent==0) break;
			if(tevent==ERRPTR)//No more Tasks In a task list
			{
			   os_remove_task_list(i,ERR_TASK_LIST_DONE);//Dispose Number i Task
			}else
			{
				event_list.Add_Event(tevent);
			}
		}while(tevent!=NULL);
		
	}

	event_list.Execute_Event();
	
	return 0;
}

int os_add_task_list(Task_List* ntask_list){//ntask_list as in New Task List
    if(thread_count==MAX_THREADS) return ERR_LIST_TASK_LIST_OVERFLOW; 
	//if no more space in the list of task_list
	for (int i=0; i<thread_count; i++) 
		if (thread_list[i]==ntask_list) return -1;
	thread_list[thread_count]=ntask_list;	
	
	ntask_list->t_pointer=0;
	
	//Initialize the tasklist for further use
	(ntask_list->task[0]).time_set=systime+(ntask_list->task[0]).time_step;
	//First term = Last term + time step
	for(int i=1;i < (ntask_list->t_counter);i++){
		(ntask_list->task[i]).time_set=(ntask_list->task[i-1]).time_set+(ntask_list->task[i]).time_step;
	}//This term = Last term + time step
	
	
	thread_count++;
	return 0;
}

int os_remove_task_list(byte listnum,int err_num){
	if(thread_list[listnum]==NULL) return ERR_REMOVE_EMPTY_LIST;
	int (*tfuncpt)(int)=(*thread_list[listnum]).disposeFunc;
	
	
	thread_list[listnum]=thread_list[thread_count-1]; 
	//Moving Foward the last list
	thread_count--;
	thread_list[thread_count]=NULL;
	//Dispose the list
	
	if(tfuncpt!=NULL)(*tfuncpt)(err_num);
	//Try Disposing the functions,Make Sure Not NULL!!
	
	return 0;
}

int os_add_lib_init(int (*func)()){
	
	if(lib_init_count==MAX_INIT_LIB) return ERR_LIB_INIT_SEQ_OVERFLOW;
	to_init[lib_init_count]=func;
	lib_init_count++;
	return 0;
}

int os_init_arduino(){
	//Arduino Related Initialization
	//Serial.begin(115200);
	delay(50);//wait for Serial to be ready
	SerialCom.begin(115200);
	delay(50);//wait for Serial to be ready

	//init for the LED_BUILTIN
	//os_debug_init();
	//====================
	
	return 0;
}

