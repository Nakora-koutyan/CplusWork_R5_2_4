#include<stdio.h>
#include<math.h>

int main(void)
{
	try
	{
		double n;
		printf("0�ȏ�̐������");
		scanf_s("%lf", &n);
		if (n < 0)
		{
			throw - 1;
		}
		printf("��������%lf\n", sqrt(n));
	}
	catch (int& err)
	{
		printf("�G���[�R�[�h%d\n", err);
	}
}