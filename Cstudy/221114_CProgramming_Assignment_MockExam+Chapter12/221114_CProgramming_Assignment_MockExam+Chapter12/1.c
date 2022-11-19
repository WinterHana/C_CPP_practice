#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 2�� ���� 4 - 2
/*
// ����ü ����
struct reserve {
	int id;
	char grade[4];
	int price;
};

struct tot_price {
	int id;
	int total_price;
};

// �Լ� ����
void input(struct reserve* p, int N);
int cal_num(struct reserve* p, int N);
void cal_sum(struct reserve* p, int N, struct tot_price* q);

int main()
{
	// �ʿ��� ���� ����
	int N;
	int wordsCount;
	struct reserve* parr = NULL;
	struct tot_price* totPrices = NULL, *pt;

	// N�� �Է¹��� ��, N��ŭ �����Ҵ��� �޴´�.
	scanf("%d", &N);
	parr = (struct reserve*)malloc(N * sizeof(struct reserve));
	if (parr == NULL)			// �޸� �����Ҵ� Ȯ��
	{
		printf("Memory is not allocated\n");
		return -1;
	}
	// ��id, Ƽ�� ��ް� Ƽ�� ������ �����Ѵ�.
	input(parr, N);

	// �ߺ��� id�� ������ ���� ���� �޴´�.
	wordsCount = cal_num(parr, N);

	// �ߺ� ���� ���� �� ��ŭ tot_price Ÿ���� ����ü �迭�� �����Ҵ��Ѵ�.
	totPrices = (struct tot_price*)malloc(wordsCount * sizeof(struct tot_price));
	if (totPrices == NULL)			// �޸� �����Ҵ� Ȯ��
	{
		printf("Memory is not allocated\n");
		return -1;
	}

	// Ƽ�� ���ſ� ����� �� �ݾ��� ����Ͽ� �����Ѵ�.
	cal_sum(parr, N, totPrices);

	// �� id�� Ƽ�� ���� �� �ݾ��� ���� ����Ѵ�.
	for (pt = totPrices; pt < totPrices + wordsCount; pt++)
	{
		printf("%d %d\n", pt->id, pt->total_price);
	}

	// �����Ҵ� �޸� ����
	free(parr);
	free(totPrices);

	return 0;
}

// ����ü �迭�� ������ �Է¹޴´�.
void input(struct reserve* p, int N)
{
	struct reserve* pt;
	// ������ Ƚ����ŭ ������ ����
	for (pt = p; pt < p + N; pt++)
	{
		// 1. id�� ����� �Է� �޴´�.
		scanf("%d %s", &pt->id, pt->grade);
		// 2. ����� ���뿡 ���� Ƽ�� �ݾ��� �����Ѵ�.
		if (strcmp(pt->grade, "VIP") == 0) pt->price = 140000;
		else if (strcmp(pt->grade, "R") == 0) pt->price = 110000;
		else if (strcmp(pt->grade, "S") == 0) pt->price = 85000;
		else if (strcmp(pt->grade, "A") == 0) pt->price = 55000;
	}
}

int cal_num(struct reserve* p, int N)
{
	struct reserve* pt, *pt2;
	// flag : �̸��� �ߺ��Ȱ��� Ȯ���� , result : ���� �� �� ����
	int flag = 1, result = 0;		
	for (pt = p; pt < p + N; pt++)
	{
		flag = 1;
		// ���� ������������ ���� ������ ��ȸ�Ѵ�.
		for (pt2 = pt; pt2 >= p; pt2--)
		{
			// ���� ���� �̸��� �ִٸ� �ߺ��Ǿ��ٰ� ����
			if (pt->id == pt2->id && pt2 != pt)
			{
				flag = 0;
				break;
			}
		}
		// �ڿ� ���� �̸��� ���ٸ� ���ο� id��� �����ϰ� result�� +1 ���ش�.
		if (flag) result++;
	}
	// ���� ��� ��ȯ
	return result;
}

void cal_sum(struct reserve* p, int N, struct tot_price* q)
{
	struct reserve* pt, *pt2;
	struct tot_price* qt;
	int qIndex = 0, flag = 1;		// qIndex : �ߺ����� ���� id�� �����ϱ� ���� ����

	// 1. �ߺ����� �ʰ� id�� tot_price Ÿ���� �迭�� �����Ѵ�.
	for (pt = p; pt < p + N; pt++)
	{
		flag = 1;
		for (pt2 = pt; pt2 >= p; pt2--)
		{
			// �ߺ��� �̸��� �ִٸ� �׳� �Ѿ��
			if (pt->id == pt2->id && pt2 != pt)
			{
				flag = 0;
			}
		}
		// �ߺ��� �̸��� ���ٸ� �迭�� id�� �߰��Ѵ�.
		if (flag)
		{
			(q + qIndex)->id = pt->id;
			qIndex++;		// qIndex�� +1 ���ֱ�
		}
	}
	
	// 2. ���� id�� ã�Ƽ� ���� ����ϱ�
	for (qt = q; qt < q + qIndex; qt++)
	{
		qt->total_price = 0;		// ���� ��� �ʱ�ȭ
		for (pt = p; pt < p + N; pt++)
		{
			// ���� id�� ã�� ������ �� ���ݿ� �߰��Ѵ�.
			if (qt->id == pt->id)
			{
				qt->total_price += pt->price;
			}
		}
	}
}
*/

