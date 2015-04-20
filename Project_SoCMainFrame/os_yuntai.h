#ifndef __os_yuntai_h__
#define __os_yuntai_h__

#include "Ardos.h"


#define yuntai_IO 9

class Service_Yuntai
{
public:
	Service_Yuntai();
	static int yuntai_init_left();
	static int yuntai_right(int a);
	static int yuntai_right_slowly(int a);
	static int yuntai_left_slowly(int a);
	static int yuntai_left(int a);
	static int yuntai_stop(int a);

private:
};

#endif