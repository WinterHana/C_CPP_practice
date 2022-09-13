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
	// �Է� �� ����ó��
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

	// �迭 �̵� ���� �ٷ� �� �迭���� ����
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
	for (p = a; p < a + 6; p++) scanf("%c", p);		// a�� ���� �Է�
	strcopy(b, a);
	for (p = b; p < b + 6; p++) printf("%c", *p);	// ������ b�� ���
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
	int num = (x > y) ? y : x;		// �� ���� �� ���ؼ� �� ���ϱ�!
	*gcd = 1;

	// �ִ����� ���ϱ�
	for (i = 1; i <= num; i++)
	{
		if (x % i == 0 && y % i == 0)
		{
			*gcd = i;
		}
	}

	// �ּҰ���� ���ϱ�
	*lcm = (x * y) / *gcd;
}
*/

/*
// �迭�� �����Ͽ� �ص� ������, �迭�� �̵� ���� ã�ƾ���
int* mid(int x[]);		// �Լ� ���� ����� ������ ����

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
	for (p = x; p < x + N; p++)			// p�� �迭�� �־ �߳�
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
	scanf("%d %d %d", px, py, pz); // �ּҶ� & ���� �ʿ� ����
}

void output(int* px, int* py, int* pz)
{
	printf("%d %d %d", *px, *py, *pz); // �ּ� ���� ����Ʈ�ϴ°Ŵϱ� *������ ���
}
*/