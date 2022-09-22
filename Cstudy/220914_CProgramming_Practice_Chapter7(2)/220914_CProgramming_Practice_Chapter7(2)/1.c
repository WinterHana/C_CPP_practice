#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <ctype.h>
/*
* 기초 문제 모음
*/

// 문제 16번
int main()
{
	int N;
	char x[10];
	int num[10];
	scanf("%d", &N);
	getchar();

	for (int i = 0; i < N; i++)
	{
		scanf("%c", &x[i]);
	}
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
	}

	for (int i = 0; i < N; i++)
	{
		printf("x[%d%%%d] = x[%d] = %c \n", num[i], N, num[i] % N, x[num[i] % N]);
	}

	return 0;
}
// 문제 15번
/*
int main()
{
	char arr[10];
	char ans[10];
	int size = 0;
	int flag = 1;
	for (int i = 0; i < 10; i++)
	{
		scanf("%c", &arr[i]);
	}

	for (int i = 0; i < 10; i++)
	{
		flag = 1;
		for (int j = 0; j < 10; j++)
		{
			if (arr[i] == arr[j] && i != j)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			ans[size] = arr[i];
			size++;
		}
	}

	for (int i = 0; i < size; i++)
	{
		printf("%c ", ans[i]);
	}
	return 0;
}
*/
// 문제 14번
/*
int main()
{
	char x[10], y[10];

	for (int i = 0; i < 10; i++)
	{
		scanf("%c", &x[i]);
	}
	getchar();

	for (int i = 0; i < 10; i++)
	{
		scanf("%c", &y[i]);
	}
	getchar();

	for (int i = 0; i < 10; i++)
	{
		printf("%c %c ", x[i], y[i]);
	}

	return 0;
}
*/
// 문제 13번
/*
int main()
{
	char arr[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%c", &arr[i]);
		if (isupper(arr[i]))
		{
			printf("%c ", arr[i]);
		}
	}
	return 0;
}
*/

// 문제 12번
/*
int main()
{
	float arr[10];
	int higher;
	for (int i = 0; i < 10; i++)
	{
		scanf("%f", &arr[i]);
	}

	for (int i = 0; i < 10; i++)
	{
		higher = 0;
		for (int j = 0; j < 10; j++)
		{
			if (arr[i] > arr[j]) higher++;
		}
		printf("%d ", higher);
	}
	return 0;
}
*/
// 문제 11번
/*
int main()
{
	float arr[10];
	float min;
	for (int i = 0; i < 10; i++)
	{
		scanf("%f", &arr[i]);

	}

	min = arr[0];
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}

	printf("%.1f", min);

	return 0;
}
*/
// 문제 10번
/*
int main()
{
	float arr[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%f", &arr[i]);
		if (arr[i] > 0)
		{
			printf("%.1f ", arr[i]);
		}
	}

	return 0;
}
*/
// 문제 9번
/*
int main()
{
	int arr[10];
	int N;
	int M = 0;
	int index = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = N; i > 0; i--)
	{
		M += arr[index] * pow(10, i - 1);
		index++;
	}

	printf("%d", M);

	return 0;
}
*/
// 문제 8번
/*
int main()
{
	int N;
	int arr[10];
	int i = 0;
	scanf("%d", &N);

	while(1)
	{
		arr[i] = N % 10;
		printf("%d ", arr[i]);
		if (N / 10 == 0) break;
		N = N / 10;
		i++;
	}
	return 0;
	
}
*/
// 문제 7번
/*
int main()
{
	int arr[10];
	int ans[10];
	int size = 0;
	int flag = 1;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < 10; i++)
	{
		flag = 1;
		for (int j = 0; j < 10; j++)
		{
			if (arr[i] == ans[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			ans[size] = arr[i];
			size++;
		}
	}

	for (int i = 0; i < size; i++)
	{
		printf("%d ", ans[i]);
	}
	return 0;
}
*/
// 문제 6번
/*
int main()
{
	int arr[10];
	int count;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < 10; i++)
	{
		count = 0;
		for (int j = 0; j < 10; j++)
		{
			if (arr[i] < arr[j])
			{
				count++;
			}
		}
		printf("%d ", count);
	}

	return 0;
}
*/
// 문제 5번
/*
int main()
{
	int arr[10];
	int max;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}

	max = arr[0];
	for (int i = 1; i < 10; i++)
	{
		if (max < arr[i]) max = arr[i];
	}

	printf("%d", max);
	return 0;
}
*/
// 문제 4번
/*
int main()
{
	int arr1[10], arr2[10], sum[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr1[i]);
	}

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr2[i]);
	}

	for (int i = 0; i < 10; i++)
	{
		sum[i] = arr1[i] + arr2[9 - i];
		printf("%d ", sum[i]);
	}

	return 0;
}
*/
// 문제 3번
/*
int main()
{
	int arr1[10], arr2[10], sum[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr1[i]);
	}

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr2[i]);
		sum[i] = arr1[i] + arr2[i];
		printf("%d ", sum[i]);
	}

	return 0;
}
*/
// 문제 2번
/*
int main()
{
	int arr[10];
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	printf("%d", sum);

	return 0;
}
*/
// 문제 1번
/*
int main()
{
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
		if (arr[i] % 2 == 0) printf("%d ", arr[i]);
	}

	return 0;
}
*/