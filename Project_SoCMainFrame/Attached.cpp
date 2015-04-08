#include "Ardos.h"

int Devide()
{
	part1=(byte)(whole>>8);
	part2=(byte)(whole&0x000000ff);
	return 0;
}

int Combine()
{
	whole=(((int)part1)<<8)+(int)part2;
	return 0;
}