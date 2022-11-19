#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 문제 3
int check_row(int** p, int M, int N);
int check_col(int** p, int M, int N);

int main()
{
	// 변수 선언
	int** arr;						// 이차원 배열을 담을 변수
	int M, N, i, j, value;
	int rowMax, colMax, result;

	// 행 X와 열 Y를 입력받는다
	scanf("%d %d", &M, &N);

	// 이차원 배열을 담을 공간을 동적할당 받는다.
	arr = (int**)malloc(M * sizeof(int*));
	if (arr == NULL)		// 메모리 할당 확인
	{
		printf("Insufficient Memory, Exiting...\n");
		return 0;
	}

	// 각 공간에 다시 정수형 배열을 동적할당 받는다.
	for (i = 0; i < M; i++)
	{
		arr[i] = (int*)malloc(N * sizeof(int));
		if (arr[i] == NULL)		// 메모리 할당 확인
		{
			printf("Insufficient Memory, Exiting...\n");
			return 0;
		}

		// 동적할당을 받은 후, 각 요소의 값을 0으로 초기화
		for (j = 0; j < N; j++)
		{
			arr[i][j] = 0;
		}
	}

	// 0 0 0을 입력받을 때까지, 행과 열, 그리고 value값을 입력받아 배열에 저장한다.
	while (1)
	{
		scanf("%d %d %d", &i, &j, &value);
		if (i == 0 && j == 0 && value == 0) break;		// 0 0 0을 입력받으면 탈출
		arr[i][j] = value;								// value를 통해 저장
	}

	// 입력이 끝난 후, 만들어진 2차원 배열을 출력한다.
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
			printf("%d ", arr[i][j]);		// 각 요소 출력
		printf("\n");
	}
	
	rowMax = check_row(arr, M, N);			// 각 행을 검사해서 연속된 0의 최대 수 반환
	colMax = check_col(arr, M, N);			// 각 열을 검사해서 연속된 0의 최대 수 반환

	result = (rowMax > colMax) ? rowMax : colMax;	// 두 값을 비교해서 더 큰 값을 결과로 저장

	printf("%d\n", result);					// 출력

	// 동적할당 메모리를 해제한다.
	for (i = 0; i < M; i++)
		free(arr[i]);
	free(arr);

	return 0;
}

int check_row(int** p, int M, int N)
{
	int i, j;
	int max = 0, count = 0;
	// 열은 고정
	for (j = 0; j < N; j++)
	{	
		// 각 행을 보기 위해 행을 순회하면서 검사한다.
		for (i = 0; i < M; i++)
		{
			if (p[i][j] == 0)		// 값이 0이면, count에 1 더하기
			{
				count++;
			}
			else					// 값이 0이 아니라면, 연속된 0이 끝났다는 뜻
			{
				if (max < count) max = count;		// 만약 최대값이 갱신됐다면, 갱신하기
				count = 0;							// count를 다시 세기 위해 0으로 초기화
			}
		}
		// 다른 행으로 넘어갈 때도, 최대값 검사 후 count를 초기화한다.
		if (max < count) max = count;
		count = 0;
	}
	// 구해진 최대 길이를 반환한다.
	return max;
}

int check_col(int** p, int M, int N)
{
	int i, j;
	int max = 0, count = 0;
	// 행은 고정
	for (i = 0; i < M; i++)
	{	
		// 각 열을 보기 위해 열을 순회하면서 검사한다.
		for (j = 0; j < N; j++)
		{
			if (p[i][j] == 0)	// 값이 0이면, count에 1 더하기
			{
				count++;
			}
			else				// 값이 0이 아니라면, 연속된 0이 끝났다는 뜻
			{
				if (max < count) max = count;		// 만약 최대값이 갱신됐다면, 갱신하기
				count = 0;							// count를 다시 세기 위해 0으로 초기화
			}
		}
		// 다른 행으로 넘어갈 때도, 최대값 검사 후 count를 초기화한다.
		if (max < count) max = count;
		count = 0;
	}
	// 구해진 최대 길이를 반환한다.
	return max;
}

