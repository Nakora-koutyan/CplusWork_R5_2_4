#include<stdio.h>
#include"newtest.h"
int main(void)
{
	new_test* pos;

	pos = new new_test();
	
	pos->Draw();

	delete pos;

	return 0;
}