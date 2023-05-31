#include<stdio.h>
#include"CTest.h"

int main(void)
{
	CTest test1, test2;

	printf("test1:%p\n", &test1);
	printf("test2:%p\n", &test2);
	printf("test1:%p\n", test1.RetThis());
	printf("test2:%p\n", test2.RetThis());

	return 0;
}