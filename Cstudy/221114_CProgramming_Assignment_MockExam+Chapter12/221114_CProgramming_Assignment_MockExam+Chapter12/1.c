#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 2차 모의 4 - 2
/*
// 구조체 선언
struct reserve {
	int id;
	char grade[4];
	int price;
};

struct tot_price {
	int id;
	int total_price;
};

// 함수 선언
void input(struct reserve* p, int N);
int cal_num(struct reserve* p, int N);
void cal_sum(struct reserve* p, int N, struct tot_price* q);

int main()
{
	// 필요한 변수 선언
	int N;
	int wordsCount;
	struct reserve* parr = NULL;
	struct tot_price* totPrices = NULL, *pt;

	// N을 입력받은 후, N만큼 동적할당을 받는다.
	scanf("%d", &N);
	parr = (struct reserve*)malloc(N * sizeof(struct reserve));
	if (parr == NULL)			// 메모리 동적할당 확인
	{
		printf("Memory is not allocated\n");
		return -1;
	}
	// 고객id, 티켓 등급과 티켓 가격을 저장한다.
	input(parr, N);

	// 중복된 id를 제외한 고객의 수를 받는다.
	wordsCount = cal_num(parr, N);

	// 중복 없는 고객의 수 만큼 tot_price 타입의 구조체 배열을 동적할당한다.
	totPrices = (struct tot_price*)malloc(wordsCount * sizeof(struct tot_price));
	if (totPrices == NULL)			// 메모리 동적할당 확인
	{
		printf("Memory is not allocated\n");
		return -1;
	}

	// 티켓 구매에 사용한 총 금액을 계산하여 저장한다.
	cal_sum(parr, N, totPrices);

	// 고객 id와 티켓 구매 총 금액을 최종 출력한다.
	for (pt = totPrices; pt < totPrices + wordsCount; pt++)
	{
		printf("%d %d\n", pt->id, pt->total_price);
	}

	// 동적할당 메모리 해제
	free(parr);
	free(totPrices);

	return 0;
}

// 구조체 배열에 정보를 입력받는다.
void input(struct reserve* p, int N)
{
	struct reserve* pt;
	// 정해진 횟수만큼 정보를 받음
	for (pt = p; pt < p + N; pt++)
	{
		// 1. id와 등급을 입력 받는다.
		scanf("%d %s", &pt->id, pt->grade);
		// 2. 등급의 내용에 따라 티켓 금액을 저장한다.
		if (strcmp(pt->grade, "VIP") == 0) pt->price = 140000;
		else if (strcmp(pt->grade, "R") == 0) pt->price = 110000;
		else if (strcmp(pt->grade, "S") == 0) pt->price = 85000;
		else if (strcmp(pt->grade, "A") == 0) pt->price = 55000;
	}
}

int cal_num(struct reserve* p, int N)
{
	struct reserve* pt, *pt2;
	// flag : 이름이 중복된건지 확인함 , result : 최종 고객 수 저장
	int flag = 1, result = 0;		
	for (pt = p; pt < p + N; pt++)
	{
		flag = 1;
		// 시작 지점에서부터 뒤의 끝까지 순회한다.
		for (pt2 = pt; pt2 >= p; pt2--)
		{
			// 만약 같은 이름이 있다면 중복되었다고 판정
			if (pt->id == pt2->id && pt2 != pt)
			{
				flag = 0;
				break;
			}
		}
		// 뒤에 같은 이름이 없다면 새로운 id라고 생각하고 result를 +1 해준다.
		if (flag) result++;
	}
	// 최종 결과 반환
	return result;
}

void cal_sum(struct reserve* p, int N, struct tot_price* q)
{
	struct reserve* pt, *pt2;
	struct tot_price* qt;
	int qIndex = 0, flag = 1;		// qIndex : 중복되지 않은 id를 저장하기 위한 변수

	// 1. 중복되지 않게 id를 tot_price 타입의 배열에 저장한다.
	for (pt = p; pt < p + N; pt++)
	{
		flag = 1;
		for (pt2 = pt; pt2 >= p; pt2--)
		{
			// 중복된 이름이 있다면 그냥 넘어가기
			if (pt->id == pt2->id && pt2 != pt)
			{
				flag = 0;
			}
		}
		// 중복된 이름이 없다면 배열에 id를 추가한다.
		if (flag)
		{
			(q + qIndex)->id = pt->id;
			qIndex++;		// qIndex도 +1 해주기
		}
	}
	
	// 2. 같은 id를 찾아서 총합 계산하기
	for (qt = q; qt < q + qIndex; qt++)
	{
		qt->total_price = 0;		// 총합 계산 초기화
		for (pt = p; pt < p + N; pt++)
		{
			// 같은 id를 찾을 때마다 총 가격에 추가한다.
			if (qt->id == pt->id)
			{
				qt->total_price += pt->price;
			}
		}
	}
}
*/

// 2차 모의 5 - 2
// 구조체 선언
struct string {
char* str;
int words;
};

