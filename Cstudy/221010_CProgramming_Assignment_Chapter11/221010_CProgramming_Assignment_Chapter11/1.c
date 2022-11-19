#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 문제 5
// 과목에 대한 구조체 선언
/*
typedef struct subject {
	char name[31];			// 과목 이름
	double score;			// 그 과목에 대한 점수
} Subject;

// 학생 정보에 대한 구조체 선언
typedef struct student {
	char name[31];			// 이름
	int id;					// 학번
	int subjectNum;			// 과목 개수
	Subject subject[10];	// subject 구조체의 배열(과목 최대 10개)
	double avgScore;		// 총 평균 학점
} Student;

// 함수 선언
void inputStudent(Student sp[], int count);
void print_s(Student sp[], int count);
void sort_s(Student sp[], int count);
void deleteStudent(Student sp[], int count, char deleteName[]);

int main()
{
	Student students[100];		// Student 배열 선언
	int count = 0;				// 저장된 Student의 수를 지속적으로 업데이트
	char order;					// 명령어를 받을 변수
	char deleteName[31];		// 지울 이름을 받을 변수
	// 'Q'가 입력될 때까지 무한 반복
	while (1)
	{
		scanf("%c", &order);	// 명령어 입력

		switch (order) {
		case 'I':
			inputStudent(students, count);		// 학생 정보 입력
			count++;							// 학생 수 +1
			break;
		case 'P':
			print_s(students, count);			// 남은 학생 출력
			break;
		case 'S':
			sort_s(students, count);			// 학생 이름을 오른차순으로 정렬 후 출력
			break;
		case 'D':
			scanf("%s", deleteName);			// 지울 학생의 이름을 받고
			deleteStudent(students, count, deleteName);		// 학생을 지운다.
			count--;							// 학생 수 -1
			break;
		case 'Q':								// 프로그램 종료
			return 0;
		}

		if (count <= 0) count = 0;				// count가 음수로 갈 때(deleteStudent 실행 시) 0으로 다시 바꾸기
	}
}

// 학생 정보 입력
void inputStudent(Student sp[], int count)
{
	double sumScore = 0;		// 학생 학점의 합계 저장
	// 1. 이름, 학번, 과목수 까지 입력받는다.
	scanf("%s %d %d", sp[count].name, &sp[count].id, &sp[count].subjectNum);
	// 2. 과목 수에 따라 각각의 과목과 점수를 입력받는다.
	for (int i = 0; i < sp[count].subjectNum; i++)
	{
		scanf("%s %lf", sp[count].subject[i].name, &sp[count].subject[i].score);
		sumScore += sp[count].subject[i].score;			// 이때, 학점의 합계는 바로 합친다.
	}
	if(sp[count].subjectNum > 0) sp[count].avgScore = sumScore / sp[count].subjectNum;	// 학점의 평균을 구해서 추가해준다.
}

// 배열 내의 남아있는 학생 출력
void print_s(Student sp[], int count)
{
	if (count <= 0) return;		// 학생이 없으먄 출력하지 않음
	// 배열을 순회하며 정보를 출력한다
	for (int i = 0; i < count; i++)
	{
		printf("%s %d %d %.2f\n", sp[i].name, sp[i].id, sp[i].subjectNum, sp[i].avgScore);		// 이름, 학번, 과목 개수, 평균 학점
	}
}

// 이름을 오름차순으로 정렬해서 출력하기
void sort_s(Student sp[], int count)
{
	Student tmp[100];			// 임시로 저장할 배열
	Student tmpOne;
	// 인자로 받은 배열을 임시 배열에 복사한다.
	for (int i = 0; i < count; i++)
	{
		tmp[i] = sp[i];			// Student 구조체를 각각 복사
	}

	// 버블 정렬로 임시 배열을 정렬한다.
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count - 1 - i; j++)
		{
			// 이름 기준으로 오름차순으로 정렬한다.
			if (strcmp(tmp[j].name, tmp[j + 1].name) > 0)
			{
				tmpOne = tmp[j];
				tmp[j] = tmp[j + 1];
				tmp[j + 1] = tmpOne;
			}
		}
	}
	// 임시 배열를 바로 출력한다.
	print_s(tmp, count);
}

// 입력받은 학생의 이름으로 학생 정보 지우기
void deleteStudent(Student sp[], int count, char deleteName[])
{
	if (count <= 0) return;			// 학생이 없으면 바로 종료
	int i;
	// 학생이 어느 인덱스에 있는지 찾는다 > i에 저장
	for (i = 0; i < count; i++)
	{
		if (strcmp(sp[i].name, deleteName) == 0)
		{
			break;			// 찾았으면, 바로 반복문 탈출
		}
	}

	// 그 인덱스부터 배열에서 한 칸씩 앞당긴다.
	for (; i < count - 1; i++)
	{
		sp[i] = sp[i + 1];
	}
}
*/

