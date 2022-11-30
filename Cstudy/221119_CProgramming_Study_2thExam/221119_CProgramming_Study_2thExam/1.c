#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
int main()
{
	int a[11], b[11], alen = 0, blen = 0;
	int* pt, *qt, max, min;

	for (pt = a; pt < a + 11; pt++)
	{
		scanf("%d", pt);
		if (*pt == -1) break;
		alen++;
	}

	for (pt = b; pt < b + 11; pt++)
	{
		scanf("%d", pt);
		if (*pt == -1) break;
		blen++;
	}

	for (pt = a; pt < a + alen; pt++)
	{
		max = *pt;
		for (qt = pt; qt < a + alen; qt++)
		{
			if (max < *qt)
			{
				max = *qt;
				*qt = *pt;
				*pt = max;
			}
		}

		for (qt = b; qt < b + blen; qt++)
		{
			if (max < *qt)
			{
				max = *qt;
				*qt = *pt;
				*pt = max;
			}
		}
	}

	for (pt = b; pt < b + blen; pt++)
	{
		min = *pt;
		for (qt = pt; qt < b + blen; qt++)
		{
			if (*qt < min)
			{
				min = *qt;
				*qt = *pt;
				*pt = min;
			}
		}
	}

	for (pt = a; pt < a + alen; pt++)
		printf("%d ", *pt);
	printf("\n");
	for (pt = b; pt < b + blen; pt++)
		printf("%d ", *pt);
	return 0;
}
*/
/*
int passengerN(int n);
void rebooking(int* ar);
int changeseat(int* ar);

int main()
{
	int people[21];
	int N, i, *pt;
	scanf("%d", &N);
	for (pt = people; pt < people + N; pt++)
	{
		scanf("%d", pt);
	}

	printf("%d\n", passengerN(N));
	if (passengerN(N) == -1) return -1;

	rebooking(people);

	for (pt = people; pt < people + N; pt++)
	{
		printf("%d ", *pt);
	}
	printf("\n");

	return 0;
}
int passengerN(int n)
{
	if (n >= 5 && n <= 21) return 0;
	else return -1;
}

void rebooking(int* ar)
{
	int* pt, *pt2;
	int changeNo;
	for (pt = ar; *pt >= 1 && *pt <= 21; pt++)
	{
		for (pt2 = pt + 1; *pt2 >= 1 && *pt2 <= 21; pt2++)
		{
			if (*pt2 == *pt)
			{
				changeNo = changeseat(ar);
				*pt2 = changeNo;
			}
		}
	}
}

int changeseat(int* ar)
{
	int i;
	int* pt;
	int flag;
	for (i = 1; i <= 21; i++)
	{
		flag = 1;
		for (pt = ar; *pt >= 1 && *pt <= 21; pt++)
		{
			if (*pt == i) flag = 0;
		}

		if (flag) break;
	}

	return i;
}
*/
/*
3
3 7 6 5 5 -2 0
1 7 6 2 3 13 2 0
2 0

2
13 7 6 6 2 0
7 3 4 5 6 7 10 4 0
*/
/*
int* MAX(int ar[]);
int* MIN(int ar[]);
int main()
{
	int N, i, index;
	int ar[100];
	int* max, *min, *pt;
	scanf("%d", &N);
	
	for (i = 0; i < N; i++)
	{
		index = 0;
		while (1)
		{
			scanf("%d", ar + index);
			if (*(ar + index) == 0) break;
			index++;
		}
		max = MAX(ar);
		min = MIN(ar);

		// printf("%d %d\n", *max, *min);

		if (max > min)
		{
			if (min + 1 == max)
			{
				printf("none\n");
				continue;
			}

			for (pt = min + 1; pt < max; pt++)
			{
				printf("%d ", *pt);
			}
			printf("\n");
		}
		else if (max < min)
		{
			if (max + 1 == min) 
			{
				printf("none\n");
				continue;
			}
				
			for (pt = max + 1; pt < min; pt++)
			{
				printf("%d ", *pt);
			}
			printf("\n");
		}
		else if (max == min)
		{
			printf("none\n");
		}
	}
	return 0;
}

int* MAX(int ar[])
{
	int* pt, *max;

	max = ar;
	for (pt = ar; *pt != 0; pt++)
	{
		if (*max < *pt)
		{
			max = pt;
		}
	}

	return max;
}

int* MIN(int ar[])
{
	int* pt, * min;

	min = ar;
	for (pt = ar; *pt != 0; pt++)
	{
		if (*min > *pt)
		{
			min = pt;
		}
	}

	return min;
}
*/
/*
int Convertor(char x);
void StringAdd(char arr[], char ch, int index);

int main()
{
	char str[20];
	int stringLen;
	scanf("%s", str);
	stringLen = strlen(str);
	for (int i = 0; i < stringLen- 1; i++)
	{
		if (Convertor(str[i]) % 2 == 0 && Convertor(str[i + 1]) % 2 == 0)
		{
			printf("%d %d\n", Convertor(str[i]), Convertor(str[i + 1]));
			StringAdd(str, '*', i + 1);
			stringLen++;
			i++;
			printf("%s\n", str);
		}
		else if (Convertor(str[i]) % 2 == 1 && Convertor(str[i + 1]) % 2 == 1)
		{
			printf("%d %d\n", Convertor(str[i]), Convertor(str[i + 1]));
			StringAdd(str, '+', i + 1);
			stringLen++;
			i++;
			printf("%s\n", str);
		}
	}

	printf("%s\n", str);
	return 0;
}

int Convertor(char x)
{
	return x - '0';
}

void StringAdd(char arr[], char ch, int index)
{
	int stringLen = strlen(arr);
	for (int i = stringLen; i >= index; i--)
	{
		arr[i + 1] = arr[i];
	}
	arr[index] = ch;

}
*/
/*
I have a pen. I have an applepen. PPAP
pen
mouse
a
*/
/*
void changeWords(char strA[], char wordB[], char wordC[]);

int main()
{
	char strA[101], wordB[11], wordC[11];
	gets(strA);
	scanf("%s", wordB); getchar();
	scanf("%s", wordC);

	changeWords(strA, wordB, wordC);

	return 0;
}

// 원리 다시 연구해보기
void changeWords(char strA[], char wordB[], char wordC[])
{
	char result[251];
	int resultLen, wordBLen, wordCLen, Cindex, i, j, order = 0, lenGap;
	strcpy(result, strA);
	resultLen = strlen(result);
	wordBLen = strlen(wordB);
	wordCLen = strlen(wordC);
	lenGap = wordBLen - wordCLen;

	if (lenGap == 0) order = 0;
	else if (lenGap > 0) order = 1;
	else if (lenGap < 0) { order = -1; lenGap *= (-1); }

	i = 0;
	while (result[i] != '\0')
	{
		if (strncmp(&result[i], wordB, wordBLen) == 0)
		{
			if (order == 0)
			{
				for (j = 0; j < wordCLen; i++, j++)
				{
					result[i] = wordC[j];
				}
			}
			else if (order == -1)
			{
				for (j = resultLen; j >= i + wordBLen; j--)
				{
					result[j + lenGap] = result[j];
				}

				for (j = 0; j < wordCLen; i++, j++)
				{
					result[i] = wordC[j];
				}
				resultLen = strlen(result);
				i--;
			}
			else if (order == 1)
			{
				for (j = 0; j < wordCLen; i++, j++)
				{
					result[i] = wordC[j];
					// printf("%s\n", result);
				}

				for (j = i + lenGap; j < resultLen + 1; j++)
				{
					result[j - lenGap] = result[j];
					// printf("%s\n", result);
				}
				resultLen = strlen(result);
				i--;
			}
		}
		i++;
	}

	printf("%s\n", result);

	return result;
}
*/
// 1 2 3 4 5 4 3 2 3 4 2 -1
/*
int input(int* p);
int* sel_next(int* p);
int number(int* p, int* q);

int main()
{
	int index;
	int* start, * end;
	int x[100], result;

	index = input(x);

	start = x;
	do 
	{
		end = sel_next(start);
		result = number(start, end);
		printf("%d\n", result);
		start = end;
	} while (*(end + 1) != -1);
	
	return 0;
}
int input(int* p)
{
	int index = 0;
	while (1)
	{
		scanf("%d", p + index);
		index++;
		if (*(p + index - 1) == -1) break;
	}

	return index;
}

int* sel_next(int* p)
{
	int flag = -1, *pt;
	if (*p < *(p + 1)) flag = 1;
	else if (*p > *(p + 1)) flag = 0;

	if (flag)
	{
		for (pt = p; *(pt + 1) != -1; pt++)
		{
			if (*pt > *(pt + 1)) break;
		}
		return pt;
	}
	else
	{
		for (pt = p; *(pt + 1) != -1 ; pt++)
		{
			if (*pt < *(pt + 1)) break;
		}
		return pt;
	}
}

int number(int* p, int* q)
{
	int count = 1, result = 0;
	int* pt;
	for (pt = q; pt >= p; pt--)
	{
		result += (*pt) * count;
		count *= 10;
	}
	return result;
}
*/
/*
7 3
Aaaaa 75 85
Bbbbb 86 77
Ccccc 94 82
Ddddd 78 70
Eeeee 65 85
Fffff 83 90
Ggggg 90 70
*/
/*
struct person {
	char name[11];
	int exam;
	int interview;
	double sum;
};

void swap(struct person* p, struct person* q);

int main()
{
	int N, M, i, j;
	struct person arr[100];
	scanf("%d %d", &N, &M); getchar();
	for (i = 0; i < N; i++)
	{
		scanf("%s %d %d", arr[i].name, &arr[i].exam, &arr[i].interview);
		arr[i].sum = 0.8 * arr[i].exam + 0.2 * arr[i].interview;
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - (i + 1); j++)
		{
			if (arr[j].sum < arr[j + 1].sum)
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}

	for (i = 0; i < M; i++)
	{
		printf("%s %.1f\n", arr[i].name, arr[i].sum);
	}
	return 0;
}

void swap(struct person* p, struct person* q)
{
	struct person tmp;
	tmp = *p;
	*p = *q;
	*q = tmp;
}
*/
// simple is best
// i am a boy
/*
int main()
{
	char str[201], *pt;
	char words[20][201], tmp[201];
	int stringLen, i, j, index = 0;
	gets(str);
	stringLen = strlen(str);
	
	pt = str;
	for (i = 0; i < stringLen + 1; i++)
	{
		if (str[i] == ' '|| str[i] == '\0')
		{
			str[i] = '\0';
			strcpy(words[index], pt);
			pt = str + i + 1;
			index++;
		}
	}

	for (i = 0; i < index; i++)
	{
		printf("%s\n", words[i]);
	}

	for (i = 0; i < index; i++)
	{
		for(j = 0; j < index - (i + 1); j++)
		{
			if (strcmp(words[j], words[j + 1]) > 0)
			{
				strcpy(tmp, words[j]);
				strcpy(words[j], words[j + 1]);
				strcpy(words[j + 1], tmp);
			}
		}
	}

	for (i = 0; i < index; i++)
	{
		printf("%s ", words[i]);
	}
	printf("\n");

	return 0;
}
*/