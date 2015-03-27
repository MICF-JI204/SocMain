#ifndef __Task_list_h__
#define __Task_list_h__

class Task_List{
	public:
	  int* getTask(int systime); 
	  //Returning a pointer containing necceary arguments for an event
	  //Return NULL For NO_VALID_TASK
	  //Return ERRPTR For NO_MORE_ITEMS
	  int addTask();
	  int (*disposeFunc)();
	  char* debug_Name; //A string used to printout when debugging.
	private:
	  unsigned char t_count;
	  unsigned char t_pointer;
	  
};

#endif