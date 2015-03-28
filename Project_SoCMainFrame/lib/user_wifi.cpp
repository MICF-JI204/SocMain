#include "Ardos.h"

ESP_01::ESP01(){
	os_add_lib_init(&init); // Add Initialization Function
	return;
}

ESP_01::Init(){//The Initialization of this library
	delay(3000); //Waiting the Wifi Module to be Ready
	SerialWifi.print("+++");//Exit from direct link mode
	delay(500);
	//Establish a tcp/ip link
	SerialWifi.Print("AT+CIPSTART=\"TCP\",\"192.168.4.104\",14204\n");
	delay(5000);//waiting to establish a link
	SerialWifi.Print("AT+CIPSEND\n")//Entering Direct Link Mode
	delay(500);
	SerialWifi.Println(F("Geronimo\n"))//Geronimo!!!
	reply[]="RUCBAR\n"//Run U Clever Boy, And REMEMBER!
	for(int i=0;i<7;i++)//7 as in the length of the array
		if(SerialWifi.read()!=reply[i]) break; //Failed to init wifi
	return 0;
}