// 문제 4 - 2
// 구조체 정의
/*
struct parking_info {
	int carNum;			// 차량 번호
	int phone;			// 고객 전화번호
	char goods;			// 상품
	char isTicket;		// 정기권 가입유무
	int ticketType;		// 정기권 종류
	int parkingTime;	// 주차 시간
	double fee;			// 요금
};

// 함수 정의
void input(struct parking_info* p, int N);
void compute(struct parking_info* p);
void display(struct parking_info* p, int N);
void bike_info_sort(struct parking_info* p, int N);

int main()
{
	int N;								// Parking의 선언 개수
	struct parking_info parkingList[100];			// 크기 100만큼의 Parking 배열 선언
	struct parking_info* pt;
	double sumD = 0, sumS = 0, sumTotal;// 요금의 총합

	// 1. N을 입력받는다.
	scanf("%d", &N);					

	// 2. N만큼 parkingList에 Parking을 저장한다.
	input(parkingList, N);

	// 3. parkingList에서 요금을 각각 계산한다. 이때, 요금의 총합도 같이 계산한다.
	for (pt = parkingList; pt < parkingList + N; pt++)
	{
		compute(pt);
		if (pt->goods == 'D') sumD += pt->fee;			// 상품에 따라 요금 합산하기
		else if (pt->goods == 'S') sumS += pt->fee;
	}
	sumTotal = sumD + sumS;								// 총 요금까지 구하기

	// 4. 조건에 따라 정렬한다.
	bike_info_sort(parkingList, N);

	// 5. 출력(각 Parking의 내용, 요금 총액)
	display(parkingList, N);
	printf("%.f %.f %.f", sumD, sumS, sumTotal);

	return 0;
}

// 주어진 배열 내에 정보를 입력받는다.
void input(struct parking_info* p, int N)
{
	struct parking_info* pt;
	for (pt = p; pt < p + N; pt++)		// N번 만큼 입력을 받음
	{
		// 먼저 상품 종류까지 입력받는다.
		scanf("%d %d %s", &pt->carNum, &pt->phone, &pt->goods);
		if (pt->goods == 'D')			// 만약 상품이 일일권이라면, 주차시간만 입력받는다.
		{
			scanf("%d", &pt->parkingTime);
		}
		else if (pt->goods == 'S')		// 만약 상품이 정기권이라면, 정기권의 유무와 정기권의 종류, 그리고 주차시간을 입력받는다.
		{
			scanf("%s %d %d", &pt->isTicket, &pt->ticketType, &pt->parkingTime);
		}
	}
}

// 주어진 배열 내의 정보들을 통해 주차비 총액을 계산한다.
void compute(struct parking_info* p)
{
	double result = 0;						// 결과를 따로 저장하고 나중에 구조체 내에 대입
	int useTime = p->parkingTime - 240;		// 사용한 시간을 구하는데, 기본 4시간은 무료이므로, 240분은 빼고 계산한다.
	if (useTime <= 0) useTime = 0;			// 이때, 음수가 나오면 0으로 초기화
	if (p->goods == 'S')					// 만약, 상품이 정기권이라면
	{
		if (p->isTicket == 'N')				// 그런데 정기권이 없다면
		{
			// 정기권의 종류에 따라 가격을 추가한다.
			if (p->ticketType == 7) result += 30000;
			else if (p->ticketType == 30) result += 100000;
			else if (p->ticketType == 180) result += 500000;
		}
		// 정기권이 있으면 기본 4시간까지는 무료
	}
	else if (p->goods == 'D')				// 상품이 일일권이라면
	{
		result += 5000;						// 기본 4시간 가격인 5000원을 추가한다.
	}

	result += useTime / 10 * 200;			// 사용한 시간에 따라, 가격을 추가한다.

	p->fee = result;						// 주어진 구조체에 총액 내용 추가
}

// 주어진 구조체 배열의 내용을 출력한다.
void display(struct parking_info* p, int N)
{
	struct parking_info* pt;
	for (pt = p; pt < p + N; pt++)			// 배열의 주소로 접근해서, 정보들을 출력한다.
	{
		printf("%d %d %c %.f \n", pt->carNum, pt->phone, pt->goods, pt->fee);
	}
}

// 주어진 조건에 따라 구조체 배열을 정렬한다.
void bike_info_sort(struct parking_info* p, int N)
{
	int i, j;
	struct parking_info tmp;
	// 버블 정렬을 이용 (2번)
	// 1. 상품을 기준으로 오름차순으로 정렬한다.
	for (i = 0; i < N - 1; i++)
	{
		for (j = 0; j < N - 1 - i; j++)
		{
			if (p[j].goods > p[j + 1].goods)		// D를 앞으로, S를 뒤로 정렬한다.
			{
				tmp = p[j];							// 교체를 해준다.
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}

	// 2. 상품별 차량 번호에 대해 오름차순으로 정렬한다.
	for (i = 0; i < N - 1; i++)
	{
		for (j = 0; j < N - 1 - i; j++)
		{
			// 상품 종류가 같을 때. 차량 번호를 오름차순으로 정렬한다.
			if (p[j].goods == p[j + 1].goods && p[j].carNum > p[j+1].carNum)
			{
				tmp = p[j];					// 교체를 해준다.
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}
}
*/
// 문제 3 - 2 : 찜찜해...
// 구조체 선언 : 호텔의 정보
struct hotel_info {
	char name[31];			// 이름
	int rank;				// 등급
	double fame;			// 평판도
	double distance;		// 거리
	char breakfast;			// 조식포함여부
};

