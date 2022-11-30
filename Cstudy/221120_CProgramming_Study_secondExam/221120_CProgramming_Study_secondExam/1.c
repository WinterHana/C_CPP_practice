#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{

	return 0;
}
/*
3 abc
abcabc abcabc
ABCabc ABCabc
abc abc abc abcd
*/
/*
int main()
{
	int N, i, j, stringLen, wordLen, count, maxCount = 0;
	char X[101], str[101], maxCountStr[101] = "none";
	char** Y;
	scanf("%d %s\n", &N, X);
	wordLen = strlen(X);
	Y = (char**)malloc(sizeof(char*) * N);
	if (Y == NULL)
	{
		printf("Memory is not allocated\n");
		return -1;
	}

	for (i = 0; i < N; i++) {
		gets(str);
		stringLen = strlen(str);
		Y[i] = (char*)malloc(sizeof(char) * (stringLen + 1));
		if (Y[i] == NULL)
		{
			printf("Memory is not allocated\n");
			return -1;
		}
		strcpy(Y[i], str);
	}

	for (i = 0; i < N; i++)
	{
		stringLen = strlen(str);
		count = 0;
		for (j = 0; j < stringLen; j++)
		{
			if (strncmp(Y[i] + j, X, wordLen) == 0)
			{
				count++;
				j += wordLen - 1;
				printf("%d\n", count);
			}
		}
		
		if (maxCount < count)
		{
			maxCount = count;
			strcpy(maxCountStr, Y[i]);
		}
	}

	printf("%s\n", maxCountStr);

	for (i = 0; i < N; i++)
	{
		free(Y[i]);
	}
	free(Y);

	return 0;
}
*/
/*
5 4 2
book desk pencil paper
orange apple banana lemon grape
red yellow green orange blue white black
candy cake icecream
july august september october november december
*/
/*
int main()
{
	int N, M1, M2, stringLen, i;
	char str[101], maxstr[101], minstr[101], M1word[21], M2word[21], * pt;
	char result[41];
	int maxLen = 0, minLen = 101, count;
	scanf("%d %d %d", &N, &M1, &M2); getchar();
	for (i = 0; i < N; i++)
	{
		gets(str);
		stringLen = strlen(str);
		if (maxLen < stringLen) 
		{
			strcpy(maxstr, str);
			maxLen = stringLen;
		}
		if (minLen > stringLen)
		{
			strcpy(minstr, str);
			minLen = stringLen;
		}
	}

	printf("%s\n%s\n", maxstr, minstr);

	count = 0;
	pt = maxstr;
	for (i = 0; i < maxLen; i++)
	{
		if (maxstr[i] == ' ' || maxstr[i] == '\0')
		{
			maxstr[i] = '\0';
			count++;
			if (count > M1) break;
			pt = maxstr + i + 1;
			
		}
	}
	strcpy(M1word, pt);

	count = 0;
	pt = minstr;
	for (i = 0; i < minLen; i++)
	{
		if (minstr[i] == ' ' || minstr[i] == '\0')
		{
			minstr[i] = '\0';
			count++;
			if (count > M2) break;
			pt = minstr + i + 1;
		}
	}
	strcpy(M2word, pt);

	if (strcmp(M1word, M2word) > 0)
	{
		strcpy(result, M2word);
		strcat(result, M1word);
	}
	else if (strcmp(M1word, M2word) < 0)
	{
		strcpy(result, M1word);
		strcat(result, M2word);
	}

	printf("%s\n", result);
	return 0;
}
*/