#ifndef __Event_list_h__
#define __Event_list_h__

#include "Ardos.h"

#define MAXEVENTNUM 50   // maximum of the event list
#define MAXOPNUM 50		// maximum of the operation list

struct Event
{
	byte priority;
	byte operation;
	int para[2];
};//存放event的结构体

struct oper				//struct of a operation 
{
	byte op_num;
	int (*fp) (int para1, int para2);
};//存放operation的结构体

class Event_List
{
	public:
		int Add_Event(struct Task *AddOne);     // here is the pointer;
		int Add_Event(byte a,byte b,int c,int d);  // here is the exact data not the pointer
		int Execute_Event(); // Execute One Event
		int Regist_Event(byte opera,int (*fun_add) (int para1,int para2));// regist an event 
		Event_List();
		
	private:
		struct Event list[MAXEVENTNUM];			// list of the event--> list
		byte Num;								// number of the entries of the list
		struct oper list_op[MAXOPNUM];			// list of the operation--> list_op
		byte opNum;								// number of the entries of the list_op

};

#endif