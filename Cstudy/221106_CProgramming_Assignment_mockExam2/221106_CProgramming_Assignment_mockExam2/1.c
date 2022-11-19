#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ���� 3
int check_row(int** p, int M, int N);
int check_col(int** p, int M, int N);

int main()
{
	// ���� ����
	int** arr;						// ������ �迭�� ���� ����
	int M, N, i, j, value;
	int rowMax, colMax, result;

	// �� X�� �� Y�� �Է¹޴´�
	scanf("%d %d", &M, &N);

	// ������ �迭�� ���� ������ �����Ҵ� �޴´�.
	arr = (int**)malloc(M * sizeof(int*));
	if (arr == NULL)		// �޸� �Ҵ� Ȯ��
	{
		printf("Insufficient Memory, Exiting...\n");
		return 0;
	}

	// �� ������ �ٽ� ������ �迭�� �����Ҵ� �޴´�.
	for (i = 0; i < M; i++)
	{
		arr[i] = (int*)malloc(N * sizeof(int));
		if (arr[i] == NULL)		// �޸� �Ҵ� Ȯ��
		{
			printf("Insufficient Memory, Exiting...\n");
			return 0;
		}

		// �����Ҵ��� ���� ��, �� ����� ���� 0���� �ʱ�ȭ
		for (j = 0; j < N; j++)
		{
			arr[i][j] = 0;
		}
	}

	// 0 0 0�� �Է¹��� ������, ��� ��, �׸��� value���� �Է¹޾� �迭�� �����Ѵ�.
	while (1)
	{
		scanf("%d %d %d", &i, &j, &value);
		if (i == 0 && j == 0 && value == 0) break;		// 0 0 0�� �Է¹����� Ż��
		arr[i][j] = value;								// value�� ���� ����
	}

	// �Է��� ���� ��, ������� 2���� �迭�� ����Ѵ�.
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
			printf("%d ", arr[i][j]);		// �� ��� ���
		printf("\n");
	}
	
	rowMax = check_row(arr, M, N);			// �� ���� �˻��ؼ� ���ӵ� 0�� �ִ� �� ��ȯ
	colMax = check_col(arr, M, N);			// �� ���� �˻��ؼ� ���ӵ� 0�� �ִ� �� ��ȯ

	result = (rowMax > colMax) ? rowMax : colMax;	// �� ���� ���ؼ� �� ū ���� ����� ����

	printf("%d\n", result);					// ���

	// �����Ҵ� �޸𸮸� �����Ѵ�.
	for (i = 0; i < M; i++)
		free(arr[i]);
	free(arr);

	return 0;
}

int check_row(int** p, int M, int N)
{
	int i, j;
	int max = 0, count = 0;
	// ���� ����
	for (j = 0; j < N; j++)
	{	
		// �� ���� ���� ���� ���� ��ȸ�ϸ鼭 �˻��Ѵ�.
		for (i = 0; i < M; i++)
		{
			if (p[i][j] == 0)		// ���� 0�̸�, count�� 1 ���ϱ�
			{
				count++;
			}
			else					// ���� 0�� �ƴ϶��, ���ӵ� 0�� �����ٴ� ��
			{
				if (max < count) max = count;		// ���� �ִ밪�� ���ŵƴٸ�, �����ϱ�
				count = 0;							// count�� �ٽ� ���� ���� 0���� �ʱ�ȭ
			}
		}
		// �ٸ� ������ �Ѿ ����, �ִ밪 �˻� �� count�� �ʱ�ȭ�Ѵ�.
		if (max < count) max = count;
		count = 0;
	}
	// ������ �ִ� ���̸� ��ȯ�Ѵ�.
	return max;
}

int check_col(int** p, int M, int N)
{
	int i, j;
	int max = 0, count = 0;
	// ���� ����
	for (i = 0; i < M; i++)
	{	
		// �� ���� ���� ���� ���� ��ȸ�ϸ鼭 �˻��Ѵ�.
		for (j = 0; j < N; j++)
		{
			if (p[i][j] == 0)	// ���� 0�̸�, count�� 1 ���ϱ�
			{
				count++;
			}
			else				// ���� 0�� �ƴ϶��, ���ӵ� 0�� �����ٴ� ��
			{
				if (max < count) max = count;		// ���� �ִ밪�� ���ŵƴٸ�, �����ϱ�
				count = 0;							// count�� �ٽ� ���� ���� 0���� �ʱ�ȭ
			}
		}
		// �ٸ� ������ �Ѿ ����, �ִ밪 �˻� �� count�� �ʱ�ȭ�Ѵ�.
		if (max < count) max = count;
		count = 0;
	}
	// ������ �ִ� ���̸� ��ȯ�Ѵ�.
	return max;
}

