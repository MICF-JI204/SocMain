#ifndef __Event_list_h__
#define __Event_list_h__

#define MAXEVENTNUM 20

struct Event
{
	byte priority;
	byte operation;
	int para[2];
};

class Event_List
{
	public:
		int Add_Event(struct Event* AddOne);     // here is the pointer;
		int Add_Event(byte a,byte b,int c,int d);  // here is the exact data not the pointer
		int Execute_Event(); // Execute One Event
		int Regist_Event();// haven't complete;
		Event_List();
		
	private:
		//unsigned char t_count;
		//unsigned char t_pointer;
		struct Event list[MAXEVENTNUM];
		unsigned char Num;
		
};

#endif