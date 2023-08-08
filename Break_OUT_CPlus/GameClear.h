#pragma once
#include "AbstractScene.h"
#include "MouseControll.h"
#include "StageBlock.h"
#include "GameMain.h"
#include "Title.h"

class GameClear :public AbstractScene
{
private:
	int g_wait_time;
	int g_key_flg;

public:

	//コンストラクタ
	GameClear();
	//デストラクタ
	~GameClear();

	void ClearGame();

	//描画以外の更新を実装する
	virtual AbstractScene* Update()override;
};

