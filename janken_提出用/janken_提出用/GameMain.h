#pragma once
#include<stdio.h>
#include"DxLib.h"
#include"AbstractScene.h"
#include"EnemyTurn.h"

class GameMain :public AbstractScene {
private:
	int a = -1;
	int key = 1;
	
public:

	//デストラクタ
	virtual ~GameMain() {};

	//描画以外の更新を実装する
	virtual AbstractScene* Update()override;

	//描画に関することを実装する
	virtual void Draw()const override;
};