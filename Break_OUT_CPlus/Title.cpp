#include"DxLib.h"
#include"Title.h"
#include"GameMain.h"
#include"MouseControll.h"

TitleScene::TitleScene()
{
	g_TitleImage = LoadGraph("Images/Title.bmp");
	if (g_TitleImage == -1)
	{
		throw - 1;
	}
	g_MenuNumber = 0;
	g_MenuY = 0;
}

TitleScene::~TitleScene()
{
	
}

AbstractScene*TitleScene:: Update()
{
	//if (CheckHitKey(KEY_INPUT_A) == TRUE)
	if(MouseControll::OnPressKey(KEY_INPUT_A) != 0)
	{
		return new GameMainScene;
	}
	return this;

	//���j���[�J�[�\���ړ�����
	if (MouseControll::OnPressKey(KEY_INPUT_DOWN)) {
		if (++g_MenuNumber > 2) g_MenuNumber = 0;
	}
	if (MouseControll::OnPressKey(KEY_INPUT_UP)) {
		if (--g_MenuNumber < 0) g_MenuNumber = 2;
	}
	// �y�L�[�Ń��j���[�I��
	if (MouseControll::OnPressKey(KEY_INPUT_A)) {
		if (g_MenuNumber == 0)
		{
			return new GameMainScene;
		}
	}
	g_MenuY = g_MenuNumber * 52;
}

void TitleScene:: Draw ()const
{
	//�^�C�g���摜�\��
	DrawGraph(0, 0, g_TitleImage, FALSE);
	//���j���[�J�[�\���i�O�p�`�j�̕\��
	DrawTriangle(240, 255 + g_MenuY, 260, 270 + g_MenuY, 240, 285 + g_MenuY, GetColor(255, 0, 0), TRUE);
}