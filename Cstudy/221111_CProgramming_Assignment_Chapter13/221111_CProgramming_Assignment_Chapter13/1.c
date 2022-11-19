#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 문제 4 - 2
int main()
{
	return 0;
}
// 문제 2 - 3
/*
int countWords(char arr[]);
int splitWords(char** arr, char str[]);
void compareWords(char** arr1, char** arr2, int countWord1, int countWord2);
void sorting(char* arr[], int count);

int main()
{
	// 필요한 변수 선언
	char str1[101], str2[101];
	char** arr1 = NULL;
	char** arr2 = NULL;
	int countWord1, countWord2;
	int i, check;

	// 두 개의 문자열을 받는다.
	gets(str1);
	gets(str2);
	// 문자열의 단어 개수를 저장한다.
	countWord1 = countWords(str1);
	countWord2 = countWords(str2);

	// arr1에서 문자열의 단어 개수만큼 동적 할당을 한다.
	arr1 = (char**)malloc(countWord1 * sizeof(char*));
	if (arr1 == NULL)			// 메모리 동적 할당 성공여부 체크
	{
		printf("Memory is not allocated\n");
		return -1;
	}
	// arr2도 마찬가지로 문자열의 단어 개수만큼 동적 할당을 한다.
	arr2 = (char**)malloc(countWord2 * sizeof(char*));
	if (arr2 == NULL)			// 메모리 동적 할당 성공여부 체크
	{
		printf("Memory is not allocated\n");
		return -1;
	}

	// 단어마다 분리한 후, 그 단어 각각 동적할당을 한다.
	check = splitWords(arr1, str1);
	if (check == -1) return -1;		// 이때, 만약 동적할당에 실패했으면 프로그램으 끝낸다.
	check = splitWords(arr2, str2);
	if (check == -1) return -1;

	// 조건에 따른 단어 비교 후, 정렬하고 출력한다.
	compareWords(arr1, arr2, countWord1, countWord2);

	for (i = 0; i < countWord1; i++)
		free(arr1[i]);
	free(arr1);
	for (i = 0; i < countWord2; i++)
		free(arr2[i]);
	free(arr2);

	return 0;
}

// 단어의 개수를 저장한다.
int countWords(char str[])
{
	int countWord = 0, i;
	int stringLen = strlen(str);		// 받은 문자열에서 문자의 개수를 저장한다.
	// 순회를 하면서 만약 빈칸이나 널문자를 만나면, 
	// 단어를 하나 지나갔다고 생각해 단어 개수를 센다
	for (i = 0; i <= stringLen; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
			countWord++;
	}

	// 단어 개수 반환
	return countWord;
}

// 단어 단위로 문자열을 나누고 단어마다 동적배열을 한다.
int splitWords(char** arr, char str[])
{
	int i, len, word = 0;
	int stringLen = strlen(str);
	char* pt = str;
	for (i = 0; i <= stringLen + 1; i++)
	{
		// 빈칸이나, 널 문자를 만났을 때
		if (str[i] == '\0' || str[i] == ' ')
		{
			str[i] = '\0';			// 널 문자를 채우고
			len = strlen(pt);		// 문자의 길이를 알아낸 뒤
			arr[word] = (char*)malloc((len + 1) * sizeof(char));	// 그에 따라서 동적할당을 진행한다.
			if (arr[word] == NULL)			// 메모리 동적 할당 성공여부 체크
			{
				printf("Memory is not allocated\n");
				return -1;
			}
			strcpy(arr[word], pt);		// 동적할당이 완료되었으면 단어를 저장한다.
			// 또 다른 단어 저장을 위한 초기화 과정
			pt = str + i + 1;			
			word++;
		}
	}
	return 0;			// 아무 문제 없이 실행됐다면 0을 반환한다.
}

// 조건에 따른 단어 비교 후, 정렬하고 출력한다.
void compareWords(char** arr1, char** arr2, int countWord1, int countWord2)
{
	char compareString[101] = "";			// 비교할 문자열 저장
	char* tmp[101];							// 조건에 맞는 문자들을 저장할 포인터 배열
	char* tmp2;								// 정렬을 하기 위한 임시 변수
	int i, j, k, l, count = 0, flag = 1;
	for (i = 0; i < countWord2; i++)		// 각 단어마다 체크한다.
	{
		for (j = 0; j < countWord1; j++)
		{
			for (k = j + 1; k < countWord1; k++)
			{
				flag = 1;				// flag가 0일 때는 이미 같은 문자가 있다는 뜻이므로 바로 넘어간다.
				// 1. 앞단어 + 뒷단어 조합과 비교
				strcpy(compareString, arr1[j]);
				strcat(compareString, arr1[k]);
				for (l = 0; l < count; l++)
				{
					// 만약 이미 같은 문자가 있다면 바로 넘어간다.
					if (strcmp(compareString, tmp[l]) == 0)
					{
						flag = 0;
						break;
					}	
				}
				// 같은 문자가 없고, 조합한 단어과 같을 때, 임시 배열에 저장한다.
				if ((strcmp(arr2[i], compareString) == 0) && flag == 1) 
				{
					tmp[count] = arr2[i];
					count++;
				}

				flag = 1;
				// 2. 뒷단어 + 앞단어 조합과 비교
				strcpy(compareString, arr1[k]);
				strcat(compareString, arr1[j]);
				for (l = 0; l < count; l++)
				{
					// 만약 이미 같은 문자가 있다면 바로 넘어간다.
					if (strcmp(compareString, tmp[l]) == 0)
					{
						flag = 0;
						break;
					}
				}
				// 같은 문자가 없고, 조합한 단어과 같을 때, 임시 배열에 저장한다.
				if ((strcmp(arr2[i], compareString) == 0) && flag == 1)
				{
					tmp[count] = arr2[i];
					count++;
				}
			}
		}
	}

	// 조건에 맞게 정렬한다. 
	for (i = 0; i < count; i++)
	{
		for (j = 0; j < count - (i + 1); j++)
		{
			// 1. 단어의 길이를 내림차순으로 정렬한다.
			if (strlen(tmp[j]) < strlen(tmp[j + 1]))
			{
				tmp2 = tmp[j];
				tmp[j] = tmp[j + 1];
				tmp[j + 1] = tmp2;
			}
			// 2, 단어의 길이가 같다면, 사전 순서대로 정렬한다.
			else if ((strlen(tmp[j]) == strlen(tmp[j + 1])) && (strcmp(tmp[j], tmp[j + 1]) > 0))
			{
				tmp2 = tmp[j];
				tmp[j] = tmp[j + 1];
				tmp[j + 1] = tmp2;
			}
		}
	}

	// 최종 결과를 출력한다.
	for (i = 0; i < count; i++)
	{
		printf("%s\n", tmp[i]);
	}

}

void sorting(char* arr[], int count)
{
	int i, j;
	char* tmp;
	
	for (i = 0; i < count; i++)
	{
		for (j = 0; j < count - (i + 1); j++)
		{
			if (strlen(arr[j]) < strlen(arr[j + 1]))
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			else if ((strlen(arr[j]) == strlen(arr[j + 1])) && (strcmp(arr[j], arr[j + 1]) > 0))
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
*/
// 문제 1 - 2

