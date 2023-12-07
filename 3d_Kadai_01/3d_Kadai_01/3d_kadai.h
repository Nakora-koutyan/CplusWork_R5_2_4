#pragma once
#pragma warning(suppress : 4996)
#include <stdio.h>
#include<stdlib.h>
#include "pch.h"
#define WIN32_LEAN_AND_MEAN             // Windows �w�b�_�[����قƂ�ǎg�p����Ă��Ȃ����������O����

void ThirdDFileRead(const char* _file, float& min_x, float& min_y, float& min_z, float& max_x, float& max_y, float& max_z)
{
	//�t�@�C���ւ̃|�C���^��錾
	FILE* file;
#pragma warning(disable : 4996)
	//�t�@�C�����J��
	file = fopen(_file, "r");

	//�t�@�C������f�[�^��ǂ�ŏo��
	char str[256];

	float x, y, z;

	//�t�@�C���̏I���܂œǂݑ�����
	while (fgets(str, 256, file))
	{
		if ((str[0] == 'v') && (str[1] == ' ' || str[1] == 't' || str[1] == 'n'))
		{
			if (sscanf(str + 1, "%f %f %f", &x, &y, &z) == 3)
			{
				if (x > max_x) { max_x = x; }
				if (y > max_y) { max_y = y; }
				if (z > max_z) { max_z = z; }
				if (x < min_x) { min_x = x; }
				if (y < min_y) { min_y = y; }
				if (z < min_z) { min_z = z; }
			}
		}
	}
	//�t�@�C���N���[�Y
	fclose(file);
}