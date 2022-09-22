#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 문제 14번
/*
int is_prime(int x);
int next_prime(int x);
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int num = next_prime(N);
		printf("%d ", num);
		N = num;
	}
	return 0;
}

int is_prime(int x)
{
	for (int i = 2; i < x; i++)
	{
		if (x % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int next_prime(int x)
{
	int num = x;
	while (1)
	{
		num++;
		if (is_prime(num)) break;
	}
	return num;
}
*/
// 문제 13번
/*
int count_3(int x);
int main()
{
	int num;
	int sum = 0;

	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		sum += count_3(i);
	}

	printf("%d", sum);
}
int count_3(int x)
{
	int count = 0;
	int num = x;
	while (num != 0)
	{
		if (num % 10 == 3)
		{
			count++;

		}
		num = num / 10;
	}

	return count;
}
*/
// 문제 12번
/*
void print_line(int x, int y, int z);

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		print_line(N - 1 - i, i, N - 1 - i);
	}
	return 0;
}

void print_line(int x, int y, int z)
{
	for (int i = 0; i < x; i++)
	{
		printf(" ");
	}
	for (int i = 0; i < 2 * y + 1; i++)
	{
		printf("*");
	}
	for (int i = 0; i < z; i++)
	{
		printf(" ");
	}
	printf("\n");
}
*/
// 문제 11번
/*
int x[3];
int count_strike(int a, int b, int c);
int count_ball(int a, int b, int c);

int main(void)
{
	
	int a, b, c;
	scanf("%d %d %d", &x[0], &x[1], &x[2]);

	while (1)
	{
		scanf("%d %d %d", &a, &b, &c);
		int strike = count_strike(a, b, c);
		int ball = count_ball(a, b, c);
		printf("%dS%dB\n", strike, ball);
		if (strike == 3) break;
	}
	return 0;
}

int count_strike(int a, int b, int c)
{
	int ans = 0;
	if (x[0] == a) ans++;
	if (x[1] == b) ans++;
	if (x[2] == c) ans++;
	return ans;
}

int count_ball(int a, int b, int c)
{
	int ans = 0;
	for (int i = 0; i < 3; i++)
	{
		if (x[i] == a || x[i] == b || x[i] == c)
		{
			ans++;
		}
	}
	int strike = count_strike(a, b, c);
	return ans - strike;
}
*/
// 문제 10번
/*
int N;
void die1(int x);
void die2(int x, int y);
void die3(int x, int y, int z);

int main(void)
{
	scanf("%d", &N);
	for (int i = 1; i <= 6; i++)
	{
		die1(i);
	}
	return 0;
}

void die1(int x)
{
	for (int i = 1; i <= 6; i++)
	{
		die2(x, i);
	}
}

void die2(int x, int y)
{
	for (int i = 1; i <= 6; i++)
	{
		die3(x, y, i);
	}
}

void die3(int x, int y, int z)
{
	if (x + y + z == N)
	{
		printf("%d %d %d\n", x, y, z);
	}
}
*/
// 문제 9번
void update_max(int x);
int max1 = 0, max2 = 0;

int main()
{
	int num;
	scanf("%d", &num);
	update_max(num);
	scanf("%d", &num);
	update_max(num);

	if (max1 < max2)
	{
		int tmp = max1;
		max1 = max2;
		max2 = tmp;
	}

	while (1)
	{
		scanf("%d", &num);
		if (num == 0) break;
		update_max(num);
	}

	printf("%d %d", max1, max2);
	return 0;
}

void update_max(int x)
{
	if (max1 == NULL) max1 = x;
	else if (max2 == NULL) max2 = x;
	else if (x > max1)
	{
		max2 = max1;
		max1 = x;
	}

	else if (x > max2)
	{
		max2 = x;
	}
}
// 문제 8번
/*
int fun2(int x, int a, int b, int c);

int main()
{
	int x, ans_1, ans_2;
	int a1, b1, c1;
	int a2, b2, c2;
	scanf("%d", &x);
	scanf("%d %d %d", &a1, &b1, &c1);
	scanf("%d %d %d", &a2, &b2, &c2);
	ans_1 = fun2(x, a1, b1, c1);
	ans_2 = fun2(ans_1, a2, b2, c2);
	printf("%d", ans_2);
	return 0;
}

int fun2(int x, int a, int b, int c)
{
	return a * x * x + b * x + c;
}
*/
// 문제 7번
/*
int fun2(int x, int a, int b, int c);

int main()
{
	int x, a, b, c;
	scanf("%d", &x);
	scanf("%d %d %d", &a, &b, &c);
	int ans = fun2(x, a, b, c);
	printf("%d", ans);
	return 0;
}

int fun2(int x, int a, int b, int c)
{
	return a * x * x + b * x + c;
}
*/
// 문제 6번
/*
int fun1(int x);

int main()
{
	int x;
	scanf("%d", &x);
	int ans = fun1(x);
	printf("%d", ans);
	return 0;
}

int fun1(int x)
{
	return 2 * x * x - 5 * x + 1;
}
*/
// 문제 5번
/*
void print_triangle(int x);

int main()
{
	int num;
	
	while (1)
	{
		scanf("%d", &num);
		if (num <= 0)
		{
			return 0;
		}
		print_triangle(num);
	} 
	return 0;
}

void print_triangle(int x)
{
	for (int i = 1; i <= x; i++)
	{
		for (int j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
*/
// 문제 4번
/*
void print_row1(int x);
void print_row2(int x);

int main()
{
	int x;
	scanf("%d", &x);

	for (int i = 0; i < x; i++)
	{
		if (i == 0 || i == x - 1)
		{
			print_row1(x);
		}
		else
		{
			print_row2(x);
		}
	}
}

void print_row1(int x)
{
	for (int i = 0; i < x; i++)
	{
		printf("%d", x);
	}
	printf("\n");
}

void print_row2(int x)
{
	for (int i = 0; i < x; i++)
	{
		if (i == 0 || i == x - 1)
		{
			printf("%d", x);
		}
		else
		{
			printf(" ");
		}
	}
	printf("\n");
}
*/
// 문제 3번
/*
int sum(int n);

int main()
{
	int num;
	int ans = 0;
	scanf("%d", &num);

	for (int i = 1; i <= num; i++)
	{
		ans = ans + sum(i);
	}

	printf("%d", ans);
}

int sum(int n)
{
	int sum = n * (n + 1) / 2;
	return sum;
}
*/
// 문제 2번
/*
int sum(int n);

int main()
{
	int A, B;
	int ans;
	scanf("%d", &A); scanf("%d", &B);

	ans = sum(B) - sum(A - 1);

	printf("%d", ans);
}

int sum(int n)
{
	int sum = n * (n + 1) / 2;
	return sum;
}
*/
// 문제 1번
/*
int add(int x, int y);

int main()
{
	int num = NULL;
	int sum = 0;
	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		sum = add(sum, i);
	}

	printf("%d", sum);
	return 0;
}

int add(int x, int y)
{
	return x + y;
}
*/