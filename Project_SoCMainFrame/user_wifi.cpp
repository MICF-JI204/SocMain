#include "Ardos.h"

//===========bluetooth
Wireless_Com wireless_com;//Firstly, Define your module
Task_List task_list_com;

//Define however amount of task lists you want 
//Task_List task_list_com2;
//Task_List task_list_com3;
//.....
//As Many As You Want, Initialize them below
Wireless_Com::Wireless_Com(){
	os_add_lib_init((Wireless_Com::bInit)); // Add Initialization Function
	//蓝牙的初始化的加入。额外提一下，这里不应该是wifi的一开始写的是WiFi但是后来其实用的是蓝牙
	return;
}

byte Wireless_Com::out_buffer[COM_OUT_BUFFER_SIZE]={0};
byte Wireless_Com::buffer[COM_BUFFER_SIZE]={0};
// 因为static只声明不定义所以得重新定义
/*int Wireless_Com::wInit(){//The Initialization of this library on wifi
	
	//Initialize the class 
    for(int i=0;i<COM_BUFFER_SIZE;i++)buffer[i]=0x0;
	for(int i=0;i<COM_OUT_BUFFER_SIZE;i++)out_buffer[i]=0x0;
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
*/
//本来的wifi端的控制程序
int Wireless_Com::bInit(){//The Initialization of this library,As in bluetooth
	
	//Initialize the class 
    for(int i=0;i<COM_BUFFER_SIZE;i++)buffer[i]=0x0;
	for(int i=0;i<COM_OUT_BUFFER_SIZE;i++)out_buffer[i]=0x0;
	//输出的缓存区和输入的缓存区的清零
	//Associate Operation With Functions using os_regsit_event
	os_regist_event(OP_CHECK_COM,Wireless_Com::Get_Msg);
    os_regist_event(OP_SEND_CHECK_MSG,Wireless_Com::Send_Check_Msg);
	//注册两个关键operation，一个是接受消息一个输出消息
	//Generate Necessary Task List
	//Each Task Must Have 5 arguments
	//Use zero to fill the unused place
	//Last argument for "How soon should it be called,in ms"
	task_list_com.addTask(10,OP_CHECK_COM,0,0,20);
	//先生成一张列表，其中只有一条信息：20second之后获取蓝牙信号
	//Mast Have, tell system what to do after finish an task list
	//If there is nothing to do, write:
	//			task_list_com.disposeFunc=NULL;
	//The argument gives the reason of its diposal
	//Is it diposed normally or something goes wrong
	//Can be used to create loops
	task_list_com.disposeFunc=DisposeFunc1;
	//disposeFunc是。。。内容是再把这张表加回来
	//At Last, Add the entire list to os using os_add_task_list
	os_add_task_list(&task_list_com);
	//把这个task_list加进系统
	//Then we are done!
	//os_debug_LED_blink(500,500);
	delay(3000); //Waiting the Bluetooth Module to be Ready
	
	for( int tt=0;tt<=1;tt++)
	{
	SerialCom.println(F("Geronimo\n"));//Geronimo!!!
	//delay(500);
	}
	//Serial.println("hh");
	//os_debug_LED_blink(3000,500);
	char reply[]="RUCBAR\n";//Run U Clever Boy, And REMEMBER!
	bool check=1;
	byte sendso;
	for(int i=0;i<7;i++)//7 as in the length of the array
	{
		while (SerialCom.available()<=0);
		sendso=SerialCom.read();
		SerialCom.println((char)sendso);
		//Serial.println(sendso);
		check=check&&(SerialCom.read()==reply[i]); //Failed to init bluetooth
	}
	//byte outout[4]={0xCC,0xF2,0x00,0xBE};
	os_add_event(10,OP_SEND_CHECK_MSG,0,0);
//以上全部是一个最最基本的握手程序，大家自行理解吧。。
	return 0;
}

int Wireless_Com::Get_Msg(int op1,int op2){//TO REGIST IT,MUST ALWAYS HAVE 2 PARAMETERS

	if(SerialCom.available()<COM_BUFFER_SIZE)return ERR_COM_CMD_NOT_READY;
	while(SerialCom.available()>=COM_BUFFER_SIZE){
		//查询可以获得的蓝牙信号
		Wireless_Com::buffer[0]=SerialCom.read();
		if(Wireless_Com::buffer[0]!=COM_PACKAGE_HEADER)continue;//Header note reached
		//如果信号的head不是我们规定的head就无视继续收消息
		for(int i=1;i<COM_BUFFER_SIZE;i++)
		{
			buffer[i]=SerialCom.read();//read in rest of the message
			//收取剩余消息
		}
		if(Wireless_Com::Check_Sum()==true)//如果这边八个消息的最后一个check通过
		{
			os_add_event(10,OP_SEND_CHECK_MSG,0,0);//增加一个返回“我们收到了”的event
			Wireless_Com::Distribute_Msg();//分析我们收的消息，并转化成event
		}
	}
}

int Wireless_Com::Send_Check_Msg(int a, int b)
{
	byte outout[4]={0xCC,0xF2,0x00,0xBE};
	SerialCom.write(outout,4);
	return 0;//发送“我们收到了”这条消息
}

int Wireless_Com::Send_Msg(byte op,byte arg){//TO REGIST IT,MUST ALWAYS HAVE 2 PARAMETERS
	out_buffer[1]=op;
	out_buffer[2]=arg;
	out_buffer[0]=COM_PACKAGE_HEADER;
	out_buffer[3]=0;
	for(int i=0;i<COM_OUT_BUFFER_SIZE-1;i++)out_buffer[3]+=out_buffer[i];
	SerialCom.write(out_buffer,COM_OUT_BUFFER_SIZE);
	return 0;//发送别的消息使用
}

bool Wireless_Com::Check_Sum(){
  byte sum = 0;
  //验证方式为前七个加起来的和mod 256的余数应当和第八个一致
  for(int i=0;i<COM_BUFFER_SIZE-1;i++)sum+=(byte)buffer[i];//checksum
  return (sum == buffer[COM_BUFFER_SIZE-1]);// return checksum result
}

int Wireless_Com::Distribute_Msg(){
	int cache1,cache2;
	part1=buffer[3]; part2=buffer[4]; Combine(); cache1=whole;
	part1=buffer[5]; part2=buffer[6]; Combine(); cache2=whole;
	//先把四个byte的参数合并成两个int
	os_add_event((byte)buffer[1],(byte)buffer[2],cache1,cache2);
	return 0;
}
int Wireless_Com::DisposeFunc1(int ERRNUM){
	//再把这张表加回去
	os_add_task_list(&task_list_com);//Adding back the same list
}