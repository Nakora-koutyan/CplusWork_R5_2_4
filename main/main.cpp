#include<stdio.h>
#include"POS.h"		//クラスPOS.hの型定義を読み取る

int main(void)
{
	//クラスPOSのオブジェクトを作成(変数pos)
	POS pos;
	//クラスPOSのオブジェクト
	//複数オブジェクトを作っても作られるメモリが違うため、別のデータを持てる
	POS pos2;

	//posのメンバ変数に値を代入
	pos.x = 100.0;
	pos.y = 200.0;

	pos.print();	//posのメンバ関数を呼び出す

	pos2.x = 300.0;
	pos2.y = 256.0;

	pos2.print();	//pos2のメンバ関数を呼び出す

	return 0;
}