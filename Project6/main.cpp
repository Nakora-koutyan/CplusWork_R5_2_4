#include<stdio.h>

int main(void)
{
	int* pNum1 = new int;			//初期化なし
	short* pNum2 = new short(50);	//初期化あり

	*pNum1 = 100;

	printf("Num1:%d\n", *pNum1);
	printf("Num2:%d\n", *pNum2);

	delete pNum1;
	delete pNum2;

	return 0;
}