#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
7 3
Kim 75 85
Lee 93 63
Park 94 82
Choi 78 70
Jung 65 85
Kang 83 90
Cho 90 70

7 3
Kim 75 85
Lee 96 56
Park 94 82
Choi 78 70
Jung 65 85
Kang 93 63
Cho 93 63
*/
// 문제 4 - 1, 4 - 2

// 구조체 선언
struct student {
	char* name;
	int firstStage;
	int interview;
	double sum;
};

int main()
{
	// 필요한 변수 선언
	int N, M, i, j, nameLen;
	struct student* arr = NULL, tmp, compare;
	char name[11];

	// N과 M을 입력받는다.
	scanf("%d %d", &N, &M);
	// 입력받은 N으로 student 배열을 동적할당
	arr = (struct student*)malloc(N * sizeof(struct student));
	if (arr == NULL)			// 메모리 할당 확인
	{
		printf("Memory is not allocated\n");
		return -1;
	}
	// 각 배열마다 정보를 저장한다.
	for (i = 0; i < N; i++)
	{
		// 1. 이름 입력 받기
		scanf("%s", name);
		// 입력받은 이름의 길이를 알아낸 다음 (그 길이 + 1)만큼 동적할당
		nameLen = strlen(name);		
		arr[i].name = (char *)malloc((nameLen + 1) * sizeof(char));
		if (arr[i].name == NULL)			// 메모리 할당 확인
		{
			printf("Memory is not allocated\n");
			return -1;
		}
		// 동적할당이 완료됐으면 임시 저장한 이름을 최종 저장
		strcpy(arr[i].name, name);

		// 2. 성적 입력 받기
		scanf("%d %d", &arr[i].firstStage, &arr[i].interview);
		// 부동소수점 표현의 오차를 감안하여 계산. 나중에 나누기 10을 해서 출력할 것
		arr[i].sum = 7 * arr[i].firstStage + 3 * arr[i].interview;
	}

	// 조건에 따라 정렬한다.
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - (i + 1); j++)
		{
			// 1. 총점 순으로 내림차순 정렬
			if (arr[j].sum < arr[j + 1].sum)
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			// 2. 총점이 같아면, 1단계 점수가 더 높은 순으로 정렬
			else if ((arr[j].sum == arr[j + 1].sum) && (arr[j].firstStage < arr[j + 1].firstStage))
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			// 3. 총점과 1단계 점수가 같다면 이름 사전 순으로 정렬
			else if ((arr[j].sum == arr[j + 1].sum) && (arr[j].firstStage == arr[j + 1].firstStage))
			{
				// 사전 순으로 더 빠른 순서대로 정렬한다.
				if (strcmp(arr[j].name, arr[j + 1].name) > 0)
				{
					tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
			}
		}
	}

	// 동점일 때 추가합격자를 가려내기 위해 compare에 맨 마지막 합격자 정보를 저장
	compare = arr[M - 1];
	for (i = M; i < N; i++)
	{
		// 맨 마지막 합격자 정보와 동일한 조건 일때, 추가 합격을 한다.(M을 1 더하기)
		if (compare.sum == arr[i].sum && compare.firstStage == arr[i].firstStage) M++;
		else break;
	}

	// 최종 결과 출력
	for (i = 0; i < M; i++)
	{
		// 지원자 정보
		printf("%s %d %d %.1f\n", arr[i].name, arr[i].firstStage, arr[i].interview, arr[i].sum / 10);
	}
	// 합격자 수
	printf("%d\n", M);

	// 각 구조체에 동적 할당 된 문자열 해제
	for (i = 0; i < N ; i++) free(arr[i].name);
	// 구조체 배열 해제
	free(arr);

	return 0;
}