// 구조체 선언
struct st {
	char* str;
	int cnt1;
	int cnt2;
	int num;
	int pos;
	int result;
};

// 함수 선언
void inputStr(struct st* parr, int N);
void inputInfo(struct st* parr, int N);
void sort(struct st* parr, int N);

int main()
{
	// 필요한 변수 선언
	int N, i;				
	struct st* parr = NULL;	
	// N을 입력 받은 뒤, N에 따라서 구조체 배열을 동적 할당 받는다.
	scanf("%d", &N); getchar();
	parr = (struct st*)malloc(N * sizeof(struct st));
	if (parr == NULL)			// 메모리 동적 할당 성공여부 체크
	{
		printf("Memory is not allocated\n");
		return -1;
	}
	inputStr(parr, N);			// 1. 문자열을 입력받는다.
	inputInfo(parr, N);			// 2. 그 문자열을 통해 필요한 정보를 받는다
	sort(parr, N);				// 3, result에 따라서 구조체 배열을 출력한다.

	// 최종 결과를 출력한다.
	for (i = 0; i < N; i++)
	{
		printf("%s\n", parr[i].str);
	}

	// 결과 출력 후 메모리를 반환받는다.
	for (i = 0; i < N; i++)
		free(parr[i].str);
	free(parr);
	return 0;
}

