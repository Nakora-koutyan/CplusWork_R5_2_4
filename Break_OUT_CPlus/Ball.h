#pragma once
#include "HitCollision.h"

struct LocationBall				/* ���S���W */
{
	int x;						//�{�[���̂����W
	int y;						//�{�[���̂����W
};
class Ball
{
public:

	static int speed;					//�{�[���̑��x
	static int ball_flg;				//�{�[���̏��(0.�ړ����@1.�o�[�ڐG�@2.�X�^�[�g���)
	static int moveball_x;				//�{�[���̓�������
	static int moveball_y;				//�{�[���̓�������
	static float change_angle;			//�{�[���̊p�x
	static LocationBall location_ball;		

public:
	Ball();								//�R���X�g���N�^
	~Ball();							//�f�X�g���N�^
	void MoveBall();					//�{�[���̈ړ�����
	void StartBall();					//�{�[���̓���J�n
	void ReflectionBall();				//�{�[���̔���
	void Update();						//�`��ȊO�Ɋւ��邱�Ƃ���������
	void Draw()const;					//�`��Ɋւ��邱�Ƃ���������
	static void ChangeBallAngle();		//�{�[���̊p�x�̕ύX����
};

