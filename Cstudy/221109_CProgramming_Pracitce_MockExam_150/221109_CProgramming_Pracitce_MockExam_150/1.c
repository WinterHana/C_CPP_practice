#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
I have a pen. I have an applepen. PPAP.
pen
mouse

I have a pen. I have an applepen. PPAP.
have
a

Sequence GTCGTCG
GTCG
CAGC
*/
// 巩力 5 - 1
void replaceWord(char* str, char * B, char * C, int i);

int main()
{
	char str[100];
	char B[10], C[10];
	char result[250], *pt;
	int i = 0, blen, clen;
	gets(str);
	scanf("%s", B);
	scanf("%s", C);
	blen = strlen(B);
	clen = strlen(C);
	
	while (str[i] != '\0')
	{
		if (strncmp(&str[i], B, blen) == 0)
		{
			replaceWord(str, B, C, i);
			i += clen;
		}
		else
		{
			i++;
		}
	}

	printf("%s\n", str);
	return 0;
}

void replaceWord(char* str, char* B, char* C, int n)
{
	int blen = strlen(B);
	int clen = strlen(C);
	int stringlen = strlen(str);
	char* pt;
	int i = 0, gap;

	if (blen == clen)
	{
		for (pt = str + n; pt < str + n + clen; pt++)
		{
			*(pt) = *(C + i);
			i++;
		}
	}
	else if (blen < clen)
	{
		gap = clen - blen;
		for (pt = str + stringlen; pt > str + n + blen - 1; pt--)
		{
			*(pt + gap) = *pt;
		}
		
		for (pt = str + n; pt < str + n + clen; pt++)
		{
			*(pt) = *(C+i);
			i++;
		}

	}
	else if (blen > clen)
	{
		gap = blen - clen;
		for (pt = str + n; pt < str + n + clen; pt++)
		{
			*(pt) = *(C + i);
			i++;
		}

		for (pt = str + n + clen + gap; pt <= str + stringlen; pt++)
		{
			*(pt - gap) = *pt;
		}
	}

	return n + clen;
}
// 巩力 4 - 2
/*
int input(int* p);
int* sel_next(int* p);
int number(int* p, int* q);

int main()
{
	int x[100];
	int i, N, result;
	int* pt, * last;
	
	N = input(x);
	pt = x;
	do {
		last = sel_next(pt);
		result = number(pt, last);
		printf("%d\n", result);
		pt = last;
	} while (*(pt + 1) != -1);

	return 0;
}

int input(int* p)
{
	int i = 0;
	int flag = 1;
	while (i < 100 && flag == 1)
	{
		scanf("%d", p + i);
		if (*(p + i) == -1) flag = 0;
		i++;
	}

	return i;
}

int* sel_next(int* p)
{
	int* pt = p;
	int flag = (*pt < *(pt + 1)) ? 1 : 0;

	if (flag)
	{
		for (pt = p; *(pt + 1) != -1; pt++)
		{
			if (*(pt) < *(pt + 1))
				continue;
			else
				break;
		}
	}
	else
	{
		for (pt = p; *(pt + 1) != -1; pt++)
		{
			if (*(pt) > *(pt + 1))
				continue;
			else
				break;
		}
	}

	return pt;
}

int number(int* p, int* q)
{
	int count = 1;
	int result = 0;
	int* pt;
	for (pt = q; pt >= p; pt--)
	{
		result += (*pt) * count;
		count *= 10;
	}

	return result;
}
*/
// 巩力 4 - 1
/*
1 2 4 6 7 4 3 -1
1

1 2 3 4 5 4 3 -1
4
*/
/*
int input(int* p);
int* sel_next(int* p, int N, int M);
int number(int* p, int* q);

int main()
{
	int x[100];
	int i, M, N, result;
	int* pt, *last;
	N = input(x);

	scanf("%d", &M);
	last = sel_next(x, N, M);

	result = number(x + M, last);

	printf("%d\n", result);

	return 0;
}

int input(int* p)
{
	int i = 0;
	int flag = 1;
	while (i < 100 && flag == 1)
	{
		scanf("%d", p + i);
		if (*(p + i) == -1) flag = 0;
		i++;
	}

	return i;
}

int* sel_next(int* p, int N, int M)
{
	int* pt;
	for (pt = p + M; pt < p + N; pt++)
	{
		if (*(pt) < *(pt + 1))
			continue;
		else
			break;
	}

	return pt;
}

int number(int* p, int* q)
{
	int count = 1;
	int result = 0;
	int* pt;
	for (pt = q; pt >= p; pt--)
	{
		result += (*pt) * count;
		count *= 10;
	}

	return result;
}
*/
// 巩力 3 - 1
/*
7 3
Aaaaa 75 85
Bbbbb 86 77
Ccccc 94 82
Ddddd 78 70
Eeeee 65 85
Fffff 83 90
Ggggg 90 70
*/
/*
struct person {
	char name[11];
	int exam;
	int interview;
	double total;
};
void swap(struct person* p, struct person *q);
void inputInfo(struct person* people, int N);

int main()
{
	int N, M, i, j;
	struct person people[100];
	scanf("%d %d", &N, &M);
	inputInfo(people, N);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - (i + 1); j++)
		{
			if (people[j].total < people[j + 1].total)
			{
				swap(&people[j], &people[j + 1]);
			}
		}
	}

	for (i = 0; i < M; i++)
	{
		printf("%s %.1f\n", people[i].name, people[i].total);
	}

	return 0;
}

void swap(struct person* p, struct person* q)
{
	struct person tmp;
	tmp = *p;
	*p = *q;
	*q = tmp;
}

void inputInfo(struct person* people, int N)
{
	int i;
	for (i = 0; i < N; i++)
	{
		scanf("%s %d %d", people[i].name, &people[i].exam, &people[i].interview);
		people[i].total = 0.8 * people[i].exam + 0.2 * people[i].interview;
	}
}
*/
// 巩力 2 - 1
/*
lee1 2017102656 A
lee2 2018111823 A
park 2018059961 A
choi 2018010101 F
lee3 2019565656 B
park
*/
/*
struct student {
	char name[10];
	char id[11];
	char avg;
};

void inputInfo(struct student* students, int n);
void findingStudent(struct student* students, char name[], int n);

int main()
{
	struct student students[5];
	char name[10];
	inputInfo(students, 5);
	scanf("%s", name);
	findingStudent(students, name, 5);
	return 0;
}

void inputInfo(struct student* students, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%s %s %c", students[i].name, students[i].id, &students[i].avg);
	}
}

void findingStudent(struct student* students, char name[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (strcmp(students[i].name, name) == 0)
		{
			printf("%s %c", students[i].id, students[i].avg);
			break;
		}
	}
}
*/
// 巩力 1 - 1
/*
* simple is best
* i am a boy
*/
/*
int main()
{
	char str[200], saveWord[20][200], tmp[200];
	char* pt;
	int stringLen, saveCount, i, j;
	gets(str);

	stringLen = strlen(str);
	saveCount = 0;
	pt = str;
	for (i = 0; i < stringLen + 1; i++)
	{
		if (str[i] == '\0' || str[i] == ' ')
		{
			str[i] = '\0';
			strcpy(saveWord[saveCount], pt);
			printf("%s\n", saveWord[saveCount]);
			saveCount++;
			pt = str + i + 1;
		}
	}	

	for (i = 0; i < saveCount; i++)
	{
		for (j = 0; j < saveCount - (i + 1); j++)
		{
			if (strcmp(saveWord[j], saveWord[j + 1]) > 0)
			{
				strcpy(tmp, saveWord[j]);
				strcpy(saveWord[j], saveWord[j + 1]);
				strcpy(saveWord[j + 1], tmp);
			}
		}
	}

	for (i = 0; i < saveCount; i++)
	{
		printf("%s ", saveWord[i]);
	}
	printf("\n");

	return 0;
}
*/