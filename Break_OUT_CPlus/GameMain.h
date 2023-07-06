#pragma once
#include "AbstractScene.h"
#include "PlayerBar.h"
#include "Ball.h"

class GameMainScene :public AbstractScene
{
private:
	unsigned int Cr;		//メンバ変数
	PlayerBar player_bar;	//クラスのオブジェクト化
	Ball ball;				//クラスのオブジェクト化

public:
	//コンストラクタ
	GameMainScene();

	//デストラクタ
	virtual ~GameMainScene();

	//描画以外に関することを実行する
	virtual AbstractScene* Update() override;

	//描画に関することを実装する
	virtual void Draw() const override;
};