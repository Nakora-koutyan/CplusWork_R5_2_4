#include<stdio.h>
#include"POS.h"


POS::POS()
{
	x = 0;
	y = 0;
}

POS::POS(int tmpx, int tmpy)
{
	x = tmpx;
	y = tmpy;

}

void POS::print()
{
	printf("x:%d,y:%d\n", x, y);
}

