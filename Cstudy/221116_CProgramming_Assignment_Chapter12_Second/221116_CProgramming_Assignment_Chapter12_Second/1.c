#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
7 3
Kim 75 85
Lee 93 63
Park 94 82
Choi 78 70
Jung 65 85
Kang 83 90
Cho 90 70

7 3
Kim 75 85
Lee 96 56
Park 94 82
Choi 78 70
Jung 65 85
Kang 93 63
Cho 93 63
*/
// ���� 4 - 1, 4 - 2

// ����ü ����
struct student {
	char* name;
	int firstStage;
	int interview;
	double sum;
};

int main()
{
	// �ʿ��� ���� ����
	int N, M, i, j, nameLen;
	struct student* arr = NULL, tmp, compare;
	char name[11];

	// N�� M�� �Է¹޴´�.
	scanf("%d %d", &N, &M);
	// �Է¹��� N���� student �迭�� �����Ҵ�
	arr = (struct student*)malloc(N * sizeof(struct student));
	if (arr == NULL)			// �޸� �Ҵ� Ȯ��
	{
		printf("Memory is not allocated\n");
		return -1;
	}
	// �� �迭���� ������ �����Ѵ�.
	for (i = 0; i < N; i++)
	{
		// 1. �̸� �Է� �ޱ�
		scanf("%s", name);
		// �Է¹��� �̸��� ���̸� �˾Ƴ� ���� (�� ���� + 1)��ŭ �����Ҵ�
		nameLen = strlen(name);		
		arr[i].name = (char *)malloc((nameLen + 1) * sizeof(char));
		if (arr[i].name == NULL)			// �޸� �Ҵ� Ȯ��
		{
			printf("Memory is not allocated\n");
			return -1;
		}
		// �����Ҵ��� �Ϸ������ �ӽ� ������ �̸��� ���� ����
		strcpy(arr[i].name, name);

		// 2. ���� �Է� �ޱ�
		scanf("%d %d", &arr[i].firstStage, &arr[i].interview);
		// �ε��Ҽ��� ǥ���� ������ �����Ͽ� ���. ���߿� ������ 10�� �ؼ� ����� ��
		arr[i].sum = 7 * arr[i].firstStage + 3 * arr[i].interview;
	}

	// ���ǿ� ���� �����Ѵ�.
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - (i + 1); j++)
		{
			// 1. ���� ������ �������� ����
			if (arr[j].sum < arr[j + 1].sum)
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			// 2. ������ ���Ƹ�, 1�ܰ� ������ �� ���� ������ ����
			else if ((arr[j].sum == arr[j + 1].sum) && (arr[j].firstStage < arr[j + 1].firstStage))
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			// 3. ������ 1�ܰ� ������ ���ٸ� �̸� ���� ������ ����
			else if ((arr[j].sum == arr[j + 1].sum) && (arr[j].firstStage == arr[j + 1].firstStage))
			{
				// ���� ������ �� ���� ������� �����Ѵ�.
				if (strcmp(arr[j].name, arr[j + 1].name) > 0)
				{
					tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
			}
		}
	}

	// ������ �� �߰��հ��ڸ� �������� ���� compare�� �� ������ �հ��� ������ ����
	compare = arr[M - 1];
	for (i = M; i < N; i++)
	{
		// �� ������ �հ��� ������ ������ ���� �϶�, �߰� �հ��� �Ѵ�.(M�� 1 ���ϱ�)
		if (compare.sum == arr[i].sum && compare.firstStage == arr[i].firstStage) M++;
		else break;
	}

	// ���� ��� ���
	for (i = 0; i < M; i++)
	{
		// ������ ����
		printf("%s %d %d %.1f\n", arr[i].name, arr[i].firstStage, arr[i].interview, arr[i].sum / 10);
	}
	// �հ��� ��
	printf("%d\n", M);

	// �� ����ü�� ���� �Ҵ� �� ���ڿ� ����
	for (i = 0; i < N ; i++) free(arr[i].name);
	// ����ü �迭 ����
	free(arr);

	return 0;
}

