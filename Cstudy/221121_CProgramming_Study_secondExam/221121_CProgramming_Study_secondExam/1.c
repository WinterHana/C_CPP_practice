#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int i, alen, blen;
	char A[100], B[100];
	gets(A); gets(B);
	alen = strlen(A); blen = strlen(B);

	for (i = 0; i < alen + 1; i++)
	{

	}
	return 0;
}
/*
I have a pen. I have an applepen. PPAP
pen
mouse
go
*/
/*
int main()
{
	int i, j, stringLen, blen, clen;
	char str[101];
	char wordB[11], wordC[11];
	gets(str);
	scanf("%s %s", wordB, wordC); getchar();
	stringLen = strlen(str);
	blen = strlen(wordB);
	clen = strlen(wordC);

	for (i = 0; i < stringLen; i++)
	{
		if (strncmp(str + i, wordB, blen) == 0)
		{
			if (blen == clen)
			{
				for (j = 0; j < clen; j++)
				{
					str[i] = wordC[j];
					i++;
				}
			}
			else if (blen < clen)
			{
				for (j = stringLen + 1; j > i + blen - 1; j--)
				{
					str[j + (clen - blen)] = str[j];
					// printf("%s\n", str);
				}

				for (j = 0; j < clen; j++)
				{
					str[i] = wordC[j];
					i++;
					// printf("%s\n", str);
				}
				
			}
			else if(blen > clen)
			{
				for (j = 0; j < clen; j++)
				{
					str[i] = wordC[j];
					i++;
					// printf("%s\n", str);
				}

				for (j = i + (blen - clen); j < stringLen + 1; j++)
				{
					str[j - (blen - clen)] = str[j];
					// printf("%s\n", str);
				}
			}
			stringLen = strlen(str);
			i--;
		}
	}

	printf("%s\n", str);
	return 0;
}
*/
/*
3 5
0 0 5
0 1 15
0 3 25
1 2 35
2 1 45
2 3 55
0 0 0

4 4
0 1 1
0 3 3
1 0 1
1 2 3
2 2 0
2 3 6
3 1 2
0 0 0
*/
/*
int check_row(int** p, int M, int N);
int check_col(int** p, int M, int N);

int main()
{
	int M, N, i, j;
	int** p = NULL;
	int row, col, tmp, maxCol, maxRow, result;
	scanf("%d %d", &M, &N); getchar();

	p = (int**)malloc(sizeof(int*) * M);
	if (p == NULL)
	{
		printf("Not allocated memory\n");
		return -1;
	}

	for (i = 0; i < M; i++)
	{
		p[i] = (int*)calloc(N, sizeof(int));
		if (p[i] == NULL)
		{
			printf("Not allocated memory\n");
			return -1;
		}
	}

	while (1)
	{
		scanf("%d %d %d", &row, &col, &tmp);
		if (row == 0 && col == 0 && tmp == 0) break;
		p[row][col] = tmp;
	}

	maxCol = check_col(p, M, N);
	maxRow = check_row(p, M, N);
	result = (maxCol > maxRow) ? maxCol : maxRow;

	// printf("%d %d\n", maxCol, maxRow);

	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}

	printf("%d\n", result);

	return 0;
}
// За
int check_row(int** p, int M, int N)
{
	int i, j;
	int count, max = 0;
	for (j = 0; j < N; j++)
	{
		count = 0;
		for (i = 0; i < M; i++)
		{
			if (p[i][j] == 0) count++;
			else
			{
				if (count > max) max = count;
				count = 0;
			}
		}
		if (count > max) max = count;
	}

	return max;
}
// ї­
int check_col(int** p, int M, int N)
{
	int i, j;
	int count, max = 0;
	for (i = 0; i < M; i++)
	{
		count = 0;
		for (j = 0; j < N; j++)
		{
			if (p[i][j] == 0) count++;
			else
			{
				if (count > max) max = count;
				count = 0;
			}
		}
		if (count > max) max = count;
	}

	return max;
}
*/
/*
5
why why why so so so serious
icecream makes everything better and better
you make me smile
c language exam and exam and exam and exam
see you later later later laters
*/
/*
struct string {
	char* str;
	int words;
};
int main()
{
	int N, i, j, k, stringLen, wordLen, wordsIndex;
	int count, maxCount;
	char str[101], maxWord[101];
	char** words, *pt;
	struct string* p = NULL;
	struct string tmp;

	scanf("%d", &N); getchar();
	p = (struct string*)malloc(sizeof(struct string) * N);
	if (p == NULL)
	{
		printf("Memory is not allocated\n");
		return -1;
	}

	for (i = 0; i < N; i++)
	{
		gets(str);
		stringLen = strlen(str);
		p[i].words = 0;
		p[i].str = (char*)malloc(sizeof(char) * (stringLen + 1));
		if (p[i].str == NULL)
		{
			printf("Memory is not allocated\n");
			return -1;
		}
		strcpy(p[i].str, str);

		for (j = 0; j < stringLen + 1; j++)
		{
			if (str[j] == ' ' || str[j] == '\0')
			{
				p[i].words++;
			}
		}
		// printf("%d\n", p[i].words);
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - (i + 1); j++)
		{
			if (p[j].words < p[j + 1].words)
			{
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}

	for (i = 0; i < N; i++)
	{
		strcpy(str, p[i].str);
		stringLen = strlen(str);
		words = (char**)malloc(sizeof(char*) * p[i].words);
		if (words == NULL)
		{
			printf("Memory is not allocated\n");
			return -1;
		}

		pt = str;
		wordsIndex = 0;
		for (j = 0; j < stringLen + 1; j++)
		{
			if (str[j] == ' ' || str[j] == '\0')
			{
				str[j] = '\0';
				wordLen = strlen(pt);
				words[wordsIndex] = (char*)malloc(sizeof(char) * (wordLen + 1));
				if (words[wordsIndex] == NULL)
				{
					printf("Memory is not allocated\n");
					return -1;
				}
				strcpy(words[wordsIndex], pt);
				pt += wordLen + 1;
				wordsIndex++;
			}
		}
		maxCount = 0;
		for (j = 0; j < wordsIndex; j++)
		{
			count = 0;
			for (k = j; k < wordsIndex; k++)
			{
				if (strcmp(words[j], words[k]) == 0)
				{
					count++;
				}
			}
			if (maxCount < count)
			{
				maxCount = count;
				strcpy(maxWord, words[j]);
			}
			else if(maxCount == count && strcmp(maxWord, words[j]) > 0)
			{
				maxCount = count;
				strcpy(maxWord, words[j]);
			}
		}

		printf("%s %d %s %d\n", p[i].str, p[i].words, maxWord, maxCount);

		for (j = 0; j < wordsIndex; j++)
		{
			free(words[j]);
		}
		free(words);
	}

	for (i = 0; i < N; i++) free(p[i].str);
	free(p);
	return 0;
}
*/
/*
7 3
Kim 75 85
Lee 93 63
Park 94 82
Choi 78 70
Jung 65 85
Kang 83 90
Cho 90 70

7 3
Kim 75 85
Lee 96 56
Park 94 82
Choi 78 70
Jung 65 85
Kang 93 63
Cho 93 63
*/
/*
struct student {
	char* name;
	int firstStage;
	int interview;
	double sum;
};

int main()
{
	int N, M, i, j, nameLen;
	char tmp[11];
	struct student stuTmp;
	scanf("%d %d", &N, &M);
	struct student* p = (struct student*)malloc(N * sizeof(struct student));
	
	if (p == NULL)
	{
		printf("Memory is not allocated\n");
		return -1;
	}
	 
	for (i = 0; i < N; i++)
	{
		scanf("%s", tmp); getchar();
		nameLen = strlen(tmp);
		p[i].name = (char*)malloc((nameLen + 1) * sizeof(char));
		if (p[i].name == NULL)
		{
			printf("Memory is not allocated\n");
			return -1;
		}
		strcpy(p[i].name, tmp);

		scanf("%d %d", &p[i].firstStage, &p[i].interview);
		p[i].sum = p[i].firstStage * 7 + p[i].interview * 3;
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - (i + 1); j++)
		{
			if (p[j].sum < p[j + 1].sum)
			{
				stuTmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = stuTmp;
			}
			else if (p[j].sum == p[j + 1].sum && p[j].firstStage < p[j + 1].firstStage)
			{
				stuTmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = stuTmp;
			}
			else if (p[j].sum == p[j + 1].sum && p[j].firstStage == p[j + 1].firstStage)
			{
				if (strcmp(p[j].name, p[j + 1].name) > 0)
				{
					stuTmp = p[j];
					p[j] = p[j + 1];
					p[j + 1] = stuTmp;
				}
			}
		}
	}

	stuTmp = p[M];
	for (i = M - 1; i < N - 1; i++)
	{
		if (p[i].sum == p[i + 1].sum && p[i].firstStage == p[i + 1].firstStage)
		{
			M++;
		}
		else break;
	}

	
	for (i = 0; i < M; i++)
	{
		printf("%s %d %d %.1f\n", p[i].name, p[i].firstStage, p[i].interview, p[i].sum / 10);
	}
	printf("%d\n", M);

	for (i = 0; i < M; i++) free(p[i].name);
	free(p);
	return 0;
}
*/
/*
5
His0tory
3Politics
2DonQuixote
Lapest9e
Chaos5
*/
/*
struct st {
	char* str;
	int cnt1;
	int cnt2;
	int num;
	int pos;
	int result;
};

int main()
{
	int N, i, j, k, wordLen, flag;
	struct st* arr = NULL, sttmp;
	char tmp[101];
	char compare[10] = { 'a', 'e', 'u', 'i', 'o', 'A', 'E', 'U', 'I', 'O' };
	scanf("%d", &N);
	
	arr = (struct st*)malloc(sizeof(struct st) * N);
	if (arr == NULL)
	{
		printf("Memory is not allocated\n");
		return -1;
	}

	for (i = 0; i < N; i++)
	{
		scanf("%s", tmp); getchar();
		wordLen = strlen(tmp);
		arr[i].str = (char*)malloc(sizeof(struct st) * (wordLen + 1));
		if (arr[i].str == NULL)
		{
			printf("Memory is not allocated\n");
			return -1;
		}
		strcpy(arr[i].str, tmp);
		arr[i].cnt1 = 0;
		arr[i].cnt2 = wordLen;

		for (j = 0; j < wordLen; j++)
		{
			if ((tmp[j] >= 'a' && tmp[j] <= 'z') || (tmp[j] >= 'A' && tmp[j] <= 'Z'))
			{
				flag = 1;
				for (k = 0; k < 10; k++)
				{
					if (tmp[j] == compare[k])
					{
						flag = 0;
						break;
					}
				}
				if (flag) arr[i].cnt1 += 1;
			}

			else if (tmp[j] >= '0' && tmp[j] <= '9')
			{
				arr[i].num = tmp[j] - '0';
				arr[i].pos = j + 1;
			}
		}

		arr[i].result = arr[i].cnt1 * arr[i].cnt2 * arr[i].num * arr[i].pos;
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - (i + 1); j++)
		{
			if (arr[j].result < arr[j + 1].result)
			{
				sttmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = sttmp;
			}
		}
	}

	for (i = 0; i < N; i++)
	{
		printf("%s %d\n", arr[i].str, arr[i].result);
	}

	for (i = 0; i < N; i++)
	{
		
		free(arr[i].str);
	}
	free(arr);

	return 0;
}
*/