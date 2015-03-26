#ifndef __Ardos_h__
#define __Ardos_h__

#include "Task_list.h"

#define MAX_TASK_LIST 10 // Maximum 10 task lists
#define Max_TASK 10   // Maximum 10 tasks in EACH list

struct OS_Status{
	int systime; //System Time in milliseconds
	char task_list_count;// Number of current task lists
	Task_List* tlist[10]; //instantiate a mission list
};
				
extern struct OS_Status os_status;

extern int os_init();
extern int os_run();
extern int os_add_tasklist();
extern int os_remove_tasklist();

#endif