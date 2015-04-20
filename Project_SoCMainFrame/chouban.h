#ifndef __chouban_h__
#define __chouban_h__


#include "Ardos.h"

#define OP_chouban_ON 0xB0
#define OP_chouban_OFF 0xB1
#define chouban_IO 10


 class chouban_control
 {
 	public:
 		chouban_control();
 		static int chouban_init();
 		static int chouban_on(int a, int b);
 		static int chouban_off(int a, int b);
 	private:
};

#endif
