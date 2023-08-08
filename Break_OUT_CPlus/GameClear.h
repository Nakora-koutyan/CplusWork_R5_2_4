#pragma once
#include "AbstractScene.h"
#include "MouseControll.h"
#include "StageBlock.h"
#include "GameMain.h"
#include "Title.h"

class GameClear :public AbstractScene
{
private:
	int g_wait_time;
	int g_key_flg;

public:

	//�R���X�g���N�^
	GameClear();
	//�f�X�g���N�^
	~GameClear();

	void ClearGame();

	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update()override;
};

