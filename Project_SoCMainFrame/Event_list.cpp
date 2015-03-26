#include "Ardos.h"

Event_list::Add_event() //Add 1 event
{
	Num++;
	
}

Event_list::Add_event() //Add a couple of events
{
	Num++;
	
}

Event_list::Exacte_event()
{
	
	
	int i;
	int j;
	Event swap;
	
	for (i=0; i<=Num-1; i++)
		for (j=i+1; j<=Num-1; j++)
			if (list[i].priority>list[j].priority)
			{
				swap=list[i];
				list[i]=list[j];
				list[j]=swap;
			}
			
	unsigned char Mark;
	Mark=list[Num].priority;
	
	while 
	
}