#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
// 문제 4-2
int main()
{
	char str1[101], str2[101], result[251] = "";
	gets(str1);
	gets(str2);

	int str1Len = strlen(str1);
	int str2Len = strlen(str2);

	char *pwords[101], *changeWords[101], tmp[100][100];
	int pwordsCnt = 0;
	int changeWordsCnt = 0;
	int count = 0;

	for (int i = 0; i < str1Len; i++)
	{
		if (str1[i] == ' ') str1[i] = '\0';
	}

	for (int i = 0; i < str2Len; i++)
	{
		if (str2[i] == ' ') str2[i] = '\0';
	}

	for (int i = 0; i < str1Len; i++)
	{
		if (i == 0 || (i >= 1 && str1[i - 1] == '\0'))
		{
			pwords[pwordsCnt] = &str1[i];
			pwordsCnt++;
		}
	}

	for (int i = 0; i < str2Len; i++)
	{
		if (i == 0 || (i >= 1 && str2[i - 1] == '\0'))
		{
			changeWords[changeWordsCnt] = &str2[i];
			changeWordsCnt++;
		}
	}

	for (int i = 0; i < pwordsCnt; i++)
	{
		strcpy(tmp[i], pwords[i]);
	}

	/*
	for (i = 0, N3 = 0; i <= N1; i++) {
		if (str1[i] == ' ' || str1[i] == '\0') {
			str1[i] = '\0';
			strcpy(str3[N3], p);
			p = str1 + i + 1;
			N3++;
		}
	}

	N2 = strlen(str2);
	p = str2;
	for (i = 0, N4 = 0; i <= N2; i++) {
		if (str2[i] == ' ' || str2[i] == '\0') {
			str2[i] = '\0';
			strcpy(str4[N4], p);
			p = str2 + i + 1;
			N4++;
		}
	}
	*/

	for (int i = 0; i < pwordsCnt; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			if (i != j && strcmp(tmp[i], tmp[j]) == 0)
			{
				strcpy(tmp[i], changeWords[count]);
				count++;
			}
		}
	}

	for (int i = 0; i < pwordsCnt; i++)
	{
		if (i == 0)
		{
			strcat(result, tmp[i]);
		}
		else
		{
			strcat(result, " ");
			strcat(result, tmp[i]);
		}
	}

	printf("%s", result);


	return 0;
}

