#include<stdio.h>
#include<memory.h>
#include"CIntArray.h"


CIntArray::CIntArray(const int nNumOf)
{
	m_pnum = new int[nNumOf];
	if (m_pnum == NULL)
	{
		m_NumOf = 0;
	}
	else
	{
		m_NumOf = nNumOf;
		for (int i = 0; i < m_NumOf; i++)
		{
			m_pnum[i] = 0;
		}
	}

	printf("コントラクタが呼ばれました。\n");
	printf("要素数は%dです\n", m_NumOf);
}

CIntArray::~CIntArray()
{
	if (m_pnum != NULL)
	{
		delete[]m_pnum;
	}

	printf("デストラクタが呼ばれました。");
	printf("要素数は%dです\n", m_NumOf);
}

int CIntArray::Get(const int index)
{
	CheckIndex(index);
	return m_pnum[index];
}

void CIntArray::Set(const int index, const int value)
{
	CheckIndex(index);
	m_pnum[index] = value;
}

void CIntArray::CheckIndex(const int index)
{
	if (index < m_NumOf)
	{
		return;
	}

	printf("インデックスが不正です！\n");
	printf("値:%d\n", index);
}