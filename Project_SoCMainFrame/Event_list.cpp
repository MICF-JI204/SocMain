#include "Ardos.h"

Event_List::Event_List()
{
	for (int i=0; i<MAXEVENTNUM; i++)
	{
		list[i].priority=0; 
		list[i].operation=0;
		list[i].para[0]=0; list[i].para[1]=0;
	}
	NUM=0;
	
	for (int i=0; i<MAXOPNUM; i++)
	{
		list_op[i].op_num=0;
		list_op[i].fp=NULL;
	}
	opNum=0;
	
}

int Event_List::Add_Event(struct Event* AddOne) //Add 1 event
{
	if (Num==MAXEVENTNUM) return ERR_EVENT_LIST_OVERFLOW;
	list[Num].priority=AddOne->priority;
	list[Num].operation=AddOne->operation;
	list[Num].para[0]=AddOne->para[0];
	list[Num].para[1]=AddOne->para[1];
	Num++;
		
	return 0;	
}

int Event_List::Add_Event(byte a,byte b,int c,int d); 
{
	if (Num==MAXEVENTNUM) return ERR_EVENT_LIST_OVERFLOW;
	list[Num].priority=a;
	list[Num].operation=b;
	list[Num].para[0]=c;
	list[Num].para[1]=d;
	Num++;
		
	return 0;	
}
}

int Event_list::Exacute_event()
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
			}
			
	byte Mark;
	Mark=list[Num-1].priority;
	
	while ( (Num>0) && (Mark==list[Num-1].priority) )
	{
		
		j=0;
		while ( (j<opNum) && (list_op[j].op_num!=list[Num-1].operation) )
			j++;
		
		if (j==opNum) return ERR_EVENT_NOT_REGISTED;
		
		list_op[j].fp(list[Num-1].para[1],list[Num-1].para2);
		
		memset(list[Num-1],sizeof(list[Num-1]),0);
		Num--;
	}
}

int Event_List::Regist_Event(int (fun_add*) (int para1,int para2), byte opera)
{
	if (opNum==MAXOPNUM) return ERR_EVENT_RIGISTRY_OVERFLOWED;//
	
	int i,j;
	for (i=0; i<opNum; i++)
		if (opera==list_op[i].op_num) break;
	
	if (opera==list_op[i].op_num)
	{
		list_op[i].fp=fun_add;
	};
	else
	{
		list_op[opNum].op_num=opera;
		list_op[opNum].fp=fun_add;
		opNum++;
	};
	
	return 0;
}


