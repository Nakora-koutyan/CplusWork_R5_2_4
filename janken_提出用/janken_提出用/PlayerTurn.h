#pragma once
#include"GameMain.h"
#include"AbstractScene.h"
#include"DxLib.h"

class PlayerTurn :public AbstractScene {
public:

	int Push_key;
	int a;

public:
	PlayerTurn();

	//�f�X�g���N�^
	~PlayerTurn(){};

	//�`��ȊO�̍X�V����������
	AbstractScene* Update()override;

	//�`��̍X�V����������
	void Draw()const override;
};