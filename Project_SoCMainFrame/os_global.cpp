/* This files makes global definitions 
   Index this file using "Ardos.h"
   Usage See "Ardos.h"
*/
#include "Ardos.h"

Event_List event_list;

//===========OS_STATUS==========
int systime; //System Time in milliseconds

Task_List* tlist[MAX_TASK_LIST]={NULL}; //instantiate a task list	
byte task_list_count=0;	// Number of current task lists	

int (*to_init[MAX_INIT_LIB])()={NULL};//libs to init after initialization
byte lib_init_count=0;	//how many inits?

char errptr=-1;