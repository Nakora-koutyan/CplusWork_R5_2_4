#include "MouseControll.h"
#include"PlayerBar.h"

InputMouse MouseControll::Mouse;
char MouseControll::Now_Key[];
char MouseControll::Old_Key[];

MouseControll::MouseControll()
{
}
void MouseControll::Update()
{
	GetMousePoint(&Mouse.x, &Mouse.y);	//マウスの座標取得

	for (int i = 0; i < 256; i++)					//キーボードの全キーの入力情報取得
	{
		Old_Key[i] = Now_Key[i];
	}
	GetHitKeyStateAll(Now_Key);

	Mouse.old_click = Mouse.now_click;				//前回の入力キーの更新
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)	//現在の入力キーの更新
	{
		Mouse.now_click = 1;
	}
	else
	{
		Mouse.now_click = 0;
	}
}

int MouseControll::OnPressKey(int button)			//押された瞬間に真を返す(キー)
{
	if (Now_Key[button] == 1 && Old_Key[button] == 0)
	{
		return 1;
	}
	return 0;
}

bool MouseControll::OnClickMouse()					//押された瞬間に真を返す(マウス左クリック)
{
	if (Mouse.now_click == 1 && Mouse.old_click == 0)
	{
		return true;
	}
	return false;
}

