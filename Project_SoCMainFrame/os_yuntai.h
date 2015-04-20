#ifndef __os_yuntai_h__
#define __os_yuntai_h__

#include "Ardos.h"

#define yuntai_left 1
#define yuntai_right 2
#define yuntai_stop 3
#define yuntai_IO 9

class Service_Yuntai
{
public:
	Service_Yuntai();
	static int yuantai_init;
	static int yuantai_right(int a);
	static int yuantai_right_slowly(int a);
	static int yuantai_left_slowly(int a);
	static int yuntai_left(int a);
	static int yuntai_stop(int a);

private:
};

#endif