#include "POS.h"

int main(void)
{
	POS pos1;	//コンストラクタの呼び出し
	POS pos2(100, 200);	//引数無しのコンストラクタ

	//引数ありコンストラクタ
	pos1.print();
	pos2.print();

	return 0;
}