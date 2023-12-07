#pragma once
#include"GameMain.h"
#include"AbstractScene.h"
#include"DxLib.h"

class PlayerTurn :public AbstractScene {
public:

	int Push_key;
	int a;

public:
	PlayerTurn();

	//デストラクタ
	~PlayerTurn(){};

	//描画以外の更新を実装する
	AbstractScene* Update()override;

	//描画の更新を実装する
	void Draw()const override;
};