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
	DrawFormatString(20, 110, GetColor(255, 255, 255), "結果は・・・");
	if (Player_hand == Enemy_hand)
	{
		DrawFormatString(20, 130, GetColor(255, 255, 255), "引き分けです!!!");
	}
	else if ((Player_hand == 0 && Enemy_hand == 1) || (Player_hand == 1 && Enemy_hand == 2) || (Player_hand == 2 && Enemy_hand == 0))
	{
		DrawFormatString(20, 130, GetColor(255, 255, 255), "あなたの勝ちです!!!");
	}
	else
	{
		DrawFormatString(20, 130, GetColor(255, 255, 255), "あなたの負けです...");
	}

	DrawFormatString(20, 150, GetColor(255, 255, 255), "Gキーでゲームメインへ");
	DrawFormatString(60, 200,GetColor(255, 255, 255), "Escapeキーでゲーム終了");

}