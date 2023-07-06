#include "Ball.h"
#include "DxLib.h"
#include "MouseControll.h"

Ball::Ball()
{
	location.x = 270;
	ball_flg = 2;
	speed = 0;
	ball_angle;
}
Ball::~Ball()
{
}
bool Ball::InitBallLocation()
{
	location.x;
	ball_flg;

	return true;
}
void Ball::Update()
{
	location.x = 270;
	location.y = 375;
}
void Ball::Draw()const
{
	DrawCircle(location.x,location.y,4,0xffff00,TRUE);
	DrawFormatString(400, 400, 0xffffff, "%d %d", location.x,location.y);
}
void Ball::StartBall()
{
	if (MouseControll::OnClickMouse() && InitBallLocation())
	{
		ball_flg = 0;
		//スピードとアングルによる移動計算
		speed = 3;
	}
}
