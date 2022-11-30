#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 14장 문제 2번

int main()
{
	FILE* inputF, * outputF;
	char data[20];
	int i;

	inputF = fopen("test1.txt", "r");
	if (inputF == NULL)
	{
		printf("File open error\n");
		return -1;
	}

	fgets(data, sizeof(data), inputF);

	int len = strlen(data);

	for (i = 0; i < len; i++)
	{
		if ('A' <= data[i] && data[i] <= 'Z')
			data[i] += ('a' - 'A');
		else if ('a' <= data[i] && data[i] <= 'z')
			data[i] -= ('a' - 'A');
	}

	outputF = fopen("test2.txt", "w");

	if (outputF == NULL)
	{
		printf("File open error\n");
		return -1;
	}

	fputs(data, outputF);

	fclose(inputF);
	fclose(outputF);

	return 0;
}

// 14장 문제 1번
/*
int main()
{
	FILE* fp = NULL;
	int in, cnt = 0, sum = 0;
	float avg = 0.0f;

	fp = fopen("data.txt", "w");
	if (fp == NULL)
	{
		printf("File open error\n");
		return 0;
	}

	scanf("%d", &in);

	while (!feof(stdin)) {			// 키보드 입력 체크
		fprintf(fp, "%d\n", in);
		scanf("%d", &in);
		// getchar();
	}

	fclose(fp);

	fp = fopen("data.txt", "r");
	if (fp == NULL)
	{
		printf("File open error\n");
		exit(1);
	}
	

	fscanf(fp, "%d", &in);
	while (!feof(fp)) {				// 파일 체크
		cnt++;
		sum += in;
		fscanf(fp, "%d", &in);
	}

	avg = (float)sum / cnt;
	fclose(fp);
	printf("%d\n%d\n%.2f", cnt, sum, avg);

	return 0;
}
*/

// 문제 8번
/*
int add(int, int);
int sub(int, int);
int multiply(int, int);

int main()
{
	int num1, num2;
	int result1, result2, result3;
	int (*handle[3]) (int, int) = { add, sub, multiply };
	scanf("%d %d", &num1, &num2);

	result1 = handle[0](num1, num2);
	result2 = handle[1](num1, num2);
	result3 = handle[2](num1, num2);

	printf("%d %d %d", result1, result2, result3);

	return 0;
}

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int multiply(int a, int b)
{
	return a * b;
}
*/
// 문제 7번
/*
int sum(int a, int b)
{
	return a + b;
}

int main()
{
	int z, x, y;
	void* pz;
	int (*psum) (int, int);

	scanf("%d" ,&z);
	scanf("%d %d", &x, &y);

	pz = &z;
	psum = &sum;

	printf("%d\n", *((int*)pz));
	printf("%d\n", psum(x, y));

	return 0;
}
*/
// 문제 6번
/*
void ABC(int(*p)[20], int k1, int k2);

int main()
{
	int arr[20][20] = { 0 };
	int N, i, j;
	scanf("%d", &N);

	ABC(arr, N, N);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}

void ABC(int(*p)[20], int k1, int k2)
{
	int i, j;

	for (i = 0; i < k1; i++)
	{
		for (j = 0; j < k2; j++)
		{
			*(* (p + i) + j) = i + j;		// p[i][j] = i + j;
		}
	}
}
*/
// 문제 5번
/*
void pswap(int **ppx, int **ppy);

int main()
{
	int x, y;
	int* px, * py;

	px = &x;
	py = &y;
	scanf("%d %d", &x, &y);

	pswap(&px, &py);
	printf("%d %d\n", *px, *py);

	return 0;
}

void pswap(int** ppx, int** ppy)
{
	int *temp;			// 포인터 변수로 교환 *ppx, *ppy에는 주소가 들어 있으니까
	temp = *ppx;
	*ppx = *ppy;
	*ppy = temp;
}
*/
// 문제 4번
/*
int main()
{
	int a, b, c, d;
	unsigned int r;

	scanf("%d %d %d %d", &a, &b, &c, &d);
	r = (a << 24) + (b << 16) + (c << 8) + d;

	printf("%d", r);

	return 0;
}
*/
