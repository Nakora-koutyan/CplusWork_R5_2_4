#include"POS.h"


POS::POS()
{
	x = 0; //メンバ変数x
	y = 0; //メンバ変数y
}

int POS::getX()const
{
	return x; //
}

int POS::getY()const
{
	return y;
}

void POS::setX(int tmpx)
{
	x = tmpx;
}

void POS::setY(int tmpy)
{
	y = tmpy;
}