// ���� 3 - 2
/*
5
HongGilDong 1003 Math 85 C 80 AdvC 90
JeonWooChi 1001 English 60 C 75 Physics 80 Math 70
HeungBoo 1002 Economics 80 AdvC 90 Math 80 C 90
NolBoo 1004 Ethics 50 C 62
Euler 1005 Math 100 Physics 90 AdvC 85
2

5
HongGilDong 1003 Math 85 C 80 AdvC 90
JeonWooChi 1001 English 60 C 75 Physics 80 Math 70
HeungBoo 1002 Economics 80 AdvC 90 Math 80 C 90
NolBoo 1004 Ethics 50 C 62
Euler 1005 Math 100 Physics 90 AdvC 85
4

1
HongGilDong 1003 Math 85 C 80 AdvC 90
*/
/*
// ����ü ����
struct subject {
	char* name;
	double score;
};

struct student {
	char* name;
	char id[5];
	int numSubject;
	struct subject* psub;
	double avg;
};

int main()
{
	// �ʿ��� �������� �����Ѵ�.
	int N, K, i, j, stringLen, wordLen, countingWord;
	char str[101];
	char* pt, *subpt;
	struct student* parr = NULL, tmpstudent;		// tmpstudent : �ӽ÷� ������ ����ü
	double score, sum;
	struct subject tmpsubject;						// tmpsubject : �ӽ÷� ������ ����

	// �л��� ������� �Է��ϰ�, �� ���� ���缭 student ����ü �迭�� �����Ҵ� �޴´�.
	scanf("%d", &N); getchar();
	parr = (struct student*)malloc(N * sizeof(struct student));
	if (parr == NULL)				// �����Ҵ� Ȯ��
	{
		printf("Memory is not allocated\n");
		return -1;
	}
	
	// ����ü �迭 ������ ������ �Է¹ޱ� ���� ������ �����Ѵ�.
	for (i = 0; i < N; i++)
	{
		gets(str);				// ������ ��� �����ִ� ���ڿ��� �Է� ����.
		
		// 0. ���鸦 NULL���ڷ� �ٲ۴�.
		stringLen = strlen(str);
		pt = str;		// ���� ������ : ���ڿ��� ���� �κ�
		// ������ ��, �� ������ NULL���ڷ� �ٲ�.
		for (j = 0; j < stringLen; j++)
		{
			if (str[j] == ' ') str[j] = '\0';
		}

		// 1. �̸� : �� �տ� �̸��� �����Ѵ�.
		// �̸��� ���� : ó�� ������ ���̴� ���� null���ڷ� �ٲ����Ƿ� �ű���� ���̸� �޴´�.
		wordLen = strlen(pt);
		// �� �̸��� ���̿� ���缭 �޸� ������ �����Ҵ� �޴´�.(���� + 1)
		parr[i].name = (char*)malloc((wordLen + 1) * sizeof(char));
		if (parr[i].name == NULL)		// �����Ҵ� Ȯ��
		{
			printf("Memory is not allocated\n");
			return -1;
		}
		// �ܾ �����Ҵ� ������ ���� �����Ѵ�.
		strcpy(parr[i].name, pt);
		pt += wordLen + 1;		// �����͸� �� ���� �������� �ű��.

		// 2. �й� : �ι�°�� ���� ������ �����´�, "1. �̸�"�� �����Ҵ� ���� ������ ���
		wordLen = strlen(pt);
		strcpy(parr[i].id, pt);
		pt += wordLen + 1;	// �����͸� �� ���� �������� �ű��.	

		// 3. ������ ���� ����
		subpt = pt;				// ������ ���� �˾Ƴ��� ���� �ӽ� ����
		countingWord = 0;		// �ڿ� �ִ� ������ ������ �����Ѵ�.
		while (subpt != str + stringLen + 1)
		{
			if (*subpt == '\0') countingWord++;		// �� ���ڸ� ���� ������ ���� ���� �ϳ� �߰�
			subpt++;
		}

		parr[i].numSubject = countingWord / 2;		// ������ ���� �ܾ��� �� / 2 �̴�(����� : ����)
		// �� ������ ���� ���� ���� ����ü �迭�� �����Ҵ� �޴´�.
		parr[i].psub = (struct subject*)malloc(countingWord * sizeof(struct subject));
		if (parr[i].psub == NULL)					// �����Ҵ� Ȯ��
		{
			printf("Memory is not allocated\n");
			return -1;
		}

		// 4. ���� ���� �Է�
		for (j = 0; j < parr[i].numSubject; j++)
		{
			// 1, ����� ����
			wordLen = strlen(pt);				// null���ڱ����� ���� ���� �ޱ�		
			parr[i].psub[j].name = (char*)malloc((wordLen + 1) * sizeof(char));		// �� ���� ���̸�ŭ �����Ҵ� �ޱ�
			if (parr[i].psub[j].name == NULL)	// �����Ҵ� Ȯ��
			{
				printf("Memory is not allocated\n");
				return -1;
			}
			strcpy(parr[i].psub[j].name, pt);	// ���ڿ� ����
			pt += wordLen + 1;					// ������ �̵�

			// 2. ���� ���� ����
			wordLen = strlen(pt);				// null���ڱ����� ���� ���� �ޱ�
			score = atoi(pt);					// ���ڿ��� ������ ��ȯ
			parr[i].psub[j].score = score;		// �� ������ double ������ �ֱ�
			pt += wordLen + 1;					// ������ �̵�
		}

		// 5. ��� ������ ��� ���� �Է�
		sum = 0.0;								// ��� ���� ������ ���� ����
		for (j = 0; j < parr[i].numSubject; j++)
		{
			sum += parr[i].psub[j].score;		// ���� ���
		}
		parr[i].avg = sum / parr[i].numSubject;	// ��� ���
	}

	// ��� ������ ���� �����ϱ�
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - (i + 1); j++)
		{
			// ��� ���� ����
			if (parr[j].avg < parr[j + 1].avg)
			{
				tmpstudent = parr[j];
				parr[j] = parr[j + 1];
				parr[j + 1] = tmpstudent;
			}
			// ��� ������ ������, �й� ������ �����Ѵ�.
			else if ((parr[j].avg == parr[j + 1].avg) && (strcmp(parr[j].id, parr[j + 1].id) > 0))
			{
				tmpstudent = parr[j];
				parr[j] = parr[j + 1];
				parr[j + 1] = tmpstudent;
			}
		}
	}
	// K��° �л��� ã�Ƽ� �̸�, �й�, ����� ����Ѵ�.
	scanf("%d", &K);
	printf("%s %s %.2f ", parr[K - 1].name, parr[K - 1].id, parr[K - 1].avg);

	// K��° �л��� ���� ������ ����� ������ ����Ѵ�.
	tmpsubject = parr[K - 1].psub[0];
	for (i = 0; i < parr[K - 1].numSubject; i++)
	{
		if (parr[K - 1].psub[i].score > tmpsubject.score) tmpsubject = parr[K - 1].psub[i];
	}
	// ���� ��� ���
	printf("%s %.2f", tmpsubject.name, tmpsubject.score);
	
	// �޸� ���� 1. ���ڿ� 2. ����ü 3. ����ü �迭
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < parr[i].numSubject; j++)
		{
			free(parr[i].psub[j].name);
		}
		free(parr[i].psub);
	}

	free(parr);

	return 0;
}
*/