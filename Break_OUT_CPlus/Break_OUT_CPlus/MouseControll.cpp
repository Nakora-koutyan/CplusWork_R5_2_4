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
	GetMousePoint(&Mouse.x, &Mouse.y);	//�}�E�X�̍��W�擾

	for (int i = 0; i < 256; i++)					//�L�[�{�[�h�̑S�L�[�̓��͏��擾
	{
		Old_Key[i] = Now_Key[i];
	}
	GetHitKeyStateAll(Now_Key);

	Mouse.old_click = Mouse.now_click;				//�O��̓��̓L�[�̍X�V
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)	//���݂̓��̓L�[�̍X�V
	{
		Mouse.now_click = 1;
	}
	else
	{
		Mouse.now_click = 0;
	}
}

int MouseControll::OnPressKey(int button)			//�����ꂽ�u�Ԃɐ^��Ԃ�(�L�[)
{
	if (Now_Key[button] == 1 && Old_Key[button] == 0)
	{
		return 1;
	}
	return 0;
}

bool MouseControll::OnClickMouse()					//�����ꂽ�u�Ԃɐ^��Ԃ�(�}�E�X���N���b�N)
{
	if (Mouse.now_click == 1 && Mouse.old_click == 0)
	{
		return true;
	}
	return false;
}

