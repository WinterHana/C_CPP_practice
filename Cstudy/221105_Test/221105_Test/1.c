#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct book_title {
	char* title; 
} BINFO;

int main()
{
	// 2. 2차원 배열처럼 동적 할당하는 방법
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

	// 1. 동적 메모리 할당을 사용한 문자열 처리 프로그램
	/*
	BINFO* bp = NULL;
	int n, i, len;
	char temp[100];

	scanf("%d", &n);
	getchar();

	// 책 배열 동적 할당 및 동적 할당 오류 검사
	bp = (BINFO*)malloc(n * sizeof(BINFO));
	if (bp == NULL)
	{
		printf("메모리 부족!");
		return -1;
	}

	// 구조체 배열마다 title을 동적 할당하기
	for (i = 0; i < n; i++)
	{
		gets(temp);

		len = strlen(temp);
		bp[i].title = (char*)malloc((len + 1) * sizeof(char));
		if (bp[i].title == NULL)
		{
			printf("메모리 부족!");
			return -1;
		}

		strcpy(bp[i].title, temp);
	}
	
	// 이름 출력 후 title에 동적 할당된 부분을 해제시키기
	for (i = 0; i < n; i++)
	{
		printf("%s\n", bp[i].title);
		free(bp[i].title);
	}

	// 구조체 배열 해제시키기
	free(bp);

	return 0;
	*/
}