#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>		// 새로운 헤더파일 선언
#include <stdlib.h>
int main()
{
	// 1. 이차원 배열을 이용해서 문자열 넣기에 익숙해지기
	/*
	int i;
	char num[3][5] = { "zero", "one", "two" };

	for (i = 0; i < 3; i++)
		printf("%s\n", num[i]);
	*/
	// 2. 문자형 포인터로 문자열 넣기
	/*
	char* pnum0 = "zero";
	char* pnum1 = "one";
	char* pnum2 = "two";

	char* pnum[3] = { "zero", "one", "two" };
	for (int i = 0; i < 3; i++)
		printf("%s\n", pnum[i]);
	*/
	// 3. 각 문자열에서 영어 소문자 'a'가 몇 번 나오는지 출력하기
	/*
	char str[3][20] = { "Time is gold", "No pain no gain", "No sweat no sweet" };
	// char *pstr[3] = { "Time is gold", "No pain no gain", "No sweat no sweet" }; // 포인터 배열로 바꿔서 실행해도 된다.
	
	int count;
	for (int i = 0; i < 3; i++)
	{
		count = 0;
		// 억지로 포인터 써보기
		for (char* j = str[i]; *j != '\0'; j++)
		{
			if (*j == 'a') count++;
		}

		for (int j = 0; str[i][j]; j++)
		{
			if (str[i][j] == 'a') count++;
		}
		printf("\"%s\"에서 문자 \'a\'가 %d번 나타남\n", str[i], count);
	}
	*/
	// 4. 문자열 관련 함수 쓰기
	/*
	char str[20] = "Hello World";
	printf("length : %d\n", strlen(str));

	char str1[6] = "Hello";
	strcpy(str1, "hi");
	printf("str1 : %s\n", str1);

	char s1[50] = "hi", s2[50] = "hello";
	int cmp_result = strcmp(s1, s2);

	if (cmp_result < 0)
		printf("%s가 %s보다 앞에 있습니다.\n", s1, s2);
	else if(cmp_result == 0)
		printf("%s가 %s와 같습니다.\n", s1, s2);
	else // cmp_result > 0
		printf("%s가 %s보다 뒤에 있습니다.\n", s1, s2);
	*/

	// 5. 실습해보기 [예제 10.6]
	/*
	char str1[21], str2[21];		// null문자 포함해서 크기 선언!
	char ch;						// 엔터를 입력받아서 버릴 변수
	scanf("%s", str1);
	scanf("%c", &ch);
	scanf("%s", str2);
	// 1) 길이 출력
	printf("%d %d\n", strlen(str1), strlen(str2));

	// 2) 사전 순으로 빠른 문자열 출력
	int strResult = strcmp(str1, str2);
	if (strResult < 0) printf("%s\n", str1);
	else if (strResult > 0) printf("%s\n", str2);
	else printf("동일");

	// 3) ABA형태의 새로운 문자열 생성
	char str3[61] = "";
	strcat(str3, str1);
	strcat(str3, str2);
	strcat(str3, str1);
	printf("%s\n", str3);
	*/

	// 6. 문자열 출력, 입력함수
	char str[10] = "Hi World";
	int ret = 1;

	ret = puts(str);				// 여기서 출력이 됨
	printf("return : %d\n", ret);
	
	char str1[10];
	gets_s(str, 10);
	printf("str : %s!!\n", str);

	int c;
	c = getchar();			// 개행 문자를 버리기 위해 쓰기도 했지...
	putchar(c);
	return 0;
}