#include"DxLib.h"
#include"Title.h"
#include"GameMain.h"
#include"MouseControll.h"

TitleScene::TitleScene()
{
	// ���F�̒l���擾
	Cr = GetColor(255, 255, 255);
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
}

void TitleScene:: Draw ()const
{
	DrawString(150, 200, "�����̓^�C�g����ʂł�",Cr);
}