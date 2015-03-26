#ifndef __Task_list_h__
#define __Task_list_h__

class Task_List{
	public:
	  int getTask(int systime); 
	  //Returning a pointer containing necceary arguments for an event
	  int addTask();
	  int (*disposeFunc)();
	private:
	  unsigned char t_count;
	  unsigned char t_pointer;
	  
};

#endif