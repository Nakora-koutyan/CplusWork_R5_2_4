#pragma once
class POS
{
private://�A�N�Z�X�w��q�F�O������J
	int x;	//�����o�ϐ�x:�O������J
	int y;	//�����o�ϐ�y:�O���ɔ���J

public:	//�A�N�Z�X�w��q�F�O���Ɋ��S���J
	/**
	*�֐���:POS �����Ȃ��R���X�g���N�^
	*�����F�Ȃ�
	* �������e�F�����o�ϐ��̏�����
	*/
	POS();

	/*
	* �֐���:POS ��������R���X�g���N�^
	* �����F
	* int tmpx,int tmpy
	* �������e�F
	* �����o�ϐ�x ��tmpx,
	* �����o�ϐ�y ��tmpy �ŏ���������
	*/
	POS(int tmpx, int tmpy);

	void print();
};