#ifndef __user_wifi_h__
#define __user_wifi_h__
#include "Ardos.h"

class ESP_01{
	ESP_01();
	int Init(); //This function CAN be blocking
	//Functions Below cannot be blocking, 
	//i.e. shouldn't contain a total delay() longer than 5ms
	
};

#endif