#include <stdio.h>
#include"POS.h"

int POS::setPos(int tmpx, int tmpy)
{
	//�����o�ϐ��̒l���X�V
	x = tmpx;
	y = tmpy;

	return 0;
}

void POS::print()
{
	//�����o�ϐ��̒l����ʂɏo��
	printf("x:%d,y:%d\n", x, y);
}

