#include<stdio.h>
#include"POS.h"


int main(void)
{
	POS pos;	//�N���XPOS�̃I�u�W�F�N�g���쐬

	//�����o�ϐ���private�ɂȂ��Ă��邽��
	//�����o�֐�SetPos(x,y)�Ń����o�ϐ��̒l��ύX����
	pos.setPos(100, 200);

	//�����o�ϐ���private�ɂȂ��Ă��邽��
	//�����o�֐�print()�Ń����o�ϐ��̒l���o�͂���
	pos.print();

	return 0;
}