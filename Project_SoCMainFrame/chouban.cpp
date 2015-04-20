#include "Ardos.h"


chouban_control chouban_test;




 chouban_control::chouban_control()
{
	os_add_lib_init(&chouban_control::chouban_init);

	return;
 }


 int chouban_control::chouban_init()
{
 	os_regist_event(OP_chouban_ON,chouban_control::chouban_on);
	os_regist_event(OP_chouban_OFF,chouban_control::chouban_off);
    //pinMode(chouban_IO,OUTPUT);
    //digitalWrite(chouban_IO,LOW);
	pinMode(chouban_IO,OUTPUT);
	digitalWrite(chouban_IO,LOW);

 	return 0;
}


int chouban_control::chouban_on(int a, int b)
 {
    digitalWrite(chouban_IO,HIGH);
 	return 0;
 }


int chouban_control::chouban_off(int a, int b)
{
	digitalWrite(chouban_IO,LOW);
 	return 0;
 }



