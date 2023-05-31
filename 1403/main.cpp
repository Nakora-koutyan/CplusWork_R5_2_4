#include<stdio.h>

int main()
{
	try
	{
		throw"—áŠO”­¶!";
	}
	catch (int err)
	{
		printf("%d\n",err);
	}
	return 0;
}