#pragma once
#include<stdio.h>
#include"DxLib.h"
#include"AbstractScene.h"
#include"EnemyTurn.h"

class GameMain :public AbstractScene {
private:
	int a = -1;
	int key = 1;
	
public:

	//�f�X�g���N�^
	virtual ~GameMain() {};

	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update()override;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw()const override;
};