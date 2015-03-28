#ifndef __Event_list_h__
#define __Event_list_h__

#define MAXEVENTNUM 20
#define MAXOPNUM 50

struct Event
{
	byte priority;
	byte operation;
	int para[2];
};

struct oper
{
	byte op_num;
	int (fp*) (int para1, int para2);
}

class Event_List
{
	public:
		int Add_Event(struct Event* AddOne);     // here is the pointer;
		int Add_Event(byte a,byte b,int c,int d);  // here is the exact data not the pointer
		int Execute_Event(); // Execute One Event
		int Regist_Event(int (fun_add*) (int para1,int para2), byte opera);//
		Event_List();
		
	private:
		struct Event list[MAXEVENTNUM];
		byte Num;
		struct oper list_op[MAXOPNUM];
		byte opNum;

};

#endif