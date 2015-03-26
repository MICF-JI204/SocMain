#ifndef __Event_list_h__
#define __Event_list_h__

struct Event
{
	// P  OP  Para1-4
	
};

class Event_List
{
	public:
		int Add_Event();     // haven't complete;
		int Exacute_Event(); // Execute One Event
		int Regist_Event();// haven't complete;
		
	private:
		//unsigned char t_count;
		//unsigned char t_pointer;
		struct Event list[100];
	
};

#endif