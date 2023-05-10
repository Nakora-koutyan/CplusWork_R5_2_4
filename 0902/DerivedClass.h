#pragma once
#include"BaseClass.h"

class DerivedClass :protected BaseClass
{
public:
	void setStr(const char* s);
	void printStr();
};
