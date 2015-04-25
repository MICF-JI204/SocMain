#ifndef __diaobi_updown_h__
#define __diaobi_updown_h__

#include "Ardos.h"


#define diaobi_pin1 40
#define diaobi_pin2 41 
#define diaobi_speed 4


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