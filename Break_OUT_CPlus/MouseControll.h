#pragma once
#include "DxLib.h"
#include"PlayerBar.h"

/*マクロ定義*/
#define MAX_KEY 256

//構造体
struct InputMouse
{
	int button;
	int x;
	int y;
	int now_click;
	int old_click;
};
class MouseControll
{
public:
	static InputMouse Mouse;
	static char Now_Key[256];
	static char Old_Key[256];

public:
	MouseControll();					//コンストラクタ
	static void Update();				//更新
	static int OnPressKey(int button);	//キー入力更新
	static bool OnClickMouse();			//クリック更新
};

