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
		
	return 0;	
}

int Event_List::Add_Event(byte a,byte b,int c,int d)  // directly add one event using data not a pointer 
{
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
	//Num++;					// one more event
		
	return 0;	
}


int Event_List::Execute_Event()
{
	//Serial.println("Event_list_____1");
	//Serial.println(Num);
	//delay(1000);
	
	if (Num==0) return 0;
	
	int i;
	int j;
	//struct Event swap;
	
	/*for (i=0; i<=Num-2; i++)
		for (j=i+1; j<=Num-1; j++)
			if (list[i].priority>list[j].priority)
			{
				swap=list[i];
				list[i]=list[j];
				list[j]=swap;
			}		*/										//make it in order of priority
			
	byte Mark;
	Mark=list[Num-1].priority;
	
	int temp1,temp2;
	
	while ( (Num>0) && (millis()<over_time) )// for all events of the same priority
	{
		
		j=0;
		while ( (j<opNum) && (list_op[j].op_num!=list[Num-1].operation) )
			j++;											// finding the matching operation
		
			
		
		//Serial.print("this operation:");
		//Serial.println(list[Num-1].operation);
		//delay(1000);
		//Serial.print("this event number:");
		//Serial.println(Num);
		//delay(1000);
		
		
		temp1=list[Num-1].para[0]; temp2=list[Num-1].para[1];
		list[Num-1].priority=0; list[Num-1].operation=0;
		list[Num-1].para[0]=0;  list[Num-1].para[1]=0;
		Num--;
		if (j==opNum) return ERR_EVENT_NOT_REGISTED;
			// no operation found here 
		
		list_op[j].fp(temp1,temp2);  // execute the operation

		temp1=0; temp2=0;
		//=======================NEED REFINEMENT========================
		//memset(list[Num-1],sizeof(list[Num-1]),0);			// delete the event
		//=======================NEED REFINEMENT========================
		//The change has been made to make the program more perfect
		
	}

	//Serial.println("Event_list_______2");
	//Serial.println(Num);
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


