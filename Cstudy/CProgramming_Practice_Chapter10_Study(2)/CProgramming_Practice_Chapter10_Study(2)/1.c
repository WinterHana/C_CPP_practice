#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>		// ���ο� ������� ����
#include <stdlib.h>
int main()
{
	// 1. ������ �迭�� �̿��ؼ� ���ڿ� �ֱ⿡ �ͼ�������
	/*
	int i;
	char num[3][5] = { "zero", "one", "two" };

	for (i = 0; i < 3; i++)
		printf("%s\n", num[i]);
	*/
	// 2. ������ �����ͷ� ���ڿ� �ֱ�
	/*
	char* pnum0 = "zero";
	char* pnum1 = "one";
	char* pnum2 = "two";

	char* pnum[3] = { "zero", "one", "two" };
	for (int i = 0; i < 3; i++)
		printf("%s\n", pnum[i]);
	*/
	// 3. �� ���ڿ����� ���� �ҹ��� 'a'�� �� �� �������� ����ϱ�
	/*
	char str[3][20] = { "Time is gold", "No pain no gain", "No sweat no sweet" };
	// char *pstr[3] = { "Time is gold", "No pain no gain", "No sweat no sweet" }; // ������ �迭�� �ٲ㼭 �����ص� �ȴ�.
	
	int count;
	for (int i = 0; i < 3; i++)
	{
		count = 0;
		// ������ ������ �Ẹ��
		for (char* j = str[i]; *j != '\0'; j++)
		{
			if (*j == 'a') count++;
		}

		for (int j = 0; str[i][j]; j++)
		{
			if (str[i][j] == 'a') count++;
		}
		printf("\"%s\"���� ���� \'a\'�� %d�� ��Ÿ��\n", str[i], count);
	}
	*/
	// 4. ���ڿ� ���� �Լ� ����
	/*
	char str[20] = "Hello World";
	printf("length : %d\n", strlen(str));

	char str1[6] = "Hello";
	strcpy(str1, "hi");
	printf("str1 : %s\n", str1);

	char s1[50] = "hi", s2[50] = "hello";
	int cmp_result = strcmp(s1, s2);

	if (cmp_result < 0)
		printf("%s�� %s���� �տ� �ֽ��ϴ�.\n", s1, s2);
	else if(cmp_result == 0)
		printf("%s�� %s�� �����ϴ�.\n", s1, s2);
	else // cmp_result > 0
		printf("%s�� %s���� �ڿ� �ֽ��ϴ�.\n", s1, s2);
	*/

	// 5. �ǽ��غ��� [���� 10.6]
	/*
	char str1[21], str2[21];		// null���� �����ؼ� ũ�� ����!
	char ch;						// ���͸� �Է¹޾Ƽ� ���� ����
	scanf("%s", str1);
	scanf("%c", &ch);
	scanf("%s", str2);
	// 1) ���� ���
	printf("%d %d\n", strlen(str1), strlen(str2));

	// 2) ���� ������ ���� ���ڿ� ���
	int strResult = strcmp(str1, str2);
	if (strResult < 0) printf("%s\n", str1);
	else if (strResult > 0) printf("%s\n", str2);
	else printf("����");

	// 3) ABA������ ���ο� ���ڿ� ����
	char str3[61] = "";
	strcat(str3, str1);
	strcat(str3, str2);
	strcat(str3, str1);
	printf("%s\n", str3);
	*/

	// 6. ���ڿ� ���, �Է��Լ�
	char str[10] = "Hi World";
	int ret = 1;

	ret = puts(str);				// ���⼭ ����� ��
	printf("return : %d\n", ret);
	
	char str1[10];
	gets_s(str, 10);
	printf("str : %s!!\n", str);

	int c;
	c = getchar();			// ���� ���ڸ� ������ ���� ���⵵ ����...
	putchar(c);
	return 0;
}