int main()
{
	// 필요한 변수 선언
	char temp[101];
	int N, i, j, k, l, len, wordcount, count, maxcount;
	struct string* p = NULL, tmp;
	char** pword = NULL;
	char* strtmp, * strp, maxtmp[101];

	// N을 입력받은 후, N에 따라서 구조체 배열을 선언한다.
	scanf("%d", &N); getchar();
	p = (struct string*)malloc(N * sizeof(struct string));
	if (p == NULL)				// 메모리 동적할당 확인 
	{
		printf("Memory is not allocated\n");
		return -1;
	}

	// 구조체 배열의 크기만큼 순회
	for (i = 0; i < N; i++)
	{
		// 각 구조체의 str에서 동적할당을 받는다.
		gets(temp);
		len = strlen(temp);		// 입력할 문자열의 길이를 받는다.
		p[i].str = (char*)malloc((len + 1) * sizeof(char));	// 문자열의 길이 + 1 만큼 크기를 배정받아 동적할당한다.
		if (p[i].str == NULL)	// 메모리 동적할당 확인
		{
			printf("Memory is not allocated\n");
			return -1;
		}
		strcpy(p[i].str, temp);	// 동적할당이 완료됐으면 문자열을 복사해서 최종 입력한다.

		p[i].words = 0;			// 단어의 개수 초기화

		j = 0;
		// 문자열의 널문자까지 순회한다.
		while (1)
		{
			// 단어가 있으면 그만큼 단어 개수를 추가한다.
			if (p[i].str[j] == ' ' || p[i].str[j] == '\0') p[i].words++;
			if (p[i].str[j] == '\0') break;
			j++;
		}
	}

	// 단어의 개수에 따라 문자열을 내림차순으로 정렬한다.
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - (i + 1); j++)
		{
			// 뒤의 문자열의 단어 개수가 더 많으면, 앞과 자리 바꾸기
			if (p[j].words < p[j + 1].words)
			{
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}

	// 각 문자를 단어로 나눠서 동적 할당받은 2차원 배열에 저장한다.
	for (i = 0; i < N; i++)
	{
		// 단어의 개수만큼 배열을 동적할당한다.
		wordcount = p[i].words;
		pword = (char**)malloc(wordcount * sizeof(char*));
		if (pword == NULL)		// 메모리 동적할당 확인
		{
			printf("Memory is not allocated\n");
			return -1;
		}
		// 문자열의 길이 파악
		len = strlen(p[i].str);
		count = 0;		// 단어의 길이 저장
		k = 0;			// 배열의 인덱스
		strp = p[i].str;		// 처음 단어의 시작 위치 = 문자열의 시작 위치
		for (j = 0; j <= len; j++)
		{
			// 단어가 나타날 때마다 동적 할당 준비
			if (p[i].str[j] == ' ' || p[i].str[j] == '\0')
			{
				p[i].str[j] = '\0';
				count = strlen(strp);		// 단어의 길이를 가져오고, 그 크기 + 1만큼 동적할당한다.
				pword[k] = (char*)malloc((count + 1) * sizeof(char));
				if (pword[k] == NULL)		// 메모리 동적할당 확인
				{
					printf("error...\n");
					return -1;
				}
				strcpy(pword[k], strp);		// 동적할당이 완료됐으면 단어를 저장한다.

				k++;		// 인덱스 증가
				if (j != len) p[i].str[j] = ' ';	// 널문자로 바꾼 띄어쓰기를 다시 원래대로 한다.
				strp = p[i].str + j + 1;	// 단어의 시작 위치 초기화
			}
		}

		// 각 문자열 마다 저장된 단어 중 중복 횟수가 가장 많은 단어를 찾는다.
		maxcount = 0;		// 최대 중복 횟수
		count = 0;			// 각 단어의 중복 횟수
		for (j = 0; j < p[i].words; j++)
		{
			// 중복된 단어를 찾았을 때 중복 횟수 증가
			for (l = j; l < p[i].words; l++)
			{
				if (strcmp(pword[j], pword[l]) == 0)
				{
					count++;
				}
			}

			// 최종적으로 중복 횟수를 비교해서, 최대값이면 갱신하기
			if (maxcount < count)
			{
				maxcount = count;
				strcpy(maxtmp, pword[j]);
			}
			// 최대 중복 횟수가 같으면, 사전 순서상 가장 빠른 단어 출력 
			else if (maxcount == count && strcmp(maxtmp, pword[j]) > 0)
			{
				strcpy(maxtmp, pword[j]);
			}

			// 초기화
			count = 0;
		}
		// 최종적으로 문자열, 문자열 단어 수, 중복 횟수가 가장 많은 단어, 그 단어의 중복 횟수를 출력한다.
		printf("%s %d %s %d\n", p[i].str, p[i].words, maxtmp, maxcount);

		// 동적할당 받은 2차원 배열 동적 메모리를 해제한다.
		for (j = 0; j < p[i].words; j++)
			free(pword[j]);
		free(pword);
	}

	// 구조체와 그 문자열의 동적 메모리를 해제한다.
	for (i = 0; i < N; i++)
		free(p[i].str);
	free(p);

	return 0;
}