// 함수 선언
int in_hotel_info(struct hotel_info* p);
void out_hotel_info(struct hotel_info* p, int N, int G, double D);

int main()
{
	struct hotel_info hotels[100];	// 호텔에 대한 배열 선언
	int G;				// 평판
	double D;			// 거리
	int count = in_hotel_info(hotels);		// in_hotel_info를 통해 호텔의 정보를 몇 개 받았는지 확인

	scanf("%d %lf", &G, &D);				// 평판과 거리 입력받기
	
	out_hotel_info(hotels, count, G, D);	// out_hotel_info를 통해 출력

	return 0;
}

// 호텔의 정보 입력받기
int in_hotel_info(struct hotel_info* p)
{
	int count = 0;		// 입력 받은 횟수
	char tmp[31];		// 임시로 이름을 저장할 char 배열 변수
	struct hotel_info* pt;
	for (pt = p; pt < p + 100; pt++)		// 주소로 순회하기
	{
		scanf("%s", tmp);			// 이름을 먼저 입력받아, "0"을 입력했는지 확인한다.
		if (strcmp(tmp, "0") == 0)
		{
			break;					// 0을 입력받았다면, 반복문을 끝내고 바로 count 반환
		}
		else
		{
			strcpy(pt->name, tmp);	// 이름을 입력받았다면, 이름을 구조체 변수에 복사
			scanf("%d %lf %lf %c", &pt->rank, &pt->fame, &pt->distance, &pt->breakfast); // 나머지 변수를 입력받음
			count++;				// count++로 입력 횟수 저장
		}
	}
	return count;
}

