#include "Ardos.h"

Event_List::Event_List() // initialization
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
	
}

int Event_List::Add_Event(struct Task* AddOne) //Add one event
{
	if (Num==MAXEVENTNUM) return ERR_EVENT_LIST_OVERFLOW; //
	list[Num].priority=AddOne->priority;
	list[Num].operation=AddOne->operation;
	list[Num].para[0]=AddOne->para[0];
	list[Num].para[1]=AddOne->para[1];
	Num++;                              // one more event
		
	return 0;	
}

int Event_List::Add_Event(byte a,byte b,int c,int d)  // directly add one event using data not a pointer 
{
	if (Num==MAXEVENTNUM) return ERR_EVENT_LIST_OVERFLOW;
	list[Num].priority=a;
	list[Num].operation=b;
	list[Num].para[0]=c;
	list[Num].para[1]=d;
	Num++;					// one more event
		
	return 0;	
}


int Event_List::Execute_Event()
{
	if (Num==0) return 0;
	
	int i;
	int j;
	struct Event swap;
	
	for (i=0; i<=Num-2; i++)
		for (j=i+1; j<=Num-1; j++)
			if (list[i].priority>list[j].priority)
			{
				swap=list[i];
				list[i]=list[j];
				list[j]=swap;
			}												//make it in order of priority
			
	byte Mark;
	Mark=list[Num-1].priority;
	
	while ( (Num>0) && (Mark==list[Num-1].priority) )      // for all events of the same priority
	{
		
		j=0;
		while ( (j<opNum) && (list_op[j].op_num!=list[Num-1].operation) )
			j++;											// finding the matching operation
		
		if (j==opNum) return ERR_EVENT_NOT_REGISTED;		// no operation found here 
		
		list_op[j].fp(list[Num-1].para[0],list[Num-1].para[1]);  // execute the operation
		//=======================NEED REFINEMENT========================
		//memset(list[Num-1],sizeof(list[Num-1]),0);			// delete the event
		//=======================NEED REFINEMENT========================
		//The change has been made to make the program more perfect
		
		list[Num-1].priority=0; list[Num-1].operation=0;
		list[Num-1].para[0]=0;  list[Num-1].para[1]=0;
		Num--;
	}
}

int Event_List::Regist_Event(byte opera,int (*fun_add) (int para1,int para2))
{
	if (opNum==MAXOPNUM) return ERR_EVENT_RIGISTRY_OVERFLOWED;//
	
	int i,j;
	for (i=0; i<opNum; i++)
		if (opera==list_op[i].op_num) break;		// check if there is a operation registed before but occupied the same button
	
	if (opera==list_op[i].op_num)
	{
		list_op[i].fp=fun_add;				// there is, then just change the pointer of the function
	}
	else
	{
		list_op[opNum].op_num=opera;		// create a new one
		list_op[opNum].fp=fun_add;
		opNum++;
	};
	
	return 0;
}


