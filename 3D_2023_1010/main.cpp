#include<stdio.h>
#include"LibProject/StaticLibTest.h"

int main(void)
{
	Calculation calc;
	//����X
	int first_num;
	//����Y
	int second_num;

	//����X�̓���
	printf("����X����͂��Ă��������B\n");
	scanf_s("%d", &first_num);
	printf("����X�F%d\n", first_num);

	//����Y�̓���
	printf("����Y����͂��Ă��������B\n");
	scanf_s("%d", &second_num);
	printf("����Y�F%d\n", second_num);

	printf("\n���Z���@%d\n",calc.Add(first_num, second_num));
	printf("���Z���@%d\n",calc.Sub(first_num, second_num));
	printf("��Z���@%d\n",calc.Multi(first_num, second_num));
	printf("���Z���@%d\n",calc.Div(first_num, second_num));

	return 0;
}