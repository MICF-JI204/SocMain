#include "Ardos.h"

Event_List::Event_List()
{
	for (int i=0; i<MAXEVENTNUM; i++)
	{
		list[i].priority=0; 
		list[i].operation=0;
		list[i].para[0]=0; list[i].para[1]=0;
		list[i].para[2]=0; list[i].para[3]=0;
	}
	NUM=0;
	
}

int Event_List::Add_Event(struct Event* AddOne) //Add 1 event
{
	if (Num==MAXEVENTNUM) return ERR_EVENT_LIST_OVERFLOW;
	list[Num].priority=AddOne->priority;
	list[Num].operation=AddOne->operation;
	list[Num].para[0]=AddOne->para[0];
	list[Num].para[1]=AddOne->para[1];
	list[Num].para[2]=AddOne->para[2];
	list[Num].para[3]=AddOne->para[3];
	Num++;
		
	return 0;	
}

int Event_List::Add_Event(byte a,byte b,int c,int d,int e,int f); 
{
	if (Num==MAXEVENTNUM) return ERR_EVENT_LIST_OVERFLOW;
	list[Num].priority=a;
	list[Num].operation=b;
	list[Num].para[0]=c;
	list[Num].para[1]=d;
	list[Num].para[2]=e;
	list[Num].para[3]=f;
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
	
	for (i=0; i<=Num-1; i++)
		for (j=i+1; j<=Num-1; j++)
			if (list[i].priority>list[j].priority)
			{
				swap=list[i];
				list[i]=list[j];
				list[j]=swap;
			}
			
	byte Mark;
	Mark=list[Num].priority;
	
	while ( (Num>0) && (Mark==list[Num].priority) )
	{
		
		
		memset(list[Num-1],sizeof(list[Num-1]),0);
		Num--;
	}
}