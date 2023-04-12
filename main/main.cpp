#include<stdio.h>
#include"POS.h"		//クラスPOS.hの型定義を読み取る

int main(void)
{
	//クラスPOSのオブジェクトを作成(変数pos)
	POS pos;

	//posのメンバ変数に値を代入
	pos.x = 100.0;
	pos.y = 200.0;

	//posの値を画面に表示して確認
	printf("x:%lf y:%lf\n", pos.x, pos.y);

	return 0;
}