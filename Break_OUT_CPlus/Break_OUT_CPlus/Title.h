#pragma once
#include"AbstractScene.h"

class TitleScene :public AbstractScene
{
private:
	unsigned int Cr;

public:
	//コンストラクタ
	TitleScene();

	//デストラクタ
	virtual ~TitleScene();

	//描画以外の更新を実装する
	virtual AbstractScene* Update() override;

	//描画に関することを実装する
	virtual void Draw() const override;
};