#ifndef __os_yuntai_h__
#define __os_yuntai_h__

#include "Ardos.h"


#define yuntai_IO 9

class Service_Yuntai
{
public:
	Service_Yuntai();
	static long long int yuntai_init();
	static long long int yuntai_quick(long long int a,long long int b);
	static long long int yuntai_slow(long long int a,long long int b);
	static long long int yuntai_stop(long long int a,long long int b);

private:
};

#endif