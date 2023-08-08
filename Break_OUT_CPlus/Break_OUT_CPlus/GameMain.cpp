#include "DxLIb.h"
#include "GameMain.h"
#include "MouseControll.h"

GameMainScene::GameMainScene()	//�R���X�g���N�^
{
	//�Q�[���J�n���̃}�E�X�̈ʒu���Œ肷��
	SetMousePoint(300, 300);

	//���F�̒l���擾
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
	DrawString(150, 250, "�����̓Q�[�����C���V�[���ł��B",Cr);
	DrawFormatString(250, 400, Cr,"%d", MouseControll::Mouse.x);
	DrawFormatString(350, 400, Cr, "%d", MouseControll::OnPressKey(KEY_INPUT_Z));
	DrawFormatString(380, 400, Cr, "%d", MouseControll::Old_Key[6]);
	player_bar.Draw();
	ball.Draw();
}