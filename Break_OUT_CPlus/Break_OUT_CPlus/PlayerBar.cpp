#include "PlayerBar.h"
#include "MouseControll.h"

int PlayerBar::bar_x;
int PlayerBar::bar_y;

PlayerBar::PlayerBar()
{
	bar_x = MouseControll::Mouse.x;;
	bar_y = 380;
}

PlayerBar::~PlayerBar()
{
	bar_x;
	bar_y;
}

void PlayerBar::Update()
{
	bar_x = MouseControll::Mouse.x;
	ReflectionBar();
}

void PlayerBar::Draw()const
{
	//ÉoÅ[ÇÃï`âÊ
	DrawBox(bar_x,bar_y,bar_x+60,bar_y+8,0xFFD700,TRUE);
}

void PlayerBar::ReflectionBar()
{
	if (bar_x < 4 || bar_x > 640 - 60)
	{
		if (bar_x < 4)
		{
			bar_x = 4;
		}
		else
		{
			bar_x = 640 - 60;
		}
	}
}