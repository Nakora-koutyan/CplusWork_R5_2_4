#pragma once
#include "DxLib.h"
#include "Ball.h"
#include "PlayerBar.h"

class Collision
{
private:
	int mx0;
	int mx1;
	int my0;
	int my1;
	int sx0;
	int sx1;
	int sy0;
	int sy1;

public:
	Collision();
	~Collision();
	void Update();
};