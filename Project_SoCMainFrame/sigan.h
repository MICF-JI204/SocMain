
#ifndef __sigan_h__
#define __sigan_h__


#include "Ardos.h"

#define OP_sigan_ON 0xB1
#define OP_sigan_OFF 0xB3
#define OP_sigan_RON 0xB2
#define sigan_IO 48
#define sigan_IOe 49


 class sigan_control
 {
 	public:
 		sigan_control();
 		static int sigan_init();
 		static int sigan_on(int a, int b);
 		static int sigan_off(int a, int b);
		static int sigan_ron(int a, int b);

 	private:
};

#endif

