#include<stdio.h>
#include"DxLib.h"
#include"SceneManager.h"
#include"Result.h"
#include"EnemyTurn.h"
#include"GameMain.h"

Result::Result(int a,int b)
{
	Player_hand = a;
	Enemy_hand = b;
}

AbstractScene* Result::Update() {
	if (CheckHitKey(KEY_INPUT_G)) {
		return new GameMain();
	}
	return this;
}


void Result::Draw()const
{
	DrawFormatString(20, 110, GetColor(255, 255, 255), "���ʂ́E�E�E");
	if (Player_hand == Enemy_hand)
	{
		DrawFormatString(20, 130, GetColor(255, 255, 255), "���������ł�!!!");
	}
	else if ((Player_hand == 0 && Enemy_hand == 1) || (Player_hand == 1 && Enemy_hand == 2) || (Player_hand == 2 && Enemy_hand == 0))
	{
		DrawFormatString(20, 130, GetColor(255, 255, 255), "���Ȃ��̏����ł�!!!");
	}
	else
	{
		DrawFormatString(20, 130, GetColor(255, 255, 255), "���Ȃ��̕����ł�...");
	}

	DrawFormatString(20, 150, GetColor(255, 255, 255), "G�L�[�ŃQ�[�����C����");
	DrawFormatString(60, 200,GetColor(255, 255, 255), "Escape�L�[�ŃQ�[���I��");

}