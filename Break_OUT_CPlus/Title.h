#pragma once
#include"AbstractScene.h"

class TitleScene :public AbstractScene
{
private:
	unsigned int Cr;

public:
	//�R���X�g���N�^
	TitleScene();

	//�f�X�g���N�^
	virtual ~TitleScene();

	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update() override;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const override;
};