#include "Ardos.h"

Task_List::Task_List(){
	t_counter=0;
	t_pointer=0;
	disposeFunc=NULL;//再次说明凡是一个task_list它的disposefunction必须被写明确
}

struct Task* Task_List::getTask(int systime){
	if(t_pointer >= t_counter) return ERRPTR;//No task left
	if (task[t_pointer].time_set>systime) 
	{
		over_time=(over_time<=task[t_pointer].time_set)? over_time:task[t_pointer].time_set;
		return NULL;//Time hasn't come yet
	}
	// return first task then increases pointer
	return &(task[t_pointer++]);
}//根据提供的系统时间获得可执行的任务

int Task_List::addTask(byte priority,byte operation,int para0,int para1,int time_step){
	if(t_counter==MAX_TASK)return ERR_TASK_LIST_OVERFLOW;//No spaces left
	task[t_counter].priority=priority;
	task[t_counter].operation=operation;
	task[t_counter].para[0]=para0;
	task[t_counter].para[1]=para1;
	task[t_counter].time_step=time_step;
	t_counter++;
	return 0;
}//在这个task_list中增加一个task