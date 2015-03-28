#ifndef __Ardos_h__
#define __Ardos_h__

#include "Arduino.h"
#include "Task_list.h"
#include "Event_list.h"
#include "Debug.h"
#include "lib/user_wifi.h"

#define byte unsigned char
#define SerialWifi Serial1 //which serial port the wifi is using?

#define MAX_TASK_LIST 10 // Maximum 10 task lists
#define MAX_TASK 5   // Maximum 5 tasks in EACH list
#define MAX_INIT_LIB 10 //Maxium 10 libs to init
#define ERRPTR (void*)(&errptr) // Error Pointer, Define for using as a constant

extern byte task_list_count;	// Number of current task lists	
extern byte lib_init_count;	//how many inits?
extern int systime; //System Time in milliseconds
extern Task_List* tlist[MAX_TASK_LIST]; //instantiate a mission list	
extern int (*to_init)()[MAX_INIT_LIB];//libs to init after initialization

extern struct  ;
extern char errptr;

extern int os_init();
extern int os_run();
extern int os_add_tasklist();
extern int os_remove_tasklist();
extern int os_add_lib_init(int (*func)());
extern int os_init_arduino();
extern Event_List event_list;
e

#endif