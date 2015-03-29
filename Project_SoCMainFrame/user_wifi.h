#ifndef __user_com_h__
#define __user_com_h__
#include "Ardos.h"
/* The Following Rule defines a Proper Wifi Package:
    A Wifi Pakage consists of 6 fields:(UChar==Byte)
    UChar(Header) UChar(CMD) byte(Urgency) 4*data  byte(CheckSum)
    The CMD specifies the command type
    The The 4 Para fields Specify Data for CMD, 0x00 by default
    The CheckSum is used to end the command & used to check wheater the transmittion is successful
        Checksum = (Header + CMD + 2 * Para) % 0xFF
*/

#define OP_CHECK_COM 0x10 //Define Operation

#define COM_BUFFER_SIZE 8 // Size of the buffer
#define COM_OUT_BUFFER_SIZE 4// Size of Out Going Buffer
#define COM_PACKAGE_HEADER 0xCC
class Wireless_Com{
	public:
		Wireless_Com();   //Must have, In construction, regist initialization function
		static int wInit(); //Must have, This is initializa function 
		            // It can not be CAN be blocking
		            //Functions Below cannot be blocking, 
		            //i.e. shouldn't contain a total delay() longer than 5ms
		static int bInit();//Use this lib for bluetooth
		static int Get_Msg(int,int);//Try Obtaining a(multiple) Wifi Command(s)
		static int DisposeFunc1(int);//Dispose function for task list 1
		                      //The argument gives the reason for its disposal
							  //Defined in debug.h
		static int Send_Msg(byte,byte);
		static byte out_buffer[COM_OUT_BUFFER_SIZE];//buffer for sending out msgs
	private:
	    static byte buffer[COM_BUFFER_SIZE];
		//byte buffer_ptr;//buffer counter
		static bool Check_Sum();//Check the buffer whether it is valid
		static int Distribute_Msg();//Turn Msg Into Events/System Calls
};

#endif