#include "Ardos.h"

ESP_01 wifi_com();//Firstly, Define your module
Task_List task_list_wifi;
//Define however amount of task lists you want 
//Task_List task_list_wifi2;
//Task_List task_list_wifi3;
//.....
//As Many As You Want, Initialize them below
ESP_01::ESP_01(){
	os_add_lib_init((ESP_01::Init)); // Add Initialization Function
	return;
}

int ESP_01::Init(){//The Initialization of this library
	
	//Initialize the class 
    for(int i=0;i<WIFI_BUFFER_SIZE;i++)buffer[i]=0x0;
	
	//Associate Operation With Functions using os_regsit_event
	os_regist_event(OP_CHECK_WIFI,ESP_01::Get_Msg);
	
	//Generate Neccesary Task List
	//Each Task Must Have 5 arguments
	//Use zero to fill the unused place
	//Last argument for "How soon should it be called,in ms"
	task_list_wifi.addTask(10,OP_CHECK_WIFI,0,0,20);
	//Mast Have, tell system what to do after finish an task list
	//If there is nothing to do, write:
	//			task_list_wifi.disposeFunc=NULL;
	//The argument gives the reason of its diposal
	//Is it diposed normally or something goes wrong
	//Can be used to create loops
	task_list_wifi.disposeFunc=DisposeFunc1;
	//At Last, Add the entire list to os using os_add_task_list
	os_add_task_list(&task_list_wifi);
	//Then we are done!
	
	delay(3000); //Waiting the Wifi Module to be Ready
	SerialWifi.print("+++");//Exit from direct link mode
	delay(500);
	//Establish a tcp/ip link
	SerialWifi.print("AT+CIPSTART=\"TCP\",\"192.168.4.104\",14204\n");
	delay(5000);//waiting to establish a link 
	SerialWifi.print("AT+CIPSEND\n");//Entering Direct Link Mode
	delay(500);
	SerialWifi.println(F("Geronimo\n"));//Geronimo!!!
	char reply[]="RUCBAR\n";//Run U Clever Boy, And REMEMBER!
	for(int i=0;i<7;i++)//7 as in the length of the array
		if(SerialWifi.read()!=reply[i]) break; //Failed to init wifi
	return 0;
}

int ESP_01::Get_Msg(int op1,int op2){//TO REGIST IT,MUST ALWAYS HAVE 2 PARAMETERS
	if(SerialWifi.available()<WIFI_BUFFER_SIZE)return ERR_WIFI_CMD_NOT_READY;
	while(SerialWifi.available()>=WIFI_BUFFER_SIZE){
		if((buffer[0]=SerialWifi.read())!=WIFI_PACKAGE_HEADER)continue;//Header note reached
		for(int i=1;i<WIFI_BUFFER_SIZE;i++)buffer[i]=SerialWifi.read();//read in rest of the message
		if(Check_Sum()==true)Distribute_Msg();
	}
}

bool ESP_01::Check_Sum(){
  byte sum = 0;
  for(int i=0;i<WIFI_BUFFER_SIZE-1;i++)sum+=(byte)buffer[i];//checksum
  return (sum == buffer[WIFI_BUFFER_SIZE-1]);// return checksum result
}

int ESP_01::Distribute_Msg(){
	os_add_event((byte)buffer[1],(byte)buffer[2],buffer[3],buffer[4]);
	return 0;
}
int ESP_01::DisposeFunc1(int ERRNUM){
	os_add_task_list(&task_list_wifi);//Adding back the same list
}