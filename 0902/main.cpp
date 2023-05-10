#include"DerivedClass.h"

int main()
{
	DerivedClass dc{};

	dc.setStr("Hello");

	dc.printStr();

	return 0;
}