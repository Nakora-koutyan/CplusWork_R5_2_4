#include"POS.h"


POS::POS()
{
	x = 0; //�����o�ϐ�x
	y = 0; //�����o�ϐ�y
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