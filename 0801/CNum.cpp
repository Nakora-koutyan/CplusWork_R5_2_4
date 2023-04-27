#include<stdio.h>
#include"CNum.h"

int CNum::m_num;

CNum::CNum(int num)
{
	m_num = num;
}

void CNum::Disp()
{
	printf("%d\n", m_num);
}