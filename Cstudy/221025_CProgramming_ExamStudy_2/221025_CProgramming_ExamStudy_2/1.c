#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char a[101], b[101], cpyA[101][50], cpyB[101][50];
	char result[251] = {0};
	int n = 0, m = 0, iterator = 0, flag = 0;
	char* pt = a;
	char* pt2 = b;
	gets(a);
	gets(b);

	// ¾ÆÀÕ½ËÆÈ ¼ø¼­
	int alen = strlen(a);
	int blen = strlen(b);

	for (int i = 0; i <= alen; i++)
	{
		if (a[i] == ' ' || a[i] == '\0')
		{
			a[i] = '\0';
			strcpy(cpyA[n], pt);
			pt = a + i + 1;
			n++;
		}
	}

	for (int i = 0; i <= blen; i++)
	{
		if (b[i] == ' ' || b[i] == '\0')
		{
			b[i] = '\0';
			strcpy(cpyB[m], pt2);
			pt2 = b + i + 1;
			m++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			if (strcmp(cpyA[i], cpyA[j]) == 0 && i != j)
			{
				strcpy(cpyA[i], cpyB[iterator]);
				iterator++;
			}
		}
	}
	/*
	for (i = 0; i < N3; i++) {
		flag = 0;
		for (j = 0; j < i; j++) {
			if (strcmp(str3[i], str3[j]) == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			strcat(res, str4[T]);
			strcat(res, " ");
			T++;
		}
		else {
			strcat(res, str3[i]);
			strcat(res, " ");
		}
	}
	*/
	for (int i = 0; i < n; i++)
	{
		strcat(result, cpyA[i]);
		strcat(result, " ");
	}

	printf("%s\n", result);

	return 0;
}
/*
void StringAdd(char arr[], char ch, int index);
int Convertor(char x);
int main()
{
	char str[20];
	int len, i;
	int front, back;
	scanf("%s", str);
	len = strlen(str);


	for (i = 0; i < len - 1; i++)
	{
		front = Convertor(str[i]);
		back = Convertor(str[i + 1]);
		if (front % 2 == 0 && back % 2 == 0)
		{
			StringAdd(str, '*', i + 1);
			i++;
			len++;
		}
		else if (front % 2 == 1 && back % 2 == 1)
		{
			StringAdd(str, '+', i + 1);
			i++;
			len++;
		}
	}

	printf("%s\n", str);
	return 0;
}

void StringAdd(char arr[], char ch, int index)
{
	int i;
	int len = strlen(arr);
	for (i = len + 1; i >= index; i--)
	{
		arr[i + 1] = arr[i];
	}

	arr[index] = ch;
}

int Convertor(char x)
{
	return x - '0';
}
*/
/*
int s_check(char* p, char* q);

int main()
{
	char string[10][201]; 
	int k1, k2;
	int M;
	int result;
	scanf("%d", &M);
	scanf("%d %d", &k1, &k2);
	getchar();

	for (int i = 0; i < M; i++)
	{
		gets(string[i]);
	}

	for (int i = 0; i < M; i++)
	{
		result = s_check(&string[i][k1], &string[i][k2]);
		if (result > 0) printf("%d\n", result);
	}

	return 0;
}

int s_check(char* p, char* q)
{
	int count = 0;
	char* cp;
	for (cp = p; cp <= q; cp++)
	{
		if (*cp >= 'a' && *cp <= 'z') count++;
	}
	return count;
}
*/