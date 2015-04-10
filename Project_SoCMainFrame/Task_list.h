#ifndef __Task_list_h__
#define __Task_list_h__
#include "Ardos.h"

struct Task{// Necessary Info of a specific Task
	byte priority;
	byte operation;
	int para[2];
	int time_step;
	int time_set;
};//每个task的定义结构体

class Task_List{
	public:
		Task_List();
		struct Task *getTask(int systime); 
		//Returning a pointer containing necceary arguments for an event
		//Return NULL For NO_VALID_TASK
		//Return ERRPTR For NO_MORE_ITEMS
		int addTask(byte,byte,int,int,int);
		// 		priority,op,		para0-1,   time_step
		//        This Function Call Is Ordered
		int (*disposeFunc)(int Errnum);//A function to call when all tasks are done
		char* debug_Name; //A string used to printout when debugging.
	  	//=======================NEED REFINEMENT========================
		struct Task task[5];//MAX_TASK of tasks
		unsigned char t_counter;//How Many Tasks?
		unsigned char t_pointer;//Which Task Are We at?
		//=======================NEED REFINEMENT========================
	  
	private:


};

#endif