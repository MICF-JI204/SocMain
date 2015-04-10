#ifndef __Ardos_h__
#define __Ardos_h__

#include "Arduino.h"
#include "Task_list.h"
#include "Event_list.h"
#include "Debug.h"
#include "user_wifi.h"
#include "os_debug_buzzer.h"
#include "os_debug_LED.h"

#define byte unsigned char
#define SerialCom Serial1 //which serial port the wifi is using?

#define MAX_THREADS 10 // Maximum 10 task lists
#define MAX_TASK 10   // Maximum 10 tasks in EACH list
#define MAX_INIT_LIB 10 //Maxium 10 libs to init

#define MAXINT 2147483647;

#define ERRPTR (&errptr) // Error Pointer, Define for using as a constant
#define os_add_event event_list.Add_Event// A Macro for easy interface
#define os_regist_event event_list.Regist_Event// Another Macro for easy interface

extern byte thread_count;	// Number of current task lists	
extern byte lib_init_count;	//lib初始化的数量
extern int systime; //存放系统时间的
extern Task_List* thread_list[MAX_THREADS]; //线程数定义（里面存放的是tasklist的头指针）	
extern int (*(to_init[MAX_INIT_LIB]))();//libs to init after initialization （函数的extern声明）
//以下都是函数、变量的extern声明
extern struct Task errptr; // 这个的用来标记，gettask的时候这个tasklist是否用完

extern int os_init();
extern int os_run();
extern int os_add_task_list(Task_List* ntask_list);
extern int os_remove_task_list(byte,int);
extern int os_add_lib_init(int (*func)());
extern int os_init_arduino();

//========Attached
extern int Devide();
extern int Combine();
extern byte part1;
extern byte part2;
extern int whole;
//以上部分只有当使用多于两个参数时使用，但是因为大家基本上不用用到两个参数以上的，所以我不做解释了

extern Event_List event_list;// Event_List的实例化

extern int over_time;//优化使用的一个变量
/*具体方法：在查找task_list的时候顺便记录下次一个最近的任务的绝对时间，然后记录。执行event_list的时候只要系统时间没到这个记录时间就不断执行event_list*/

#endif