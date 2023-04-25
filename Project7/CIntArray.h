#pragma once
class CIntArray
{
private:	//�A�N�Z�X�w��q�F�O���ɔ���J
	int* m_pnum;	//�����o�ϐ� *m_pnum�F�O���ɔ���J
	int m_NumOf;	//�����o�ϐ� m_NumOf�F�O���ɔ���J

public:		//�A�N�Z�X�w��q�F�O���Ɍ��J
	/**
	*�@�֐����FCIntArray �R���X�g���N�^
	* �����F
	* const int nNumOf �쐬����z��̗v�f��
	* �������e�F
	* �����o�ϐ�m_pnum�Ɉ���NumOf�̕������z���new�ō쐬����
	* �����o�ϐ�m_NumOf���쐬�����z��̗v�f���F�O���Ɍ��J
	*/
	CIntArray(const int nNumOf);
	~CIntArray();

public:
	int Get(const int index);
	void Set(const int index, const int value);

private:
	void CheckIndex(const int index);
};
