#include "Ardos.h"

int Task_List::getTask(int systime){
	if(t_pointer > t_counter) return ERRPTR;//No task left
	if(task[t_pointer].time_set>systime) return NULL;//Time hasn't come yet
	// return first task then increases pointer
	return &(task[t_pointer++]);
}

int addTask(byte piority,byte operation,int para0,int para1,int para2,int para3,int time_step){
	if(t_counter==MAX_TASK)return ERR_TASK_LIST_OVERFLOW;//No spaces left
	task[t_pointer].piorit=piority;
	task[t_pointer].operation=operation;
	task[t_pointer].para[0]=para0;
	task[t_pointer].para[1]=para1;
	task[t_pointer].para[2]=para2;
	task[t_pointer].para[3]=para3;
	task[t_pointer].time_step=time_step;
	return 0;
}