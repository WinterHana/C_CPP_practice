#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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