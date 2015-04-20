#ifndef __os_yuntai_h__
#define __os_yuntai_h__

#include "Ardos.h"


#define yuntai_IO 9

class Service_Yuntai
{
public:
	Service_Yuntai();
	static int yuntai_init();
	static int yuntai_quick(int a,int b);
	static int yuntai_slow(int a,int b);
	static int yuntai_stop(int a,int b);

private:
};

#endif