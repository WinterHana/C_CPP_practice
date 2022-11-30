#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 문제 7
/*
red orange red yellow green red blue purple yellow
white black gray pink brown blush crimson garnet vermilion indigo
*/
/*
int splitWords(char str[], char* word[]);

int main()
{
	char strA[101], strB[101], result[251] = "";
	char* wordA[101], *wordB[101], *pt;
	int wordCountA, wordCountB, i, j;
	int Bindex = 0;
	gets(strA); gets(strB);

	wordCountA = splitWords(strA, wordA);
	wordCountB = splitWords(strB, wordB);
	
	// printf("%d %d\n", wordCountA, wordCountB);
	for (i = 0; i < wordCountA; i++)
	{
		printf("%s\n", wordA[i]);
	}
	for (i = 0; i < wordCountB; i++)
	{
		printf("%s\n", wordB[i]);
	}

	for (i = 0; i < wordCountA; i++)
	{
		for (j = i + 1; j < wordCountA; j++)
		{
			if (strcmp(wordA[i], wordA[j]) == 0)
			{
				wordA[j] = wordB[Bindex];
				Bindex++;
			}
		}
	}

	for (i = 0; i < wordCountA; i++)
	{
		printf("%s ", wordA[i]);
	}
	printf("\n");

	for (i = 0; i < wordCountA; i++)
	{
		strcat(result, wordA[i]);
		strcat(result, " ");
	}
	
	printf("%s\n", result);
	
	return 0;
}

int splitWords(char str[], char* word[])
{
	char* pt = str;
	int index = 0, wordLen;
	int stringLen = strlen(str);
	for(int i = 0; i < stringLen + 1; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			str[i] = '\0';
			wordLen = strlen(pt);
			word[index] = pt;
			pt = pt + wordLen + 1;
			index++;
		}
	}
	return index;
}
*/
// 문제 4
/*
struct student {
	char* name;
	int firstStage;
	int interview;
	double sum;
};

int main()
{
	int N, M, i, j, nameLen;
	struct student* arr = NULL, tmp, compare;
	char name[11];

	scanf("%d %d", &N, &M);
	M = (int) (N * M / 100.0f);
	arr = (struct student*)malloc(N * sizeof(struct student));
	if (arr == NULL)			// 메모리 할당 확인
	{
		printf("Memory is not allocated\n");
		return -1;
	}
	for (i = 0; i < N; i++)
	{
		scanf("%s", name);
		nameLen = strlen(name);
		arr[i].name = (char*)malloc((nameLen + 1) * sizeof(char));
		if (arr[i].name == NULL)			// 메모리 할당 확인
		{
			printf("Memory is not allocated\n");
			return -1;
		}
		strcpy(arr[i].name, name);
		scanf("%d %d", &arr[i].firstStage, &arr[i].interview);
		arr[i].sum = 7 * arr[i].firstStage + 3 * arr[i].interview;
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - (i + 1); j++)
		{
			if (arr[j].sum < arr[j + 1].sum)
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			else if ((arr[j].sum == arr[j + 1].sum) && (arr[j].firstStage < arr[j + 1].firstStage))
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	compare = arr[M - 1];
	for (i = M; i < N; i++)
	{
		if (compare.sum == arr[i].sum && compare.firstStage == arr[i].firstStage) M++;
		else break;
	}

	for (i = 0; i < M; i++)
	{
		printf("%s %d %d %.1f\n", arr[i].name, arr[i].firstStage, arr[i].interview, arr[i].sum / 10);
	}
	printf("%d\n", M);

	for (i = 0; i < N; i++) free(arr[i].name);
	free(arr);

	return 0;
}
*/
// 문제 5
/*
10
210 S
210 VIP
123 A
523 A
123 R
523 VIP
123 A
210 VIP
123 A
123 R
*/
/*
struct reserve {
	int id;
	char grade[4];
	int price;
};

struct tot_price {
	int id;
	int total_price;
};

void input(struct reserve* p, int N);
int cal_num(struct reserve* p, int N);
void cal_sum(struct reserve* p, int N, struct tot_price *q);

int main()
{
	int N, i, j;
	int count;
	struct reserve* arr = NULL;
	struct tot_price* totalArr = NULL, tmp;
	scanf("%d", &N);
	arr = (struct reserve*)malloc(N * sizeof(struct reserve));

	input(arr, N);
	count = cal_num(arr, N);

	totalArr = (struct tot_price*)malloc(count * sizeof(struct tot_price));
	cal_sum(arr, N, totalArr);

	for (i = 0; i < count; i++)
	{
		for (j = 0; j < count - (i + 1); j++)
		{
			if (totalArr[j].id > totalArr[j + 1].id)
			{
				tmp = totalArr[j];
				totalArr[j] = totalArr[j + 1];
				totalArr[j + 1] = tmp;
			}
		}
	}

	for (i = 0; i < count; i++)
	{
		printf("%d %d\n", totalArr[i].id, totalArr[i].total_price);
	}

	free(arr);
	return 0;
}

void input(struct reserve* p, int N)
{
	struct reserve *pt;
	for (pt = p; pt < p + N; pt++)
	{
		scanf("%d %s", &pt->id, pt->grade);
		if (strcmp(pt->grade, "VIP") == 0) pt->price = 140000;
		else if (strcmp(pt->grade, "R") == 0) pt->price = 110000;
		else if (strcmp(pt->grade, "S") == 0) pt->price = 85000;
		if (strcmp(pt->grade, "A") == 0) pt->price = 55000;
	}
}

int cal_num(struct reserve* p, int N)
{
	struct reserve* pt, *pt2;
	int flag = 1;
	int count = 0;
	for (pt = p; pt < p + N; pt++)
	{
		flag = 1;
		for (pt2 = pt; pt2 >= p; pt2--)
		{
			if (pt->id == pt2->id && pt2 != pt)
			{
				flag = 0;
				break;
			}
		}
		if (flag) count++;
	}
	return count;
}

void cal_sum(struct reserve* p, int N, struct tot_price* q)
{
	struct reserve* pt, * pt2;
	struct tot_price *qt;
	int flag = 1;
	int tot_count = 0;
	int i;
	for (pt = p; pt < p + N; pt++)
	{
		flag = 1;
		for (pt2 = pt; pt2 >= p; pt2--)
		{
			if (pt->id == pt2->id && pt2 != pt)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			q[tot_count].id = pt->id;
			tot_count++;
		}
	}

	for (qt = q; qt < q + tot_count; qt++)
	{
		qt->total_price = 0;
		for (pt = p; pt < p + N; pt++)
		{
			if (qt->id == pt->id)
			{
				qt->total_price += pt->price;
			}
		}
	}
}
*/

