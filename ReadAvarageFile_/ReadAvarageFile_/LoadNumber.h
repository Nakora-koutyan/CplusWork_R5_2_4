#pragma once
#include<stdio.h>
#define CITY_NAME 5
#define DATA_NUM 5

struct AverageData
{
	char name[5];
	int no;
};

struct AverageData gAvegNum[CITY_NAME];

int LoadNumbers()
{
	FILE* fp;
#pragma warning(disable:4996)
	//�t�@�C���I�[�v��
	fp = fopen("sample.txt","r");
	
	//�G���[�m�F
	if (fp == NULL)
	{
		printf("�G���[���������܂����B\n");
		return -1;
	}

	//1�s�ړǂݔ�΂�
	char header[256];
	fgets(header, sizeof(header), fp);

	//�Q�s�ڈȍ~�̃f�[�^�̓Ǎ�
	for (int i = 0; i < CITY_NAME; i++) 
	{
		int dammy = fscanf(fp, "%s %d %d %d %d %d", &gAvegNum[i].name, &gAvegNum[i].no, &gAvegNum[i].no, &gAvegNum[i].no, &gAvegNum[i].no, &gAvegNum[i].no);
	}

	//�t�@�C���N���[�Y
	fclose(fp);

	return 0;
}