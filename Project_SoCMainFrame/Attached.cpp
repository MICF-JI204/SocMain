#include "Ardos.h"
//将一个int拆分成两个byte
int Devide()
{
	part1=(byte)(whole>>8);
	part2=(byte)(whole&0x000000ff);
	return 0;
}
//将两个byte合成成一个int。在输入的时候参数是作四个byte的，然后在这里处理成了两个int
int Combine()
{
	whole=(((int)part1)<<8)+(int)part2;
	return 0;
}