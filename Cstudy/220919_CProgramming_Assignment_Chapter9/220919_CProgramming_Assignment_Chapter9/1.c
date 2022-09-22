#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 문제 4-1
int main()
{
	int a[10], b[10];						// 크기가 10인 배열 선언
	int n = 0, m = 0;
	int num;								// 입력받은 정수를 임시로 저장
	int max, min;					// 최댓값, 최솟값 저장
	// 행렬 a(101호)의 값 입력 받기
	for (int i = 0; i < 11; i++)			// 11번 반복하는 이유는 10번 입력하고 -1을 입력할 수도 있기 때문이다.
	{
		scanf("%d", &num);
		if (num == -1) break;				// -1이 입력되면 종료
		*(a + i) = num;						// 종료되지 않았으면 배열에 넣기
		if (i == 0)
		{
			max = *a;
			min = *a;
		}
		n++;								// 점수 n개도 설정
		if (*(a + i) > max) max = *(a + i);
		if (*(a + i) < min) min = *(a + i);
	}

	// 행렬 b(102호)의 값 입력 받기
	for (int i = 0; i < 11; i++)
	{
		scanf("%d", &num);
		if (num == -1) break;				// -1이 입력되면 종료
		*(b + i) = num;						// 종료되지 않았으면 배열에 넣기
		m++;								// 점수 m개도 설정
		if (*(b + i) > max) max = *(b + i);
		if (*(b + i) < min) min = *(b + i);
	}

	printf("%d %d\n", n, m);
	printf("%d %d\n", max, min);

	return 0;
}
// 문제 4-2
/*
void descending(int* arr1, int* arr2, int n, int m);
void ascending(int* arr1, int* arr2, int n, int m);

int main()
{
	int a[10], b[10];						// 크기가 10인 배열 선언
	int n = 0, m = 0;
	int num;								// 입력받은 정수를 임시로 저장
	// 행렬 a(101호)의 값 입력 받기
	for (int i = 0; i < 11; i++)			// 11번 반복하는 이유는 10번 입력하고 -1을 입력할 수도 있기 때문이다.
	{
		scanf("%d", &num);
		if (num == -1) break;			// -1이 입력되면 종료
		*(a + i) = num;					// 종료되지 않았으면 배열에 넣기
		n++;							// 점수 n개도 설정
	}

	// 행렬 b(102호)의 값 입력 받기
	for (int i = 0; i < 11; i++)
	{
		scanf("%d", &num);
		if (num == -1) break;			// -1이 입력되면 종료
		*(b + i) = num;					// 종료되지 않았으면 배열에 넣기
		m++;							// 점수 m개도 설정
	}

	descending(a, b, n, m);					// 1. 가장 높은 n개의 점수를 내림차순으로 출력
	ascending(a, b, n, m);					// 2. 가장 낮은 m개의 점수를 오름차순으로 출력

	return 0;
}

// 두 행렬에서 제일 큰 수부터 내림차순으로 정렬하여 출력
void descending(int* arr1, int * arr2, int n, int m)
{
	int tmp;							// 값을 교대하기 위한 빈 변수
	// 행렬 하나를 내림차순으로 정렬
	for (int* i = arr1; i < arr1 + n; i++)
	{
		for (int* j = arr1; j < arr1 + n; j++)
		{
			if (*i > *j)				// 비교하는 값이 더 크면, 자리 바꾸기
			{
				tmp = *j;
				*j = *i;
				*i = tmp;
			}
		}
	}
	// 다른 행렬 하나도 내림차순으로 정렬
	for (int* i = arr2; i < arr2 + m; i++)
	{
		for (int* j = arr2; j < arr2 + m; j++)
		{
			if (*i > *j)				// 비교하는 값이 더 크면, 자리 바꾸기
			{
				tmp = *j;
				*j = *i;
				*i = tmp;
			}
		}
	}

	// 내림차순이 된 두 행렬 각각의 첫번째 요소부터 비교를 해서 가장 큰 수부터 출력하기
	for (int i = 0, j = 0, count = 0; count < n; count++)
	{
		if (*(arr1 + i) > *(arr2 + j))			// 더 큰 수를 찾는다
		{
			printf("%d ", *(arr1 + i));
			i++;								// arr1의 다음 요소와 비교
		}
		else
		{
			printf("%d ", *(arr2 + j));
			j++;								// arr2의 다음 요소와 비교
		}

		// 만약 어느 한 행렬이 끝까지 점검했다면, 다른 한 행렬을 남은 횟수로 순서대로 출력하기
		if (i == n)													// arr1이 끝일 때
		{
			for (count = count + 1; count < n; count++, j++)		// 바로 다음 출력부터 고갈되지 않은 행렬을 순서대로 출력
			{
				printf("%d ", *(arr2 + j));
			}
			break;													// 전부 출력했으면 반복문 탈출하기
		}
		else if (j == m)												// arr2가 끝일 때
		{
			for (count = count + 1; count < n; count++, i++)		// 바로 다음 출력부터 고갈되지 않은 행렬을 순서대로 출력
			{
				printf("%d ", *(arr1 + i));
			}
			break;													// 전부 출력했으면 반복문 탈출하기
		}
	}

	printf("\n");
}

// 두 행렬에서 제일 작은 수부터 오름차순으로 정렬하여 출력
void ascending(int* arr1, int* arr2, int n, int m)
{
	int tmp;							// 값을 교대하기 위한 빈 변수
	// 행렬 하나를 오름차순으로 정렬, -1을 만날 때까지 반복
	for (int* i = arr1; i < arr1 + n; i++)
	{
		for (int* j = arr1; j < arr1 + n; j++)
		{
			if (*i < *j)				// 비교하는 값이 더 작으면, 자리 바꾸기
			{
				tmp = *j;
				*j = *i;
				*i = tmp;
			}
		}
	}
	// 다른 행렬 하나도 오름차순으로 정렬, -1을 만날 때까지 반복
	for (int* i = arr2; i < arr2 + m; i++)
	{
		for (int* j = arr2; j < arr2 + m; j++)
		{
			if (*i < *j)				// 비교하는 값이 더 크면, 자리 바꾸기
			{
				tmp = *j;
				*j = *i;
				*i = tmp;
			}
		}
	}

	// 오름차순이 된 두 행렬 각각의 첫번째 요소부터 비교를 해서 가장 작은 수부터 출력하기
	for (int i = 0, j = 0, count = 0; count < m; count++)
	{
		if (*(arr1 + i) < *(arr2 + j))			// 더 작은 수를 찾는다
		{
			printf("%d ", *(arr1 + i));		
			i++;								// 다음 요소와 비교
		}
		else if (*(arr1 + i) >= *(arr2 + j))
		{
			printf("%d ", *(arr2 + j));			// 다음 요소와 비교
			j++;								
		}
		
		// 만약 어느 한 행렬이 -1에 도달해 끝까지 점검했다면, 다른 한 행렬을 남은 횟수로 순서대로 출력하기
		if (i == n)										// arr1이 끝일 때
		{
			for (count = count + 1; count < m; count++, j++)		// 바로 다음 출력부터 고갈되지 않은 행렬을 순서대로 출력
			{
				printf("%d ", *(arr2 + j));
			}
			break;													// 전부 출력했으면 반복문 탈출하기
		}
		else if (j == m)									// arr2가 끝일 때
		{
			for (count = count + 1; count < m; count++, i++)		// 바로 다음 출력부터 고갈되지 않은 행렬을 순서대로 출력
			{
				printf("%d ", *(arr1 + i));
			}
			break;													// 전부 출력했으면 반복문 탈출하기
		}
	}
	printf("\n");
}
*/
// 문제 3-2
/*
void PRT(int n, char* p);
int main()
{
	// 변수 초기화
	char arr[100] = { 0 };
	int i = 0;
	int maxString = 0;			// 가장 긴 단어의 길이 저장
	char* maxChar = arr;		// 가장 긴 단어의 첫 문자 저장
	int count = 0;				// 단어 길이 임시 저장
	char * countChar;			// 첫 문자 임시 저장
	// 1. 문자 입력 받기
	while (1)
	{
		scanf("%c", arr + i);
		if (*(arr + i) == '#') break;			// '#'을 받으면 탈출
		i++;
	}

	countChar = arr;				// 무조건 오는 첫 소문자 저장
	
	// 2. 소문자만 출력하기
	i = 0;							// 초기화
	while (1)
	{
		// 소문자라면 출력하기
		if (*(arr + i) >= 'a' && *(arr + i) <= 'z')
		{
			printf("%c", *(arr + i));
			i++;
			count++;				// 단어별 개수 임시 저장
		}
		else
		{	
			if (maxString < count)
			{
				maxString = count;		// 최대 문자열 길이 최신화
				maxChar = countChar;	// 첫 문자 최신화
			}

			if (*(arr + i) == '#')			// 바로 '#'이 나왔다면 반복문 탈출
			{
				printf("\n");
				break;
			}

			while (!(* (arr + i) >= 'a' && *(arr + i) <= 'z'))	// 소문자 만날 때까지 계속 배열 내 탐색
			{
				if (*(arr + i) == '#') break;			// 순회하다가 '#'을 만나면 반복문 탈출
				i++;									// 아니면 계속 진행
				
			}

			if (*(arr + i) == '#')			// 여기서도 '#'이 나왔으면 반복문 탈출
			{
				printf("\n");
				break;
			}

			// 다음 단어 정보를 얻기 위해서 초기화
			count = 0;
			countChar = arr + i;
			printf("\n");
		}
	}
	printf("%d %c\n", maxString, *(maxChar));				// 최대 문자 수, 그에 대한 첫 문자 출력
	PRT(maxString, maxChar);								// 최대 길이 문자 출력

	return 0;
}
// 최대 길이의 문자 출력, maxString, maxChar를 받아서 순회하며 출력할 것
void PRT(int n, char* arr)					
{
	// 첫 소문자 후 바로 '#'이 오면 출력이 안되서 do-while문으로 설정함
	char* i = arr;
	do
	{
		printf("%c", *i);
		i++;
	}while (i < arr + n);
}
// 문제 2-2
/*
int passengerN(int N);
int changeseat(int* arr);
void rebooking(int* arr);

int main()
{
	// 변수 선언
	int booking[21] = { 0 };
	int N;
	// 승객 수 입력 받기
	scanf("%d", &N);
	// 승객 수만큼 배열에 저장
	for (int i = 0; i < N; i++)
	{
		scanf("%d", booking + i);
	}
	// 승객의 수에 따라서 출력 0이나 -1 출력, 만약 부족하면 바로 프로그램 끝내기
	printf("%d\n", passengerN(N));
	if(passengerN(N) == -1) return 0;

	rebooking(booking);				// 새로운 예약번호 배정

	for (int *i = booking; *i != 0; i++)		// 출력하기
	{
		printf("%d ", *i);
	}

	return 0;
}

int passengerN(int N)
{
	if (N >= 5) return 0;
	else return -1;
}

int changeseat(int* arr)
{
	int min;						// 구할 최소값
	int flag = 0;					// 배열에 같은 값이 존재하는지 확인해주는 변수
									// 주어진 숫자 범위 내에서 배열에 존재하지 않고 최소인 값 구하기
	for (min = 1; min <= 21; min++)
	{
		flag = 0;
		// 배열에 존재하는지 확인
		for (int* j = arr; *j != 0; j++)
		{
			if (*j == min) 
			{
				flag = 1;
				break;		// 배열에 존재하면 다음 반복문으로 넘어감
			}
		}
		if (flag == 0) break; // 배열에 존재하지 않으면 반복 끝냄
	}
	return min;			// 조건에 맞는 값 반환
}

void rebooking(int* arr)
{
	// 중복된 좌석 번호를 확인하기 위해 이중 반복문 사용
	for (int* i = arr; *i != 0; i++)			
	{
		for (int* j = arr; *j != 0; j++)		// 비교 대상 순회
		{
			if (*i == *j && i != j)		// 중복된 값을 발견했을 때, 단 그것이 자기 자신이 아닐 때 변경
			{
				int k = changeseat(arr);
				*j = k;			// 새로운 좌석번호를 배열에 직접 배정하기
			}
		}
	}
}
*/
/*
* 문제 풀 때는 문제 n-2 먼저 풀고 정 못풀겠으면 n-1 풀기
*/
// 문제 1-2
/*
int* MAX(int* arr);
int* MIN(int* arr);

int main()
{
	// 필요한 변수 선언
	int arr[100];
	int N;
	int* max, * min;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)			// N번 반복
	{
		int j = 0;
		while (1)
		{
			scanf("%d", arr + j);		// 주소로 입력 받기
			if (arr[j] == 0) break;		// 만약 0을 받았으면, 반복 종료
			j++;						// j를 하나 더해주면서 계속 배열에 값을 넣음
		}

		// MAX, MIN 함수 실행
		max = MAX(arr);
		min = MIN(arr);

		// 출력 : 경우에 따라 출력하는 경우가 달라짐
		// 1. 숫자를 하나만 입력해서 max와 min이 같거나 두개만 입력해서 사이에 숫자가 없을 때
		if (max == min || max+1 == min || max == min+1)
		{
			printf("none\n");
		}
		// 2. 최대값이 최소값보다 더 뒤에 위치해 있을 때
		else if (max > min)
		{
			for (int* p = min + 1; p < max; p++)
			{
				printf("%d ", *p);
			}
			printf("\n");
		}

		// 2. 최소값이 최대값보다 더 뒤에 위치해 있을 때
		else if (min > max)
		{
			for (int* p = max + 1; p < min; p++)
			{
				printf("%d ", *p);
			}
			printf("\n");
		}
	}

	return 0;
}

// 가장 큰 값 찾기
int* MAX(int* arr)
{
	int* p, * max;
	max = arr;
	for (p = arr; *p != 0; p++)		// 주소로 반복
	{
		if (*max < *p)				// 가장 큰 값 최신화 하기
		{
			max = p;
		}
	}
	return max;						// 배열의 주소를 반환
}

// 가장 작은 값 찾기
int* MIN(int* arr)
{
	int* p, * min;
	min = arr;
	for (p = arr; *p != 0; p++)		// 주소로 반복
	{
		if (*min > *p)				// 가장 작은 값 최신화 하기
		{
			min = p;
		}
	}
	return min;						// 배열의 주소를 반환
}
*/
// 문제 1-1
/*
int* MAX(int *arr);
int* MIN(int* arr);

int main()
{
	// 필요한 변수 선언
	int arr[100];
	int N;
	int* max, * min;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)			// N번 반복
	{
		int j = 0;
		while (1)
		{
			scanf("%d", arr + j);		// 주소로 입력 받기
			if (arr[j] == 0) break;		// 만약 0을 받았으면, 반복 종료
			j++;						// j를 하나 더해주면서 계속 배열에 값을 넣음
		}
		
		// MAX, MIN 함수 실행
		max = MAX(arr);					
		min = MIN(arr);

		// 출력
		printf("%d %d\n", *max, *min);
	}

	return 0;
}

// 가장 큰 값 찾기
int* MAX(int* arr)
{
	int* p, *max;
	max = arr;
	for (p = arr; *p != 0; p++)		// 주소로 반복
	{
		if (*max < *p)				// 가장 큰 값 최신화 하기
		{
			max = p;
		}
	}
	return max;						// 배열의 주소를 반환
}

// 가장 작은 값 찾기
int* MIN(int* arr)
{
	int* p, * min;
	min = arr;
	for (p = arr; *p != 0; p++)		// 주소로 반복
	{
		if (*min > *p)				// 가장 작은 값 최신화 하기
		{
			min = p;
		}
	}
	return min;						// 배열의 주소를 반환
}
*/