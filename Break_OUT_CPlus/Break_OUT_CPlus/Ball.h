#pragma once

struct LocationBall				/* ���S���W */
{
	int x;						//�{�[���̂����W
	int y;						//�{�[���̂����W
};
class Ball
{
private:
	int speed;					//�{�[���̑��x
	int ball_flg;				//�{�[���̏��(0.�ړ����@1.�o�[�ڐG�@2.�X�^�[�g���)
	int moveball_x;				//�{�[���̓�������
	int moveball_y;				//�{�[���̓�������
	LocationBall location_ball;		

public:
	Ball();						//�R���X�g���N�^
	~Ball();					//�f�X�g���N�^
	void MoveBall();			//�{�[���̈ړ�����
	void StartBall();			//�{�[���̓���J�n
	void ReflectionBall();		//�{�[���̔���
	void Update();				//�`��ȊO�Ɋւ��邱�Ƃ���������
	void Draw()const;			//�`��Ɋւ��邱�Ƃ���������
};

