#pragma once
#include "AbstractScene.h"
#include "PlayerBar.h"
#include "Ball.h"

class GameMainScene :public AbstractScene
{
private:
	unsigned int Cr;		//�����o�ϐ�
	PlayerBar player_bar;	//�N���X�̃I�u�W�F�N�g��
	Ball ball;				//�N���X�̃I�u�W�F�N�g��

public:
	//�R���X�g���N�^
	GameMainScene();

	//�f�X�g���N�^
	virtual ~GameMainScene();

	//�`��ȊO�Ɋւ��邱�Ƃ����s����
	virtual AbstractScene* Update() override;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const override;
};