// ���� 2
/*
int main()
{
	// ���� ����
	// stringLen : ���ڿ��� ���� ����, wordLen : �ܾ��� ���� ����
	int N, i, j, wordLen, stringLen;
	// ���ǿ� �´� ���ڿ��� ã�� ���� ����
	int maxWordcount = 0, count = 0;
	// tmp : �ӽ÷� ���ڿ��� ������ ����, maxString : ���� ���� ���ڸ� �����ϴ� ���ڿ� ����
	char X[101], tmp[101], maxString[101] = "NONE";
	char* pt, *k, ** Y;

	// ���� N�� ������ �������� �ʴ� ���ڿ��� ���ÿ� �Է¹޴´�.
	scanf("%d %s", &N, X); getchar();
	// �ܾ��� ���� ����
	wordLen = strlen(X);

	// Y���� ������ ������ �迭 ����
	Y = (char**)malloc(N * sizeof(char *));
	if (Y == NULL)		// �޸� �Ҵ� Ȯ��
	{
		printf("Insufficient Memory, Exiting...\n");
		return 0;
	}
	
	// Y�� N���� ���ڿ��� �����ϱ� ���� ������
	for (i = 0; i < N; i++)
	{
		gets(tmp);
		stringLen = strlen(tmp);								// �Է¹��� ���ڿ��� ���̸� �޾Ƽ�
		Y[i] = (char*)malloc((stringLen + 1) * sizeof(char));	// ���ڿ��� ũ�� + NULL����(1)��ŭ �����Ҵ�
		if (Y[i] == NULL) // �޸� �Ҵ� Ȯ��
		{
			printf("Insufficient Memory, Exiting...\n");
			return 0;
		}
		strcpy(Y[i], tmp);										// ���� �Ҵ�� ������ �ӽ� ����� ���ڿ� �����ϱ�
	}

	// ���� ���� ���ڰ� ��Ÿ���� ���ڿ� ã��
	for (i = 0; i < N; i++)
	{
		stringLen = strlen(Y[i]);
		// ���ڿ��� ��ȸ�ϸ鼭 ������ �ܾ� ã��
		for (k = Y[i]; k < Y[i] + stringLen; k++)
		{
			// ������ �ܾ ã������, count�� �ø��� ��ٷ� �ܾ� ���� ��ġ�� ���� ��
			if (strncmp(k, X, wordLen) == 0)
			{
				count++;
				k += (wordLen - 1);
			}
		}

		// �� ���� �ܾ �����ϰ� �ִ� ���ڿ��� ã������ �������ֱ�
		if (count > maxWordcount)
		{
			maxWordcount = count;			// ���� ���� �ܾ ���Ե� ���� ����
			strcpy(maxString, Y[i]);		// ���ڿ� ����
		}
		count = 0;							// count �ʱ�ȭ �� �ٽ� �ϱ�
	}

	printf("%s\n", maxString);				// ���ǿ� �´� ���ڿ� ���


	// ������ �迭 ���� �����Ҵ� �޸𸮸� ���� ����
	for (i = 0; i < N; i++)
		free(Y[i]);
	// ������ �迭 �����Ҵ� �޸� ����
	free(Y);

	return 0;
}
*/
// ���� 1 - 2
/*
int main()
{
	// ���� ����
	int N, M1, M2, i, count, minLen = 101, maxLen = 0;		// minlen, maxLen���� �� ���ڿ�, ª�� ���ڿ��� ���� ����
	char tmp[101], maxStr[101], minStr[101];				// tmp�� �ӽ÷� ���ڿ��� ������
	char word1[101], word2[101], result[101] = "";			// ���ǿ� �´� �ܾ word1, word2���� ����, result���� ��� ���ڿ� ����
	char* pt;

	// N, M1, M2 ����
	scanf("%d %d %d", &N, &M1, &M2);
	getchar();

	// ���ڿ��� �Է¹޾Ƽ�,  ���� ��, ª�� ���ڿ� ��������
	for (i = 0; i < N; i++)
	{
		gets(tmp);
		if (strlen(tmp) > maxLen)		// �� ���ڿ� �����ϱ�
		{
			strcpy(maxStr, tmp);
			maxLen = strlen(maxStr);
		}
		if (strlen(tmp) < minLen)		// ª�� ���ڿ� �����ϱ�
		{
			strcpy(minStr, tmp);
			minLen = strlen(minStr);
		}
	}

	// ���� ��, ª�� ���ڿ� �����ϱ�
	printf("%s \n%s \n", maxStr, minStr);

	// ���� �� ���ڿ�����. M1��° �ܾ �����´�.
	count = 0;
	pt = maxStr;
	for (i = 0; i < maxLen + 1; i++)
	{
		if (maxStr[i] == ' ' || maxStr[i] == '\0')		// �����̳� NULL������ ��, NULL���� ����
		{
			maxStr[i] = '\0';
			strcpy(word1, pt);					// �ܾ� ��������		
			pt = maxStr + i + 1;				// ���� �ּ� �ʱ�ȭ
			count++;				
		}
		if (count > M1) break;					// �ܾ ã������, �ݺ��� Ż��
	}

	// ���� ª�� ���ڿ�����. M2��° �ܾ �����´�.
	count = 0;
	pt = minStr;
	for (i = 0; i < minLen + 1; i++)
	{
		
		if (minStr[i] == ' ' || minStr[i] == '\0')		// �����̳� NULL������ ��, NULL���� ����
		{
			minStr[i] = '\0';
			strcpy(word2, pt);					// �ܾ� ��������
			pt = minStr + i + 1;				// ���� �ּ� �ʱ�ȭ
			count++;				
		}
		if (count > M2) break;					// �ܾ ã������, �ݺ��� Ż��
	}

	// �� �ܾ ���� ������� �ռ��ϱ�
	if (strcmp(word1, word2) > 0)		// word2�� �ܾ� ������ �� ���� ��
	{
		strcat(result, word2);			
		strcat(result, word1);
	}
	else if (strcmp(word1, word2) < 0)	// word1�� �ܾ� ������ �� ���� ��
	{
		strcat(result, word1);
		strcat(result, word2);
	}

	// ��� ���
	printf("%s\n", result);

	return 0;
}
*/
// ���� 1 - 1
/*
int main()
{
	// ���� ���� ����
	int M, N, i, count, str1len, str2len;		// count : null ���ڸ� ���� Ƚ�� ����
	char str1[101], str2[101], word1[101], word2[101], result[101] = "";		// word1, word2���� ��ĥ �ܾ� ����, result���� ��� �ܾ� ����
	char* pt;

	// M, N �Է� �ޱ�
	scanf("%d %d", &M, &N);		
	getchar();

	// ������ ���Ե� ���ڿ� �ޱ�
	gets(str1);
	gets(str2);

	// ������ ���ڿ� ���̸� �޴´�.
	str1len = strlen(str1);
	str2len = strlen(str2);

	// str1�� M��° �ܾ� ã��
	count = 0;
	pt = str1;		// str1�� ù��° �ּҿ��� ����
	for (i = 0; i < str1len + 1; i++)
	{
		// ��ȸ�ϴٰ� ���� �����̳� NULL���ڸ� ������ ��. NULL���ڸ� �� �ڸ��� �����Ѵ�.
		if (str1[i] == ' ' || str1[i] == '\0')
		{
			str1[i] = '\0';
			strcpy(word1, pt);		// NULL���ڸ� ������ ���¿��� strcpy�� �ܾ �����´�.
			pt = str1 + i + 1;		// ���� �������� NULL���� �������� �����Ѵ�.
			count++;				// count�� �������Ѽ�, �ܾ� ������ �Ϸ������ ������.
		}
		if (count > M) break;		// ������ �����ϸ� �ݺ��� Ż��
	}

	// str2�� N��° �ܾ� ã�� : �� ����� ����
	count = 0;
	pt = str2;			// str2�� ù��° �ּҿ��� ����
	for (i = 0; i < str2len + 1; i++)
	{
		// ��ȸ�ϴٰ� ���� �����̳� NULL���ڸ� ������ ��.NULL���ڸ� �� �ڸ��� �����Ѵ�.
		if (str2[i] == ' ' || str2[i] == '\0')
		{
			str2[i] = '\0';
			strcpy(word2, pt);		// NULL���ڸ� ������ ���¿��� strcpy�� �ܾ �����´�.
			pt = str2 + i + 1;		// ���� �������� NULL���� �������� �����Ѵ�.
			count++;				// count�� �������Ѽ�, �ܾ� ������ �Ϸ������ ������.
		}
		if (count > N) break;		// ������ �����ϸ� �ݺ��� Ż��
	}

	// �� �ܾ ������ ��, ���� �ܾ� �ڿ� ������ ���� �ܾ �����Ѵ�
	if (strcmp(word1, word2) > 0)		// strcmp�� ���� �ܾ �� : ���� ������ word2�� �� ����
	{
		strcat(result, word2);			// ���ǿ� �°� �ܾ result�� ��ģ��.
		strcat(result, word1);
	}
	else if (strcmp(word1, word2) < 0)	// strcmp�� ���� �ܾ �� : ���� ������ word1�� �� ����
	{
		strcat(result, word1);
		strcat(result, word2);
	}

	// ��� ���
	printf("%s\n", result);

	return 0;
}
*/