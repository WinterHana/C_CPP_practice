#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ���� 4-1
int main()
{
	int a[10], b[10];						// ũ�Ⱑ 10�� �迭 ����
	int n = 0, m = 0;
	int num;								// �Է¹��� ������ �ӽ÷� ����
	int max, min;					// �ִ�, �ּڰ� ����
	// ��� a(101ȣ)�� �� �Է� �ޱ�
	for (int i = 0; i < 11; i++)			// 11�� �ݺ��ϴ� ������ 10�� �Է��ϰ� -1�� �Է��� ���� �ֱ� �����̴�.
	{
		scanf("%d", &num);
		if (num == -1) break;				// -1�� �ԷµǸ� ����
		*(a + i) = num;						// ������� �ʾ����� �迭�� �ֱ�
		if (i == 0)
		{
			max = *a;
			min = *a;
		}
		n++;								// ���� n���� ����
		if (*(a + i) > max) max = *(a + i);
		if (*(a + i) < min) min = *(a + i);
	}

	// ��� b(102ȣ)�� �� �Է� �ޱ�
	for (int i = 0; i < 11; i++)
	{
		scanf("%d", &num);
		if (num == -1) break;				// -1�� �ԷµǸ� ����
		*(b + i) = num;						// ������� �ʾ����� �迭�� �ֱ�
		m++;								// ���� m���� ����
		if (*(b + i) > max) max = *(b + i);
		if (*(b + i) < min) min = *(b + i);
	}

	printf("%d %d\n", n, m);
	printf("%d %d\n", max, min);

	return 0;
}
// ���� 4-2
/*
void descending(int* arr1, int* arr2, int n, int m);
void ascending(int* arr1, int* arr2, int n, int m);

int main()
{
	int a[10], b[10];						// ũ�Ⱑ 10�� �迭 ����
	int n = 0, m = 0;
	int num;								// �Է¹��� ������ �ӽ÷� ����
	// ��� a(101ȣ)�� �� �Է� �ޱ�
	for (int i = 0; i < 11; i++)			// 11�� �ݺ��ϴ� ������ 10�� �Է��ϰ� -1�� �Է��� ���� �ֱ� �����̴�.
	{
		scanf("%d", &num);
		if (num == -1) break;			// -1�� �ԷµǸ� ����
		*(a + i) = num;					// ������� �ʾ����� �迭�� �ֱ�
		n++;							// ���� n���� ����
	}

	// ��� b(102ȣ)�� �� �Է� �ޱ�
	for (int i = 0; i < 11; i++)
	{
		scanf("%d", &num);
		if (num == -1) break;			// -1�� �ԷµǸ� ����
		*(b + i) = num;					// ������� �ʾ����� �迭�� �ֱ�
		m++;							// ���� m���� ����
	}

	descending(a, b, n, m);					// 1. ���� ���� n���� ������ ������������ ���
	ascending(a, b, n, m);					// 2. ���� ���� m���� ������ ������������ ���

	return 0;
}

// �� ��Ŀ��� ���� ū ������ ������������ �����Ͽ� ���
void descending(int* arr1, int * arr2, int n, int m)
{
	int tmp;							// ���� �����ϱ� ���� �� ����
	// ��� �ϳ��� ������������ ����
	for (int* i = arr1; i < arr1 + n; i++)
	{
		for (int* j = arr1; j < arr1 + n; j++)
		{
			if (*i > *j)				// ���ϴ� ���� �� ũ��, �ڸ� �ٲٱ�
			{
				tmp = *j;
				*j = *i;
				*i = tmp;
			}
		}
	}
	// �ٸ� ��� �ϳ��� ������������ ����
	for (int* i = arr2; i < arr2 + m; i++)
	{
		for (int* j = arr2; j < arr2 + m; j++)
		{
			if (*i > *j)				// ���ϴ� ���� �� ũ��, �ڸ� �ٲٱ�
			{
				tmp = *j;
				*j = *i;
				*i = tmp;
			}
		}
	}

	// ���������� �� �� ��� ������ ù��° ��Һ��� �񱳸� �ؼ� ���� ū ������ ����ϱ�
	for (int i = 0, j = 0, count = 0; count < n; count++)
	{
		if (*(arr1 + i) > *(arr2 + j))			// �� ū ���� ã�´�
		{
			printf("%d ", *(arr1 + i));
			i++;								// arr1�� ���� ��ҿ� ��
		}
		else
		{
			printf("%d ", *(arr2 + j));
			j++;								// arr2�� ���� ��ҿ� ��
		}

		// ���� ��� �� ����� ������ �����ߴٸ�, �ٸ� �� ����� ���� Ƚ���� ������� ����ϱ�
		if (i == n)													// arr1�� ���� ��
		{
			for (count = count + 1; count < n; count++, j++)		// �ٷ� ���� ��º��� ������ ���� ����� ������� ���
			{
				printf("%d ", *(arr2 + j));
			}
			break;													// ���� ��������� �ݺ��� Ż���ϱ�
		}
		else if (j == m)												// arr2�� ���� ��
		{
			for (count = count + 1; count < n; count++, i++)		// �ٷ� ���� ��º��� ������ ���� ����� ������� ���
			{
				printf("%d ", *(arr1 + i));
			}
			break;													// ���� ��������� �ݺ��� Ż���ϱ�
		}
	}

	printf("\n");
}

// �� ��Ŀ��� ���� ���� ������ ������������ �����Ͽ� ���
void ascending(int* arr1, int* arr2, int n, int m)
{
	int tmp;							// ���� �����ϱ� ���� �� ����
	// ��� �ϳ��� ������������ ����, -1�� ���� ������ �ݺ�
	for (int* i = arr1; i < arr1 + n; i++)
	{
		for (int* j = arr1; j < arr1 + n; j++)
		{
			if (*i < *j)				// ���ϴ� ���� �� ������, �ڸ� �ٲٱ�
			{
				tmp = *j;
				*j = *i;
				*i = tmp;
			}
		}
	}
	// �ٸ� ��� �ϳ��� ������������ ����, -1�� ���� ������ �ݺ�
	for (int* i = arr2; i < arr2 + m; i++)
	{
		for (int* j = arr2; j < arr2 + m; j++)
		{
			if (*i < *j)				// ���ϴ� ���� �� ũ��, �ڸ� �ٲٱ�
			{
				tmp = *j;
				*j = *i;
				*i = tmp;
			}
		}
	}

	// ���������� �� �� ��� ������ ù��° ��Һ��� �񱳸� �ؼ� ���� ���� ������ ����ϱ�
	for (int i = 0, j = 0, count = 0; count < m; count++)
	{
		if (*(arr1 + i) < *(arr2 + j))			// �� ���� ���� ã�´�
		{
			printf("%d ", *(arr1 + i));		
			i++;								// ���� ��ҿ� ��
		}
		else if (*(arr1 + i) >= *(arr2 + j))
		{
			printf("%d ", *(arr2 + j));			// ���� ��ҿ� ��
			j++;								
		}
		
		// ���� ��� �� ����� -1�� ������ ������ �����ߴٸ�, �ٸ� �� ����� ���� Ƚ���� ������� ����ϱ�
		if (i == n)										// arr1�� ���� ��
		{
			for (count = count + 1; count < m; count++, j++)		// �ٷ� ���� ��º��� ������ ���� ����� ������� ���
			{
				printf("%d ", *(arr2 + j));
			}
			break;													// ���� ��������� �ݺ��� Ż���ϱ�
		}
		else if (j == m)									// arr2�� ���� ��
		{
			for (count = count + 1; count < m; count++, i++)		// �ٷ� ���� ��º��� ������ ���� ����� ������� ���
			{
				printf("%d ", *(arr1 + i));
			}
			break;													// ���� ��������� �ݺ��� Ż���ϱ�
		}
	}
	printf("\n");
}
*/
// ���� 3-2
/*
void PRT(int n, char* p);
int main()
{
	// ���� �ʱ�ȭ
	char arr[100] = { 0 };
	int i = 0;
	int maxString = 0;			// ���� �� �ܾ��� ���� ����
	char* maxChar = arr;		// ���� �� �ܾ��� ù ���� ����
	int count = 0;				// �ܾ� ���� �ӽ� ����
	char * countChar;			// ù ���� �ӽ� ����
	// 1. ���� �Է� �ޱ�
	while (1)
	{
		scanf("%c", arr + i);
		if (*(arr + i) == '#') break;			// '#'�� ������ Ż��
		i++;
	}

	countChar = arr;				// ������ ���� ù �ҹ��� ����
	
	// 2. �ҹ��ڸ� ����ϱ�
	i = 0;							// �ʱ�ȭ
	while (1)
	{
		// �ҹ��ڶ�� ����ϱ�
		if (*(arr + i) >= 'a' && *(arr + i) <= 'z')
		{
			printf("%c", *(arr + i));
			i++;
			count++;				// �ܾ ���� �ӽ� ����
		}
		else
		{	
			if (maxString < count)
			{
				maxString = count;		// �ִ� ���ڿ� ���� �ֽ�ȭ
				maxChar = countChar;	// ù ���� �ֽ�ȭ
			}

			if (*(arr + i) == '#')			// �ٷ� '#'�� ���Դٸ� �ݺ��� Ż��
			{
				printf("\n");
				break;
			}

			while (!(* (arr + i) >= 'a' && *(arr + i) <= 'z'))	// �ҹ��� ���� ������ ��� �迭 �� Ž��
			{
				if (*(arr + i) == '#') break;			// ��ȸ�ϴٰ� '#'�� ������ �ݺ��� Ż��
				i++;									// �ƴϸ� ��� ����
				
			}

			if (*(arr + i) == '#')			// ���⼭�� '#'�� �������� �ݺ��� Ż��
			{
				printf("\n");
				break;
			}

			// ���� �ܾ� ������ ��� ���ؼ� �ʱ�ȭ
			count = 0;
			countChar = arr + i;
			printf("\n");
		}
	}
	printf("%d %c\n", maxString, *(maxChar));				// �ִ� ���� ��, �׿� ���� ù ���� ���
	PRT(maxString, maxChar);								// �ִ� ���� ���� ���

	return 0;
}
// �ִ� ������ ���� ���, maxString, maxChar�� �޾Ƽ� ��ȸ�ϸ� ����� ��
void PRT(int n, char* arr)					
{
	// ù �ҹ��� �� �ٷ� '#'�� ���� ����� �ȵǼ� do-while������ ������
	char* i = arr;
	do
	{
		printf("%c", *i);
		i++;
	}while (i < arr + n);
}
// ���� 2-2
/*
int passengerN(int N);
int changeseat(int* arr);
void rebooking(int* arr);

int main()
{
	// ���� ����
	int booking[21] = { 0 };
	int N;
	// �°� �� �Է� �ޱ�
	scanf("%d", &N);
	// �°� ����ŭ �迭�� ����
	for (int i = 0; i < N; i++)
	{
		scanf("%d", booking + i);
	}
	// �°��� ���� ���� ��� 0�̳� -1 ���, ���� �����ϸ� �ٷ� ���α׷� ������
	printf("%d\n", passengerN(N));
	if(passengerN(N) == -1) return 0;

	rebooking(booking);				// ���ο� �����ȣ ����

	for (int *i = booking; *i != 0; i++)		// ����ϱ�
	{
		printf("%d ", *i);
	}

	return 0;
}

int passengerN(int N)
{
	if (N >= 5) return 0;
	else return -1;
}

int changeseat(int* arr)
{
	int min;						// ���� �ּҰ�
	int flag = 0;					// �迭�� ���� ���� �����ϴ��� Ȯ�����ִ� ����
									// �־��� ���� ���� ������ �迭�� �������� �ʰ� �ּ��� �� ���ϱ�
	for (min = 1; min <= 21; min++)
	{
		flag = 0;
		// �迭�� �����ϴ��� Ȯ��
		for (int* j = arr; *j != 0; j++)
		{
			if (*j == min) 
			{
				flag = 1;
				break;		// �迭�� �����ϸ� ���� �ݺ������� �Ѿ
			}
		}
		if (flag == 0) break; // �迭�� �������� ������ �ݺ� ����
	}
	return min;			// ���ǿ� �´� �� ��ȯ
}

void rebooking(int* arr)
{
	// �ߺ��� �¼� ��ȣ�� Ȯ���ϱ� ���� ���� �ݺ��� ���
	for (int* i = arr; *i != 0; i++)			
	{
		for (int* j = arr; *j != 0; j++)		// �� ��� ��ȸ
		{
			if (*i == *j && i != j)		// �ߺ��� ���� �߰����� ��, �� �װ��� �ڱ� �ڽ��� �ƴ� �� ����
			{
				int k = changeseat(arr);
				*j = k;			// ���ο� �¼���ȣ�� �迭�� ���� �����ϱ�
			}
		}
	}
}
*/
/*
* ���� Ǯ ���� ���� n-2 ���� Ǯ�� �� ��Ǯ������ n-1 Ǯ��
*/
// ���� 1-2
/*
int* MAX(int* arr);
int* MIN(int* arr);

int main()
{
	// �ʿ��� ���� ����
	int arr[100];
	int N;
	int* max, * min;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)			// N�� �ݺ�
	{
		int j = 0;
		while (1)
		{
			scanf("%d", arr + j);		// �ּҷ� �Է� �ޱ�
			if (arr[j] == 0) break;		// ���� 0�� �޾�����, �ݺ� ����
			j++;						// j�� �ϳ� �����ָ鼭 ��� �迭�� ���� ����
		}

		// MAX, MIN �Լ� ����
		max = MAX(arr);
		min = MIN(arr);

		// ��� : ��쿡 ���� ����ϴ� ��찡 �޶���
		// 1. ���ڸ� �ϳ��� �Է��ؼ� max�� min�� ���ų� �ΰ��� �Է��ؼ� ���̿� ���ڰ� ���� ��
		if (max == min || max+1 == min || max == min+1)
		{
			printf("none\n");
		}
		// 2. �ִ밪�� �ּҰ����� �� �ڿ� ��ġ�� ���� ��
		else if (max > min)
		{
			for (int* p = min + 1; p < max; p++)
			{
				printf("%d ", *p);
			}
			printf("\n");
		}

		// 2. �ּҰ��� �ִ밪���� �� �ڿ� ��ġ�� ���� ��
		else if (min > max)
		{
			for (int* p = max + 1; p < min; p++)
			{
				printf("%d ", *p);
			}
			printf("\n");
		}
	}

	return 0;
}

// ���� ū �� ã��
int* MAX(int* arr)
{
	int* p, * max;
	max = arr;
	for (p = arr; *p != 0; p++)		// �ּҷ� �ݺ�
	{
		if (*max < *p)				// ���� ū �� �ֽ�ȭ �ϱ�
		{
			max = p;
		}
	}
	return max;						// �迭�� �ּҸ� ��ȯ
}

// ���� ���� �� ã��
int* MIN(int* arr)
{
	int* p, * min;
	min = arr;
	for (p = arr; *p != 0; p++)		// �ּҷ� �ݺ�
	{
		if (*min > *p)				// ���� ���� �� �ֽ�ȭ �ϱ�
		{
			min = p;
		}
	}
	return min;						// �迭�� �ּҸ� ��ȯ
}
*/
// ���� 1-1
/*
int* MAX(int *arr);
int* MIN(int* arr);

int main()
{
	// �ʿ��� ���� ����
	int arr[100];
	int N;
	int* max, * min;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)			// N�� �ݺ�
	{
		int j = 0;
		while (1)
		{
			scanf("%d", arr + j);		// �ּҷ� �Է� �ޱ�
			if (arr[j] == 0) break;		// ���� 0�� �޾�����, �ݺ� ����
			j++;						// j�� �ϳ� �����ָ鼭 ��� �迭�� ���� ����
		}
		
		// MAX, MIN �Լ� ����
		max = MAX(arr);					
		min = MIN(arr);

		// ���
		printf("%d %d\n", *max, *min);
	}

	return 0;
}

// ���� ū �� ã��
int* MAX(int* arr)
{
	int* p, *max;
	max = arr;
	for (p = arr; *p != 0; p++)		// �ּҷ� �ݺ�
	{
		if (*max < *p)				// ���� ū �� �ֽ�ȭ �ϱ�
		{
			max = p;
		}
	}
	return max;						// �迭�� �ּҸ� ��ȯ
}

// ���� ���� �� ã��
int* MIN(int* arr)
{
	int* p, * min;
	min = arr;
	for (p = arr; *p != 0; p++)		// �ּҷ� �ݺ�
	{
		if (*min > *p)				// ���� ���� �� �ֽ�ȭ �ϱ�
		{
			min = p;
		}
	}
	return min;						// �迭�� �ּҸ� ��ȯ
}
*/