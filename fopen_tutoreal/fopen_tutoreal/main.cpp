#include <stdio.h>

int main(void)
{
	FILE* fp;

	printf("ファイルをオープンします。\n");
	fopen_s(&fp, "test1.txt", "w");
	if (fp == NULL)
	{
		printf("エラーが発生しました。\n");
		return -1;
	}
	
	printf("ファイルをクローズします。\n");
	fclose(fp);

	return 0;
}