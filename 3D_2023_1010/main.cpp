#include<stdio.h>
#include"LibProject/StaticLibTest.h"

int main(void)
{
	Calculation calc;
	//数字X
	int first_num;
	//数字Y
	int second_num;

	//数字Xの入力
	printf("数字Xを入力してください。\n");
	scanf_s("%d", &first_num);
	printf("数字X：%d\n", first_num);

	//数字Yの入力
	printf("数字Yを入力してください。\n");
	scanf_s("%d", &second_num);
	printf("数字Y：%d\n", second_num);

	printf("\n加算式　%d\n",calc.Add(first_num, second_num));
	printf("減算式　%d\n",calc.Sub(first_num, second_num));
	printf("乗算式　%d\n",calc.Multi(first_num, second_num));
	printf("除算式　%d\n",calc.Div(first_num, second_num));

	return 0;
}