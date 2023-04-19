#include <stdio.h>
#include"POS.h"

int POS::setPos(int tmpx, int tmpy)
{
	//メンバ変数の値を更新
	x = tmpx;
	y = tmpy;

	return 0;
}

void POS::print()
{
	//メンバ変数の値を画面に出力
	printf("x:%d,y:%d\n", x, y);
}

