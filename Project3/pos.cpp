#include <stdio.h>
#include"POS.h"

int POS::setPos(int tmpx, int tmpy)
{
	x = tmpx;
	y = tmpy;

	return 0;
}

void POS::print()
{
	printf("x:%d,y:%d\n", x, y);
}