// 1. 문자열을 입력받는다.
void inputStr(struct st* parr, int N)
{
	int i, len;
	char tmp[101];		// 임시로 문자열을 저장할 변수
	for (i = 0; i < N; i++)
	{
		gets(tmp);				// 문자열을 입력받는다.
		// 문자열의 길이를 받아서 (그 크기 + 1)만큼 배열을 동적할당 한다. 
		len = strlen(tmp);		
		parr[i].str = (char*)malloc((len + 1) * sizeof(char));
		if (parr[i].str == NULL)	// 메모리 동적 할당 성공여부 체크
		{
			printf("Memory is not allocated\n");
			return -1;
		}
		// 동적할당 확인 후, 임시로 저장할 문자열을 최종적으로 저장한다.
		strcpy(parr[i].str, tmp);
	}
}

// 2. 문자열을 통해 필요한 정보를 받는다
void inputInfo(struct st* parr, int N)
{
	int i, j, k;
	int stringlen, flag, cnt2;
	char tmp[101];		
	// 자음의 개수를 알아내기 위해 모음으로 비교
	char vowel[10] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
	
	// 구조체마다 반복한다.
	for (i = 0; i < N; i++)
	{
		cnt2 = 0;
		strcpy(tmp, parr[i].str);			// 문자열을 쓰기 위해 임의의 변수에 임시 저장한다.
		stringlen = strlen(tmp);			// 1. 총 문자의 수를 받는다.		

		// 문자마다 비교를 한다.
		for (j = 0; j < stringlen; j++)
		{
			// 2. 문자가 알파벳일 경우, 자음을 찾는다.
			if ((tmp[j] >= 'a' && tmp[j] <= 'z') || (tmp[j] >= 'A' && tmp[j] <= 'Z'))
			{
				flag = 1;
				for (k = 0; k < 10; k++)
				{
					if (tmp[j] == vowel[k])
					{
						flag = 0; // 모음일 경우, 자음이 아니므로 다음 문자로 바로 넘어간다
						break;
					}
				}
				if (flag) cnt2++; // 자음일 경우, 자음을 찾는 변수에 +1를 해준다.
			}

			// 3. 문자가 숫자일 경우, 그 숫자와 위치를 찾는다.
			else if (tmp[j] >= '0' && tmp[j] <= '9')
			{
				parr[i].num = tmp[j] - '0';			// 숫자 저장
				parr[i].pos = j + 1;				// 숫자의 위치 저장 : 인덱스가 0부터 시작이므로 +1을 한다.
			}	
		}

		// 결과를 구조체에 저장한다.
		parr[i].cnt1 = stringlen;
		parr[i].cnt2 = cnt2;
		// 모든 수를 곱한 결과를 result에 저장한다.
		parr[i].result = parr[i].cnt1 * parr[i].cnt2 * parr[i].num * parr[i].pos;
	}
}

// 3, result에 따라서 구조체 배열을 출력한다.
void sort(struct st* parr, int N)
{
	int i, j;
	struct st tmp;
	
	// 입력된 순서를 유지해야하므로 버블 정렬을 이용한다.
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - (i + 1); j++)
		{	
			// result가 바로 뒤에 있는 것이 더 클 때 교환한다.
			if (parr[j].result < parr[j + 1].result)
			{
				tmp = parr[j];
				parr[j] = parr[j + 1];
				parr[j + 1] = tmp;
			}
		}
	}
}
