#include<stdio.h>
#include"Person.h"

int main(void)
{
	Person a1((char*)"taro"), a2((char*)"jiro"), a3((char*)"saburo");

	a1 = a2 = a3;

	printf("\n");

	return 0;
}