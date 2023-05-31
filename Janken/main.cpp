#include "DxLib.h"

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

	//==========================================
	// 乱数の初期化
	srand((unsigned int)time(NULL));

	int a = -1;
	int b = rand() % 3;
	int key = 1;

	while (ProcessMessage() != -1)
	{
		ClearDrawScreen();

		DrawFormatString(20, 20, GetColor(255, 255, 255), "何を出しますか？（ 0:グー / 1:チョキ / 2:パー ）:");

		if (key == 1)
		{
			if (CheckHitKey(KEY_INPUT_0))
			{
				a = 0;
				key = 0;
			}
			else if (CheckHitKey(KEY_INPUT_1))
			{
				a = 2;
				key = 0;
			}
			else if (CheckHitKey(KEY_INPUT_2))
			{
				a = 2;
				key = 0;
			}
		}
		else
		{
			switch (a)
			{
			case 0:
				DrawFormatString(20, 50, GetColor(255, 255, 255), "あなたが出した手はグー");
				break;

			case 1:
				DrawFormatString(20, 50, GetColor(255, 255, 255), "あなたが出した手はチョキ");
				break;

			case 2:
				DrawFormatString(20, 50, GetColor(255, 255, 255), "あなたが出した手はパー");
				break;
			}

			switch (b)
			{
			case 0:
				DrawFormatString(20, 80, GetColor(255, 255, 255), "相手が出した手はグー");
				break;

			case 1:
				DrawFormatString(20, 80, GetColor(255, 255, 255), "相手が出した手はチョキ");
				break;

			case 2:
				DrawFormatString(20, 80, GetColor(255, 255, 255), "相手が出した手はパー");
				break;
			}
		}

		ScreenFlip();
	}
	//==========================================

	// DXライブラリの終了処理
	DxLib_End();

	return 0;
}