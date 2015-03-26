#ifndef __Task_list_h__
#define __Task_list_h__

class Task_List{
	public:
	  int* getTask(int systime); 
	  //Returning a pointer containing necceary arguments for an event
	  //NULL For NO_VALID_TASK
	  
	  int addTask();
	  int (*disposeFunc)();
	  char* debug_Name; //A string used to printout when debugging.
	private:
	  unsigned char t_count;
	  unsigned char t_pointer;
	  
};

#endif