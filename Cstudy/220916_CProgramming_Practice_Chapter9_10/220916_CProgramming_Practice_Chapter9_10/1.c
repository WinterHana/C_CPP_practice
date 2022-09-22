#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 3주차 복습 : 포인터
int* MAX(int*);
int* MIN(int*);

int main()
{
	int x[100] = { 0 };
	int i, * p, N, * p1, * p2;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		for (p = x; ; p++)
		{
			scanf("%d", p);
			if (*p == 0) break;
		}
		p1 = MAX(x);
		p2 = MIN(x);
		printf("%d %d\n", *p1, *p2);
	}

	return 0;
}

int* MAX(int* pstart)
{
	int max, * p, * maxp;
	max = *pstart;
	maxp = pstart;
	for (p = pstart; ; p++)
	{
		if (*p == 0) break;
		if (*p > max)
		{
			max = *p; maxp = p;
		}
	}
	return maxp;
}

int* MIN(int* pstart)
{
	int min, * p, * minp;
	min = *pstart;
	minp = pstart;
	for (p = pstart; ; p++)
	{
		if (*p == 0) break;
		if (*p < min)
		{
			min = *p; minp = p;
		}
	}
	return minp;
}
// 문자열 : 문제 2번
/*
int main()
{
	int N, i;
	char str[10];
	scanf("%d", &N);
	for (i = 0; N > 0; i++)
	{
		str[i] = N % 10 + '0'; // '0'을 같이 넣어야 문자열이 될 수 있다!
		N = N / 10;
	}
	str[i] = '\0';
	printf("%s", str);

	return 0;
}
*/
// 문자열 : 문제 1번
/*
#define SIZE 20
int main()
{
	int i = 0;
	char x[SIZE];
	scanf("%s", x);

	for (i = 0; x[i] != NULL; i++)
	{
		if (x[i] >= 'a' && x[i] <= 'z')
		{
			printf("%c", x[i]);
		}
	}
	return 0;
}
*/
// 문제 15번 : 이 방법 자체가 권장되는 방법은 아님
/*
void ABC(int* arr, int k);
int main()
{
	int arr[10] = { 0 };
	int i, * p;
	for (p = arr; p < arr + 10; p++)
	{
		scanf("%d", p);
	}

	for (p = arr, i = 0; p < arr + 10; i++, p++)
	{
		ABC(p, 10 - i);
	}

	for (p = arr; p < arr + 10; p++)
	{
		printf("%d ", *p);
	}

	return 0;
}

void ABC(int* arr, int k)
{
	int tmp, *i;
	for (i = arr + 1; i < arr + k; i++)
	{
		if (*arr < *i)
		{
			tmp = *i;
			*i = *arr;
			*arr = tmp;
		}
	}
}
*/
// 문제 14번
/*
int arr_to_k(int[], int[]);

int main()
{
	int N;
	int arr[100];
	int ans = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < N; i++)
	{
		ans += arr_to_k(&arr[0], &arr[i]);
	}

	printf("%d", ans);
	return 0;
}

int arr_to_k(int start[], int end[])
{
	int sum = 0;
	for (int* i = start; i <= end; i++)
	{
		sum += *i;
	}

	return sum;
}
*/
// 문제 13번
/*
int arrsum(int[], int[]);
int main()
{
	int N, S, E;
	int arr[100];
	scanf("%d %d %d", &N, &S, &E);
	for (int* i = arr; i < arr + N; i++)
	{
		scanf("%d", i);
	}
	int ans = arrsum(&arr[S], &arr[E]);

	printf("%d", ans);
	return 0;
}
int arrsum(int start[], int end[])
{
	int ans = 0;
	for (int* i = start; i <= end; i++)
	{
		ans += *i;
	}
	return ans;
}
*/
// 문제 12번
/*
void addArray(int[], int[], int[], int);

int main()
{
	int x[20], y[20], z[20], N;
	int* p, * pN = &N;

	scanf("%d", pN);
	for (p = x; p < x + N; p++) scanf("%d", p);
	for (p = y; p < y + N; p++) scanf("%d", p);
	addArray(x, y, z, N);
	for (p = z; p < z + N; p++) printf("%d ", *p);
}

void addArray(int x[], int y[], int z[], int N)
{
	int* xp, * yp, * zp;
	yp = y + N - 1;
	zp = z;
	for (xp = x; xp < x + N; xp++)
	{
		*zp = *xp + *yp;
		yp--;
		zp++;
	}
}
*/