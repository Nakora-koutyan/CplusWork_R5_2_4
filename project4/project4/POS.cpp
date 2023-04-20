#include<stdio.h>
#include"POS.h"


POS::POS()
{
	x = 0;
	y = 0;
}

void POS::print()
{
	printf("x:%d,y:%d\n", x, y);
}