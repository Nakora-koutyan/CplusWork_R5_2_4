#pragma once
#include"AbstractScene.h"
#include"EnemyTurn.h"

class Result :public AbstractScene {
private:
	int Player_hand;
	int Enemy_hand;

public:
	Result(int a,int b);

	//�f�X�g���N�^
	virtual ~Result() {};

	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update()override;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw()const override;
};