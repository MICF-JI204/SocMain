#ifndef __user_wifi_h__
#define __user_wifi_h__
#include "Ardos.h"

/* The Following Rule defines a Proper Wifi Package:
    A Wifi Pakage consists of 5 fields:(UChar==Byte)
    UChar(Header) UChar(CMD) int(Parameter0)   int(Para1)    int(Para2)      UChar(CheckSum)
e.g. 0x18           0x01           0x00           0x00         0x00                 0x19      
    The Header Must be 0x18(204D), indicating the start of CMD
    The CMD specifies the command type
    The The 4 Para fields Specify Data for CMD, 0x00 by default
    The CheckSum is used to end the command & used to check wheater the transmittion is successful
        Checksum = (Header + CMD + 2 * Para) % 0xFF
*/

class ESP_01{
	public:
		ESP_01();
		int Init(); //This function CAN be blocking
		//Functions Below cannot be blocking, 
		//i.e. shouldn't contain a total delay() longer than 5ms
		bool CMD_Available();// Check Whether there is an available 
	private:
	    int buffer[5]={0x00};
		
};

#endif