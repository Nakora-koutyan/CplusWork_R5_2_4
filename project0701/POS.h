#pragma once
class POS
{
private: //�A�N�Z�X�w��q:�O���ɔ���J
	int x; //�����o�ϐ�x
	int y; //�����o�ϐ�y

public:	//�A�N�Z�X�w��q:�O���Ɍ��J
	/**
	* �֐����FPOS() �R���X�g�����o�֐�
	* ����:POS �R���X�g���N�^
	* �������e:�Ȃ�
	* �ϐ��̒l�̌Œ艻�E�A�h���X�̌Œ艻
	* 
	*/
	POS();

	int getX()const; //getX�̒l�̌Œ艻
	int getY()const; //getY�̒l�̌Œ艻

	void setX(int tmpx);
	void setY(int tmpy);


};
