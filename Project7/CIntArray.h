#pragma once
class CIntArray
{
private:
	int* m_pnum;
	int m_NumOf;

public:
	CIntArray(const int nNumOf);
	~CIntArray();

public:
	int Get(const int index);
	void Set(const int index, const int value);

private:
	void CheckIndex(const int index);
};
