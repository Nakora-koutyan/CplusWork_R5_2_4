#pragma once
#include "DxLib.h"
#include"PlayerBar.h"

/*�}�N����`*/
#define MAX_KEY 256

//�\����
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
	MouseControll();					//�R���X�g���N�^
	static void Update();				//�X�V
	static int OnPressKey(int button);	//�L�[���͍X�V
	static bool OnClickMouse();			//�N���b�N�X�V
};

