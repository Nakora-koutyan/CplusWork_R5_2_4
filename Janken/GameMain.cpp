#include<stdio.h>
#include"GameMain.h"
#include"DxLib.h"
#include"PlayerTurn.h"

AbstractScene* GameMain::Update() {
	
	if (CheckHitKey(KEY_INPUT_P)) {
		return new PlayerTurn;
	}
	else if (CheckHitKey(KEY_INPUT_B)) {
		return nullptr;
	}
	return this;
}

void GameMain::Draw()const {
	DrawFormatString(20, 80, GetColor(255, 255, 255), "Pキーでプレイヤー画面へ");
}