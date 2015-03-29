#include "Ardos.h"

Wireless_Com wireless_com();//Firstly, Define your module
Task_List task_list_com;
//Define however amount of task lists you want 
//Task_List task_list_com2;
//Task_List task_list_com3;
//.....
//As Many As You Want, Initialize them below
Wireless_Com::Wireless_Com(){
	os_add_lib_init((Wireless_Com::bInit)); // Add Initialization Function
	return;
}

int Wireless_Com::wInit(){//The Initialization of this library on wifi
	
	//Initialize the class 
    for(int i=0;i<COM_BUFFER_SIZE;i++)buffer[i]=0x0;
	for(int i=0;i<COM_OUT_BUFFER_SIZE;i++)buffer[i]=0x0;
	//Associate Operation With Functions using os_regsit_event
	os_regist_event(OP_CHECK_COM,Wireless_Com::Get_Msg);
	
	//Generate Neccesary Task List
	//Each Task Must Have 5 arguments
	//Use zero to fill the unused place
	//Last argument for "How soon should it be called,in ms"
	task_list_com.addTask(10,OP_CHECK_COM,0,0,20);
	//Mast Have, tell system what to do after finish an task list
	//If there is nothing to do, write:
	//			task_list_com.disposeFunc=NULL;
	//The argument gives the reason of its diposal
	//Is it diposed normally or something goes wrong
	//Can be used to create loops
	task_list_com.disposeFunc=DisposeFunc1;
	//At Last, Add the entire list to os using os_add_task_list
	os_add_task_list(&task_list_com);
	//Then we are done!
	
	delay(3000); //Waiting the Wifi Module to be Ready
	SerialCom.print("+++");//Exit from direct link mode
	delay(500);
	//Establish a tcp/ip link
	SerialCom.print("AT+CIPSTART=\"TCP\",\"192.168.4.104\",14204\n");
	delay(5000);//waiting to establish a link 
	SerialCom.print("AT+CIPSEND\n");//Entering Direct Link Mode
	delay(500);
	SerialCom.println(F("Geronimo\n"));//Geronimo!!!
	char reply[]="RUCBAR\n";//Run U Clever Boy, And REMEMBER!
	for(int i=0;i<7;i++)//7 as in the length of the array
		if(SerialCom.read()!=reply[i]) break; //Failed to init wifi
	return 0;
}

int Wireless_Com::bInit(){//The Initialization of this library,As in bluetooth
	
	//Initialize the class 
    for(int i=0;i<COM_BUFFER_SIZE;i++)buffer[i]=0x0;
	for(int i=0;i<COM_OUT_BUFFER_SIZE;i++)buffer[i]=0x0;
	//Associate Operation With Functions using os_regsit_event
	os_regist_event(OP_CHECK_COM,Wireless_Com::Get_Msg);
	
	//Generate Neccesary Task List
	//Each Task Must Have 5 arguments
	//Use zero to fill the unused place
	//Last argument for "How soon should it be called,in ms"
	task_list_com.addTask(10,OP_CHECK_COM,0,0,20);
	//Mast Have, tell system what to do after finish an task list
	//If there is nothing to do, write:
	//			task_list_com.disposeFunc=NULL;
	//The argument gives the reason of its diposal
	//Is it diposed normally or something goes wrong
	//Can be used to create loops
	task_list_com.disposeFunc=DisposeFunc1;
	//At Last, Add the entire list to os using os_add_task_list
	os_add_task_list(&task_list_com);
	//Then we are done!
	
	delay(3000); //Waiting the Bluetooth Module to be Ready
	SerialCom.println(F("Geronimo\n"));//Geronimo!!!
	char reply[]="RUCBAR\n";//Run U Clever Boy, And REMEMBER!
	for(int i=0;i<7;i++)//7 as in the length of the array
		if(SerialCom.read()!=reply[i]) break; //Failed to init bluetooth
	return 0;
}

int Wireless_Com::Get_Msg(int op1,int op2){//TO REGIST IT,MUST ALWAYS HAVE 2 PARAMETERS
	if(SerialCom.available()<COM_BUFFER_SIZE)return ERR_COM_CMD_NOT_READY;
	while(SerialCom.available()>=COM_BUFFER_SIZE){
		if((buffer[0]=SerialCom.read())!=COM_PACKAGE_HEADER)continue;//Header note reached
		for(int i=1;i<COM_BUFFER_SIZE;i++)buffer[i]=SerialCom.read();//read in rest of the message
		if(Wireless_Com::Check_Sum()==true)Wireless_Com::Distribute_Msg();
	}
}

int Wireless_Com::Send_Msg(byte op,byte arg){//TO REGIST IT,MUST ALWAYS HAVE 2 PARAMETERS
	out_buffer[1]=op;
	out_buffer[2]=arg;
	out_buffer[0]=COM_PACKAGE_HEADER;
	out_buffer[3]=0;
	for(int i=0;i<COM_OUT_BUFFER_SIZE-1;i++)out_buffer[3]+=out_buffer[i];
	SerialCom.write(out_buffer,COM_OUT_BUFFER_SIZE);
	return 0;
}

bool Wireless_Com::Check_Sum(){
  byte sum = 0;
  for(int i=0;i<COM_BUFFER_SIZE-1;i++)sum+=(byte)buffer[i];//checksum
  return (sum == buffer[COM_BUFFER_SIZE-1]);// return checksum result
}

int Wireless_Com::Distribute_Msg(){
	//os_add_event((byte)buffer[1],(byte)buffer[2],buffer[3],buffer[4]);
	return 0;
}
int Wireless_Com::DisposeFunc1(int ERRNUM){
	os_add_task_list(&task_list_com);//Adding back the same list
}