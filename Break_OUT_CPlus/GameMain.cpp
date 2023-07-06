#include "DxLIb.h"
#include "GameMain.h"
#include "MouseControll.h"

GameMainScene::GameMainScene()	//コンストラクタ
{
	//ゲーム開始時のマウスの位置を固定する
	SetMousePoint(300, 300);

	//白色の値を取得
	Cr = GetColor(255, 255, 255);
}
GameMainScene::~GameMainScene()
{

}
AbstractScene*GameMainScene :: Update()
{
	MouseControll::Update();
	player_bar.Update();
	ball.Update();

	if (CheckHitKey(KEY_INPUT_ESCAPE))
	{
		return nullptr;
	}

	return this;
}
void GameMainScene::Draw () const
{
	DrawString(150, 250, "ここはゲームメインシーンです。",Cr);
	DrawFormatString(250, 400, Cr,"%d", MouseControll::Mouse.x);
	DrawFormatString(350, 400, Cr, "%d", MouseControll::OnPressKey(KEY_INPUT_Z));
	DrawFormatString(380, 400, Cr, "%d", MouseControll::Old_Key[6]);
	player_bar.Draw();
	ball.Draw();
}