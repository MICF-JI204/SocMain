#include "Ardos.h"

Event_List::Event_List() // initialization event_list的构造函数
{
	for (int i=0; i<MAXEVENTNUM; i++)
	{
		list[i].priority=0; 
		list[i].operation=0;
		list[i].para[0]=0; list[i].para[1]=0;
	}
	Num=0; 
	
	for (int i=0; i<MAXOPNUM; i++)
	{
		list_op[i].op_num=0;
		list_op[i].fp=NULL;
	}
	opNum=0;
	//所有东西清零
}

int Event_List::Add_Event(struct Task* AddOne) //Add one event
{ //输入一个task的指针，然后把这个task转化成event
	if (Num==MAXEVENTNUM) return ERR_EVENT_LIST_OVERFLOW; //
	
	int j;
	j=Num;
	Num++;
	while ( (j>0) && (list[j-1].priority>=AddOne->priority) )
	{
		list[j]=list[j-1];
		j--;
	}
	
	list[j].priority=AddOne->priority;
	list[j].operation=AddOne->operation;
	list[j].para[0]=AddOne->para[0];
	list[j].para[1]=AddOne->para[1];
	// one more event
		//最简单的插入排序，维护一个priority的从低到高
	return 0;	
}

int Event_List::Add_Event(byte a,byte b,int c,int d)  // directly add one event using data not a pointer 
{//和上面一样，只是一个重载
	if (Num==MAXEVENTNUM) return ERR_EVENT_LIST_OVERFLOW;
	
	int j;
	j=Num;
	Num++;
	while ( (j>0) && ( list[j-1].priority>=a ) )
	{
		list[j]=list[j-1];
		j--;
	}
	
	list[j].priority=a;
	list[j].operation=b;
	list[j].para[0]=c;
	list[j].para[1]=d;
	// one more event
		
	return 0;	
}


int Event_List::Execute_Event()
{//执行event_list,依次
	if (Num==0) return 0; //如果event已经被执行完了

	int i;
	int j;

	//byte Mark;
	//Mark=list[Num-1].priority;
	
	int temp1,temp2;
	
	while ( (Num>0) && (millis()<over_time) )// 只要有任务并且时间上还有盈余，就不断执行
	{
		
		j=0;
		while ( (j<opNum) && (list_op[j].op_num!=list[Num-1].operation) )
			j++;											// finding the matching operation
		//寻找匹配的operation
		if (j==opNum) return ERR_EVENT_NOT_REGISTED;	
		//不存在该操作
		temp1=list[Num-1].para[0]; temp2=list[Num-1].para[1];
		list[Num-1].priority=0; list[Num-1].operation=0;
		list[Num-1].para[0]=0;  list[Num-1].para[1]=0;
		Num--;
		//先把这个event清理掉，两个参数暂时存放（此处必须暂存）
		list_op[j].fp(temp1,temp2);  // execute the operation

		temp1=0; temp2=0;
		//清理暂存
	}

}

int Event_List::Regist_Event(byte opera,int (*fun_add) (int para1,int para2))
{//注册一个operation
	if (opNum==MAXOPNUM) return ERR_EVENT_RIGISTRY_OVERFLOWED;//
	//operation满了
	int i,j;
	for (i=0; i<opNum; i++)
		if (opera==list_op[i].op_num) break;		// check if there is a operation registed before but occupied the same button
	//如果有一样的操作号被注册了
	if (opera==list_op[i].op_num)
	{
		list_op[i].fp=fun_add;				// there is, then just change the pointer of the function
	}
	else
	{
		list_op[opNum].op_num=opera;		// create a new one
		list_op[opNum].fp=fun_add;
		opNum++;//在op_list中增加一个操作
	};
	
	return 0;
}


