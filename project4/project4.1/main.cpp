#include "POS.h"

int main(void)
{
	POS pos1;	//�R���X�g���N�^�̌Ăяo��
	POS pos2(100, 200);	//���������̃R���X�g���N�^

	//��������R���X�g���N�^
	pos1.print();
	pos2.print();

	return 0;
}