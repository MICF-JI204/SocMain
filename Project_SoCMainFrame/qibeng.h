#ifndef __qibeng_h__
#define __qibeng_h__


#include "Ardos.h"

#define OP_qibeng_ON 0xE8
#define OP_qibeng_OFF 0xE9
#define qibeng_IO 11


 class qibeng_control
 {
 	public:
 		qibeng_control();
 		static int qibeng_init();
 		static int qibeng_on(int a, int b);
 		static int qibeng_off(int a, int b);
 	private:
};

#endif
