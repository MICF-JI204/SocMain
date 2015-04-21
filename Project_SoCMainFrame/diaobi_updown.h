#ifndef __diaobi_updown_h__
#define __diaobi_updown_h__

#include "Ardos.h"


#define diaobi_pin1 7
#define diaobi_pin2 8
#define diaobi_speed 11


class Service_diaobi
{
public:
	Service_diaobi();
	static int diaobi_init();

	static int diaobi_slow(int a,int b);
	static int diaobi_stop(int a,int b);

private:
};

#endif