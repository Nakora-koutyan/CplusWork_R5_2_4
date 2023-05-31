#include<stdio.h>
#include<math.h>

int Func()
{
	double n;
	printf("0以上の数を入力");
	scanf_s("%lf", &n);
	if (n < 0)
	{
		throw - 1;
	}
	printf("平方根は%lf\n", sqrt(n));
}

int main(void)
{
	try
	{
		Func();
	}
	catch (int& err)
	{
		printf("エラーコード%d\n", err);
	}
}