// 2�� ���� 5 - 2
// ����ü ����
struct string {
char* str;
int words;
};

int main()
{
	// �ʿ��� ���� ����
	char temp[101];
	int N, i, j, k, l, len, wordcount, count, maxcount;
	struct string* p = NULL, tmp;
	char** pword = NULL;
	char* strtmp, * strp, maxtmp[101];

	// N�� �Է¹��� ��, N�� ���� ����ü �迭�� �����Ѵ�.
	scanf("%d", &N); getchar();
	p = (struct string*)malloc(N * sizeof(struct string));
	if (p == NULL)				// �޸� �����Ҵ� Ȯ�� 
	{
		printf("Memory is not allocated\n");
		return -1;
	}

	// ����ü �迭�� ũ�⸸ŭ ��ȸ
	for (i = 0; i < N; i++)
	{
		// �� ����ü�� str���� �����Ҵ��� �޴´�.
		gets(temp);
		len = strlen(temp);		// �Է��� ���ڿ��� ���̸� �޴´�.
		p[i].str = (char*)malloc((len + 1) * sizeof(char));	// ���ڿ��� ���� + 1 ��ŭ ũ�⸦ �����޾� �����Ҵ��Ѵ�.
		if (p[i].str == NULL)	// �޸� �����Ҵ� Ȯ��
		{
			printf("Memory is not allocated\n");
			return -1;
		}
		strcpy(p[i].str, temp);	// �����Ҵ��� �Ϸ������ ���ڿ��� �����ؼ� ���� �Է��Ѵ�.

		p[i].words = 0;			// �ܾ��� ���� �ʱ�ȭ

		j = 0;
		// ���ڿ��� �ι��ڱ��� ��ȸ�Ѵ�.
		while (1)
		{
			// �ܾ ������ �׸�ŭ �ܾ� ������ �߰��Ѵ�.
			if (p[i].str[j] == ' ' || p[i].str[j] == '\0') p[i].words++;
			if (p[i].str[j] == '\0') break;
			j++;
		}
	}

	// �ܾ��� ������ ���� ���ڿ��� ������������ �����Ѵ�.
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - (i + 1); j++)
		{
			// ���� ���ڿ��� �ܾ� ������ �� ������, �հ� �ڸ� �ٲٱ�
			if (p[j].words < p[j + 1].words)
			{
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}

	// �� ���ڸ� �ܾ�� ������ ���� �Ҵ���� 2���� �迭�� �����Ѵ�.
	for (i = 0; i < N; i++)
	{
		// �ܾ��� ������ŭ �迭�� �����Ҵ��Ѵ�.
		wordcount = p[i].words;
		pword = (char**)malloc(wordcount * sizeof(char*));
		if (pword == NULL)		// �޸� �����Ҵ� Ȯ��
		{
			printf("Memory is not allocated\n");
			return -1;
		}
		// ���ڿ��� ���� �ľ�
		len = strlen(p[i].str);
		count = 0;		// �ܾ��� ���� ����
		k = 0;			// �迭�� �ε���
		strp = p[i].str;		// ó�� �ܾ��� ���� ��ġ = ���ڿ��� ���� ��ġ
		for (j = 0; j <= len; j++)
		{
			// �ܾ ��Ÿ�� ������ ���� �Ҵ� �غ�
			if (p[i].str[j] == ' ' || p[i].str[j] == '\0')
			{
				p[i].str[j] = '\0';
				count = strlen(strp);		// �ܾ��� ���̸� ��������, �� ũ�� + 1��ŭ �����Ҵ��Ѵ�.
				pword[k] = (char*)malloc((count + 1) * sizeof(char));
				if (pword[k] == NULL)		// �޸� �����Ҵ� Ȯ��
				{
					printf("error...\n");
					return -1;
				}
				strcpy(pword[k], strp);		// �����Ҵ��� �Ϸ������ �ܾ �����Ѵ�.

				k++;		// �ε��� ����
				if (j != len) p[i].str[j] = ' ';	// �ι��ڷ� �ٲ� ���⸦ �ٽ� ������� �Ѵ�.
				strp = p[i].str + j + 1;	// �ܾ��� ���� ��ġ �ʱ�ȭ
			}
		}

		// �� ���ڿ� ���� ����� �ܾ� �� �ߺ� Ƚ���� ���� ���� �ܾ ã�´�.
		maxcount = 0;		// �ִ� �ߺ� Ƚ��
		count = 0;			// �� �ܾ��� �ߺ� Ƚ��
		for (j = 0; j < p[i].words; j++)
		{
			// �ߺ��� �ܾ ã���� �� �ߺ� Ƚ�� ����
			for (l = j; l < p[i].words; l++)
			{
				if (strcmp(pword[j], pword[l]) == 0)
				{
					count++;
				}
			}

			// ���������� �ߺ� Ƚ���� ���ؼ�, �ִ밪�̸� �����ϱ�
			if (maxcount < count)
			{
				maxcount = count;
				strcpy(maxtmp, pword[j]);
			}
			// �ִ� �ߺ� Ƚ���� ������, ���� ������ ���� ���� �ܾ� ��� 
			else if (maxcount == count && strcmp(maxtmp, pword[j]) > 0)
			{
				strcpy(maxtmp, pword[j]);
			}

			// �ʱ�ȭ
			count = 0;
		}
		// ���������� ���ڿ�, ���ڿ� �ܾ� ��, �ߺ� Ƚ���� ���� ���� �ܾ�, �� �ܾ��� �ߺ� Ƚ���� ����Ѵ�.
		printf("%s %d %s %d\n", p[i].str, p[i].words, maxtmp, maxcount);

		// �����Ҵ� ���� 2���� �迭 ���� �޸𸮸� �����Ѵ�.
		for (j = 0; j < p[i].words; j++)
			free(pword[j]);
		free(pword);
	}

	// ����ü�� �� ���ڿ��� ���� �޸𸮸� �����Ѵ�.
	for (i = 0; i < N; i++)
		free(p[i].str);
	free(p);

	return 0;
}

