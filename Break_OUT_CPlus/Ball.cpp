#include "Ball.h"
#include "DxLib.h"
#include "MouseControll.h"
#include "PlayerBar.h"
#define	 _USE_MATH_DEFINES
#include <math.h>
#include "common.h"

LocationBall Ball::location_ball;
int Ball::ball_flg;
float Ball::change_angle;
int Ball::speed;
int Ball::moveball_x;
int Ball::moveball_y;

Ball::Ball()	//�R���X�g���N�^
{
	location_ball.x = 270;
	location_ball.y = 376;
	ball_flg = 2;
	speed = 0;
	moveball_x = -1;
	moveball_y = -2;
	change_angle = 0.625f;
}

Ball::~Ball()	//�f�X�g���N�^
{
}

void Ball::Update()		//�`��ȊO�Ɋւ��鏈���̍X�V����
{
	MoveBall();
	StartBall();
	ReflectionBall();
}

void Ball::Draw()const	//�`��Ɋւ��鏈���̎���
{
	DrawCircle(location_ball.x,location_ball.y,4,0xffff00,TRUE);
	DrawBox(location_ball.x-5, location_ball.y-5, location_ball.x+5, location_ball.y+5, 0xff0000,TRUE);
	DrawFormatString(400, 400, 0xffffff, "%d %d", location_ball.x,location_ball.y);
}

void Ball::StartBall()
{
	//�}�E�X���N���b�N�ŃQ�[���X�^�[�g
	if (MouseControll::OnClickMouse() && ball_flg == 2)
	{
		ball_flg = 0;
		//�X�s�[�h�ƃA���O���ɂ��ړ��v�Z
		speed = 3;
		moveball_x = -1;
		moveball_y = -2;
	}
}

void Ball::MoveBall()
{
	if (ball_flg == 2)
	{
		location_ball.x = PlayerBar::bar_x + 30;
		location_ball.y = PlayerBar::bar_y - 4;
	}
	else
	{
		location_ball.x += moveball_x;
		location_ball.y += moveball_y;
	}
}

void Ball::ReflectionBall()
{
	//���̕ǂƉE�̕ǂł̔���
	if (location_ball.x < 4 || location_ball.x > 640 - 4)
	{
		if (location_ball.x < 4)
		{
			//���̕ǂɓ������������̐�ɐi�܂Ȃ��悤�ɂ���
			location_ball.x = 4;
		}
		else
		{
			//�E�̕ǂɓ������������̐�ɐi�߂Ȃ��悤�ɂ���
			location_ball.x = 640 - 4;
		}
		//�{�[���𐳔��˂���
		change_angle = (1.0f - change_angle) + 0.5f;
		if (change_angle > 1)
		{
			change_angle -= 1.0f;
		}
		ChangeBallAngle();
	}
	if (location_ball.y < 8)
	{
		//��̕ǂɓ������������̐�ɐi�߂Ȃ��悤�ɂ���
		change_angle = (1.0f - change_angle); 
		ChangeBallAngle();
	}
	if (location_ball.y > 480 + 4)
	{
		//�{�[�����X�^�[�g��Ԃɂ���
		ball_flg = 2;
		change_angle = 0.625f;
	}
}

void Ball::ChangeBallAngle()
{
	float rad = change_angle * (float)M_PI * 2;
	moveball_x = (int)(speed * cosf(rad));
	moveball_y = (int)(speed * sinf(rad));
}