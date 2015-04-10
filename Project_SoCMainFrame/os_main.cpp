#include "Ardos.h"

/*This is the Main File of Ardos.
  Ardos is an NOT-SO-GENERAL purpose operating system 
  for Arduino Boards, samll and light weight enough to 
  be put into arduino uno.
  This operating system features a simple event driven
  model, and a simple timer for NOT-REAL-TIME timer.
  (Multithresding)
*/
//最长的部分

int os_init(){//Initialization process of the system
  os_init_arduino(); //其实这部分就是蓝牙的初始设置
  
  for(int i=0;i<lib_init_count;i++) (*to_init[i])(); //Execute Each Init Functions
	//lib中的各项东西的确定init
  return 0;
}

int os_run(){//the main cycle of the system
	systime=millis();//Acquire System Time
	//获得系统时间
	struct Task* tevent=NULL; 
	//这个是个指向结构体的指针
	over_time=MAXINT;
	//maxint=2147483647
	for(int i=0;i<thread_count;i++)
	{//Go Through Task List

		do
		{
			if (i>=thread_count) break;//为了防止删掉一个任务之后这个还在运行
			tevent=(*(thread_list[i])).getTask(systime);//活得task
			if (tevent==0) break;//==0说明现在没有任务可以被使用
			if(tevent==ERRPTR)//No more Tasks In a task list
			{//说明这张表走完了
			   os_remove_task_list(i,ERR_TASK_LIST_DONE);//Dispose Number i Task
			}else
			{
				event_list.Add_Event(tevent);//否则增加这个新的事件
			}
		}while(tevent!=NULL);
		
	}

	event_list.Execute_Event();//执行event_list
	
	return 0;
}

int os_add_task_list(Task_List* ntask_list){//ntask_list as in New Task List
    if(thread_count==MAX_THREADS) return ERR_LIST_TASK_LIST_OVERFLOW; 
	//if no more space in the list of task_list
	for (int i=0; i<thread_count; i++) 
		if (thread_list[i]==ntask_list) return -1;
	//如果之前这个tasklist已经被使用了，驳回这个申请
	thread_list[thread_count]=ntask_list;	
	//增加一个tasklist
	ntask_list->t_pointer=0;
	//表示现在从头开始 t_counter表示一共有多少个task在一张list内，t_pointer表示现在走到了第几个
	//Initialize the tasklist for further use
	(ntask_list->task[0]).time_set=systime+(ntask_list->task[0]).time_step;
	//计算绝对时间
	//First term = Last term + time step
	for(int i=1;i < (ntask_list->t_counter);i++){
		(ntask_list->task[i]).time_set=(ntask_list->task[i-1]).time_set+(ntask_list->task[i]).time_step;
	}//This term = Last term + time step
	
	
	thread_count++;
	//线程数加一
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
	//先将这张表清除掉
	if(tfuncpt!=NULL)(*tfuncpt)(err_num);
	//Try Disposing the functions,Make Sure Not NULL!!
	//如果这张表的dipose函数不为空，那么执行这个dispose的过程。比如蓝牙信号获取的list的dispose函数就是把自己这张表加回去
	return 0;
}

int os_add_lib_init(int (*func)()){
//在初始的状态下增加一个lib	
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
//这部分没多少价值其实完全可以扔到蓝牙部分的初始化中的
	
	return 0;
}

