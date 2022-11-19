#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ���� 4 - 2
int main()
{
	return 0;
}
// ���� 2 - 3
/*
int countWords(char arr[]);
int splitWords(char** arr, char str[]);
void compareWords(char** arr1, char** arr2, int countWord1, int countWord2);
void sorting(char* arr[], int count);

int main()
{
	// �ʿ��� ���� ����
	char str1[101], str2[101];
	char** arr1 = NULL;
	char** arr2 = NULL;
	int countWord1, countWord2;
	int i, check;

	// �� ���� ���ڿ��� �޴´�.
	gets(str1);
	gets(str2);
	// ���ڿ��� �ܾ� ������ �����Ѵ�.
	countWord1 = countWords(str1);
	countWord2 = countWords(str2);

	// arr1���� ���ڿ��� �ܾ� ������ŭ ���� �Ҵ��� �Ѵ�.
	arr1 = (char**)malloc(countWord1 * sizeof(char*));
	if (arr1 == NULL)			// �޸� ���� �Ҵ� �������� üũ
	{
		printf("Memory is not allocated\n");
		return -1;
	}
	// arr2�� ���������� ���ڿ��� �ܾ� ������ŭ ���� �Ҵ��� �Ѵ�.
	arr2 = (char**)malloc(countWord2 * sizeof(char*));
	if (arr2 == NULL)			// �޸� ���� �Ҵ� �������� üũ
	{
		printf("Memory is not allocated\n");
		return -1;
	}

	// �ܾ�� �и��� ��, �� �ܾ� ���� �����Ҵ��� �Ѵ�.
	check = splitWords(arr1, str1);
	if (check == -1) return -1;		// �̶�, ���� �����Ҵ翡 ���������� ���α׷��� ������.
	check = splitWords(arr2, str2);
	if (check == -1) return -1;

	// ���ǿ� ���� �ܾ� �� ��, �����ϰ� ����Ѵ�.
	compareWords(arr1, arr2, countWord1, countWord2);

	for (i = 0; i < countWord1; i++)
		free(arr1[i]);
	free(arr1);
	for (i = 0; i < countWord2; i++)
		free(arr2[i]);
	free(arr2);

	return 0;
}

// �ܾ��� ������ �����Ѵ�.
int countWords(char str[])
{
	int countWord = 0, i;
	int stringLen = strlen(str);		// ���� ���ڿ����� ������ ������ �����Ѵ�.
	// ��ȸ�� �ϸ鼭 ���� ��ĭ�̳� �ι��ڸ� ������, 
	// �ܾ �ϳ� �������ٰ� ������ �ܾ� ������ ����
	for (i = 0; i <= stringLen; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
			countWord++;
	}

	// �ܾ� ���� ��ȯ
	return countWord;
}

// �ܾ� ������ ���ڿ��� ������ �ܾ�� �����迭�� �Ѵ�.
int splitWords(char** arr, char str[])
{
	int i, len, word = 0;
	int stringLen = strlen(str);
	char* pt = str;
	for (i = 0; i <= stringLen + 1; i++)
	{
		// ��ĭ�̳�, �� ���ڸ� ������ ��
		if (str[i] == '\0' || str[i] == ' ')
		{
			str[i] = '\0';			// �� ���ڸ� ä���
			len = strlen(pt);		// ������ ���̸� �˾Ƴ� ��
			arr[word] = (char*)malloc((len + 1) * sizeof(char));	// �׿� ���� �����Ҵ��� �����Ѵ�.
			if (arr[word] == NULL)			// �޸� ���� �Ҵ� �������� üũ
			{
				printf("Memory is not allocated\n");
				return -1;
			}
			strcpy(arr[word], pt);		// �����Ҵ��� �Ϸ�Ǿ����� �ܾ �����Ѵ�.
			// �� �ٸ� �ܾ� ������ ���� �ʱ�ȭ ����
			pt = str + i + 1;			
			word++;
		}
	}
	return 0;			// �ƹ� ���� ���� ����ƴٸ� 0�� ��ȯ�Ѵ�.
}

// ���ǿ� ���� �ܾ� �� ��, �����ϰ� ����Ѵ�.
void compareWords(char** arr1, char** arr2, int countWord1, int countWord2)
{
	char compareString[101] = "";			// ���� ���ڿ� ����
	char* tmp[101];							// ���ǿ� �´� ���ڵ��� ������ ������ �迭
	char* tmp2;								// ������ �ϱ� ���� �ӽ� ����
	int i, j, k, l, count = 0, flag = 1;
	for (i = 0; i < countWord2; i++)		// �� �ܾ�� üũ�Ѵ�.
	{
		for (j = 0; j < countWord1; j++)
		{
			for (k = j + 1; k < countWord1; k++)
			{
				flag = 1;				// flag�� 0�� ���� �̹� ���� ���ڰ� �ִٴ� ���̹Ƿ� �ٷ� �Ѿ��.
				// 1. �մܾ� + �޴ܾ� ���հ� ��
				strcpy(compareString, arr1[j]);
				strcat(compareString, arr1[k]);
				for (l = 0; l < count; l++)
				{
					// ���� �̹� ���� ���ڰ� �ִٸ� �ٷ� �Ѿ��.
					if (strcmp(compareString, tmp[l]) == 0)
					{
						flag = 0;
						break;
					}	
				}
				// ���� ���ڰ� ����, ������ �ܾ�� ���� ��, �ӽ� �迭�� �����Ѵ�.
				if ((strcmp(arr2[i], compareString) == 0) && flag == 1) 
				{
					tmp[count] = arr2[i];
					count++;
				}

				flag = 1;
				// 2. �޴ܾ� + �մܾ� ���հ� ��
				strcpy(compareString, arr1[k]);
				strcat(compareString, arr1[j]);
				for (l = 0; l < count; l++)
				{
					// ���� �̹� ���� ���ڰ� �ִٸ� �ٷ� �Ѿ��.
					if (strcmp(compareString, tmp[l]) == 0)
					{
						flag = 0;
						break;
					}
				}
				// ���� ���ڰ� ����, ������ �ܾ�� ���� ��, �ӽ� �迭�� �����Ѵ�.
				if ((strcmp(arr2[i], compareString) == 0) && flag == 1)
				{
					tmp[count] = arr2[i];
					count++;
				}
			}
		}
	}

	// ���ǿ� �°� �����Ѵ�. 
	for (i = 0; i < count; i++)
	{
		for (j = 0; j < count - (i + 1); j++)
		{
			// 1. �ܾ��� ���̸� ������������ �����Ѵ�.
			if (strlen(tmp[j]) < strlen(tmp[j + 1]))
			{
				tmp2 = tmp[j];
				tmp[j] = tmp[j + 1];
				tmp[j + 1] = tmp2;
			}
			// 2, �ܾ��� ���̰� ���ٸ�, ���� ������� �����Ѵ�.
			else if ((strlen(tmp[j]) == strlen(tmp[j + 1])) && (strcmp(tmp[j], tmp[j + 1]) > 0))
			{
				tmp2 = tmp[j];
				tmp[j] = tmp[j + 1];
				tmp[j + 1] = tmp2;
			}
		}
	}

	// ���� ����� ����Ѵ�.
	for (i = 0; i < count; i++)
	{
		printf("%s\n", tmp[i]);
	}

}

void sorting(char* arr[], int count)
{
	int i, j;
	char* tmp;
	
	for (i = 0; i < count; i++)
	{
		for (j = 0; j < count - (i + 1); j++)
		{
			if (strlen(arr[j]) < strlen(arr[j + 1]))
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			else if ((strlen(arr[j]) == strlen(arr[j + 1])) && (strcmp(arr[j], arr[j + 1]) > 0))
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
*/
// ���� 1 - 2

