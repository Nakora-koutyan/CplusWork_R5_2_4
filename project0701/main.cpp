#include<stdio.h>
#include"POS.h"


int main(void)
{
	POS pos;

	printf("x:%d y:%d\n", pos.getX(), pos.getY());

	pos.setX(100);
	pos.setY(200);

	printf("x:%d y:%d\n", pos.getX(), pos.getY());

	return 0;
}