#include<stdio.h>
#include"CNum.h"


int CNum::m_num;


CNum::CNum()
{
	m_num++;
}

CNum::~CNum()
{
	m_num--;
}

void CNum::Disp()
{
	printf("%d\n", m_num);
}