#include<stdio.h>
#include"EnemyTurn.h"

EnemyTurn::EnemyTurn(int a)
{
	Player_hand = a;
	b = Enemy_Rand();
}

AbstractScene* EnemyTurn::Update() {
	//�����̏�����
	srand((unsigned int)time(NULL));

	if (CheckHitKey(KEY_INPUT_R)) {
		return new Result(Player_hand,b);
	}
	return this;
}

void EnemyTurn::Draw()const {

	DrawFormatString(20, 20, GetColor(255, 255, 255),"�ΐ푊���.....");

	switch (b)
	{
	case 0:
		DrawFormatString(20, 80, GetColor(255, 255, 255), "���肪�o������̓O�[");
		break;

	case 1:
		DrawFormatString(20, 80, GetColor(255, 255, 255), "���肪�o������̓`���L");
		break;

	case 2:
		DrawFormatString(20, 80, GetColor(255, 255, 255), "���肪�o������̓p�[");
		break;
	}

	DrawFormatString(20, 100, GetColor(255, 255, 255), "R�L�[�ŃG���h�t�F�C�Y��");

}

int EnemyTurn::Enemy_Rand()
{
	int b = rand() % 3;

	return b;
}