// 문제 6
/*
I have a pen. I have an applepen. PPAP.
pen
ki
mouse
sen
*/

int main()
{
	char A[101];
	char B[101], C[101];
	int Alen, Blen, Clen, i, j;
	gets(A);
	scanf("%s", B); getchar(); scanf("%s", C);
	Alen = strlen(A);
	Blen = strlen(B);
	Clen = strlen(C);
	i = 0;
	while (A[i] != '\0')
	{
		if (strncmp(A + i, B, Blen) == 0)
		{
			if (Blen == Clen)
			{
				for (j = 0; j < Clen; i++, j++)
				{
					A[i] = C[j];
				}
			}
			else if (Blen < Clen)
			{
				for (j = Alen; j >= i + Blen; j--)
				{
					A[j + (Clen - Blen)] = A[j];
					// printf("%s\n", A);
				}

				for (j = 0; j < Clen; i++, j++)
				{
					A[i] = C[j];
					// printf("%s\n", A);
				}
				Alen = strlen(A);
			}

			else if (Blen > Clen)
			{
				for (j = 0; j < Clen; i++, j++)
				{
					A[i] = C[j];
					// printf("%s\n", A);
				}

				for (j = i + 1; j < Alen + 1; j++)
				{
					A[j - (Blen - Clen)] = A[j];
					// printf("%s\n", A);
				}

				Alen = strlen(A);
			}
		}
		i++;
	}
	printf("%s\n", A);

	return 0;
}