// 문제 2
/*
int main()
{
	// 변수 선언
	// stringLen : 문자열의 길이 저장, wordLen : 단어의 길이 저장
	int N, i, j, wordLen, stringLen;
	// 조건에 맞는 문자열을 찾기 위한 변수
	int maxWordcount = 0, count = 0;
	// tmp : 임시로 문자열을 저장할 변수, maxString : 가장 많은 문자를 포함하는 문자열 저장
	char X[101], tmp[101], maxString[101] = "NONE";
	char* pt, *k, ** Y;

	// 정수 N과 공백을 포함하지 않는 문자열을 동시에 입력받는다.
	scanf("%d %s", &N, X); getchar();
	// 단어의 길이 저장
	wordLen = strlen(X);

	// Y에서 문자형 포인터 배열 선언
	Y = (char**)malloc(N * sizeof(char *));
	if (Y == NULL)		// 메모리 할당 확인
	{
		printf("Insufficient Memory, Exiting...\n");
		return 0;
	}
	
	// Y에 N개의 문자열을 저장하기 위해 선언함
	for (i = 0; i < N; i++)
	{
		gets(tmp);
		stringLen = strlen(tmp);								// 입력받은 문자열의 길이를 받아서
		Y[i] = (char*)malloc((stringLen + 1) * sizeof(char));	// 문자열의 크기 + NULL문자(1)만큼 동적할당
		if (Y[i] == NULL) // 메모리 할당 확인
		{
			printf("Insufficient Memory, Exiting...\n");
			return 0;
		}
		strcpy(Y[i], tmp);										// 동적 할당된 공간에 임시 저장된 문자열 저장하기
	}

	// 가장 많이 문자가 나타나는 문자열 찾기
	for (i = 0; i < N; i++)
	{
		stringLen = strlen(Y[i]);
		// 문자열을 순회하면서 동일한 단어 찾기
		for (k = Y[i]; k < Y[i] + stringLen; k++)
		{
			// 동일한 단어를 찾았으면, count를 늘리고 곧바로 단어 다음 위치로 가게 함
			if (strncmp(k, X, wordLen) == 0)
			{
				count++;
				k += (wordLen - 1);
			}
		}

		// 더 많은 단어를 포함하고 있는 문자열을 찾았으면 갱신해주기
		if (count > maxWordcount)
		{
			maxWordcount = count;			// 가장 많은 단어가 포함된 개수 저장
			strcpy(maxString, Y[i]);		// 문자열 저장
		}
		count = 0;							// count 초기화 후 다시 하기
	}

	printf("%s\n", maxString);				// 조건에 맞는 문자열 출력


	// 포인터 배열 내의 동적할당 메모리를 먼저 해제
	for (i = 0; i < N; i++)
		free(Y[i]);
	// 포인터 배열 동적할당 메모리 해제
	free(Y);

	return 0;
}
*/
// 문제 1 - 2
/*
int main()
{
	// 변수 선언
	int N, M1, M2, i, count, minLen = 101, maxLen = 0;		// minlen, maxLen으로 긴 문자열, 짧은 문자열의 길이 저장
	char tmp[101], maxStr[101], minStr[101];				// tmp은 임시로 문자열을 지정함
	char word1[101], word2[101], result[101] = "";			// 조건에 맞는 단어를 word1, word2에서 저장, result에서 결과 문자열 저장
	char* pt;

	// N, M1, M2 저장
	scanf("%d %d %d", &N, &M1, &M2);
	getchar();

	// 문자열을 입력받아서,  가장 긴, 짧은 문자열 가져오기
	for (i = 0; i < N; i++)
	{
		gets(tmp);
		if (strlen(tmp) > maxLen)		// 긴 문자열 저장하기
		{
			strcpy(maxStr, tmp);
			maxLen = strlen(maxStr);
		}
		if (strlen(tmp) < minLen)		// 짧은 문자열 저장하기
		{
			strcpy(minStr, tmp);
			minLen = strlen(minStr);
		}
	}

	// 가장 긴, 짧은 문자열 저장하기
	printf("%s \n%s \n", maxStr, minStr);

	// 가장 긴 문자열에서. M1번째 단어를 가져온다.
	count = 0;
	pt = maxStr;
	for (i = 0; i < maxLen + 1; i++)
	{
		if (maxStr[i] == ' ' || maxStr[i] == '\0')		// 공백이나 NULL문자일 때, NULL문자 삽입
		{
			maxStr[i] = '\0';
			strcpy(word1, pt);					// 단어 가져오기		
			pt = maxStr + i + 1;				// 시작 주소 초기화
			count++;				
		}
		if (count > M1) break;					// 단어를 찾았으면, 반복문 탈출
	}

	// 가장 짧은 문자열에서. M2번째 단어를 가져온다.
	count = 0;
	pt = minStr;
	for (i = 0; i < minLen + 1; i++)
	{
		
		if (minStr[i] == ' ' || minStr[i] == '\0')		// 공백이나 NULL문자일 때, NULL문자 삽입
		{
			minStr[i] = '\0';
			strcpy(word2, pt);					// 단어 가져오기
			pt = minStr + i + 1;				// 시작 주소 초기화
			count++;				
		}
		if (count > M2) break;					// 단어를 찾았으면, 반복문 탈출
	}

	// 두 단어를 사전 순서대로 합성하기
	if (strcmp(word1, word2) > 0)		// word2의 단어 순서가 더 앞일 때
	{
		strcat(result, word2);			
		strcat(result, word1);
	}
	else if (strcmp(word1, word2) < 0)	// word1의 단어 순서가 더 앞일 때
	{
		strcat(result, word1);
		strcat(result, word2);
	}

	// 결과 출력
	printf("%s\n", result);

	return 0;
}
*/
// 문제 1 - 1
/*
int main()
{
	// 각종 변수 선언
	int M, N, i, count, str1len, str2len;		// count : null 문자를 넣을 횟수 조절
	char str1[101], str2[101], word1[101], word2[101], result[101] = "";		// word1, word2에서 합칠 단어 저장, result에서 결과 단어 저장
	char* pt;

	// M, N 입력 받기
	scanf("%d %d", &M, &N);		
	getchar();

	// 공백이 포함된 문자열 받기
	gets(str1);
	gets(str2);

	// 각각의 문자열 길이를 받는다.
	str1len = strlen(str1);
	str2len = strlen(str2);

	// str1의 M번째 단어 찾기
	count = 0;
	pt = str1;		// str1의 첫번째 주소에서 시작
	for (i = 0; i < str1len + 1; i++)
	{
		// 순회하다가 만약 공백이나 NULL문자를 만났을 때. NULL문자를 그 자리에 삽입한다.
		if (str1[i] == ' ' || str1[i] == '\0')
		{
			str1[i] = '\0';
			strcpy(word1, pt);		// NULL문자를 삽입한 상태에서 strcpy로 단어를 가져온다.
			pt = str1 + i + 1;		// 다음 시작점을 NULL문자 다음으로 지정한다.
			count++;				// count를 증가시켜서, 단어 저장이 완료됐으면 끝낸다.
		}
		if (count > M) break;		// 조건이 만족하면 반복문 탈출
	}

	// str2의 N번째 단어 찾기 : 전 방법과 동일
	count = 0;
	pt = str2;			// str2의 첫번째 주소에서 시작
	for (i = 0; i < str2len + 1; i++)
	{
		// 순회하다가 만약 공백이나 NULL문자를 만났을 때.NULL문자를 그 자리에 삽입한다.
		if (str2[i] == ' ' || str2[i] == '\0')
		{
			str2[i] = '\0';
			strcpy(word2, pt);		// NULL문자를 삽입한 상태에서 strcpy로 단어를 가져온다.
			pt = str2 + i + 1;		// 다음 시작점을 NULL문자 다음으로 지정한다.
			count++;				// count를 증가시켜서, 단어 저장이 완료됐으면 끝낸다.
		}
		if (count > N) break;		// 조건이 만족하면 반복문 탈출
	}

	// 두 단어를 연결할 때, 빠른 단어 뒤에 순서가 늦은 단어를 연결한다
	if (strcmp(word1, word2) > 0)		// strcmp를 통해 단어를 비교 : 사전 순서상 word2가 더 빠름
	{
		strcat(result, word2);			// 조건에 맞게 단어를 result에 합친다.
		strcat(result, word1);
	}
	else if (strcmp(word1, word2) < 0)	// strcmp를 통해 단어를 비교 : 사전 순서상 word1가 더 빠름
	{
		strcat(result, word1);
		strcat(result, word2);
	}

	// 결과 출력
	printf("%s\n", result);

	return 0;
}
*/