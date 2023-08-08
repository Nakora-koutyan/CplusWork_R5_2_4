#pragma once
#include"AbstractScene.h"

class TitleScene :public AbstractScene
{
private:
	int g_TitleImage;
	int g_MenuY;
	int g_MenuNumber;

public:
	//コンストラクタ
	TitleScene();

	//デストラクタ
	virtual ~TitleScene();

	//描画以外の更新を実装する
	virtual AbstractScene* Update() override;

	//描画に関することを実装する
	virtual void Draw() const override;

	//メニュー選択
	void SelectMenu();

};