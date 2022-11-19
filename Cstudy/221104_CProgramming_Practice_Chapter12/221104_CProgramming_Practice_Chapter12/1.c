#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 응용 1번
int count_c(char* p, int M);

int main()
{
	char** str, * temp, tmp[101];
	int i, j, N, M;

	scanf("%d %d", &N, &M); getchar();
	str = (char**)malloc(sizeof(char*) * N);
	if (str == NULL)
	{
		printf("메모리 할당 실패"); return -1;
	}

	for (i = 0; i < N; i++)
	{
		gets(tmp);
		str[i] = (char*)malloc(strlen(tmp) + 1);
		if (str[i] == NULL)
		{
			printf("메모리 할당 실패"); return -1;
		}
		strcpy(str[i], tmp);
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - i - 1; j++)
		{
			if (count_c(str[j], M) < count_c(str[j + 1], M))
			{
				temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
		}
	}

	for (i = 0; i < N; i++)
	{
		if (count_c(str[i], M) != 0)
			printf("%s\n", str[i]);
	}

	for (i = 0; i < N; i++)
		free(str[i]);
	free(str);

	return 0;
}

int count_c(char* p, int M)
{
	char* pt, *qt;
	int count = 0;

	if (strlen(p) < M)
		qt = p + strlen(p);
	else
		qt = p + M;

	for (pt = p; pt < qt; pt++)
	{
		if (!(*pt >= 'a' && *pt <= 'z') && *pt != ' ' && !(*pt >= 'A' && *pt <= 'Z')) count++;
	}
	return count;
}
// 응용 2번
/*
* 함수 만들 때 이런 식으로도 응용이 가능
* if(strlen(p) < q - p + 1)
*		q = p + strlen(p);
*/
/*
int count_c(char* p, char* q);

int main()
{
	char** str, * temp, tmp[101];
	int i, j, N, M;

	scanf("%d %d", &N, &M); getchar();
	str = (char**)malloc(sizeof(char*) * N);
	if (str == NULL)
	{
		printf("메모리 할당 실패"); return -1;
	}

	for (i = 0; i < N; i++)
	{
		gets(tmp);
		str[i] = (char*)malloc(strlen(tmp) + 1);
		if (str[i] == NULL)
		{
			printf("메모리 할당 실패"); return -1;
		}
		strcpy(str[i], tmp);
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - i - 1; j++)
		{
			if (count_c(str[j], str[j] + M - 1) < count_c(str[j + 1], str[j + 1] + M - 1))
			{
				temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
		}
	}

	for (i = 0; i < N; i++)
	{
		if (count_c(str[i], str[i] + M - 1) != 0)
			printf("%s\n", str[i]);
	}

	for (i = 0; i < N; i++)
		free(str[i]);
	free(str);

	return 0;
}

int count_c(char* p, char* q)
{
	char* pt;
	int count = 0;
	for (pt = p; pt < q; pt++)
	{
		if (*pt == '\0') break;

		if (!(*pt >= 'a' && *pt <= 'z') && *pt != ' ' && !(*pt >= 'A' && *pt <= 'Z')) count++;
	}
	return count;
}
*/
// 응용 3번
/*
int count_c(char* p, char* q);

int main()
{
	char** str, temp[100], max_str[101];
	int i, N, max, t;

	scanf("%d", &N); getchar();
	str = (char**)malloc(sizeof(char*) * N);
	if (str == NULL)
	{
		printf("메모리 할당 실패"); return -1;
	}

	max = 0;
	for (i = 0; i < N; i++)
	{
		gets(temp);
		str[i] = (char*)malloc(strlen(temp) + 1);
		if (str[i] == NULL)
		{
			printf("메모리 할당 실패"); return -1;
		}
		strcpy(str[i], temp);
		t = count_c(str[i], str[i] + strlen(str[i]) - 1);

		if (t > max)
		{
			strcpy(max_str, str[i]);
			max = t;
		}
	}
	printf("%s\n", max_str);
	return 0;
}

int count_c(char* p, char* q)
{
	char* pt;
	int count = 0;
	for (pt = p; pt <= q; pt++)
	{
		if (!(*pt >= 'a' && *pt <= 'z') && *pt != ' ' && !(*pt >= 'A' && *pt <= 'Z')) count++;
	}
	return count;
}
*/
// 문제 13번
/*
int main()
{
	int n, i, d;
	int* pnum;

	scanf("%d", &n);
	pnum = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		scanf("%d", &pnum[i]);
	}
	getchar();

	scanf("%d", &d);
	pnum = (int*)realloc(pnum, (n - d) * sizeof(int));

	for (i = 0; i < n - d - 1; i++)
	{
		printf("%d\n", pnum[i]);
	}

	printf("%d", pnum[i]);
	free(pnum);
	return 0;
}
*/
// 문제 12번 : null 체크해주기
/*
int main()
{
	char** p, * tmp, temp[101];
	int i, j, N, len;
	scanf("%d", &N); getchar;
	p = (char**)malloc(sizeof(char*) * N);

	if (p == NULL)
	{
		printf("error of memory allocating");
		return -1;
	}

	for (i = 0; i < N; i++)
	{
		scanf("%s", temp);
		len = strlen(temp);
		p[i] = (char*)malloc(sizeof(char) * (len + 1));
		strcpy(p[i], temp);
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - (i + 1); j++)
		{
			if (strcmp(p[j], p[j + 1]) > 0)
			{
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}

	for (i = 0; i < N; i++)
	{
		printf("%s\n", p[i]);
		free(p[i]);
	}
	free(p);

	return 0;
}
*/
// 문제 11번 : realloc 써도 됨
/*
int main()
{
	int size = 5, i = 0, j;
	int* arr = (int*)malloc(sizeof(int) * size);

	while (1)
	{
		scanf("%d", &arr[i]);
		if (arr[i] == -1)
		{
			arr[i] = -1;
			break;
		}

		if (i + 1 == size) 
		{
			size += 3;
			arr = (int*)realloc(arr, sizeof(int) * size);
		}
		i++;
	}

	for (j = 0; j < i + 1; j++)
	{
		printf("%d ", arr[j]);
	}

	free(arr);

	return 0;
}
*/
// 문제 10번
/*
int main()
{
	int* a, * b, i, n;
	scanf("%d", &n);

	a = (int*)malloc(sizeof(int) * n);
	b = (int*)malloc(sizeof(int) * (n - 1));

	for (i = 0; i < n; i++)
		*(a + i) = i;

	memcpy(b, a, sizeof(int) * (n / 2));
	memcpy(b + (n / 2), a + (n / 2) + 1, sizeof(int) * (n / 2));

	for (i = 0; i < (n - 1); i++)
		printf(" %d", *(b + i));
	free(a);
	free(b);
	return 0;
}
*/
// 문제 9번 : 내가 한 거->오류 남
/*
int main()
{
	int N, i, j, len1, len2;
	char** pstr, tmp[100], temp[100];

	scanf("%d", &N); getchar();
	pstr = (char**)malloc(sizeof(char*) * N);
	for (i = 0; i < N; i++)
	{
		gets(temp);
		pstr[i] = (char*)malloc(strlen(temp) + 1);
		strcpy(pstr[i], temp);
	}

	if (N >= 1)
	{
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N - (i + 1); j++)
			{
				len1 = strlen(pstr[j]);
				len2 = strlen(pstr[j + 1]);

				if (len1 < len2)
				{
					strcpy(tmp, pstr[j]);
					strcpy(pstr[j], pstr[j + 1]);
					strcpy(pstr[j + 1], tmp);

				}
			}
		}
	}

	for (i = 0; i < N; i++)
		printf("%s\n", pstr[i]);

	for (i = 0; i < N; i++)
		free(pstr[i]);
	free(pstr);
}
*/
// 문제 9번
/*
int main()
{
	int N, i, j, len1, len2;
	char** pstr = NULL, temp[100], *temp_str;

	scanf("%d", &N); getchar();
	pstr = (char**)malloc(sizeof(char*) * N);
	for (i = 0; i < N; i++)
	{
		gets(temp);
		pstr[i] = (char*)malloc(strlen(temp) + 1);
		strcpy(pstr[i], temp);
	}

	if (N >= 1)
	{
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N - (i + 1); j++)
			{
				len1 = strlen(pstr[j]);
				len2 = strlen(pstr[j + 1]);

				if (len1 < len2)
				{
					temp_str = pstr[j];
					pstr[j] = pstr[j + 1];
					pstr[j + 1] = temp_str;
				}
			}
		}
	}

	for (i = 0; i < N; i++)
	{
		printf("%s\n", pstr[i]);
		free(pstr[i]);
	}
	
	free(pstr);
	
	return 0;
}
*/
// 문제 8번
/*
int main()
{
	int N, i, len, min_len = 100;
	char** pstr, temp[100], min_word[100];

	scanf("%d", &N); getchar();
	pstr = (char**)malloc(sizeof(char*) * N);
	for (i = 0; i < N; i++)
	{
		gets(temp);
		pstr[i] = (char*)malloc(strlen(temp) + 1);
		strcpy(pstr[i], temp);
	}
	if (N >= 1)
	{
		for (i = 0; i < N; i++)
		{
			if (strlen(pstr[i]) < min_len)
			{
				min_len = strlen(pstr[i]);
				strcpy(min_word, pstr[i]);
			}
		}
	}
	printf("%s", min_word);

	for (i = 0; i < N; i++)
		free(pstr[i]);
	free(pstr);

	return 0;
}
*/