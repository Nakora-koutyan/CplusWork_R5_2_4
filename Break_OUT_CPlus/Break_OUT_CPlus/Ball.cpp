#include "Ball.h"
#include "DxLib.h"
#include "MouseControll.h"
#include "PlayerBar.h"
#define		_USE_MATH_DEFINES
#include	<math.h>
#include "common.h"

Ball::Ball()	//�R���X�g���N�^
{
	location_ball.x = 270;
	location_ball.y = 376;
	ball_flg = 2;
	speed = 0;
	moveball_x = 1;
	moveball_y = -2;

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
	DrawFormatString(400, 400, 0xffffff, "%d %d", location_ball.x,location_ball.y);
}

void Ball::StartBall()
{
	if (MouseControll::OnClickMouse() && ball_flg == 2)
	{
		ball_flg = 0;
		//�X�s�[�h�ƃA���O���ɂ��ړ��v�Z
		speed = 3;
	}
}

void Ball::MoveBall()
{
	if (ball_flg == 2)
	{
		location_ball.x = PlayerBar::bar_x + 30;
	}
	else
	{
		location_ball.x += moveball_x;
		location_ball.y += moveball_y;
	}
}

void Ball::ReflectionBall()
{
	if (location_ball.x < 4 || location_ball.x > 640 - 4)	//���̕ǂƉE�̕ǂł̔���
	{
		if (location_ball.x < 4)
		{
			location_ball.x = 4;		//���̕ǂɓ������������̐�ɐi�܂Ȃ��悤�ɂ���
		}
		else
		{
			location_ball.x = 640 - 4;	//�E�̕ǂɓ������������̐�ɐi�߂Ȃ��悤�ɂ���
		}
	}
	if (location_ball.y < 8)
	{
		location_ball.y = 8;			//��̕ǂɓ������������̐�ɐi�߂Ȃ��悤�ɂ���
	}
}