// 문제 3 - 2
/*
5
HongGilDong 1003 Math 85 C 80 AdvC 90
JeonWooChi 1001 English 60 C 75 Physics 80 Math 70
HeungBoo 1002 Economics 80 AdvC 90 Math 80 C 90
NolBoo 1004 Ethics 50 C 62
Euler 1005 Math 100 Physics 90 AdvC 85
2

5
HongGilDong 1003 Math 85 C 80 AdvC 90
JeonWooChi 1001 English 60 C 75 Physics 80 Math 70
HeungBoo 1002 Economics 80 AdvC 90 Math 80 C 90
NolBoo 1004 Ethics 50 C 62
Euler 1005 Math 100 Physics 90 AdvC 85
4

1
HongGilDong 1003 Math 85 C 80 AdvC 90
*/
/*
// 구조체 선언
struct subject {
	char* name;
	double score;
};

struct student {
	char* name;
	char id[5];
	int numSubject;
	struct subject* psub;
	double avg;
};

int main()
{
	// 필요한 변수들을 선언한다.
	int N, K, i, j, stringLen, wordLen, countingWord;
	char str[101];
	char* pt, *subpt;
	struct student* parr = NULL, tmpstudent;		// tmpstudent : 임시로 저장할 구조체
	double score, sum;
	struct subject tmpsubject;						// tmpsubject : 임시로 저장할 과목

	// 학생이 몇명인지 입력하고, 그 수에 맞춰서 student 구조체 배열을 동적할당 받는다.
	scanf("%d", &N); getchar();
	parr = (struct student*)malloc(N * sizeof(struct student));
	if (parr == NULL)				// 동적할당 확인
	{
		printf("Memory is not allocated\n");
		return -1;
	}
	
	// 구조체 배열 각각에 정보를 입력받기 위해 정보를 추출한다.
	for (i = 0; i < N; i++)
	{
		gets(str);				// 정보가 담긴 공백있는 문자열을 입력 받음.
		
		// 0. 공백를 NULL문자로 바꾼다.
		stringLen = strlen(str);
		pt = str;		// 시작 포인터 : 문자열의 시작 부분
		// 공백일 때, 그 공백을 NULL문자로 바꿈.
		for (j = 0; j < stringLen; j++)
		{
			if (str[j] == ' ') str[j] = '\0';
		}

		// 1. 이름 : 맨 앞에 이름을 저장한다.
		// 이름의 길이 : 처음 공백이 보이는 곳을 null문자로 바꿨으므로 거기까지 길이를 받는다.
		wordLen = strlen(pt);
		// 그 이름의 길이에 맞춰서 메모리 공간을 동적할당 받는다.(길이 + 1)
		parr[i].name = (char*)malloc((wordLen + 1) * sizeof(char));
		if (parr[i].name == NULL)		// 동적할당 확인
		{
			printf("Memory is not allocated\n");
			return -1;
		}
		// 단어를 동적할당 공간에 최종 저장한다.
		strcpy(parr[i].name, pt);
		pt += wordLen + 1;		// 포인터를 널 문자 다음으로 옮긴다.

		// 2. 학번 : 두번째로 적힌 내용을 가져온다, "1. 이름"과 동적할당 없이 동일한 방법
		wordLen = strlen(pt);
		strcpy(parr[i].id, pt);
		pt += wordLen + 1;	// 포인터를 널 문자 다음으로 옮긴다.	

		// 3. 과목의 개수 새기
		subpt = pt;				// 과목의 수를 알아내기 위한 임시 변수
		countingWord = 0;		// 뒤에 있는 문자의 개수를 저장한다.
		while (subpt != str + stringLen + 1)
		{
			if (*subpt == '\0') countingWord++;		// 널 문자를 만날 때마다 문자 개수 하나 추가
			subpt++;
		}

		parr[i].numSubject = countingWord / 2;		// 과목의 수는 단어의 수 / 2 이다(과목명 : 점수)
		// 그 과목의 수에 맞춰 과목 구조체 배열을 동적할당 받는다.
		parr[i].psub = (struct subject*)malloc(countingWord * sizeof(struct subject));
		if (parr[i].psub == NULL)					// 동적할당 확인
		{
			printf("Memory is not allocated\n");
			return -1;
		}

		// 4. 과목 정보 입력
		for (j = 0; j < parr[i].numSubject; j++)
		{
			// 1, 과목명 저장
			wordLen = strlen(pt);				// null문자까지의 문자 길이 받기		
			parr[i].psub[j].name = (char*)malloc((wordLen + 1) * sizeof(char));		// 그 문자 길이만큼 동적할당 받기
			if (parr[i].psub[j].name == NULL)	// 동적할당 확인
			{
				printf("Memory is not allocated\n");
				return -1;
			}
			strcpy(parr[i].psub[j].name, pt);	// 문자열 복사
			pt += wordLen + 1;					// 포인터 이동

			// 2. 과목 점수 저장
			wordLen = strlen(pt);				// null문자까지의 문자 길이 받기
			score = atoi(pt);					// 문자열을 정수로 변환
			parr[i].psub[j].score = score;		// 그 점수를 double 변수에 넣기
			pt += wordLen + 1;					// 포인터 이동
		}

		// 5. 모든 과목의 평균 점수 입력
		sum = 0.0;								// 모든 과목 점수의 총합 저장
		for (j = 0; j < parr[i].numSubject; j++)
		{
			sum += parr[i].psub[j].score;		// 총합 계산
		}
		parr[i].avg = sum / parr[i].numSubject;	// 평균 계산
	}

	// 평균 점수에 따라 정렬하기
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - (i + 1); j++)
		{
			// 평균 점수 정렬
			if (parr[j].avg < parr[j + 1].avg)
			{
				tmpstudent = parr[j];
				parr[j] = parr[j + 1];
				parr[j + 1] = tmpstudent;
			}
			// 평균 점수가 같으면, 학번 순으로 정렬한다.
			else if ((parr[j].avg == parr[j + 1].avg) && (strcmp(parr[j].id, parr[j + 1].id) > 0))
			{
				tmpstudent = parr[j];
				parr[j] = parr[j + 1];
				parr[j + 1] = tmpstudent;
			}
		}
	}
	// K번째 학생을 찾아서 이름, 학번, 평균을 출력한다.
	scanf("%d", &K);
	printf("%s %s %.2f ", parr[K - 1].name, parr[K - 1].id, parr[K - 1].avg);

	// K번째 학생의 높은 점수의 과목과 점수를 출력한다.
	tmpsubject = parr[K - 1].psub[0];
	for (i = 0; i < parr[K - 1].numSubject; i++)
	{
		if (parr[K - 1].psub[i].score > tmpsubject.score) tmpsubject = parr[K - 1].psub[i];
	}
	// 최종 결과 출력
	printf("%s %.2f", tmpsubject.name, tmpsubject.score);
	
	// 메모리 해제 1. 문자열 2. 구조체 3. 구조체 배열
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < parr[i].numSubject; j++)
		{
			free(parr[i].psub[j].name);
		}
		free(parr[i].psub);
	}

	free(parr);

	return 0;
}
*/