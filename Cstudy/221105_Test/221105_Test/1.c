#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct book_title {
	char* title; 
} BINFO;

int main()
{
	// 2. 2���� �迭ó�� ���� �Ҵ��ϴ� ���
	int i;
	char** pch;
	pch = (char**)malloc(3 * sizeof(char*));

	for (i = 0; i < 3; i++)
	{
		pch[i] = (char*)malloc(4 * sizeof(char));
	}

	strcpy(pch[0], "aaa");
	strcpy(pch[1], "bbb");
	pch[2][0] = '\0';

	for (i = 0; i < 3; i++)
		puts(pch[i]);
	for (i = 0; i < 3; i++)
		free(pch[i]);
	free(pch);

	// 1. ���� �޸� �Ҵ��� ����� ���ڿ� ó�� ���α׷�
	/*
	BINFO* bp = NULL;
	int n, i, len;
	char temp[100];

	scanf("%d", &n);
	getchar();

	// å �迭 ���� �Ҵ� �� ���� �Ҵ� ���� �˻�
	bp = (BINFO*)malloc(n * sizeof(BINFO));
	if (bp == NULL)
	{
		printf("�޸� ����!");
		return -1;
	}

	// ����ü �迭���� title�� ���� �Ҵ��ϱ�
	for (i = 0; i < n; i++)
	{
		gets(temp);

		len = strlen(temp);
		bp[i].title = (char*)malloc((len + 1) * sizeof(char));
		if (bp[i].title == NULL)
		{
			printf("�޸� ����!");
			return -1;
		}

		strcpy(bp[i].title, temp);
	}
	
	// �̸� ��� �� title�� ���� �Ҵ�� �κ��� ������Ű��
	for (i = 0; i < n; i++)
	{
		printf("%s\n", bp[i].title);
		free(bp[i].title);
	}

	// ����ü �迭 ������Ű��
	free(bp);

	return 0;
	*/
}