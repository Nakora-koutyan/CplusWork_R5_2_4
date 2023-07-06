#pragma once
#include"DxLib.h"
#include"AbstractScene.h"
#include"Result.h"
#include<time.h>
#include"GameMain.h"

class EnemyTurn :public AbstractScene {
private:
	int Player_hand;
	int b;

public:
	 int Enemy_Rand();

	EnemyTurn(int a);

	//デストラクタ
	~EnemyTurn() {};

	//描画以外の更新を実装する
	AbstractScene* Update()override;

	//描画に関することを実装する
	void Draw()const override;
};
