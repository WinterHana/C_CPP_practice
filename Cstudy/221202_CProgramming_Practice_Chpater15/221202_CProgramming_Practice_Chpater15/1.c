#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
12
12345 15 86
12346 52 68
12347 55 90
12348 32 88
12349 22 12
12350 65 9
12351 1 100
12352 2 10
12353 50 90
12354 90 100
12345 15 86
12345 15 86
*/
typedef struct Student {
	int id;
	int exam_1;
	int exam_2;
	double sum;
}Student;

int main()
{
	Student* parr = NULL, tmp;
	int N, i, j, pass;
	scanf("%d", &N);
	if (N < 5) return -1;
	pass = N * 0.7;
	// printf("%d\n", pass);
	parr = (Student*)malloc(sizeof(Student) * N);
	if (parr == NULL) return -1;

	for (i = 0; i < N; i++)
	{
		scanf("%d %d %d", &parr[i].id, &parr[i].exam_1, &parr[i].exam_2);
		parr[i].sum = 0.4 * parr[i].exam_1 + 0.6 * parr[i].exam_2;
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - (i + 1); j++)
		{
			if (parr[j].sum < parr[j + 1].sum)
			{
				tmp = parr[j];
				parr[j] = parr[j + 1];
				parr[j + 1] = tmp;
			}
		}
	}

	for (i = 0; i < pass; i++)
	{
		printf("%d %.1f\n", parr[i].id, parr[i].sum);
	}

	for (i = pass; i < N; i++)
	{
		if (parr[i - 1].sum == parr[i].sum)
			printf("%d %.1f\n", parr[i].id, parr[i].sum);
		else
			break;
	}

	free(parr);

	return 0;
}
/*
typedef struct Movie {
	char name[100];
	int year;
}Movie;

void Swap(Movie *list, int i, int j);

int main()
{
	Movie list[100];
	int n, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &list[i].year); getchar();
		gets(list[i].name);
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - (i + 1); j++)
		{
			if (list[j].year > list[j + 1].year)
			{
				Swap(list, j, j + 1);
			}
			else if (list[j].year == list[j + 1].year && strcmp(list[j].name, list[j + 1].name) > 0)
			{
				Swap(list, j, j + 1);
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d, %s\n", list[i].year, list[i].name);
	}
}

void Swap(Movie* list, int i, int j)
{
	Movie tmp;
	tmp = list[i];
	list[i] = list[j];
	list[j] = tmp;
}
*/
/*
int main()
{
	int n, i, j, len, score_count, sum;
	char answer[80];
	scanf("%d", &n); getchar();
	for (i = 0; i < n; i++)
	{
		scanf("%s", answer);
		len = strlen(answer);
		score_count = 0;
		sum = 0;
		for (j = 0; j < len; j++)
		{
			if (answer[j] == 'O')
			{
				score_count++;
				sum += score_count;
			}
			else
			{
				score_count = 0;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
*/
/*
int main()
{
	int** parr = NULL;
	int col, row, i, j, flag_1, count;
	scanf("%d %d", &col, &row); getchar();

	parr = (int**)malloc(sizeof(int*) * row);
	if (parr == NULL) return -1;

	for (i = 0; i < row; i++)
	{
		parr[i] = (int*)malloc(sizeof(int) * col);
		if (parr[i] == NULL) return -1;
	}

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			scanf("%d", &parr[i][j]);
		}
	}

	for (i = 0; i < row; i++)
	{
		flag_1 = 0;
		count = 0;
		for (j = 0; j < col; j++)
		{
			if (flag_1 == 1)
			{
				if (parr[i][j] == 1) count++;
				else
				{
					printf("%d ", count);
					flag_1 = 0;
					count = 0; count++;
				}
			}
			else
			{
				if (parr[i][j] == 0) count++;
				else
				{
					printf("%d ", count);
					flag_1 = 1;
					count = 0; count++;
				}
			}
		}
		printf("%d", count);
		printf("\n");
	}

	return 0;
}
*/
/*
typedef struct POINT {
	int x;
	int y;
}POINT;

double distance(POINT* p1, POINT* p2);

int main()
{
	POINT a, b;
	double dir;
	scanf("%d %d", &a.x, &a.y); getchar();
	scanf("%d %d", &b.x, &b.y);

	dir = distance(&a, &b);
	printf("%.4f", dir);

	return 0;
}

double distance(POINT* p1, POINT* p2)
{
	int xlen, ylen;
	double result;
	xlen = p1->x - p2->x;
	ylen = p1->y - p2->y;
	
	xlen = pow(xlen, 2);
	ylen = pow(ylen, 2);
	printf("%d %d\n", xlen, ylen);

	result = sqrt(xlen + ylen);

	return result;
}
*/
/*
#include <limits.h>
#define ABS(s) ((s) > (0) ? (s) : (-s))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define LENGTH 6
int main()
{
	int num[LENGTH], max = 0, i, abs_num;

	for (i = 0; i < 6; i++)
	{
		scanf("%d", &num[i]);
	}

	for (i = 0; i < 6; i++)
	{
		abs_num = ABS(num[i]);
		max = MAX(max, abs_num);
	}

	for (i = 0; ABS(num[i]) != max; i++);

	printf("%d %d\n", num[i], max);

	return 0;
}
*/
// °³³ä ¿¬½À 1
/*
#include <stdio.h>
#define DEBUG

int main()
{
#ifdef DEBUG
	printf("Debug : %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
#else
	printf("Hello World");
#endif
	return 0;
}
*/
