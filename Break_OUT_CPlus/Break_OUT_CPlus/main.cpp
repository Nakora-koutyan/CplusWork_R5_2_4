#include"DxLib.h"
#include "SceneManager.h"
#include"AbstractScene.h"
#include"Title.h"
#include"MouseControll.h"
#include"common.h"


int WINAPI WinMain(_In_ HINSTANCE ih, _In_opt_ HINSTANCE ioh, _In_ LPSTR il, _In_ int ii)
{
	//ウィンドウモードで起動
	ChangeWindowMode(TRUE);		//フルスクリーンモードで起動

	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);	//ウィンドウサイズを設定

	if (DxLib_Init() == -1)
	{
		return -1;				//DXライブラリの初期化処理
	}

	//裏画面に描画する
	SetDrawScreen(DX_SCREEN_BACK);

	//ゲーム開始時のマウスの位置を固定する
	SetMousePoint(300, 300);

	//マウスを表示状態にする
	SetMouseDispFlag(TRUE);

	//ゲームループ
	SceneManager SceneMng(dynamic_cast<AbstractScene*>(new TitleScene()));
	while(SceneMng.Update()!=nullptr && ProcessMessage() == 0)
	{

		ClearDrawScreen();
		MouseControll::Update();
		SceneMng.Draw();
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		//裏画面の内容を表画面に反映する
		ScreenFlip();
	}

	DxLib_End();		//Dxライブラリ使用の終了処理
	return 0;			//プログラムの終了
}