#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 응용 2번
/*
5
why why why so so so serious
icecream makes everything better and better
you make me smile
c language exam and exam and exam and exam
see you later later later later
*/
/*
struct string {
	char* str;
	int words;
};

int main()
{
	char temp[101];
	int N, i, j, k, l, len, wordcount, count, maxcount;
	struct string* p = NULL, tmp;
	char** pword = NULL;
	char* strtmp,*strp, maxtmp[101];

	scanf("%d", &N); getchar();
	p = (struct string*)malloc(N * sizeof(struct string));
	if (p == NULL)
	{
		printf("error...\n");
		return -1;
	}

	for (i = 0; i < N; i++)
	{
		gets(temp);
		p[i].str = (char*)malloc(101 * sizeof(char));
		if (p[i].str == NULL)
		{
			printf("error...\n");
			return -1;
		}
		strcpy(p[i].str, temp);

		// len = strlen(p[i].str, temp);
		len = strlen(p[i].str);
		p[i].words = 0;


		j = 0;
		while (1)
		{
			if (p[i].str[j] == ' ' || p[i].str[j] == '\0') p[i].words++;
			if (p[i].str[j] == '\0') break;
			j++;
		}
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - (i + 1); j++)
		{
			if (p[j].words < p[j + 1].words)
			{
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}

	for(i = 0; i < N; i++)
	{
		wordcount = p[i].words;
		pword = (char**)malloc(wordcount * sizeof(char*));
		if (pword == NULL)
		{
			printf("error...\n");
			return -1;
		}
		len = strlen(p[i].str);
		count = 0;
		k = 0;
		strp = p[i].str;
		for (j = 0; j <= len; j++)
		{
			if (p[i].str[j] == ' ' || p[i].str[j] == '\0')
			{
				p[i].str[j] = '\0';
				count = strlen(strp);
				pword[k] = (char*)malloc((count + 1)* sizeof(char));
				if (pword[k] == NULL)
				{
					printf("error...\n");
					return -1;
				}
				strcpy(pword[k], strp);

				k++;
				if(j != len) p[i] .str[j] = ' ';
				strp = p[i].str + j + 1;
			}
		}

		maxcount = 0;
		count = 0;
		for (j = 0; j < p[i].words; j++)
		{
			for (l = j; l < p[i].words; l++)
			{
				if (strcmp(pword[j], pword[l]) == 0)
				{
					count++;
				}
			}

			if (maxcount < count)
			{
				maxcount = count;
				strcpy(maxtmp, pword[j]);
			}

			else if (maxcount == count && strcmp(maxtmp, pword[j]) > 0)
			{
				strcpy(maxtmp, pword[j]);
			}

			count = 0;
		}
		printf("%s %d %s %d\n", p[i].str, p[i].words, maxtmp, maxcount);

		for (j = 0; j < p[i].words; j++)
			free(pword[j]);
		free(pword);		
	}

	for (i = 0; i < N; i++)
		free(p[i].str);
	free(p);

}
*/
// 응용 3번
/*
10
123 A
210 VIP
123 A
123 R
210 S
210 VIP
123 A
523 A
123 R
523 VIP
123
*/
/*
struct reserve {
	int id;
	char grade[4];
	int price;
};
void input(struct reserve* p, int N);
int cal_sum(struct reserve* p, int N, int id);

int main()
{
	int N, id;
	struct reserve* parr = NULL;

	scanf("%d", &N);
	parr = (struct reserve*)malloc(N * sizeof(struct reserve));
	
	input(parr, N);

	scanf("%d", &id);
	cal_sum(parr, N, id);
	return 0;
}

void input(struct reserve* p, int N)
{
	struct reserve* pt;
	for (pt = p; pt < p + N; pt++)
	{
		scanf("%d %s", &pt->id, pt->grade);
		if (strcmp(pt->grade, "VIP") == 0) pt->price = 140000;
		else if (strcmp(pt->grade, "R") == 0) pt->price = 110000;
		else if (strcmp(pt->grade, "S") == 0) pt->price = 85000;
		else if (strcmp(pt->grade, "A") == 0) pt->price = 55000;
	}
}

int cal_sum(struct reserve* p, int N, int id)
{
	int sum = 0;
	struct reserve* pt;
	for (pt = p; pt < p + N; pt++)
	{
		if (pt->id == id)
		{
			printf("%s %d\n", pt->grade, pt->price);
			sum += pt->price;
		}
		
	}
	printf("%d", sum);
}
*/
// 응용 1번
struct string {
	char* str;
	int words;
};
int main()
{
	char temp[101];
	int N, i, j, len;
	struct string* p = NULL, tmp;

	scanf("%d", &N); getchar();
	p = (struct string*) malloc(N * sizeof(struct string));
	if (p == NULL)
	{
		printf("error...\n");
		return -1;
	}

	for (i = 0; i < N; i++)
	{
		// gets_s(temp, 100);			// _s 마이크로소프트 제품
		gets(temp);
		p[i].str = (char *)malloc(101 * sizeof(char));
		if(p[i].str == NULL)
		{
			printf("error...\n");
			return -1;
		}
		strcpy(p[i].str, temp);

		// len = strlen(p[i].str, temp);
		len = strlen(p[i].str);
		p[i].words = 0;

		
		j = 0;
		while (1)
		{
			if (p[i].str[j] == ' ' || p[i].str[j] == '\0') p[i].words++;
			if (p[i].str[j] == '\0') break;
			j++;
		}
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - (i + 1); j++)
		{
			if (p[j].words < p[j + 1].words)
			{
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}

	for (i = 0; i < N; i++)
	{
		printf("%s %d\n", p[i].str, p[i].words);
	}

	for (i = 0; i < N; i++)
		free(p[i].str);
	free(p);

	return 0;
}

// 문제 3
/*
int Fibonacci(int num)
{
	if (num == 0) return 0;
	else if (num == 1) return 1;
	else
		return Fibonacci(num - 1) + Fibonacci(num - 2);
}

int main()
{
	int num;

	scanf("%d", &num);
	printf("%d\n", Fibonacci(num));

	return 0;
}
*/
// 문제 2
/*
int factorial(int num)
{
	if (num == 1) return 1;
	else return num * factorial(num - 1);
}

int main()
{
	int i, n;
	double sum = 1.0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		sum += 1.0 / factorial(i);
	}
	printf("%f\n", sum);

	return 0;
}
*/
// 문제 1
/*
int hcf(int num1, int num2);

int main()
{
	int num1, num2;
	scanf("%d %d", &num1, &num2);

	printf("%d", hcf(num1, num2));
	return 0;
}

int hcf(int num1, int num2)
{
	if (num2 != 0) return hcf(num2, num1 % num2);
	else return num1;
}
*/
