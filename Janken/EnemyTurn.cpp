#include<stdio.h>
#include"EnemyTurn.h"

EnemyTurn::EnemyTurn(int a)
{
	Player_hand = a;
	b = Enemy_Rand();
}

AbstractScene* EnemyTurn::Update() {
	//乱数の初期化
	srand((unsigned int)time(NULL));

	if (CheckHitKey(KEY_INPUT_R)) {
		return new Result(Player_hand,b);
	}
	return this;
}

void EnemyTurn::Draw()const {

	DrawFormatString(20, 20, GetColor(255, 255, 255),"対戦相手は.....");

	switch (b)
	{
	case 0:
		DrawFormatString(20, 80, GetColor(255, 255, 255), "相手が出した手はグー");
		break;

	case 1:
		DrawFormatString(20, 80, GetColor(255, 255, 255), "相手が出した手はチョキ");
		break;

	case 2:
		DrawFormatString(20, 80, GetColor(255, 255, 255), "相手が出した手はパー");
		break;
	}

	DrawFormatString(20, 100, GetColor(255, 255, 255), "Rキーでエンドフェイズへ");

}

int EnemyTurn::Enemy_Rand()
{
	int b = rand() % 3;

	return b;
}