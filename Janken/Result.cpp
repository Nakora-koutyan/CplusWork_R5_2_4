#include<stdio.h>
#include"DxLib.h"

// ����񂯂�̌��ʂ𔻒f����
// ����񂯂�̌��ʂ�\������
int Result{
DrawFormatString(20, 110, GetColor(255, 255, 255), "���ʂ́E�E�E");
	if (a == b)
	{
		DrawFormatString(20, 130, GetColor(255, 255, 255), "���������ł�!!!");
	}
	else if ((a == 0 && b == 1) ||(a == 1 && b == 2) ||(a == 2 && b == 0))
	{
		DrawFormatString(20, 130, GetColor(255, 255, 255), "���Ȃ��̏����ł�!!!");
	}
	else
	{
		DrawFormatString(20, 130, GetColor(255, 255, 255), "���Ȃ��̕����ł�...");
	}
}
