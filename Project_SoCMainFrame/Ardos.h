#ifndef __Ardos_h__
#define __Ardos_h__

#include "Arduino.h"
#include "Task_list.h"
#include "Event_list.h"
#include "Debug.h"
#include "user_wifi.h"
#include "os_debug_buzzer.h"
#include "os_debug_LED.h"
#include "chouban.h"

#define byte unsigned char
#define SerialCom Serial //which serial port the wifi is using?

#define MAX_THREADS 10 // Maximum 10 task lists
#define MAX_TASK 10   // Maximum 10 tasks in EACH list
#define MAX_INIT_LIB 10 //Maxium 10 libs to init

#define MAXINT 2147483647;

#define ERRPTR (&errptr) // Error Pointer, Define for using as a constant
#define os_add_event event_list.Add_Event// A Macro for easy interface
#define os_regist_event event_list.Regist_Event// Another Macro for easy interface

extern byte thread_count;	// Number of current task lists	
extern byte lib_init_count;	//how many inits?
extern long int systime; //System Time in milliseconds
extern Task_List* thread_list[MAX_THREADS]; //instantiate a mission list	
extern int (*(to_init[MAX_INIT_LIB]))();//libs to init after initialization

extern struct Task errptr;

extern int os_init();
extern int os_run();
extern int os_add_task_list(Task_List* ntask_list);
extern int os_remove_task_list(byte,int);
extern int os_add_lib_init(int (*func)());
extern int os_init_arduino();

//=======LED_debug
//extern int os_debug_init();
//extern int os_debug_LED_blink(int a, int b);
//extern int os_debug_LED1(int a, int b);

//========Attached
extern int Devide();
extern int Combine();
extern byte part1;
extern byte part2;
extern int whole;

extern Event_List event_list;

extern long int over_time;

//=========for check
//extern int For_check;
//=========Bluetooth
//extern Wireless_Com wireless_com;//Firstly, Define your module
//extern Task_List task_list_com;

#endif