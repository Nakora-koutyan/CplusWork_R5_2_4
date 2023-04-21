#include<stdio.h>
#include"CIntArray.h"


CIntArray a(10);

void Viss(const int num);

int main(void)
{
	CIntArray b(20);
	Viss(1);

	CIntArray c(30);
	Viss(2);

	{
		CIntArray d(40);
		Viss(3);
	}

	Viss(4);

	return 0;
}

void Viss(const int num)
{
	printf("Viss:No%d\n", num);
}