#include<stdio.h>
#include"POS.h"		//�N���XPOS.h�̌^��`��ǂݎ��

int main(void)
{
	//�N���XPOS�̃I�u�W�F�N�g���쐬(�ϐ�pos)
	POS pos;

	//pos�̃����o�ϐ��ɒl����
	pos.x = 100.0;
	pos.y = 200.0;

	//pos�̒l����ʂɕ\�����Ċm�F
	printf("x:%lf y:%lf\n", pos.x, pos.y);

	return 0;
}