// ����ü ����
struct st {
	char* str;
	int cnt1;
	int cnt2;
	int num;
	int pos;
	int result;
};

// �Լ� ����
void inputStr(struct st* parr, int N);
void inputInfo(struct st* parr, int N);
void sort(struct st* parr, int N);

int main()
{
	// �ʿ��� ���� ����
	int N, i;				
	struct st* parr = NULL;	
	// N�� �Է� ���� ��, N�� ���� ����ü �迭�� ���� �Ҵ� �޴´�.
	scanf("%d", &N); getchar();
	parr = (struct st*)malloc(N * sizeof(struct st));
	if (parr == NULL)			// �޸� ���� �Ҵ� �������� üũ
	{
		printf("Memory is not allocated\n");
		return -1;
	}
	inputStr(parr, N);			// 1. ���ڿ��� �Է¹޴´�.
	inputInfo(parr, N);			// 2. �� ���ڿ��� ���� �ʿ��� ������ �޴´�
	sort(parr, N);				// 3, result�� ���� ����ü �迭�� ����Ѵ�.

	// ���� ����� ����Ѵ�.
	for (i = 0; i < N; i++)
	{
		printf("%s\n", parr[i].str);
	}

	// ��� ��� �� �޸𸮸� ��ȯ�޴´�.
	for (i = 0; i < N; i++)
		free(parr[i].str);
	free(parr);
	return 0;
}

