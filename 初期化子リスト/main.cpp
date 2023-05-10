#include<stdio.h>
#include"Hoge.h"

int main()
{
	Hoge* obj = new Hoge();
	printf("%d\n", obj->getNum());
	delete obj;
	return 0;
}