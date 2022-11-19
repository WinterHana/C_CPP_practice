#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 문제 4
int s_check(char* p, char* q);

int main()
{
	int M;						// 문자열 반복 횟수
	int k1, k2;					// 체크할 범위 숫자
	char str[10][201];			// 각 문자열을 저장할 이차원 배열
	int count;					// 소문자 개수를 저장할 변수
	scanf("%d", &M);			// 필요한 정보를 입력받는다.
	scanf("%d %d", &k1, &k2);
	getchar();					// 남은 Enter키를 지우기 위해 getchar를 사용한다/

	for (int i = 0; i < M; i++)	// 반복해서 이차원 배열에 문자열을 저장한다.
	{
		gets(str[i]);			// 공백이 포함된 문자열이므로 gets 이용
	}

	for (int i = 0; i < M; i++)	// 입력받은 만큼, 조건을 체크해서 count를 출력한다.
	{			
		count = s_check(&(str[i][k1]), &(str[i][k2]));		// 소문자 개수를 반환받아서 count에 저장
		if (count > 0)			
		{
			printf("%d\n", count);		// 만약 count가 0 초과라면, 출력하기
		}
	}

	return 0;
}

// 주어진 주소의 내용을 차례대로 살펴서, 소문자의 개수를 반환한다.
int s_check(char* p, char* q)
{
	int count = 0;					// 소문자 개수 저장

	for (char* i = p; i <= q; i++)	// 처음 주소부터 끝 주소까지 차례로 순회
	{
		if (*i >= 'a' && *i <= 'z')	// 만약 내용이 영어 소문자라면, count에 +1를 한다.
		{
			count++;
		}
	}

	return count;			// 소문자 개수 반환
}
// 문제 3 - 2
/*
int checkStr(char* str, int strLen2);

int main()
{
	char str1[100], str2[100];			// 입력받을 두 문자열
	int count = 0;						// 독립된 단어의 개수를 저장할 변수
	gets(str1);							// 두 문자열을 입력받는다.
	gets(str2);

	int strLen1 = strlen(str1);			// 문자열 각각의 길이를 구한다.
	int strLen2 = strlen(str2);

	for (int i = 0; i < strLen1 - strLen2 + 1; i++)		// 문자열 str1 전체를 순회해서, 조건에 맞는 단어 찾기
	{	
		// 1. 단어가 동일 2. 단어의 양쪽을 점검해서 독립된 단어인지 확인하기
		// 이때, 2는 함수로 따로 만들어 점검한다.
		if (strncmp(&str1[i], str2, strLen2) == 0 && checkStr(&str1[i], strLen2))
		{
			count++;		// 조건에 맞다면, count를 올려준다.
		}
	}
	printf("%d\n", count);	// 마지막에 count를 출력
}

// 독립된 단어인지 확인해주는 함수
int checkStr(char* str1, int strLen2)
{
	// 단어 양쪽에 '.'이나 ' '이 존재한다면, 독립된 단어라고 판단하고 1을 반환한다.
	// 단어의 오른쪽 끝을 확인하기 위해서는 첫 글자에서 단어의 길이만큼 뒤로 가야해서 strLen2를 받는다.
	if ((*(str1 - 1) == '.' || *(str1 - 1) == ' ') && (*(str1 + strLen2) == '.' || *(str1 + strLen2) == ' '))
		return 1;
	// 독립된 단어가 맨 끝이거나 맨 처음에 있을 경우도 고려해서 1을 반환해준다.
	else if ((*(str1 - 1) < 'A' || *(str1 - 1) > 'z') && (*(str1 + strLen2) == '.' || *(str1 + strLen2) == ' ' || *(str1 + strLen2) == '\0'))
		return 1;
	// 위 조건이 아니라면 0을 반환한다.
	else
		return 0;
}
*/
// 문제 2 - 2
/*
int main()
{
	char str[201];				// 처음 입력받을 문자열 저장
	char splitStr[20][200];		// 분리된 문자열을 저장할 2차원 배열
	char addStr[20];			// 추가할 문자열을 저장
	int addStrCheck = 1;		// 추가 입력된 문자열을 배열에 넣을지 판단하는 변수
	char tmp[20];				// 교대를 위한 임시 배열
	char result[200] = "";		// 결과를 저장할 배열
	gets(str);					// 1. 문자열 입력
	scanf("%s", addStr);		// 2. 추가할 문자열 입력

	int i = 0;					// 이차원 배열의 행
	int j = 0;					// 이차원 배열의 열

	// 입력된 전체 문자열을 하나하나 순회해서 이차원 배열에 넣기
	for (int k = 0; k <= strlen(str); k++)
	{
		if (str[k] == ' ')			// 공백이라면, null문자를 넣고 다음 배열로 이동
		{
			splitStr[i][j] = '\0';
			i++;					// 행은 + 1
			j = 0;					// 열은 초기화
		}
		else						// 그 외의 문자는 삽입
		{
			splitStr[i][j] = str[k];
			j++;					// 열은 + 1
		}
	}

	// 추가 입력된 문자열이 이미 이차원 배열에 있는지 확인
	for (int k = 0; k <= i; k++)
	{
		// 있다면, 추가하지 않고 바로 반복문을 탈출한다.
		if (strcmp(addStr, splitStr[k]) == 0)
		{
			addStrCheck = 0;
			break;
		}
	}

	// 없다면, 이차원 배열에 문자열을 추가한다.
	if (addStrCheck)
	{
		i++;				// i를 먼저 + 1 해준 다음, 배열에 넣기
		strcpy(splitStr[i], addStr);
	}

	// 완성된 이차원 배열의 문자열들을 순회하며 출력한다.
	for (int k = 0; k <= i; k++)
	{
		printf("%s\n", splitStr[k]);
	}

	// 이차원 배열을 사전 순서대로 정렬한다.
	for (int k = 0; k <= i; k++)
	{
		for (int r = 0; r <= i; r++)
		{
			// 오름차순이 되도록 정렬하기
			if (strcmp(splitStr[k], splitStr[r]) < 0)
			{	
				// tmp을 이용해서 두 문자열을 교체한다.
				strcpy(tmp, splitStr[k]);
				strcpy(splitStr[k], splitStr[r]);
				strcpy(splitStr[r], tmp);
			}
		}
	}

	// strcat을 이용해서 result에 붙인다.
	for (int k = 0; k <= i; k++)
	{
		strcat(result, splitStr[k]);
		strcat(result, " ");			// 이때 공백문자도 넣기
	}

	// result 출력
	printf("%s", result);


	return 0;
}
*/
// 문제 1 - 2
/*
void changeStr(char str[], int N);			// 문자열 변경 함수
int checkStr(char str1[], char str2[]);		// 변경 가능 여부를 확인하는 함수

int main()
{
	
	char str1[100], str2[100];		// 두 문자열을 받을 변수
	gets(str1);						// 문자열을 입력받음
	gets(str2);

	int result = checkStr(str1, str2);
	printf("%d", result);
	
}

void changeStr(char str[], int N)
{
	char cpystr[100] = {0};			// 새로운 문자열을 저장할 변수
	int i = 0;						// str의 인덱스
	int k = 0;						// cpystr의 인덱스
	// 각 문자를 순회하면서 조건에 맞게 문자를 변경한다.
	for (i = 0, k = 0; i < strlen(str); i++, k++)
	{	
		// 대문자 : 아스키 코드표 순서로 N번째 뒤 문자
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			cpystr[k] = str[i] + N;		// 단순히 N을 더함
		}
		// 소문자 : 아스키 코드표 순서대로 N번째 앞 문자
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			cpystr[k] = str[i] - N;		// 단순히 N을 뺌
		}
		// 숫자 : 해당 숫자 번째의 알파벳 대문자를 N번 반복
		else if (str[i] >= '1' && str[i] <= '9')
		{
			// 문자열로 이어진 숫자를 int형으로 바꿈. 이때, ch에 더하기 위해 -1을 한다.
			int num = atoi(&str[i]) - 1;
			char ch = 'A' + num;					// 바꿔야 할 대문자를 구함
			for (int j = 0; j < N ; k++, j++)		// N번 만큼 반복하기
			{
				cpystr[k] = ch;
			}

			if (str[i + 1] >= '1' && str[i + 1] <= '9') i++;		// 만약 두 자리 숫자를 잡았다면, i 하나 더 증가시키기
			k = k - 1;												// 증가된 k 줄이기
		}
		// 그 외 : 공백으로 변경 
		else
		{
			cpystr[k] = ' ';
		}
	}
	cpystr[k] = '\0';				// 마지막에 null 문자 추가
	strcpy(str, cpystr);
}

int checkStr(char str1[], char str2[])
{
	char cpystr[100];					// 임시로 값을 저장할 변수
	// N이 1부터 10까지 반복
	for (int N = 1; N <= 10; N++)
	{
		// 1. A -> B 점검하기
		strcpy(cpystr, str1);			// 본 문자열을 복사하고
		changeStr(cpystr, N);			// 조건에 맞게 바꾼 다음
		if (strcmp(cpystr, str2) == 0)	// strcmp를 통해 비교한다.
		{
			return 1;					// A->B가 가능하다면 1를 반환한다.
		}

		// 1. B -> A 점검하기 : 1. 과 동일한 방식으로 진행한다.
		strcpy(cpystr, str2);			// 본 문자열을 복사하고
		changeStr(cpystr, N);			// 조건에 맞게 바꾼 다음
		if (strcmp(cpystr, str1) == 0)	// strcmp를 통해 비교한다.
		{
			return 2;					// B->A가 가능하다면 2를 반환한다.
		}
	}

	return 0;			// 둘 다 불가능하다면 0을 반환한다.
}
*/