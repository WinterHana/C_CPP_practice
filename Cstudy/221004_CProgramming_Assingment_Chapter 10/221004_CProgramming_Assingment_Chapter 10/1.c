#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ���� 4
int s_check(char* p, char* q);

int main()
{
	int M;						// ���ڿ� �ݺ� Ƚ��
	int k1, k2;					// üũ�� ���� ����
	char str[10][201];			// �� ���ڿ��� ������ ������ �迭
	int count;					// �ҹ��� ������ ������ ����
	scanf("%d", &M);			// �ʿ��� ������ �Է¹޴´�.
	scanf("%d %d", &k1, &k2);
	getchar();					// ���� EnterŰ�� ����� ���� getchar�� ����Ѵ�/

	for (int i = 0; i < M; i++)	// �ݺ��ؼ� ������ �迭�� ���ڿ��� �����Ѵ�.
	{
		gets(str[i]);			// ������ ���Ե� ���ڿ��̹Ƿ� gets �̿�
	}

	for (int i = 0; i < M; i++)	// �Է¹��� ��ŭ, ������ üũ�ؼ� count�� ����Ѵ�.
	{			
		count = s_check(&(str[i][k1]), &(str[i][k2]));		// �ҹ��� ������ ��ȯ�޾Ƽ� count�� ����
		if (count > 0)			
		{
			printf("%d\n", count);		// ���� count�� 0 �ʰ����, ����ϱ�
		}
	}

	return 0;
}

