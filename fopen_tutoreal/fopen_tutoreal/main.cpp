#include <stdio.h>

int main(void)
{
	FILE* fp;

	printf("�t�@�C�����I�[�v�����܂��B\n");
	fopen_s(&fp, "test1.txt", "w");
	if (fp == NULL)
	{
		printf("�G���[���������܂����B\n");
		return -1;
	}
	
	printf("�t�@�C�����N���[�Y���܂��B\n");
	fclose(fp);

	return 0;
}