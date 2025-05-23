#include "DxLib.h"
#include"GameMain.h"
#include"AbstractScene.h"
#include"Result.h"
#include"SceneManager.h"
#include <time.h> // time

#define _SCREEN_HEIGHT_ 720
#define _SCREEN_WIDHT_	1280
#define _SCREEN_COLOR_BIT_16_ 16
#define _SCREEN_COLOR_BIT_32_ 32

int WINAPI WinMain(_In_ HINSTANCE ih, _In_opt_ HINSTANCE ioh, _In_ LPSTR il, _In_ int ii)
{
	// ウィンドウモードで起動
	if (ChangeWindowMode(TRUE) != DX_CHANGESCREEN_OK)
	{
		return -1;
	}

	// 画面サイズを変更
	if (SetGraphMode(_SCREEN_WIDHT_, _SCREEN_HEIGHT_, _SCREEN_COLOR_BIT_32_) != DX_CHANGESCREEN_OK)
	{
		return -1;
	}

	// DXライブラリの初期化
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	SceneManager SceneMng(dynamic_cast<AbstractScene*>(new GameMain()));
	while (SceneMng.Update() != nullptr)
	{
		ClearDrawScreen();
		SceneMng.Draw();
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}
	}
	//==========================================
	// DXライブラリの終了処理
	DxLib_End();

	return 0;
}