/*
void StringAdd(char arr[], char ch, int index);
int Convertor(char x);


int main()
{
	char str[20];
	scanf("%s", str);
	int stringLen = strlen(str);
	for (int i = 0; i < stringLen; i++)
	{
		if (Convertor(str[i]) % 2 == 0 && Convertor(str[i+1]) % 2 == 0 && str[i + 1] != '\0')
		{
			StringAdd(str, '*', i + 1);
			i++;
			stringLen++;
		}

		else if (Convertor(str[i]) % 2 == 1 && Convertor(str[i + 1]) % 2 == 1 && str[i + 1] != '\0')
		{
			StringAdd(str, '+', i + 1);
			i++;
			stringLen++;
		}
	}

	printf("%s", str);
	return 0;
}

void StringAdd(char arr[], char ch, int index)
{
	int i;
	int last = strlen(arr);
	for (i = last + 1; i >= index; i--)
	{
		arr[i + 1] = arr[i];
	}
	arr[index] = ch;
}

int Convertor(char x)
{
	return x - 48;
}
*/
/*
struct person {
	char name[10];
	int year, month, day;
	int exam, interview;
	double total;
};

void swap(struct person* p, struct person* q);

int main()
{
	struct person arr[100];
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%s ", arr[i].name);
		scanf("%d-%d-%d", &arr[i].year, &arr[i].month, &arr[i].day);
		scanf("%d %d", &arr[i].exam, &arr[i].interview);
		arr[i].total = arr[i].exam * 0.8 + arr[i].interview * 0.2;
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[j].total < arr[j + 1].total)
				swap(&arr[j], &arr[j + 1]);
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[j].total == arr[j + 1].total && arr[j].exam < arr[j + 1].exam)
				swap(&arr[j], &arr[j + 1]);
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[j].total == arr[j + 1].total && arr[j].exam == arr[j + 1].exam && arr[j].interview == arr[j+1].interview)
			{
				if (arr[j].year < arr[j+1].year)
					swap(&arr[j], &arr[j + 1]);
				else if (arr[j].year == arr[j + 1].year && arr[j].month < arr[j+1].month)
					swap(&arr[j], &arr[j + 1]);
				else if (arr[j].year == arr[j + 1].year && arr[j].month == arr[j + 1].month && arr[j].day < arr[j+1].day)
					swap(&arr[j], &arr[j + 1]);
				
			}
		}
	}
	
	for (int i = 0; i < M; i++)
	{
		printf("%s %.1f\n", arr[i].name, arr[i].total);
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

/*
int input(int* p);
int* sel_next(int* p);
int number(int* p, int* q);

int main()
{
	int arr[100];
	int* p1, *p2;
	int M = input(arr);
	int printNumber;
	p1 = arr;
	while (1)
	{
		p2 = sel_next(p1);
		printNumber = number(p1, p2);
		printf("%d\n", printNumber);
		if (*(p2 + 1) == -1) break;
		p1 = p2;
	}
	
	return 0;
}

int input(int* p)
{
	int* i;
	int count = 0;
	for (i = p; i < p + 100; i++)
	{
		scanf("%d", i);
		count++;
		if (*i == -1) break;
	}

	return count;
}


int* sel_next(int* p)
{
	int upper = -1;
	int* iterator = p;
	// upper =*p<*(p+1)?1:0; // 이걸로 요약이 가능함
	if (*p > *(p + 1)) upper = 0;
	else if (*p < *(p + 1)) upper = 1;

	// 이걸로 요약도 가능함
	//	if (flag==0 && !(*q<=*(q+1))){
	//		return q;
	//	}
	//	else if (flag==1 && !(*q>=*(q+1))){
	//		return q;
	//	}
	
	if (upper == 0)
	{
		while (*iterator + 1 != -1 && *iterator > *(iterator + 1))
		{
			iterator++;
			if (*iterator == -1)
			{
				iterator--;
				break;
			}
		}
	}
	else if (upper == 1)
	{
		while (*iterator + 1 != -1 && *iterator < *(iterator + 1))
		{
			iterator++;
			if (*iterator == -1)
			{
				iterator--;
				break;
			}
		}
	}

	return iterator;
}

int number(int* p, int* q)
{
	int* i;
	int k = 1;
	int result = 0;
	for (i = q; i >= p; i--)
	{
		result = result + (*i) * k;
		k = k * 10;
	}

	return result;
}
*/
/*
void input(int* p, int M);
int * sel_max(int* p, int M);
void output(int* p, int N);

int main()
{
	int in[100], out[100], * max, i, N, M;

	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
	{
		input(in, M);
		max = sel_max(in, M);
		out[i] = *max;
	}
	output(out, N);

	return 0;
}

void input(int* p, int M)
{
	int* pt;
	for (pt = p; pt < p + M; pt++)
	{
		scanf("%d", pt);
	}
}

int* sel_max(int* p, int M)
{
	int* max = p;
	int Maxcount = 0, count = 0;
	int* pt, *innerPt;
	for (pt = p; pt < p + M; pt++)
	{
		for (innerPt = p; innerPt < p + M; innerPt++)
		{
			if (*pt == *innerPt) count++;
			if (Maxcount < count)
			{
				max = pt;
				Maxcount = count;
			}
		}
		count = 0;
	}

	return max;
}

void output(int* p, int N)
{
	int * pt;
	for (pt = p; pt < p + N; pt++)
	{
		printf("%d ", *pt);
	}
}
*/
