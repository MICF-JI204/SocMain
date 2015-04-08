/* This files makes global definitions 
   Index this file using "Ardos.h"
   Usage See "Ardos.h"
*/
#include "Ardos.h"

Event_List event_list;

//===========OS_STATUS==========
int systime; //System Time in milliseconds

Task_List* thread_list[MAX_THREADS]={NULL}; //instantiate a task list	
byte thread_count=0;	// Number of current task lists	

int (*to_init[MAX_INIT_LIB])()={NULL};//libs to init after initialization
byte lib_init_count=0;	//how many inits?

struct Task errptr={0,0,{0,0},0,0};

int over_time;


//===========Attached(Combine,Devide)=====
byte part1=0;
byte part2=0;
int whole=0;

//===========run for debug
//int For_check=3000;