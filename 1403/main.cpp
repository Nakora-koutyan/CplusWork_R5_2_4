#include<stdio.h>

int main()
{
	try
	{
		throw"��O����!";
	}
	catch (int err)
	{
		printf("%d\n",err);
	}
	return 0;
}