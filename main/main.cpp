#include<stdio.h>
#include"POS.h"		//�N���XPOS.h�̌^��`��ǂݎ��

int main(void)
{
	//�N���XPOS�̃I�u�W�F�N�g���쐬(�ϐ�pos)
	POS pos;
	//�N���XPOS�̃I�u�W�F�N�g���쐬(�ϐ�pos2)
	POS pos2;

	//pos�̃����o�ϐ��ɒl����
	pos.x = 100.0;
	pos.y = 200.0;

	pos.print();	//�l����ʂɕ\��

	pos2.x = 300.0;
	pos2.y = 256.0;

	pos2.print();	//�l����ʂɕ\��

	return 0;
}