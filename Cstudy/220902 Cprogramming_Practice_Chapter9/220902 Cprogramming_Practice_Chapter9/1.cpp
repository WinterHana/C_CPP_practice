#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
int main(void)
{
	int x, y, z;
	int* px, * py, * pz, * tmp;

	px = &x;
	py = &y;
	pz = &z;

	scanf("%d %d %d", px, py, pz);
	tmp = pz;
	pz = py;
	py = px;
	px = tmp;

	printf("%d %d %d", *px, *py, *pz);

	return 0;
}
*/

/*
int main(void)
{
	char x[20], *p;
	p = x;

	for (p = x; ; p++) {
		scanf("%c", p);
		if (*p == '#') break;
	}

	while (p > x) printf("%c", *(--p));

	return 0;
}
*/

/*
int main(void)
{
	int x[50], N, cnt = 0;
	int* p, * x_end, * p_N = &N, * p_cnt = &cnt;

	scanf("%d", p_N);

	x_end = x + *p_N;
	for (p = x; p < x_end; p++) scanf("%d", p);

	for (p = x; p < x_end; p++)
	{
		if (*p == 0) break;

		++(*p_cnt);
	}
	printf("%d", *p_cnt);

	return 0;
}
*/
/*
int main(void)
{
	int x[3] = { 0 };
	int median;
	int* pmedian = &median, * a, * b, * c;
	scanf("%d %d %d", x, x + 1, x + 2);
	a = x; b = x + 1; c = x + 2;

	if (*a > *b && *a > *c)
	{
		*pmedian = (*b > *c) ? *b : *c;
	}
	if (*b > *a && *b > *c)
	{
		*pmedian = (*a > *c) ? *a : *c;
	}
	if (*c > *a && *c > *b)
	{
		*pmedian = (*a > *b) ? *a : *b;
	}

	printf("%d\n", *pmedian);

	return 0;
}
*/

/*
int main(void)
{
	int x[5], rank[5] = { 0 };
	int* p, * q, * r;

	for (p = x, r= rank; p < x + 5; p++)
	{
		scanf("%d", p);
	}

	for (p = x, r = rank; p < x + 5; p++, r++)
	{
		for (q = x; q < x + 5; q++)
		{
			if (*p < *q) (*r)++;
		}
	}

	for (p = x, r = rank; p < x + 5; p++, r++)
		printf("%d = r%d ", *p, *r + 1);

	return 0;

}
*/
/*
int main(void)
{
	char x[10] = "", ch;
	char* p, * q;
	int cnt = 0, max = 0;

	for (p = x; p < x + 10; p++) scanf("%c", p);

	for (p = x; p < x + 10; p++)
	{
		cnt = 0;
		for (q = x; q < x + 10; q++)
		{
			if (*p == *q)
				cnt++;
		}

		if (cnt > max)
		{
			max = cnt;
			ch = *p;
		}
	}

	printf("%c %d", ch, max);
	return 0;
}
*/

/*
int main(void)
{
	int A[20], N = 20, M, cnt, i, temp;

	for (i = 0; i < N; i++)
	{
		A[i] = i + 1;
	}
	scanf("%d", &M);

	temp = A[N - 1];
	i = N - 1;
	cnt = M - 1;

	while (cnt != 0)
	{
		A[i] = A[i - 1];
		i--;
		cnt--;
	}
	A[i] = temp;
	for (i = 0; i < N; i++) printf("%d ", A[i]);

	return 0;
}
*/

#define SIZE 20
int main(void)
{
	int x[SIZE] = { 0 }, N, max, min, cnt = 0, j;
	int max_a[20] = { 0 }, min_a[20] = { 0 };

	scanf("%d", &N); // 개수
	for (int i = 0; i < N; i++) scanf("%d", &x[i]);

	for (int i = N - 1; i >= 0; i--) printf("%d ", x[i]);

	for (int i = 0; i < N; i += 3)
	{
		max = min = x[i]; // 초기화

		for (j = i; j <= i + 2 && j < N; j++)
		{
			if (x[j] > max) max = x[j];
			if (x[j] < min) min = x[j];
		}
		max_a[cnt] = max; min_a[cnt] = min;
		cnt++;
	}

	printf("\n");
	for (int i = 0; i < cnt; i++) printf("%d ", max_a[i]);

	printf("\n");
	for (int i = 0; i < cnt; i++) printf("%d ", min_a[i]);

	return 0;	
}
