#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// 실습 문제 1번 a e u i o
struct st {
	char* str;
	int cnt;
};
int count_c(char* s);
int main()
{
	char temp1[100];
	int N, i, j;
	struct st* s = NULL, temp2;

	scanf("%d", &N); getchar();
	s = (struct st*)malloc(N * sizeof(struct st));

	if (s == NULL)
	{
		printf("Not enough memory!");
		return -1;
	}

	for (i = 0; i < N; i++)
	{
		gets(temp1);
		s[i].str = (char*)malloc(strlen(temp1) + 1);
		if (s[i].str == NULL) 
		{
			printf("Not enough memory!");
			return -1;
		}

		strcpy(s[i].str, temp1);
		s[i].cnt = count_c(s[i].str);
	}

	for (i = 0; i < N - 1; i++) 
	{
		for (j = 0; j < N - i - 1; j++)
		{
			if (s[j].cnt < s[j + 1].cnt) 
			{
				temp2 = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp2;
			}
		}
	}

	for (i = 0; i < N; i++)
	{
		printf("%s\n", s[i].str);
	}

	for (i = 0; i < N; i++)
	{
		free(s[i].str);
	}
	free(s);

	return 0;
}

int count_c(char* s)
{
	int count = 0;
	char com[10] = { 'a', 'i', 'u', 'e', 'o', 'A', 'I', 'U', 'E','O'};
	int flag = 1;
	for (int i = 0; i < strlen(s); i++)
	{
		flag = 1;
		for (int j = 0; j < 10; j++)
		{
			if (s[i] == com[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag) count++;
	}

	return count;
}
// 문제 7번
/*
int main()
{
	int row, col, i, j, cnt = 0;
	char** pa = NULL;

	scanf("%d %d", &col, &row);
	pa = (char**)malloc(row * sizeof(char*));
	for (i = 0; i < row; i++) pa[i] = (char*)malloc(col * sizeof(char));

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (cnt / 26 % 2 == 0) pa[i][j] = 'a' + (cnt % 26);
			else pa[i][j] = 'A' + (cnt % 26);
			cnt++;
		}
	}

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++) printf("%c ", pa[i][j]);
		printf("\n");
	}

	for (i = 0; i < row; i++) free(pa[i]);
	free(pa);

	return 0;
}
*/
// 문제 6번
/*
int main()
{
	int n, count = 0;;
	char* str, *p;
	scanf("%d", &n);
	str = (char*)malloc((n + 1) * sizeof(char));
	scanf("%s", str);

	for (p = str; p < str + n; p++)
	{
		if (strncmp(p, "cat", 3) == 0)
		{
			count++;
		}
	}

	printf("%d\n", count);

	free(str);

	return 0;
}
*/
// 문제 5번 : round #1 정렬
/*
int main()
{
	int* arr;
	int n;
	int i, tmp;
	scanf("%d", &n);

	arr = (int*)malloc(n * sizeof(int));

	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < n - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
		}
	}

	for (i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}

	free(arr);

}
*/

// 버블정렬
/*
* for(int i = 0; i < n - 1; i++)
*		for(int j = 0; j < n - i - 1; j++)
*				(조건에 맞춘 것)
*					swap(a, b);
*/

// 문제 4번
/*
struct student
{
	char name[7];
	int kor, eng, math;
	double avg;
};

int main()
{
	struct student* x = NULL, * p;
	int n, sum = 0;
	scanf("%d", &n);

	x = (struct student*)malloc(n * sizeof(struct student));
	if (x == NULL) {
		printf("not enough memory!");
		return 0;
	}
	
	for (p = x; p < x + n; p++) {
		scanf("%s", p->name);
		scanf("%d %d %d", &p->kor, &p->eng, &p->math);
		sum = p->kor + p->eng + p->math;
		p->avg = sum / 3.0;
	}

	for (p = x; p < x + n; p++) {
		printf("%s %.1f ", p->name, p->avg);
		if (p->kor >= 90 || p->eng >= 90 || p->math >= 90)
		{
			printf("GREAT ");
		}

		if (p->kor < 70 || p->eng < 70 || p->math < 70)
		{
			printf("BAD");
		}

		printf("\n");
	}

	free(x);

	return 0;
}
*/

// 문제 3번
/*
int main()
{
	int N;
	char* str, ch1, ch2, *p;
	int ch1Num = 0, ch2Num = 0;
	scanf("%d", &N);

	str = (char*)malloc((N+1) * sizeof(char));

	if (str == NULL)
	{
		printf("Insufficient Memory, Exiting...\n");
		return 0;
	}

	scanf("%s", str);
	getchar();
	scanf("%c %c", &ch1, &ch2);

	for (p = str; p < str + N; p++)
	{
		if (*p == ch1) ch1Num++;
		if (*p == ch2) ch2Num++;
	}

	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == ch1) ch1Num++;
		if (str[i] == ch2) ch2Num++;
	}
	printf("%d %d", ch1Num, ch2Num);

	free(str);

	return 0;
}
*/
// 문제 2번
/*
int main()
{
	float* arr = NULL, *p;
	int n;
	float max;

	scanf("%d", &n);
	arr = (float*)malloc(n * sizeof(float));

	if (arr == NULL) {
		printf("Insufficient Memory, Exiting...\n");
		return 0;
	}

	for (p = arr; p < arr + n; p++)
	{
		scanf("%f", p);
	}

	max = INT_MIN;
	for (p = arr; p < arr + n; p++)
	{
		if (max < *p)
		{
			max = *p;
		}
	}

	printf("%.2f", max);

	free(arr);

	return 0;
}
*/

// 문제 1번
/*
int main()
{
	int *p = NULL;
	int n, i;
	int sum = 0;

	scanf("%d", &n);
	p = (int*)malloc(n * sizeof(int));

	if (p == NULL) {
		printf("Insufficient Memory, Exiting...\n");
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &p[i]);
		sum += p[i];
	}

	printf("%d", sum);

	free(p);

	return 0;
}
*/
