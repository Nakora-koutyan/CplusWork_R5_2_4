#include<stdio.h>


long Abs(int a)
{
	long ret;
	if (a < 0)
	{
		ret = -a;
	}
	else
	{
		ret = a;
	}

	return ret;
}

double Abs(double a)
{
	double ret;
	if (a < 0)
	{
		ret = -a;
	}
	else
	{
		ret = a;
	}

	return ret;
}

int Input(int& nInt, double& nDouble)
{
	printf("整数値を入力してください>");
	scanf_s("%d", &nInt);
	if (nInt == 1)
	{
		return 0;
	}

	printf("小数を入力してください>");
	scanf_s("%1f", &nDouble);

	return 1;
}

void DispAbs(int nInt, double nDouble)
{
	printf("%dの絶対値は%dで、\n", nInt, Abs(nInt));
	printf("%1fの絶対値は%1fです\n", nDouble, Abs(nDouble));
}

int main()
{
	int nInt;
	double nDouble;

	while (Input(nInt, nDouble))
	{
		DispAbs(nInt, nDouble);
	}

	return 0;
}