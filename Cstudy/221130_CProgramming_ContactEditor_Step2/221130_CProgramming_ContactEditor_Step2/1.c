#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
<test 1>
3
1
Hong
01111112222
20000101
1
KimEunJoo
222111333
19960303
1
HanGeul
010222333
19980101
1
5
*/

/*
<test 2>
5
1
KimEunJoo
0001112222
20001010
1
Park
+820010101013211221321321
19900101
1
LeeEunJoo_MS
3401222
19950101
2
3
LeeEunJoo_MS
2
5
*/
// 데이터 구조체 선언
typedef struct tel {
	char* name;
	char* phone;
	char* birth;
}TEL;

// 필요한 함수 선언
void printMainMenu();
void swapContact(TEL** tel_list, int index1, int index2);
void sortContact(TEL** tel_list, int count);
void insertContact(TEL** tel_list, int* count, int max_num);
void deleteContact(TEL** tel_list, int* count);
void printAll(TEL** tel_list, int count);
void findContactByBirth(TEL** tel_list, int count);

int main()
{
	TEL** tel_list;
	int max_num;						// 최대 회원수
	int count = 0;						// 현재 연락처 개수
	int menu;
	printf("Max_num:");
	scanf("%d", &max_num);
	tel_list = (TEL**)malloc(sizeof(TEL*) * max_num);

	while (1) {
		printMainMenu();				//메뉴 출력
		scanf("%d", &menu);				//메뉴선택
		switch (menu) {
		case 1:
			insertContact(tel_list, &count, max_num);		//등록
			break;
		case 2:
			printAll(tel_list, count);				//보기
			break;
		case 3:
			deleteContact(tel_list, &count);		//삭제
			break;
		case 4:
			findContactByBirth(tel_list, count);	//생일자 검색
			break;
		case 5:
			return 0;
		default:
			printf("error\n");
		}
	}
	return 0;
}


// 메인 메뉴를 출력한다.
void printMainMenu()
{
	printf("*****Menu*****\n");
	printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
	printf("Enter_the_menu_number:");
}

// 데이터 내의 요소를 서로 교환한다.
void swapContact(TEL** tel_list, int index1, int index2)
{
	TEL tmp;
	tmp = *(tel_list[index1]);
	*(tel_list[index1]) = *(tel_list[index2]);
	*(tel_list[index2]) = tmp;
}

// 삽입 후 데이터를 이름순으로 정렬한다.
void sortContact(TEL** tel_list, int count)
{
	int i;
	if (count <= 1) return;				// 데이터가 하나 이하면 정렬할 필요가 없으므로 생략
	else								// 정렬할 필요가 있다면 맨 뒤에 데이터부터 자기 위치를 찾을때까지 정렬
	{
		for (i = count - 1; i >= 1; i--)
		{
			if (strcmp(tel_list[i - 1]->name, tel_list[i]->name) > 0)
				swapContact(tel_list, i, i - 1);
		}
	}
}


// 데이터 추가하기
void insertContact(TEL** tel_list, int* count, int max_num)
{
	char str[101];
	int len;
	TEL *tmp = (TEL*)malloc(sizeof(TEL));			// 새로운 구조체 동적할당을 받는다.
	// 만약 MAXCONTACT 이상의 데이터가 들어왔다면 끝내기
	if (*count >= max_num) {
		printf("OVERFLOW\n");
		return;
	}

	// 데이터 입력
	// 1, 이름
	printf("Name:");
	scanf("%s", str);
	len = strlen(str);
	tmp->name = (char*)malloc(sizeof(char) * (len + 1));
	strcpy(tmp->name, str);

	// 2. 전화번호
	printf("Phone_number:");
	scanf("%s", str);
	len = strlen(str);
	tmp->phone = (char*)malloc(sizeof(char) * (len + 1));
	strcpy(tmp->phone, str);

	// 3. 생일
	printf("Birth:");
	scanf("%s", str);
	len = strlen(str);
	tmp->birth = (char*)malloc(sizeof(char) * (len + 1));
	strcpy(tmp->birth, str);

	tel_list[*count] = tmp;
	(*count)++;								//인덱스 증가

	sortContact(tel_list, *count);				// 방금 입력된 데이터를 적절한 위치로 이동

	// 현재 인원 출력
	printf("<<%d>>\n", *count);
	return;
}

// 데이터 삭제하기
void deleteContact(TEL** tel_list, int* count)
{
	char name[101];
	int deleteIndex, i;
	// 삭제할 데이터가 없으면 끝내기
	if (*count == 0)
	{
		printf("NO MEMBER\n");
		return;
	}
	// 삭제할 이름 입력하기
	printf("Name:");
	scanf("%s", name);

	// 삭제할 이름이 어느 인덱스에 있는지 확인하기
	for (deleteIndex = 0; deleteIndex < *count; deleteIndex++)
	{
		if (strcmp(tel_list[deleteIndex]->name, name) == 0)
		{
			break; // 찾았으면 반복문 탈출
		}
	}

	// 삭제할 인덱스가 정해지면 구조체 동적할당 한 메모리를 해제한 후 다시 NULL로 초기화
	free(tel_list[deleteIndex]);
	tel_list[deleteIndex] = NULL;

	// 삭제할 인덱스 부터 인덱스를 한 칸씩 앞당기기
	for (i = deleteIndex; i < *count; i++)
	{
		tel_list[i] = tel_list[i + 1];
	}

	(*count)--; // 데이터의 수 하나 줄이기
}


// 전체 내용 출력
void printAll(TEL** tel_list, int count)
{
	int i;
	for (i = 0; i < count; i++)
	{
		printf("%s %s %s\n", tel_list[i]->name, tel_list[i]->phone, tel_list[i]->birth);
	}
}


// 생일 출력
void findContactByBirth(TEL** tel_list, int count)
{
	int birth, i;
	int month, fullBirth;
	printf("Birth:");
	scanf("%d", &birth);

	for (i = 0; i < count; i++)
	{
		fullBirth = atoi(tel_list[i]->birth);	// 생년월일 전부 숫자로 전환
		month = fullBirth % 10000;				// 월일만 가져오기
		month = month / 100;					// 월만 가져오기
		if (month == birth)						// 같은 달이면 출력한다
		{
			printf("%s %s %s\n", tel_list[i]->name, tel_list[i]->phone, tel_list[i]->birth);
		}
	}
}
