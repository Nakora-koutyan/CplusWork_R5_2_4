#include "newtest.h"
#include<stdio.h>

new_test::new_test()
{
	p = new int[5];

	p[4] = 5;
}

new_test::~new_test()
{
	delete p;
}

void new_test::Draw()
{
	printf("%d", p[4]);
}
