#pragma once
#include"DxLib.h"
#include"AbstractScene.h"
#include"Result.h"
#include<time.h>
#include"GameMain.h"

class EnemyTurn :public AbstractScene {
private:
	int Player_hand;
	int b;

public:
	 int Enemy_Rand();

	EnemyTurn(int a);

	//�f�X�g���N�^
	~EnemyTurn() {};

	//�`��ȊO�̍X�V����������
	AbstractScene* Update()override;

	//�`��Ɋւ��邱�Ƃ���������
	void Draw()const override;
};
