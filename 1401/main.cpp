#include<stdio.h>
#include<math.h>

int main(void)
{
	try
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
	catch (int& err)
	{
		printf("エラーコード%d\n", err);
	}
}