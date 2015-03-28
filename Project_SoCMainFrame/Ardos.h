#ifndef __Ardos_h__
#define __Ardos_h__

#include "Task_list.h"
#include "Event_list.h"
#include "Debug.h"
#include "lib/user_wifi.h"

#define byte unsigned char

#define MAX_TASK_LIST 10 // Maximum 10 task lists
#define Max_TASK 5   // Maximum 5 tasks in EACH list
#define ERRPTR (void*)(&errptr) // Error Pointer, Define for using as a constant

struct OS_Status{
	int systime; //System Time in milliseconds
	byte task_list_count;// Number of current task lists
	Task_List* tlist[10]; //instantiate a mission list
};
				
extern struct OS_Status os_status;
extern char errptr;

extern int os_init();
extern int os_run();
extern int os_add_tasklist();
extern int os_remove_tasklist();
extern Event_List event_list();

#endif