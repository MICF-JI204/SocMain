#ifndef __Event_list_h__
#define __Event_list_h__

struct Event
{
	unsigned char priority;
	unsigned char operation;
	int part1,part2,part3,part4;
};

class Event_List
{
	public:
		int Add_Event();     // haven't complete;
		int Execute_Event(); // Execute One Event
		int Regist_Event();// haven't complete;
		
	private:
		//unsigned char t_count;
		//unsigned char t_pointer;
		Event list[50];
		unsigned char Num;
		
};

#endif