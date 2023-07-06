#include"DxLib.h"
#include"PlayerTurn.h"

PlayerTurn::PlayerTurn()
{
	Push_key = 1;
	a = -1;
}

AbstractScene* PlayerTurn::Update() {
	if (Push_key == 1)
	{
		if (CheckHitKey(KEY_INPUT_0))
		{
			a = 0;
			Push_key = 0;
		}
		else if (CheckHitKey(KEY_INPUT_1))
		{
			a = 1;
			Push_key = 0;
		}
		else if (CheckHitKey(KEY_INPUT_2))
		{
			a = 2;
			Push_key = 0;
		}
	}
	else
	{
	}

	if (CheckHitKey(KEY_INPUT_E)) {
		return new EnemyTurn(a);
	}
	return this;
}

void PlayerTurn::Draw()const 
{
	DrawFormatString(20, 20, GetColor(255, 255, 255), "�����o���܂����H�i 0:�O�[ / 1:�`���L / 2:�p�[ �j:");

	switch (a)
	{
	case 0:
		DrawFormatString(20, 50, GetColor(255, 255, 255), "���Ȃ����o������̓O�[");
		break;

	case 1:
		DrawFormatString(20, 50, GetColor(255, 255, 255), "���Ȃ����o������̓`���L");
		break;

	case 2:
		DrawFormatString(20, 50, GetColor(255, 255, 255), "���Ȃ����o������̓p�[");
		break;
	}

	DrawFormatString(20,80 ,GetColor(255, 255, 255), "E�L�[��Enemy�^�[����");
}