// �־��� �ּ��� ������ ���ʴ�� ���켭, �ҹ����� ������ ��ȯ�Ѵ�.
int s_check(char* p, char* q)
{
	int count = 0;					// �ҹ��� ���� ����

	for (char* i = p; i <= q; i++)	// ó�� �ּҺ��� �� �ּұ��� ���ʷ� ��ȸ
	{
		if (*i >= 'a' && *i <= 'z')	// ���� ������ ���� �ҹ��ڶ��, count�� +1�� �Ѵ�.
		{
			count++;
		}
	}

	return count;			// �ҹ��� ���� ��ȯ
}
// ���� 3 - 2
/*
int checkStr(char* str, int strLen2);

int main()
{
	char str1[100], str2[100];			// �Է¹��� �� ���ڿ�
	int count = 0;						// ������ �ܾ��� ������ ������ ����
	gets(str1);							// �� ���ڿ��� �Է¹޴´�.
	gets(str2);

	int strLen1 = strlen(str1);			// ���ڿ� ������ ���̸� ���Ѵ�.
	int strLen2 = strlen(str2);

	for (int i = 0; i < strLen1 - strLen2 + 1; i++)		// ���ڿ� str1 ��ü�� ��ȸ�ؼ�, ���ǿ� �´� �ܾ� ã��
	{	
		// 1. �ܾ ���� 2. �ܾ��� ������ �����ؼ� ������ �ܾ����� Ȯ���ϱ�
		// �̶�, 2�� �Լ��� ���� ����� �����Ѵ�.
		if (strncmp(&str1[i], str2, strLen2) == 0 && checkStr(&str1[i], strLen2))
		{
			count++;		// ���ǿ� �´ٸ�, count�� �÷��ش�.
		}
	}
	printf("%d\n", count);	// �������� count�� ���
}

// ������ �ܾ����� Ȯ�����ִ� �Լ�
int checkStr(char* str1, int strLen2)
{
	// �ܾ� ���ʿ� '.'�̳� ' '�� �����Ѵٸ�, ������ �ܾ��� �Ǵ��ϰ� 1�� ��ȯ�Ѵ�.
	// �ܾ��� ������ ���� Ȯ���ϱ� ���ؼ��� ù ���ڿ��� �ܾ��� ���̸�ŭ �ڷ� �����ؼ� strLen2�� �޴´�.
	if ((*(str1 - 1) == '.' || *(str1 - 1) == ' ') && (*(str1 + strLen2) == '.' || *(str1 + strLen2) == ' '))
		return 1;
	// ������ �ܾ �� ���̰ų� �� ó���� ���� ��쵵 ����ؼ� 1�� ��ȯ���ش�.
	else if ((*(str1 - 1) < 'A' || *(str1 - 1) > 'z') && (*(str1 + strLen2) == '.' || *(str1 + strLen2) == ' ' || *(str1 + strLen2) == '\0'))
		return 1;
	// �� ������ �ƴ϶�� 0�� ��ȯ�Ѵ�.
	else
		return 0;
}
*/
// ���� 2 - 2
/*
int main()
{
	char str[201];				// ó�� �Է¹��� ���ڿ� ����
	char splitStr[20][200];		// �и��� ���ڿ��� ������ 2���� �迭
	char addStr[20];			// �߰��� ���ڿ��� ����
	int addStrCheck = 1;		// �߰� �Էµ� ���ڿ��� �迭�� ������ �Ǵ��ϴ� ����
	char tmp[20];				// ���븦 ���� �ӽ� �迭
	char result[200] = "";		// ����� ������ �迭
	gets(str);					// 1. ���ڿ� �Է�
	scanf("%s", addStr);		// 2. �߰��� ���ڿ� �Է�

	int i = 0;					// ������ �迭�� ��
	int j = 0;					// ������ �迭�� ��

	// �Էµ� ��ü ���ڿ��� �ϳ��ϳ� ��ȸ�ؼ� ������ �迭�� �ֱ�
	for (int k = 0; k <= strlen(str); k++)
	{
		if (str[k] == ' ')			// �����̶��, null���ڸ� �ְ� ���� �迭�� �̵�
		{
			splitStr[i][j] = '\0';
			i++;					// ���� + 1
			j = 0;					// ���� �ʱ�ȭ
		}
		else						// �� ���� ���ڴ� ����
		{
			splitStr[i][j] = str[k];
			j++;					// ���� + 1
		}
	}

	// �߰� �Էµ� ���ڿ��� �̹� ������ �迭�� �ִ��� Ȯ��
	for (int k = 0; k <= i; k++)
	{
		// �ִٸ�, �߰����� �ʰ� �ٷ� �ݺ����� Ż���Ѵ�.
		if (strcmp(addStr, splitStr[k]) == 0)
		{
			addStrCheck = 0;
			break;
		}
	}

	// ���ٸ�, ������ �迭�� ���ڿ��� �߰��Ѵ�.
	if (addStrCheck)
	{
		i++;				// i�� ���� + 1 ���� ����, �迭�� �ֱ�
		strcpy(splitStr[i], addStr);
	}

	// �ϼ��� ������ �迭�� ���ڿ����� ��ȸ�ϸ� ����Ѵ�.
	for (int k = 0; k <= i; k++)
	{
		printf("%s\n", splitStr[k]);
	}

	// ������ �迭�� ���� ������� �����Ѵ�.
	for (int k = 0; k <= i; k++)
	{
		for (int r = 0; r <= i; r++)
		{
			// ���������� �ǵ��� �����ϱ�
			if (strcmp(splitStr[k], splitStr[r]) < 0)
			{	
				// tmp�� �̿��ؼ� �� ���ڿ��� ��ü�Ѵ�.
				strcpy(tmp, splitStr[k]);
				strcpy(splitStr[k], splitStr[r]);
				strcpy(splitStr[r], tmp);
			}
		}
	}

	// strcat�� �̿��ؼ� result�� ���δ�.
	for (int k = 0; k <= i; k++)
	{
		strcat(result, splitStr[k]);
		strcat(result, " ");			// �̶� ���鹮�ڵ� �ֱ�
	}

	// result ���
	printf("%s", result);


	return 0;
}
*/
// ���� 1 - 2
/*
void changeStr(char str[], int N);			// ���ڿ� ���� �Լ�
int checkStr(char str1[], char str2[]);		// ���� ���� ���θ� Ȯ���ϴ� �Լ�

int main()
{
	
	char str1[100], str2[100];		// �� ���ڿ��� ���� ����
	gets(str1);						// ���ڿ��� �Է¹���
	gets(str2);

	int result = checkStr(str1, str2);
	printf("%d", result);
	
}

void changeStr(char str[], int N)
{
	char cpystr[100] = {0};			// ���ο� ���ڿ��� ������ ����
	int i = 0;						// str�� �ε���
	int k = 0;						// cpystr�� �ε���
	// �� ���ڸ� ��ȸ�ϸ鼭 ���ǿ� �°� ���ڸ� �����Ѵ�.
	for (i = 0, k = 0; i < strlen(str); i++, k++)
	{	
		// �빮�� : �ƽ�Ű �ڵ�ǥ ������ N��° �� ����
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			cpystr[k] = str[i] + N;		// �ܼ��� N�� ����
		}
		// �ҹ��� : �ƽ�Ű �ڵ�ǥ ������� N��° �� ����
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			cpystr[k] = str[i] - N;		// �ܼ��� N�� ��
		}
		// ���� : �ش� ���� ��°�� ���ĺ� �빮�ڸ� N�� �ݺ�
		else if (str[i] >= '1' && str[i] <= '9')
		{
			// ���ڿ��� �̾��� ���ڸ� int������ �ٲ�. �̶�, ch�� ���ϱ� ���� -1�� �Ѵ�.
			int num = atoi(&str[i]) - 1;
			char ch = 'A' + num;					// �ٲ�� �� �빮�ڸ� ����
			for (int j = 0; j < N ; k++, j++)		// N�� ��ŭ �ݺ��ϱ�
			{
				cpystr[k] = ch;
			}

			if (str[i + 1] >= '1' && str[i + 1] <= '9') i++;		// ���� �� �ڸ� ���ڸ� ��Ҵٸ�, i �ϳ� �� ������Ű��
			k = k - 1;												// ������ k ���̱�
		}
		// �� �� : �������� ���� 
		else
		{
			cpystr[k] = ' ';
		}
	}
	cpystr[k] = '\0';				// �������� null ���� �߰�
	strcpy(str, cpystr);
}

int checkStr(char str1[], char str2[])
{
	char cpystr[100];					// �ӽ÷� ���� ������ ����
	// N�� 1���� 10���� �ݺ�
	for (int N = 1; N <= 10; N++)
	{
		// 1. A -> B �����ϱ�
		strcpy(cpystr, str1);			// �� ���ڿ��� �����ϰ�
		changeStr(cpystr, N);			// ���ǿ� �°� �ٲ� ����
		if (strcmp(cpystr, str2) == 0)	// strcmp�� ���� ���Ѵ�.
		{
			return 1;					// A->B�� �����ϴٸ� 1�� ��ȯ�Ѵ�.
		}

		// 1. B -> A �����ϱ� : 1. �� ������ ������� �����Ѵ�.
		strcpy(cpystr, str2);			// �� ���ڿ��� �����ϰ�
		changeStr(cpystr, N);			// ���ǿ� �°� �ٲ� ����
		if (strcmp(cpystr, str1) == 0)	// strcmp�� ���� ���Ѵ�.
		{
			return 2;					// B->A�� �����ϴٸ� 2�� ��ȯ�Ѵ�.
		}
	}

	return 0;			// �� �� �Ұ����ϴٸ� 0�� ��ȯ�Ѵ�.
}
*/