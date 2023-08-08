#include "GameClear.h"
#include "common.h"

GameClear::GameClear()
{
	g_wait_time = 0;
	g_key_flg = 0;
}
GameClear::~GameClear()
{
}
AbstractScene* GameClear::Update()
{
	//�X�y�[�X�L�[��NEXT�X�e�[�W��
	if (MouseControll::OnPressKey(KEY_INPUT_SPACE)&& StageBlock::StageUpdate < 4)
	{
		StageBlock::StageUpdate;
		return new GameMainScene;
	}
	else if (MouseControll::OnPressKey(KEY_INPUT_C) || StageBlock::StageUpdate < 4)
	{
		StageBlock::StageUpdate = 0;
		return new TitleScene;
	}
	return this;
}

void GameClear::ClearGame()
{
	SetFontSize(48);
	DrawString(120, 200, "Congratulations", 0xFF0000);

	//�����̕\��(�_��)
	if (++g_wait_time < 30) {
		SetFontSize(24);
		DrawString(150, 450, "-- Press[SPACE]Key --", 0xFF0000);
	}
	else if (g_wait_time > 60) {
		g_wait_time = 0;
	}
}
