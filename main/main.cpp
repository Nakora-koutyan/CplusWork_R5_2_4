#include<stdio.h>
#include"POS.h"		//クラスPOS.hの型定義を読み取る

int main(void)
{
	//クラスPOSのオブジェクトを作成(変数pos)
	POS pos;
	//クラスPOSのオブジェクトを作成(変数pos2)
	POS pos2;

	//posのメンバ変数に値を代入
	pos.x = 100.0;
	pos.y = 200.0;

	pos.print();	//値を画面に表示

	pos2.x = 300.0;
	pos2.y = 256.0;

	pos2.print();	//値を画面に表示

	return 0;
}