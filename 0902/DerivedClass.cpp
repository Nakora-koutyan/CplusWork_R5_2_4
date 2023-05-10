#include<stdio.h>
#include"DerivedClass.h"

void DerivedClass::setStr(const char* s)
{
	str = s;
}

void DerivedClass::printStr()
{
	printf("%s\n", str);
};