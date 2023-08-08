#pragma once
#include "HitCollision.h"
#include "Ball.h"

Collision::Collision()
{
	//座標位置の事前計算
	mx0 = Ball::location_ball.x - 5;
	mx1 = Ball::location_ball.x + 5;
	my0 = Ball::location_ball.y - 5;
	my1 = Ball::location_ball.y + 5;

	//バーの当たり判定の範囲
	sx0 = PlayerBar::bar_x;
	sx1 = PlayerBar::bar_x + 60;
	sy0 = PlayerBar::bar_y;
	sy1 = PlayerBar::bar_y + 8;
};
Collision::~Collision()
{

}

void Collision::Update()
{
	//座標位置の事前計算
	mx0 = Ball::location_ball.x - 5;
	mx1 = Ball::location_ball.x + 5;
	my0 = Ball::location_ball.y - 5;
	my1 = Ball::location_ball.y + 5;

	//バーの当たり判定の範囲
	sx0 = PlayerBar::bar_x;
	sx1 = PlayerBar::bar_x + 60;
	sy0 = PlayerBar::bar_y;
	sy1 = PlayerBar::bar_y + 8;

	if ((sx0 <= mx1) && (mx0 <= sx1) && (sy0 <= my1) && (my0 <= sy1))
	{
		if (Ball::ball_flg == 0)
		{
			Ball::change_angle = (0.3f / 60) * (mx1 - sx0) + 0.6f;
			Ball::ChangeBallAngle();

			Ball::ball_flg = 1;
		}
	}
	else
	{
		if (Ball::ball_flg != 2)
		{
			Ball::ball_flg = 0;
		}
	}
}