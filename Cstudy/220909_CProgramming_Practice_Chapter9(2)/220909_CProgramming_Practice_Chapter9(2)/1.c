#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main(void)
{
	int a[100], i, cnt = 0, n;
	while (1)
	{
		scanf("%d", &n);
		if (n < 0) break;

		for (i = 0; i < cnt; i++)
		{
			if (n == a[i])
			{
				printf("0");
				break;
			}
		}

		if (cnt == i) {
			a[cnt++] = n;
			printf("1");
		}
	}
}
/*
#define SIZE 100
#define MAX(A, B) ((A>B)?A:B)


void main(void)
{
	int x[SIZE] = { 0 };
	int N;
	// 입력 및 예외처리
	scanf("%d", &N);
	if (N < 0 || N > 100) {
		printf("ERROR"); return 0;
	}
	else 
	{
		for (int i = 0; i < N; i++) 
		{
			scanf("%d", &x[i]);
			if (x[i] < 0 || x[i] > 100)
			{
				printf("ERROR"); return 0;
			}
		}
	}

	// 배열 이동 없이 바로 그 배열에서 쓰기
	int i, j;
	while (N > 1)
	{
		for (i = 0, j = 0; i < N; i += 2, j++)
		{
			if (i + 1 < N)
				x[j] = MAX(x[i], x[i + 1]);
			else
				x[j] = x[i];
			printf("%d ", x[j]);
		}
		printf("\n");
		N = j;
	}

	return 0;
}
*/

/*
void strcopy(char a[], char b[]);

int main(void)
{
	char a[7] = "", b[7] = "";
	char* p;
	for (p = a; p < a + 6; p++) scanf("%c", p);		// a에 먼저 입력
	strcopy(b, a);
	for (p = b; p < b + 6; p++) printf("%c", *p);	// 복사한 b에 출력
	return 0;
}

void strcopy(char b[], char a[])
{
	char * p1, *p2;
	p2 = b;
	for (p1 = a; p1 < a + 6; p1++, p2++)
	{
		*p2 = *p1;
	}
}
*/

/*
void gcdlcm(int, int, int*, int*);

int main(void)
{
	int a, b, gcd, lcm;
	scanf("%d %d", &a, &b);
	gcdlcm(a, b, &gcd, &lcm);
	printf("%d %d \n", gcd, lcm);

	return 0;
}

void gcdlcm(int x, int y, int* gcd, int* lcm)
{
	int i;
	int num = (x > y) ? y : x;		// 더 작은 수 구해서 다 비교하기!
	*gcd = 1;

	// 최대공약수 구하기
	for (i = 1; i <= num; i++)
	{
		if (x % i == 0 && y % i == 0)
		{
			*gcd = i;
		}
	}

	// 최소공배수 구하기
	*lcm = (x * y) / *gcd;
}
*/

/*
// 배열을 정렬하여 해도 되지만, 배열의 이동 없이 찾아야함
int* mid(int x[]);		// 함수 원형 써줘야 감점이 없음

int main(void)
{
	int x[3];
	int* p, * pr;
	for (p = x; p < x + 3; p++)
		scanf("%d", p);

	pr = mid(x);
	printf("%d ", *pr);

	return 0;
}

int* mid(int x[])
{
	int* a, * b, * c, *p = x;
	a = x; b = x + 1; c = x + 2;
	if (*a >= *b && *a >= *c)
	{
		p = (*b > *c) ? b : c;
	}
	else if (*b >= *a && *b >= *c)
	{
		p = (*a > *c) ? a : c;
	}
	else if (*c >= *a && *c >= *b)
	{
		p = (*a > *b) ? a : b;
	}

	return p;
}
*/

/*
void swap(int*, int*);

int main(void)
{
	int x[50], N, * p, a, b;
	scanf("%d", &N);
	for (p = x; p < x + N; p++)			// p에 배열을 넣어서 했네
		scanf("%d", p);
	scanf("%d %d", &a, &b);
	
	// swap(&x[a], &x[b]);
	swap(x + a, x + b);
	for (p = x; p < x + N; p++) printf("%d ", *p);
	return 0;
}

void swap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
*/

/*
void input(int*, int*, int*);
void output(int*, int*, int*);

int main(void)
{
	int x, y, z;
	input(&x, &y, &z);
	output(&x, &y, &z);
	return 0;
}

void input(int* px, int* py, int* pz)
{
	scanf("%d %d %d", px, py, pz); // 주소라서 & 해줄 필요 없음
}

void output(int* px, int* py, int* pz)
{
	printf("%d %d %d", *px, *py, *pz); // 주소 값을 프린트하는거니까 *연산자 사용
}
*/