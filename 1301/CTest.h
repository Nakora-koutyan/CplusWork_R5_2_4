#pragma once

class CTest
{
private:
	int a[100];
public:
	CTest* RetThis()
	{
		return this;
	}
};