// 구조체 배열 내에서 정렬 후, 출력한다.
void out_hotel_info(struct hotel_info* p, int N, int G, double D)
{
	struct hotel_info* pt, tmp;
	int index = 0;		// 조건에 맞는 구조체를 앞으로 보내서 이를 구분하기 위한 변수

	// 1. 등급이 더 높고, 거리가 더 짧은 것들 선별하기
	for (pt = p; pt < p + N; pt++)
	{
		// 주어진 조건에서 명성이 더 높고, 거리가 더 짧은 구조체를 배열 내의 앞으로 보낸다.
		if (pt->rank >= G && pt->distance <= D)		
		{
			tmp = *(p + index);				// 교체하기
			*(p + index) = *pt;
			*pt = tmp;
			index++;						// index를 +1 하기
		}
	}
	
	// 2. 평판이 높은 순서대로 버블정렬을 이용해 정렬하기
	// index를 이용해 조건에 맞았던 구조체들만 정렬하면 된다.
	for (int i = 0; i < index; i++)
	{
		for (pt = p; pt < p + index - 1 - i ; pt++)
		{
			if (pt->fame < (pt + 1)->fame)		// 평판이 더 높은 구조체를 앞으로 보낸다.
			{
				tmp = *pt;						// 교체 과정
				*pt = *(pt + 1);
				*(pt + 1) = tmp;
			}
			
			else if (pt->fame == (pt + 1)->fame)	// 평판이 같다면
			{
				if (strcmp(pt->name, (pt + 1)->name) > 0)	// 이름을 사전 순서대로 정렬하게 한다.
				{
					tmp = *pt;					// 교체 과정
					*pt = *(pt + 1);
					*(pt + 1) = tmp;
				}
			}
		}
	}

	// 정렬된 조건에 맞는 구조체를 반복문을 이용해서 출력한다.
	for (pt = p; pt < p + index; pt++)
	{
		printf("%s %d %.1f %.1f %c\n", pt->name, pt->rank, pt->fame, pt->distance, pt->breakfast);
	}
}

// 문제 2 - 2
/*
// 학생의 정보를 입력할 구조체
struct student {
	char name[21];
	int korean, math, english;
	double avg;
};

// 함수 선언
void read_data(struct student* st, int N);
void sort_score(struct student* st, int N);
struct student* select_out(struct student* st1, struct student* st2, int N);

int main()
{
	
	struct student st1[50], st2[50];		// student 배열 선언
	int N;									// 학생의 수

	// 1. 학생의 수를 입력받는다.
	scanf("%d", &N);					

	// 2. 각 배열에 학생의 정보를 입력한다.
	read_data(st1, N);
	read_data(st2, N);

	// 3. 구조체 배열을 정렬한다.
	sort_score(st1, N);
	sort_score(st2, N);

	// 4. 어느 배열이 중간 등수 학생의 성적이 더 큰지 선택
	struct student* result = select_out(st1, st2, N);

	// 5. 선택된 배열의 정보 출력
	for (int i = 0; i < N; i++)
	{
		printf("%s %d %d %d %.1f\n", result[i].name, result[i].korean, result[i].english, result[i].math, result[i].avg);
	}

	return 0;
}

// 정보 입력
void read_data(struct student* st, int N)
{
	struct student* i;				// 포인터 변수 선언
	for (i = st; i < st + N; i++)	// 입력받은 N만큼 학생의 정보를 입력한다.
	{
		scanf("%s %d %d %d", i->name, &i->korean, &i->english, &i->math);
		i->avg = (i->korean + i->english + i->math) / 3.0f;			// 3가지 과목의 평균값 계산
	}
}

// 정렬
void sort_score(struct student *st, int N)
{
	struct student tmp, * i, *j;		// 임시 저장용 포인터 변수 tmp 선언 
	// 버블 정렬을 통해 배열을 정렬한다.
	for (i = st + N - 1; i > st; i--) 
	{
		for (j = st; j < i; j++)
		{
			if (j->avg < (j + 1)->avg)		// 다음 학생의 평균값이 더 클 때, 서로 교환를 한다.
			{
				tmp = *j;					// swap 형태로 교환한다.
				*j = *(j + 1);
				*(j + 1) = tmp;
			}
			else if (j->avg == (j + 1)->avg)	// 만약, 평균값이 같다면,
			{
				if (j->korean < (j + 1)->korean)	// 국어 성적이 더 높은 사람이 앞으로 간다.
				{
					tmp = *j;
					*j = *(j + 1);
					*(j + 1) = tmp;
				}
				else if (j->korean == (j + 1)->korean)	// 만약, 국어 성적도 같다면,
				{
					if (j->english < (j + 1)->english)	// 영어 성적이 더 높은 사람이 앞으로 간다.
					{
						tmp = *j;
						*j = *(j + 1);
						*(j + 1) = tmp;
					}
				}
			}
		}
	}
}

// 중간 등수 학생이 더 큰 그룹 선택
struct student* select_out(struct student* st1, struct student* st2, int N)
{
	// 중간 값 도출
	// 1. N은 홀수임이 조건에 있고 2. 인덱스는 0부터 시작하므로 다음과 같은 식으로 중간 등수 선택
	int num = N / 2;		

	// 더 큰 쪽의 배열 주소를 반환한다.
	if ((st1 + num)->avg > (st2 + num)->avg)
		return st1;
	else
		return st2;
}
*/

