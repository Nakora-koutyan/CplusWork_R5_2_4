#pragma once
#include "DxLib.h"
#include "MouseControll.h"
class PlayerBar
{
public:
	static int bar_x;
	static int bar_y;

public:
	PlayerBar();			//�R���X�g���N�^
	~PlayerBar();			//�f�X�g���N�^
	void Update();			//�`��ȊO�Ɋւ��邱�Ƃ���������
	void Draw()const;		//�`��Ɋւ��邱�Ƃ���������
	void ReflectionBar();	//�o�[�̔���
};

