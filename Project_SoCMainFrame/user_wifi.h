#ifndef __user_wifi_h__
#define __user_wifi_h__
#include "Ardos.h"
/* The Following Rule defines a Proper Wifi Package:
    A Wifi Pakage consists of 6 fields:(UChar==Byte)
    UChar(Header) UChar(CMD) byte(Urgency) int(Parameter0)   int(Para1)  byte(CheckSum)
    The CMD specifies the command type
    The The 4 Para fields Specify Data for CMD, 0x00 by default
    The CheckSum is used to end the command & used to check wheater the transmittion is successful
        Checksum = (Header + CMD + 2 * Para) % 0xFF
*/

#define OP_CHECK_WIFI 0x10 //Define Operation

#define WIFI_BUFFER_SIZE 6 // Size of the buffer

#define WIFI_PACKAGE_HEADER 0x11
class ESP_01{
	public:
		ESP_01();   //Must have, In construction, regist initialization function
		static int Init(); //Must have, This is initializa function 
		            // It can not be CAN be blocking
		            //Functions Below cannot be blocking, 
		            //i.e. shouldn't contain a total delay() longer than 5ms
		static int Get_Msg(int,int);//Try Obtaining a(multiple) Wifi Command(s)
		static int DisposeFunc1(int);//Dispose function for task list 1
		                      //The argument gives the reason for its disposal
							  //Defined in debug.h
	private:
	    static int buffer[WIFI_BUFFER_SIZE];
		//byte buffer_ptr;//buffer counter
		bool Check_Sum();//Check the buffer whether it is valid
		int Distribute_Msg();//Turn Msg Into Events/System Calls
};

#endif