#ifndef __Task_list_h__
#define __Task_list_h__

struct Task{// Necessary Info of a specific Task
	byte piority;
	byte operation;
	int para[2];
	int time_step;
	int time_set;
};

class Task_List{
	public:
	  struct Task *getTask(int systime); 
	  //Returning a pointer containing necceary arguments for an event
	  //Return NULL For NO_VALID_TASK
	  //Return ERRPTR For NO_MORE_ITEMS
	  int addTask(byte,byte,int,int,int);
	  // 		piority,op,		para0-1,   time_step
	  //        This Function Call Is Ordered
	  int (*disposeFunc)(byte Errnum);//A function to call when all tasks are done
	  char* debug_Name; //A string used to printout when debugging.
	private:
	  unsigned char t_count;//How Many Tasks?
	  unsigned char t_pointer;//Which Task Are We at?
	  struct Task task[MAX_TASK];//MAX_TASK of tasks
	  
};

#endif