// 2차 모의 5 - 1
/*
// 구조체 선언
struct string {
	char* str;
	int words;
};

int main()
{
	// 필요한 변수 선언
	char temp[101];			// 임시로 문자열을 저장할 변수
	int N, i, j, len;
	struct string* p = NULL, tmp;

	// N을 입력받은 후, N에 따라서 구조체 배열을 선언한다.
	scanf("%d", &N); getchar();
	p = (struct string*)malloc(N * sizeof(struct string));
	if (p == NULL)				// 메모리 동적할당 확인 
	{
		printf("Memory is not allocated\n");
		return -1;
	}

	// 구조체 배열의 크기만큼 순회
	for (i = 0; i < N; i++)
	{
		// 각 구조체의 str에서 동적할당을 받는다.
		gets(temp);
		len = strlen(temp);		// 입력할 문자열의 길이를 받는다.
		p[i].str = (char*)malloc((len + 1) * sizeof(char));	// 문자열의 길이 + 1 만큼 크기를 배정받아 동적할당한다.
		if (p[i].str == NULL)	// 메모리 동적할당 확인
		{
			printf("Memory is not allocated\n");
			return -1;
		}
		strcpy(p[i].str, temp);	// 동적할당이 완료됐으면 문자열을 복사해서 최종 입력한다.

		p[i].words = 0;			// 단어의 개수 초기화

		j = 0;
		// 문자열의 널문자까지 순회한다.
		while (1)
		{	
			// 단어가 있으면 그만큼 단어 개수를 추가한다.
			if (p[i].str[j] == ' ' || p[i].str[j] == '\0') p[i].words++;
			if (p[i].str[j] == '\0') break;
			j++;
		}
	}

	// 단어의 개수에 따라 문자열을 내림차순으로 정렬한다.
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - (i + 1); j++)
		{
			// 뒤의 문자열의 단어 개수가 더 많으면, 앞과 자리 바꾸기
			if (p[j].words < p[j + 1].words)
			{
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}

	// 정렬된 문자열과 그 단어의 개수를 출력한다.
	for (i = 0; i < N; i++)
	{
		printf("%s %d\n", p[i].str, p[i].words);
	}

	// 각 구조체의 문자열에 동적할당을 받은 것을 해제한다.
	for (i = 0; i < N; i++)
		free(p[i].str);
	// 마지막으로 구조체 배열도 해제한다.
	free(p);

	return 0;
}
*/
// 2차 모의 4 - 1
/*
// 구조체 선언
struct reserve {
	int id;
	char grade[4];
	int price;
};

// 함수 선언
void input(struct reserve* p, int N);
int cal_sum(struct reserve* p, int N, int id);

int main()
{
	// 필요한 변수 선언
	int N, id;
	struct reserve* parr = NULL;

	// N을 입력받은 후, N만큼 동적할당을 받는다.
	scanf("%d", &N);
	parr = (struct reserve*)malloc(N * sizeof(struct reserve));
	if (parr == NULL)			// 메모리 동적할당 확인
	{
		printf("Memory is not allocated\n");
		return -1;
	}
	// 고객id, 티켓 등급과 티켓 가격을 저장한다.
	input(parr, N);

	// 고객의 id를 받은 후 탐색한다.
	scanf("%d", &id);
	// id를 통해 탐색 후 출력
	cal_sum(parr, N, id);

	free(parr); // 동적할당 메모리 해제

	return 0;
}

// 구조체 배열에 정보를 입력받는다.
void input(struct reserve* p, int N)
{
	struct reserve* pt;
	// 정해진 횟수만큼 정보를 받음
	for (pt = p; pt < p + N; pt++)
	{
		// 1. id와 등급을 입력 받는다.
		scanf("%d %s", &pt->id, pt->grade);
		// 2. 등급의 내용에 따라 티켓 금액을 저장한다.
		if (strcmp(pt->grade, "VIP") == 0) pt->price = 140000;
		else if (strcmp(pt->grade, "R") == 0) pt->price = 110000;
		else if (strcmp(pt->grade, "S") == 0) pt->price = 85000;
		else if (strcmp(pt->grade, "A") == 0) pt->price = 55000;
	}
}

// id를 받아서 총 구매 금액을 계산하여 반환한다.
int cal_sum(struct reserve* p, int N, int id)
{
	int sum = 0;			// 총 구매 금액 초기화
	struct reserve* pt;
	// 구조체 배열 전체를 순회한다.
	for (pt = p; pt < p + N; pt++)
	{
		// id가 찾는 id일 경우
		if (pt->id == id)
		{
			// 정보를 출력하고, 총 구매 금액에 더한다.
			printf("%s %d\n", pt->grade, pt->price);
			sum += pt->price;
		}
	}
	// 총 구매 금액을 출력한다.
	printf("%d", sum);
}
*/