// 문제 3
/*
red orange yellow green blue purple
pink red redorange orangered yellow black bluegreen white purple
*/
/*
int main()
{
	char A[101], B[101], result[101] = "", compare[101];
	int Alen, Blen, i, j, k, Awords = 0, Bwords = 0, tmp;
	char** parrA, ** parrB, *pt;
	int parrAlen = 0, parrBlen = 0;
	gets(A); gets(B);
	Alen = strlen(A); Blen = strlen(B);
	for (i = 0; i < Alen + 1; i++)
	{
		if (A[i] == ' ' || A[i] == '\0')
			Awords++;
	}
	
	for (i = 0; i < Blen + 1; i++)
	{
		if (B[i] == ' ' || B[i] == '\0')
			Bwords++;
	}

	parrA = (char**)malloc(Alen * sizeof(char*));
	parrB = (char**)malloc(Blen * sizeof(char*));

	// printf("%d %d\n", Awords, Bwords);
	pt = A;
	for (i = 0; i < Alen + 1; i++)
	{
		if (A[i] == ' ' || A[i] == '\0')
		{
			A[i] = '\0';
			tmp = strlen(pt);
			parrA[parrAlen] = (char*)malloc((tmp + 1) * sizeof(char));
			strcpy(parrA[parrAlen], pt);
			pt = pt + tmp + 1;
			parrAlen++;
		}
	}

	pt = B;
	for (i = 0; i < Blen + 1; i++)
	{
		if (B[i] == ' ' || B[i] == '\0')
		{
			B[i] = '\0';
			tmp = strlen(pt);
			parrB[parrBlen] = (char*)malloc((tmp + 1) * sizeof(char));
			strcpy(parrB[parrBlen], pt);
			pt = pt + tmp + 1;
			parrBlen++;
		}
	}
	
	for (i = 0; i < parrAlen; i++)
	{
		printf("%s\n", parrA[i]);
	}
	for (i = 0; i < parrBlen; i++)
	{
		printf("%s\n", parrB[i]);
	}
	

	for (i = 0; i < parrAlen; i++)
	{
		for (j = i + 1; j < parrAlen; j++)
		{
			strcpy(compare, parrA[i]);
			strcat(compare, parrA[j]);
			for (k = 0; k < parrBlen; k++)
			{
				if(strcmp(parrB[k], compare) == 0)
				{
					if (strlen(result) < strlen(compare))
					{
						strcpy(result, compare);
					}
					else if (strlen(result) == strlen(compare) && strcmp(result, compare) > 0)
					{
						strcpy(result, compare);
					}
				}

			}
			strcpy(compare, parrA[j]);
			strcat(compare, parrA[i]);
			for (k = 0; k < parrBlen; k++)
			{
				if (strcmp(parrB[k], compare) == 0)
				{
					if (strlen(result) < strlen(compare))
					{
						strcpy(result, compare);
					}
					else if (strlen(result) == strlen(compare) && strcmp(result, compare) > 0)
					{
						strcpy(result, compare);
					}
				}

			}
		}
	}
	printf("%s\n", result);
	free(parrA);
	free(parrB);
	return 0;
}
*/
// 문제 2
/*
5 abc
abcabc abcabc
ABCabc ABCabc
abc abc abcd
abcabcabc abcabcabc
abcabc abcabc abcabc
*/
/*
int main()
{
	int N, i, j;
	int tmpLen, XLen;
	char X[101], tmp[101], firstStr[101] = "", secondStr[101] = "";
	char** Y = NULL;
	int first = 0, second = 0, wordCount;
	scanf("%d %s", &N, X); getchar();
	XLen = strlen(X);
	Y = (char**)malloc(N * sizeof(char*));

	for (i = 0; i < N; i++)
	{
		gets(tmp);
		tmpLen = strlen(tmp);
		Y[i] = (char*)malloc((tmpLen + 1) * sizeof(char));
		strcpy(Y[i], tmp);
	}
	for (i = 0; i < N; i++)
	{
		wordCount = 0;
		for (j = 0; j < strlen(Y[i]); j++)
		{
			if (strncmp(Y[i] + j, X, XLen) == 0)
			{
				wordCount++;
				j += (XLen - 1);
			}
		}
		// printf("%d\n", wordCount);
		if (wordCount > first)
		{
			second = first;
			first = wordCount;
			strcpy(secondStr, firstStr);
			strcpy(firstStr, Y[i]);
		}
		else if (wordCount < first && wordCount > second)
		{
			second = wordCount;
			strcpy(secondStr, Y[i]);
		}
	}

	printf("%s\n%s\n", firstStr, secondStr);

	return 0;
}
*/
// 문제 1
/*
5
book desk pencil paper
orange apple banana lemon grape
red yellow green orange blue white black
cake candy icecream
august september july october november december
*/
/*
int main()
{
	int N, i;
	char maxString[101], minString[101], tmp[101];
	int maxLen = 0, minLen = 101, stringLen;
	char maxWord[101], minWord[101], result[101];
	int maxWordLen = 0, minWordLen = 101, tmpLen;
	char* pt;

	scanf("%d", &N); getchar();
	for (i = 0; i < N; i++)
	{
		gets(tmp);
		stringLen = strlen(tmp);
		if (maxLen < stringLen)
		{
			strcpy(maxString, tmp);
			maxLen = stringLen;
		}
		else if (minLen > stringLen)
		{
			strcpy(minString, tmp);
			minLen = stringLen;
		}
	}
	printf("%s\n%s\n", maxString, minString);

	pt = maxString;
	for (i = 0; i < maxLen + 1; i++)
	{
		if (maxString[i] == ' ' || maxString[i] == '\0')
		{
			maxString[i] = '\0';
			tmpLen = strlen(pt);
			if (minWordLen > strlen(pt))
			{
				strcpy(minWord, pt);
				minWordLen = strlen(pt);
			}
			pt = pt + tmpLen + 1;
		}
	}


	pt = minString;
	for (i = 0; i < minLen + 1; i++)
	{
		if (minString[i] == ' ' || minString[i] == '\0')
		{
			minString[i] = '\0';
			tmpLen = strlen(pt);
			if (maxWordLen < strlen(pt))
			{
				strcpy(maxWord, pt);
				maxWordLen = strlen(pt);
			}
			pt = pt + tmpLen + 1;
		}
	}
	
	if (strcmp(maxWord, minWord) > 0)
	{
		strcpy(result, minWord);
		strcat(result, maxWord);
	}
	else if (strcmp(maxWord, minWord) < 0)
	{
		strcpy(result, maxWord);
		strcat(result, minWord);
	}

	printf("%s\n", result);

	return 0;
}
*/