#ifndef __xipan_h__
#define __xipan_h__

#include "Ardos.h"


#define xipan_pin1 3
#define xipan_pin2 4
#define xipan_speed 11//请链接PWM 接口


class Service_xipan
{
public:
	Service_xipan();
	static int xipan_init();

	static int xipan_move(int a,int b);
	static int xipan_stop(int a,int b);

private:
};

#endif