// 1. ���ڿ��� �Է¹޴´�.
void inputStr(struct st* parr, int N)
{
	int i, len;
	char tmp[101];		// �ӽ÷� ���ڿ��� ������ ����
	for (i = 0; i < N; i++)
	{
		gets(tmp);				// ���ڿ��� �Է¹޴´�.
		// ���ڿ��� ���̸� �޾Ƽ� (�� ũ�� + 1)��ŭ �迭�� �����Ҵ� �Ѵ�. 
		len = strlen(tmp);		
		parr[i].str = (char*)malloc((len + 1) * sizeof(char));
		if (parr[i].str == NULL)	// �޸� ���� �Ҵ� �������� üũ
		{
			printf("Memory is not allocated\n");
			return -1;
		}
		// �����Ҵ� Ȯ�� ��, �ӽ÷� ������ ���ڿ��� ���������� �����Ѵ�.
		strcpy(parr[i].str, tmp);
	}
}

// 2. ���ڿ��� ���� �ʿ��� ������ �޴´�
void inputInfo(struct st* parr, int N)
{
	int i, j, k;
	int stringlen, flag, cnt2;
	char tmp[101];		
	// ������ ������ �˾Ƴ��� ���� �������� ��
	char vowel[10] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
	
	// ����ü���� �ݺ��Ѵ�.
	for (i = 0; i < N; i++)
	{
		cnt2 = 0;
		strcpy(tmp, parr[i].str);			// ���ڿ��� ���� ���� ������ ������ �ӽ� �����Ѵ�.
		stringlen = strlen(tmp);			// 1. �� ������ ���� �޴´�.		

		// ���ڸ��� �񱳸� �Ѵ�.
		for (j = 0; j < stringlen; j++)
		{
			// 2. ���ڰ� ���ĺ��� ���, ������ ã�´�.
			if ((tmp[j] >= 'a' && tmp[j] <= 'z') || (tmp[j] >= 'A' && tmp[j] <= 'Z'))
			{
				flag = 1;
				for (k = 0; k < 10; k++)
				{
					if (tmp[j] == vowel[k])
					{
						flag = 0; // ������ ���, ������ �ƴϹǷ� ���� ���ڷ� �ٷ� �Ѿ��
						break;
					}
				}
				if (flag) cnt2++; // ������ ���, ������ ã�� ������ +1�� ���ش�.
			}

			// 3. ���ڰ� ������ ���, �� ���ڿ� ��ġ�� ã�´�.
			else if (tmp[j] >= '0' && tmp[j] <= '9')
			{
				parr[i].num = tmp[j] - '0';			// ���� ����
				parr[i].pos = j + 1;				// ������ ��ġ ���� : �ε����� 0���� �����̹Ƿ� +1�� �Ѵ�.
			}	
		}

		// ����� ����ü�� �����Ѵ�.
		parr[i].cnt1 = stringlen;
		parr[i].cnt2 = cnt2;
		// ��� ���� ���� ����� result�� �����Ѵ�.
		parr[i].result = parr[i].cnt1 * parr[i].cnt2 * parr[i].num * parr[i].pos;
	}
}

// 3, result�� ���� ����ü �迭�� ����Ѵ�.
void sort(struct st* parr, int N)
{
	int i, j;
	struct st tmp;
	
	// �Էµ� ������ �����ؾ��ϹǷ� ���� ������ �̿��Ѵ�.
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - (i + 1); j++)
		{	
			// result�� �ٷ� �ڿ� �ִ� ���� �� Ŭ �� ��ȯ�Ѵ�.
			if (parr[j].result < parr[j + 1].result)
			{
				tmp = parr[j];
				parr[j] = parr[j + 1];
				parr[j + 1] = tmp;
			}
		}
	}
}
