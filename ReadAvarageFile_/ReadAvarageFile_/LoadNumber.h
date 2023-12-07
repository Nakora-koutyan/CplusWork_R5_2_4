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
	//ファイルオープン
	fp = fopen("sample.txt","r");
	
	//エラー確認
	if (fp == NULL)
	{
		printf("エラーが発生しました。\n");
		return -1;
	}

	//1行目読み飛ばし
	char header[256];
	fgets(header, sizeof(header), fp);

	//２行目以降のデータの読込
	for (int i = 0; i < CITY_NAME; i++) 
	{
		int dammy = fscanf(fp, "%s %d %d %d %d %d", &gAvegNum[i].name, &gAvegNum[i].no, &gAvegNum[i].no, &gAvegNum[i].no, &gAvegNum[i].no, &gAvegNum[i].no);
	}

	//ファイルクローズ
	fclose(fp);

	return 0;
}