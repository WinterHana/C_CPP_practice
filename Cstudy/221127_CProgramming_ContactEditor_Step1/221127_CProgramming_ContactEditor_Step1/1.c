#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXCONTACT 10
/*
1
B
01012345678
19990808
1
A
01023456789
20000101
1
C
01045678901
20040315
*/

//TestData1
/*
2
3
1
Kim
0001112222
19960101
1
Lee
0103332222
19960202
1
Han
0114445555
20000101
2
3
Kim
2
5
*/

// TestData2
/*
1
Kim
0112223333
19950101
1
Han
01011112222
19960302
1
Lee
0101234567
19970903
2
4
1
5
*/
typedef struct ContactInfo {
	char name[21];
	char phone[16];
	char birth[9];
} Contact;

void printMainMenu();
void swapContact(Contact* contactData, int index1, int index2);
void sortContact(Contact* contactData, int numContact);
void insertContact(Contact* contactData, int* numContact);
void deleteContact(Contact* contactData, int* numContact);
void printAll(Contact* contactData, int numContact);
void findContactByBirth(Contact* contactData, int numContact);

int main()
{
	Contact contactData[MAXCONTACT];	//100의 구조체공간 정의
	int numContact = 0;					//요소의 인덱스
	int menu;
	while (1) {
		printMainMenu();				//메뉴 출력
		scanf("%d", &menu);				//메뉴선택
		switch (menu) {
		case 1: 
			insertContact(contactData, &numContact);		//등록
			break;
		case 2:
			printAll(contactData, numContact);				// 보기
			break;
		case 3: 
			deleteContact(contactData, &numContact);		//삭제
			break;
		case 4: 
			findContactByBirth(contactData, numContact);	//생일자 검색
			break;
		case 5:
			return 0;
		default:
			printf("error\n");
		}
	}
	return 0;
}

// 기본 메인 메뉴를 출력한다.
void printMainMenu()
{
	printf("*****Menu*****\n");
	printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
	printf("Enter_the_menu_number:");
}

// 데이터 내의 요소를 서로 바꾼다.
void swapContact(Contact* contactData, int index1, int index2)
{
	Contact tmp;
	tmp = contactData[index1];
	contactData[index1] = contactData[index2];
	contactData[index2] = tmp;
}

// 삽입 후 데이터를 이름순으로 정렬한다.
void sortContact(Contact* contactData, int numContact)
{
	int i;
	if (numContact <= 1) return;				// 데이터가 하나 이하면 정렬할 필요가 없으므로 생략
	else				// 정렬할 필요가 있다면 맨 뒤에 데이터부터 자기 위치를 찾을때까지 정렬
	{
		for (i = numContact - 1; i >= 1; i--)
		{
			if (strcmp(contactData[i - 1].name, contactData[i].name) > 0)
				swapContact(contactData, i, i - 1);
		}
	}
}

// 데이터 추가하기
void insertContact(Contact* contactData, int* numContact)
{
	if (*numContact >= MAXCONTACT) {
		printf("OVERFLOW\n");
		return;
	}

	// 데이터 입력
	printf("Name:");
	scanf("%s", contactData[*numContact].name);
	printf("Phone_number:");
	scanf("%s", contactData[*numContact].phone);
	printf("Birth:");
	scanf("%s", contactData[*numContact].birth);
	(*numContact)++;								//인덱스 증가

	sortContact(contactData, *numContact);		// 방금 입력된 데이터를 적절한 위치로 이동
	
	// 현재 인원 출력
	printf("<<%d>>\n", *numContact);
	return;
}

void deleteContact(Contact* contactData, int* numContact)
{
	char name[21];
	int deleteIndex, i;
	// 삭제할 데이터가 없으면 생략
	if (*numContact == 0)
	{
		printf("NO MEMBER\n");
		return;
	}
	// 삭제할 이름 입력하기
	printf("Name:");
	scanf("%s", name);

	// 삭제할 이름이 어느 인덱스에 있는지 확인하기
	for (deleteIndex = 0; deleteIndex < *numContact; deleteIndex++)
	{
		if (strcmp(contactData[deleteIndex].name, name) == 0)
		{
			break;
		}
	}

	// 삭제할 인덱스 부터 인덱스를 한 칸씩 앞당기기
	for (i = deleteIndex; i < *numContact; i++)
	{
		contactData[i] = contactData[i + 1];
	}
	
	(*numContact)--;
}

// 전체 내용 출력
void printAll(Contact* contactData, int numContact)
{
	int i;
	for (i = 0; i < numContact; i++)
	{
		printf("%s %s %s\n", contactData[i].name, contactData[i].phone, contactData[i].birth);
	}
}

