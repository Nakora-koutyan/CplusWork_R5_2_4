#include<stdio.h>
#include"POS.h"


int main(void)
{
	POS pos;	//クラスPOSのオブジェクトを作成

	//メンバ変数がprivateになっているため
	//メンバ関数SetPos(x,y)でメンバ変数の値を変更する
	pos.setPos(100, 200);

	//メンバ変数がprivateになっているため
	//メンバ関数print()でメンバ変数の値を出力する
	pos.print();

	return 0;
}