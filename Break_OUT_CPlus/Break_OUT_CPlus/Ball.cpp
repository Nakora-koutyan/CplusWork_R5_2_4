#include "Ball.h"
#include "DxLib.h"
#include "MouseControll.h"
#include "PlayerBar.h"
#define		_USE_MATH_DEFINES
#include	<math.h>
#include "common.h"

Ball::Ball()	//コンストラクタ
{
	location_ball.x = 270;
	location_ball.y = 376;
	ball_flg = 2;
	speed = 0;
	moveball_x = 1;
	moveball_y = -2;

}

Ball::~Ball()	//デストラクタ
{
}

void Ball::Update()		//描画以外に関する処理の更新実装
{
	MoveBall();
	StartBall();
	ReflectionBall();
}

void Ball::Draw()const	//描画に関する処理の実装
{
	DrawCircle(location_ball.x,location_ball.y,4,0xffff00,TRUE);
	DrawFormatString(400, 400, 0xffffff, "%d %d", location_ball.x,location_ball.y);
}

void Ball::StartBall()
{
	if (MouseControll::OnClickMouse() && ball_flg == 2)
	{
		ball_flg = 0;
		//スピードとアングルによる移動計算
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
	if (location_ball.x < 4 || location_ball.x > 640 - 4)	//左の壁と右の壁での反射
	{
		if (location_ball.x < 4)
		{
			location_ball.x = 4;		//左の壁に当たった時その先に進まないようにする
		}
		else
		{
			location_ball.x = 640 - 4;	//右の壁に当たった時その先に進めないようにする
		}
	}
	if (location_ball.y < 8)
	{
		location_ball.y = 8;			//上の壁に当たった時その先に進めないようにする
	}
}