// 생일 출력
void findContactByBirth(Contact* contactData, int numContact)
{
	int birth, i;
	int month, fullBirth;
	printf("Birth:");
	scanf("%d", &birth);

	for (i = 0; i < numContact; i++)
	{
		fullBirth = atoi(contactData[i].birth);	// 생년월일 전부 숫자로 전환
		month = fullBirth % 10000;				// 월일만 가져오기
		month = month / 100;					// 월만 가져오기
		if (month == birth)			// 같은 달이면 출력한다
		{
			printf("%s %s %s\n", contactData[i].name, contactData[i].phone, contactData[i].birth);
		}
	}
}

// 자세한 주석
/*
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXCONTACT 10

// 데이터 구조체 선언
typedef struct ContactInfo {
	char name[21];
	char phone[16];
	char birth[9];
} Contact;

// 필요한 함수 선언
void printMainMenu();
void swapContact(Contact* contactData, int index1, int index2);
void sortContact(Contact* contactData, int numContact);
void insertContact(Contact* contactData, int* numContact);
void deleteContact(Contact* contactData, int* numContact);
void printAll(Contact* contactData, int numContact);
void findContactByBirth(Contact* contactData, int numContact);

int main()
{
	Contact contactData[MAXCONTACT];	//100의 구조체공간 정의
	int numContact = 0;					//요소의 인덱스
	int menu;
	while (1) {
		printMainMenu();				//메뉴 출력
		scanf("%d", &menu);				//메뉴선택
		switch (menu) {
		case 1:
			insertContact(contactData, &numContact);		//등록
			break;
		case 2:
			printAll(contactData, numContact);				//보기
			break;
		case 3:
			deleteContact(contactData, &numContact);		//삭제
			break;
		case 4:
			findContactByBirth(contactData, numContact);	//생일자 검색
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
void swapContact(Contact* contactData, int index1, int index2)
{
	Contact tmp;
	tmp = contactData[index1];
	contactData[index1] = contactData[index2];
	contactData[index2] = tmp;
}

// 삽입 후 데이터를 이름순으로 정렬한다.
void sortContact(Contact* contactData, int numContact)
{
	int i;
	if (numContact <= 1) return;				// 데이터가 하나 이하면 정렬할 필요가 없으므로 생략
	else				// 정렬할 필요가 있다면 맨 뒤에 데이터부터 자기 위치를 찾을때까지 정렬
	{
		for (i = numContact - 1; i >= 1; i--)
		{
			if (strcmp(contactData[i - 1].name, contactData[i].name) > 0)
				swapContact(contactData, i, i - 1);
		}
	}
}

// 데이터 추가하기
void insertContact(Contact* contactData, int* numContact)
{
	// 만약 MAXCONTACT 이상의 데이터가 들어왔다면 끝내기
	if (*numContact >= MAXCONTACT) {
		printf("OVERFLOW\n");
		return;
	}

	// 데이터 입력
	printf("Name:");
	scanf("%s", contactData[*numContact].name);
	printf("Phone_number:");
	scanf("%s", contactData[*numContact].phone);
	printf("Birth:");
	scanf("%s", contactData[*numContact].birth);
	(*numContact)++;								//인덱스 증가

	sortContact(contactData, *numContact);		// 방금 입력된 데이터를 적절한 위치로 이동

	// 현재 인원 출력
	printf("<<%d>>\n", *numContact);
	return;
}

// 데이터 삭제하기
void deleteContact(Contact* contactData, int* numContact)
{
	char name[21];
	int deleteIndex, i;
	// 삭제할 데이터가 없으면 끝내기
	if (*numContact == 0)
	{
		printf("NO MEMBER\n");
		return;
	}
	// 삭제할 이름 입력하기
	printf("Name:");
	scanf("%s", name);

	// 삭제할 이름이 어느 인덱스에 있는지 확인하기
	for (deleteIndex = 0; deleteIndex < *numContact; deleteIndex++)
	{
		if (strcmp(contactData[deleteIndex].name, name) == 0)
		{
			break; // 찾았으면 반복문 탈출
		}
	}

	// 삭제할 인덱스 부터 인덱스를 한 칸씩 앞당기기
	for (i = deleteIndex; i < *numContact; i++)
	{
		contactData[i] = contactData[i + 1];
	}

	(*numContact)--; // 데이터의 수 하나 줄이기
}

// 전체 내용 출력
void printAll(Contact* contactData, int numContact)
{
	int i;
	for (i = 0; i < numContact; i++)
	{
		printf("%s %s %s\n", contactData[i].name, contactData[i].phone, contactData[i].birth);
	}
}

// 생일 출력
void findContactByBirth(Contact* contactData, int numContact)
{
	int birth, i;
	int month, fullBirth;
	printf("Birth:");
	scanf("%d", &birth);

	for (i = 0; i < numContact; i++)
	{
		fullBirth = atoi(contactData[i].birth);	// 생년월일 전부 숫자로 전환
		month = fullBirth % 10000;				// 월일만 가져오기
		month = month / 100;					// 월만 가져오기
		if (month == birth)			// 같은 달이면 출력한다
		{
			printf("%s %s %s\n", contactData[i].name, contactData[i].phone, contactData[i].birth);
		}
	}
}
*/