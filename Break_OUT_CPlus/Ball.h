#pragma once

struct LocationBall
{
	int x;
	int y;
};
class Ball
{
private:
	int speed;					//�{�[���̑��x
	int ball_flg;				//�{�[���̏��(0.�ړ����@1.�o�[�ڐG�@2.�X�^�[�g���)
	int ball_angle;
	LocationBall location;

public:
	Ball();						//�R���X�g���N�^
	~Ball();					//�f�X�g���N�^
	bool InitBallLocation();	//�{�[���̏������W
	void StartBall();			//�{�[���̓���J�n
	void Update();				//�`��ȊO�Ɋւ��邱�Ƃ���������
	void Draw()const;			//�`��Ɋւ��邱�Ƃ���������
};

