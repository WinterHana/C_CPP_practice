#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// <5주차 실습 - 구조체 응용(?)> 문제 2번
int main()
{
	char str[100], tmp[20][100] = { 0 }, max_word[100] = "";
	int i, j = 0, k = 0, N, max = 0;

	gets(str);
	N = strlen(str);
	for (i = 0; i < N; i++) {
		while (i < N && str[i] != ' ') {
			tmp[k][j++] = str[i++];
		}
		tmp[k][j] = '\0';
		j = 0;
		k++;
	}

	for (i = 0; i < k; i++) {
		if (strlen(tmp[i]) > max) {
			max = strlen(tmp[i]);
			strcpy(max_word, tmp[i]);
		}
	}
	printf("%s", max_word);

	return 0;
}
// <5주차 실습 - 구조체 응용> 문제 1번
/*
typedef struct student {
	char name[10];
	char num[11];
	char lastGrade;
} Student;

int main()
{
	Student students[5];
	char name[10];
	for (int i = 0; i < 5; i++)
	{
		scanf("%s %s %c", &students[i].name, &students[i].num, &students[i].lastGrade);
	}

	scanf("%s", name);

	for (int i = 0; i < 5; i++)
	{
		if (strcmp(students[i].name, name) == 0)
		{
			printf("%s %c", students[i].num, students[i].lastGrade);
			break;
		}
	}
	return 0;
}
 */
// <구조체> 문제 2번
/*
typedef struct time {
	int hour, min, second;
} Time;

int main()
{
	Time t1, t2;
	int t1Sum, t2Sum;
	int ans, ansHour, ansMin, ansSecond;

	scanf("%d", &t1.hour);
	scanf("%d", &t1.min);
	scanf("%d", &t1.second);
	scanf("%d", &t2.hour);
	scanf("%d", &t2.min);
	scanf("%d", &t2.second);

	t1Sum = t1.hour * 3600 + t1.min * 60 + t1.second;
	t2Sum = t2.hour * 3600 + t2.min * 60 + t2.second;

	ans = t2Sum - t1Sum;

	ansHour = ans / 3600;
	ans = ans % 3600;

	ansMin = ans / 60;
	ans = ans % 60;

	ansSecond = ans;

	printf("%d %d %d", ansHour, ansMin, ansSecond);

	return 0;
}
*/
// <구조체> 문제 1번
/*
typedef struct vector {
	int x, y, z;
} Vector;

int main()
{
	Vector v1, v2, ans;
	int dot;
	scanf("%d", &v1.x);
	scanf("%d", &v1.y);
	scanf("%d", &v1.z);
	scanf("%d", &v2.x);
	scanf("%d", &v2.y);
	scanf("%d", &v2.z);

	ans.x = v1.x * v2.x;
	ans.y = v1.y * v2.y;
	ans.z = v1.z * v2.z;

	dot = ans.x + ans.y + ans.z;

	printf("%d %d %d \n%d", ans.x, ans.y, ans.z, dot);
	return 0;
}
*/
// 문제 12번
/*
int main()
{
	char str1[101], str2[101];
	int len1, len2, flag = -1, count = 0;
	gets(str1);
	gets(str2);
	len1 = strlen(str1);
	len2 = strlen(str2);


	for (int i = 0; i < len1 - len2 + 1; i++)
	{
		flag = 1;
		for (int j = i; j < i + len2; j++)
		{
			if (str1[j] != str2[j - i])		// j - i가 중요! 헷갈렸음 ㅎ;
			{
				flag = 0;
				break;
			}
		}

		if (flag)
		{
			i += (len2 - 1);
			count++;
		}
	}

	printf("%d", count);
	return 0;
}
*/
// 문제 11번
/*
int main()
{
	char str1[81], str2[11];
	int len1, len2, flag;
	scanf("%s", str1);
	scanf("%s", str2);
	len1 = strlen(str1);
	len2 = strlen(str2);
	flag = -1;

	for (int i = 0; i < len1 - len2 + 1; i++)
	{
		flag = 1;
		for (int j = i; j < i + len2; j++)
		{
			if (str1[j] != str2[j - i])		// j - i가 중요! 헷갈렸음 ㅎ;
			{
				flag = 0;
				break;
			}
		}
		if (flag) break;
	}

	printf("%d %d", len1, flag);

	return 0;
}
*/
// 문제 10번
/*
#define SIZE 101

int main()
{
	int N, i, len, min_len = 100;
	char str[SIZE], min_word[SIZE];
	scanf("%d", &N);
	getchar();

	for (i = N; i > 0; i--)
	{
		gets(str);
		len = strlen(str);
		if (len < min_len)
		{
			min_len = len;
			strcpy(min_word, str);
		}
	}
	puts(min_word);

	return 0;
}
*/
// 문제 9번
/*
int check(char[]);

int main()
{
	char word[31];
	int i, len;
	scanf("%s", word);
	len = strlen(word);

	printf("%d %d\n", len, check(word));

	return 0;
}

int check(char word[])
{
	int i, len;
	len = strlen(word);

	for (int i = 0; i < len; i++)
	{
		if (word[i] != word[len - i - 1])		// NULL문자 빼야해서 -1을 추가했음
		{
			return 0;
		}
	}
	return 1;
}
*/