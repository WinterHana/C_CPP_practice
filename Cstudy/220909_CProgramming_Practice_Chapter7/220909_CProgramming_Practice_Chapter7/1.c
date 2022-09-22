#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ������ ���� 6��
void prt(int x[][5], int N);

int main()
{
	int N;
	int arr[20][5];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	
	prt(arr, N);

	return 0;
}

void prt(int x[][5], int N)
{
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d ", x[i][j]);
		}
		printf("\n");
	}
}
// ������ ���� 5��
/*
int arrsum(int x[], int S, int E);

int main()
{
	int arr[100];
	int N, S, E;
	scanf("%d", &N); scanf("%d", &S); scanf("%d", &E);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("%d", arrsum(arr, S, E));
	return 0;
}

int arrsum(int x[], int S, int E)
{
	int sum = 0;
	for (int i = S; i <= E; i++)
	{
		sum += x[i];
	}
	return sum;
}
*/
// ������ ���� 3��
/*
int main()
{
	int index;
	char x[6][5] = { {'Z', 'E', 'R', 'O', '-'},
		{'O', 'N', 'E', '-', '-'},
		{'T', 'W', 'O', '-', '-'},
		{'T', 'H', 'R', 'E', 'E'}, 
		{'F', 'O', 'U', 'R', '-'},
		{'F', 'I', 'V', 'E', '-'} 
	};

	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &index);
		for (int j = 0; j < 5; j++)
		{
			printf("%c", x[index][j]);
		}
		printf("\n");
	}

	return 0;
}
*/
// ������ ���� 2��
/*
int main()
{
	int arr[3][2];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", arr[i][0] + arr[i][1]);
	}

	return 0;
}
*/
// ������ ���� 1��
/*
int main()
{
	int arr[3][3];
	int sum = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < 3; i++)
	{
		sum += arr[i][i];
	}

	printf("%d", sum);

	return 0;
}
*/
// ���� 10��
/*
int main()
{
	int x[5], rank[5] = { 0 };
	int* p, * q, * r;

	for (p = x, r = rank; p < x + 5; p++)
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
// ���� 9��
/*
int main()
{
	int arr[5];
	int tmp;
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = tmp;
			}
		}
	}


	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", arr[i]);
	}

	return 0;
}
*/
// ���� 8��
/*
int main()
{
	int arr[5];
	int tmp;
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < 4; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			tmp = arr[i + 1];
			arr[i + 1] = arr[i];
			arr[i] = tmp;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", arr[i]);
	}
	
}
*/
// ���� 7��
/*
int main() {
	int x[10], in[10] = { 0 };
	int cnt = 0;
	for (int i = 0; i < 10; i++) scanf("%d", &x[i]);

	for (int i = 0; i < 10; i++) {
		if (in[i] > 0) continue;
		for (int j = 0; j < 10; j++) {
			if (x[j] == x[i]) {
				cnt++;
				in[j] += 1;
			}
		}

		printf("%d %d\n", x[i], cnt);
		cnt = 0;
	}
	return 0;
}

int main(void)
{
	int arr[10] = { 0 };
	int ans[10] = { 0 };
	int size = 0;
	int flag = 1;
	int count = 0;

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < 10; i++)
	{
		flag = 1;
		// ��ȸ�ؼ� �ߺ��Ǵ� �� ã��
		for (int j = 0; j < 10; j++)
		{
			if (arr[i] == ans[j])
			{
				flag = 0;
			}
		}
		// �迭�� �ֱ�
		if (flag == 1)
		{
			ans[size] = arr[i];
			size++;
		}

	}

	// ���
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (ans[i] == arr[j])
			{
				count++;
			}
		}
		printf("%d %d\n", ans[i], count);
		count = 0;
	}

	return 0;
}
*/
/*
// ���� 6��
int main(void)
{
	char quiz[3] = { 0 };
	char ans[3] = { 0 };
	char tmp;
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		scanf("%c", &quiz[i]);
	}

	getchar();

	for (int i = 0; i < 5; i++)
	{
		count = 0;
		scanf("%c", &tmp);
		getchar();

		// �迭 �� Ȯ��
		for (int j = 0; j < 3; j++)
		{
			if (quiz[j] == tmp)
			{
				ans[j] = tmp;
			}
		}

		// ���
		for (int k = 0; k < 3; k++)
		{
			if (quiz[k] == ans[k])
			{
				printf("%c ", quiz[k]);
			}	
			else
			{
				printf("_ ");
			}
		}

		// �� ���߸� ������
		for (int n = 0; n < 3; n++)
		{
			if (quiz[n] == ans[n]) count++;
		}
		
		if (count == 3) return 0;
	}
	return 0;
}
*/
/*
// ���� 5��
int main(void)
{
	char arr[5];

	for (int i = 0; i < 5; i++)
	{
		scanf("%c", &arr[i]);
	}


	for (int i = 0; i < 5; i++)
	{
		for (int j = 5 - i; j < 5; j++)
		{
			if (j < 5) printf("%c", arr[j]);
		}

		for (int k = 0; k < 5 - i; k++)
		{
			printf("%c", arr[k]);
		}
		printf("\n");
	}

	return 0;
}
*/
/*
int main(void)
{
	// ���� 4��
	int arr[10];
	int one = 0, two = 0, three = 0;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < 10; i++)
	{
		switch (arr[i])
		{
		case 1:
			one++;
			break;
		case 2:
			two++;
			break;
		case 3:
			three++;
			break;
		default:
			break;
		}
	}

	printf("1 : ");
	for (int i = 0; i < one; i++) printf("*");
	printf("\n");

	printf("2 : ");
	for (int i = 0; i < two; i++) printf("*");
	printf("\n");

	printf("3 : ");
	for (int i = 0; i < three; i++) printf("*");
	printf("\n");

	return 0;
}
*/
/*
int main(void)
{
	// ������ �迭 4��
	int x[3][3], y[2][2];
	int row, column;
	int find = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &x[i][j]);
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			scanf("%d", &y[i][j]);
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf(" %d", x[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf(" %d", y[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (x[i][j] == y[0][0] && x[i + 1][j + 1] == y[1][1])
			{
				if (x[i + 1][j] == y[1][0] && x[i][j + 1] == y[0][1])
				{
					printf("%d %d \n", i, j);
					find = 1;
					break;
				}
			}
		}
		if (find)
		{
			break;
		}
	}

	if(find == 0)
	{
		printf("none");
	}

	return 0;
}
*/
/*
int main(void)
{
	// ���� 3��
	int arr[5];
	int i, j, tmp;
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (arr[j] < arr[j+1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	printf("%d \n%d", arr[0], arr[1]);

	return 0;
}
*/
/*
int main(void)
{
	// ���� 2��
	char string[7];
	int i; 
	int cat = 0;
	for (i = 0; i < 7; i++)
	{
		scanf("%c", &string[i]);
		if (string[i] == 'c' && string[i + 1] == 'a' && string[i + 2] == 't')
		{
			cat++;
		}
	}

	for (i = 0; i < 7; i++)
	{
		if (string[i] == 'c' && string[i + 1] == 'a' && string[i + 2] == 't')
		{
			cat++;
		}
	}

	printf("%d", cat);
	
	return 0;
}
*/
/*
int main(void)
{

	// ���� 1��
	int arr[5];
	int i;
	float avg = 0;

	for (i = 0; i < 5; i++)
	{
		scanf("%d", &arr[i]);
		avg += arr[i];
	}
	avg = avg / 5;

	for (i = 0; i < 5; i++)
	{
		if (arr[i] > avg)
		{
			printf("%d\n", arr[i]);
		}
	}
	return 0;
}
*/