// 문제 1 - 2
/*
// 조건에 맞는 student 구조체 선언
struct student {
	char name[10];
	char id[10];
	char grade;
};

int main()
{
	struct student students[5];							// student 배열 선언
	char findName[10], findYear[5], findGrade = "";		// 입력한 이름의 정보를 저장할 변수 선언
	char tmp[5];										// 순회하면서 배열에 있는 학생들의 입학년도 저장
	int i, check = 0;									// check는 같은 학점, 입학년도가 같은 학생을 찾은 여부 확인

	// 1. 배열에 데이터 저장(학생 이름, 학번, 학점)
	for (i = 0; i < 5; i++)
	{
		scanf("%s %s %c", students[i].name, students[i].id, &students[i].grade);
	}

	// 2. 찾을 학생의 이름 저장
	scanf("%s", findName);

	// 3. 한 번 순회하면서 입력한 학생의 정보를 저장
	for (i = 0; i < 5; i++)
	{
		if (strcmp(findName, students[i].name) == 0)
		{
			strncpy(findYear, students[i].id, 4);		// 앞의 입학년도 정보가 있는 첫 4자리의 문자열을 가져옴
			findYear[4] = '\0';							// 마지막에 null문자를 둬서 문자열 최종 완성
			findGrade = students[i].grade;				// 학점 저장
			break;										// 찾았으면 바로 반복문을 탈출한다..
		}
	}

	// 4, 다시 한 번 순회하면서 같은 학점, 입학년도가 같은 학생을 찾는다.
	for (i = 0; i < 5; i++)
	{
		// 각 학생의 입학년도는 미리 저장
		strncpy(tmp, students[i].id, 4);
		tmp[4] = '\0';
		// 1) 학점 동일 2) 입학년도 동일 3) 같은 사람이 아님
		// 조건에 맞는 학생을 찾아서 이름을 출력한다.
		if ((students[i].grade == findGrade) && (strcmp(tmp, findYear) == 0) && (strcmp(students[i].name, findName) != 0))
		{
			check = 1;				// 만약 찾았으면, check를 1로 둬서 0이 출력되지 않도록 한다.
			printf("%s ", students[i].name);
		}
	}
	if (check == 0) printf("%d", check);		// 만약 한 명도 못찾았으면, 0을 출력한다.
	printf("\n");

	// 찾고자 하는 학생의 입학년도의 131을 나눈 나머지 저장
	// 이때 문자열을 정수로 바꾸는 과정이 필요하다.
	int num = atoi(findYear) % 131;				
	printf("%s %d\n", findYear, num);			// 입학년도, 위에서 저장한 num 출력

	return 0;
}
*/