// 2�� ���� 5 - 1
/*
// ����ü ����
struct string {
	char* str;
	int words;
};

int main()
{
	// �ʿ��� ���� ����
	char temp[101];			// �ӽ÷� ���ڿ��� ������ ����
	int N, i, j, len;
	struct string* p = NULL, tmp;

	// N�� �Է¹��� ��, N�� ���� ����ü �迭�� �����Ѵ�.
	scanf("%d", &N); getchar();
	p = (struct string*)malloc(N * sizeof(struct string));
	if (p == NULL)				// �޸� �����Ҵ� Ȯ�� 
	{
		printf("Memory is not allocated\n");
		return -1;
	}

	// ����ü �迭�� ũ�⸸ŭ ��ȸ
	for (i = 0; i < N; i++)
	{
		// �� ����ü�� str���� �����Ҵ��� �޴´�.
		gets(temp);
		len = strlen(temp);		// �Է��� ���ڿ��� ���̸� �޴´�.
		p[i].str = (char*)malloc((len + 1) * sizeof(char));	// ���ڿ��� ���� + 1 ��ŭ ũ�⸦ �����޾� �����Ҵ��Ѵ�.
		if (p[i].str == NULL)	// �޸� �����Ҵ� Ȯ��
		{
			printf("Memory is not allocated\n");
			return -1;
		}
		strcpy(p[i].str, temp);	// �����Ҵ��� �Ϸ������ ���ڿ��� �����ؼ� ���� �Է��Ѵ�.

		p[i].words = 0;			// �ܾ��� ���� �ʱ�ȭ

		j = 0;
		// ���ڿ��� �ι��ڱ��� ��ȸ�Ѵ�.
		while (1)
		{	
			// �ܾ ������ �׸�ŭ �ܾ� ������ �߰��Ѵ�.
			if (p[i].str[j] == ' ' || p[i].str[j] == '\0') p[i].words++;
			if (p[i].str[j] == '\0') break;
			j++;
		}
	}

	// �ܾ��� ������ ���� ���ڿ��� ������������ �����Ѵ�.
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - (i + 1); j++)
		{
			// ���� ���ڿ��� �ܾ� ������ �� ������, �հ� �ڸ� �ٲٱ�
			if (p[j].words < p[j + 1].words)
			{
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}

	// ���ĵ� ���ڿ��� �� �ܾ��� ������ ����Ѵ�.
	for (i = 0; i < N; i++)
	{
		printf("%s %d\n", p[i].str, p[i].words);
	}

	// �� ����ü�� ���ڿ��� �����Ҵ��� ���� ���� �����Ѵ�.
	for (i = 0; i < N; i++)
		free(p[i].str);
	// ���������� ����ü �迭�� �����Ѵ�.
	free(p);

	return 0;
}
*/
// 2�� ���� 4 - 1
/*
// ����ü ����
struct reserve {
	int id;
	char grade[4];
	int price;
};

// �Լ� ����
void input(struct reserve* p, int N);
int cal_sum(struct reserve* p, int N, int id);

int main()
{
	// �ʿ��� ���� ����
	int N, id;
	struct reserve* parr = NULL;

	// N�� �Է¹��� ��, N��ŭ �����Ҵ��� �޴´�.
	scanf("%d", &N);
	parr = (struct reserve*)malloc(N * sizeof(struct reserve));
	if (parr == NULL)			// �޸� �����Ҵ� Ȯ��
	{
		printf("Memory is not allocated\n");
		return -1;
	}
	// ��id, Ƽ�� ��ް� Ƽ�� ������ �����Ѵ�.
	input(parr, N);

	// ���� id�� ���� �� Ž���Ѵ�.
	scanf("%d", &id);
	// id�� ���� Ž�� �� ���
	cal_sum(parr, N, id);

	free(parr); // �����Ҵ� �޸� ����

	return 0;
}

// ����ü �迭�� ������ �Է¹޴´�.
void input(struct reserve* p, int N)
{
	struct reserve* pt;
	// ������ Ƚ����ŭ ������ ����
	for (pt = p; pt < p + N; pt++)
	{
		// 1. id�� ����� �Է� �޴´�.
		scanf("%d %s", &pt->id, pt->grade);
		// 2. ����� ���뿡 ���� Ƽ�� �ݾ��� �����Ѵ�.
		if (strcmp(pt->grade, "VIP") == 0) pt->price = 140000;
		else if (strcmp(pt->grade, "R") == 0) pt->price = 110000;
		else if (strcmp(pt->grade, "S") == 0) pt->price = 85000;
		else if (strcmp(pt->grade, "A") == 0) pt->price = 55000;
	}
}

// id�� �޾Ƽ� �� ���� �ݾ��� ����Ͽ� ��ȯ�Ѵ�.
int cal_sum(struct reserve* p, int N, int id)
{
	int sum = 0;			// �� ���� �ݾ� �ʱ�ȭ
	struct reserve* pt;
	// ����ü �迭 ��ü�� ��ȸ�Ѵ�.
	for (pt = p; pt < p + N; pt++)
	{
		// id�� ã�� id�� ���
		if (pt->id == id)
		{
			// ������ ����ϰ�, �� ���� �ݾ׿� ���Ѵ�.
			printf("%s %d\n", pt->grade, pt->price);
			sum += pt->price;
		}
	}
	// �� ���� �ݾ��� ����Ѵ�.
	printf("%d", sum);
}
*/
