#pragma once
#include"AbstractScene.h"
#include"EnemyTurn.h"

class Result :public AbstractScene {
private:
	int Player_hand;
	int Enemy_hand;

public:
	Result(int a,int b);

	//デストラクタ
	virtual ~Result() {};

	//描画以外の更新を実装する
	virtual AbstractScene* Update()override;

	//描画に関することを実装する
	virtual void Draw()const override;
};