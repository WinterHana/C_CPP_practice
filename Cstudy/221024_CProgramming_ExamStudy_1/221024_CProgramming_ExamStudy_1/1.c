#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// chpater10 문제 4
/*
int s_check(char* p, char* q);
int main()
{
	int i, M, K1, K2, K3, K4, len = 0, s = 0;
	char a[201];
	scanf("%d", &M);
	scanf("%d %d", &K1, &K2);
	getchar();
	len = 200;
	for (i = 0; i < M; i++) {
		gets(a);
		K3 = strlen(a);
		if (K2 > K3 - 1) K4 = K3 - 1;   // 문자열 길이가 구간보다 작으면
		else K4 = K2;                      // 문자열 길이가 구간보다 크면
		s = s_check(&a[K1], &a[K4]);
		if (s == 0) continue;
		printf("%d\n", s);
	}
	return 0;
}

int s_check(char* p, char* q) {
	int x = 0;
	char* r;
	for (r = p; r <= q; r++) {
		if (*r >= 'a' && *r <= 'z')
			x++;
	}
	return x;
}
*/
// chapter9 문제 4-2 : 모범답안 참고
/*
int main()
{
	int a[11], b[11];
	int n = 0, m = 0;
	int* p, * q;
	int max = 0, min = 0;
	for (p = a; p < (a + 11); p++) {
		scanf("%d", p);
		if (*p == -1)	break;
		else		n++;
	}

	for (p = b; p < (b + 11); p++) {
		scanf("%d", p);
		if (*p == -1)	break;
		else		m++;
	}


	for (p = a; p < (a + n); p++)
	{
		max = *p;
		for (q = p; q < (a + n); q++)
		{
			if (*q > max)
			{
				max = *q;
				*q = *p;
				*p = max;
			}
		}

		for (q = b; q < (b + m); q++)
		{
			if (*q > max)
			{
				max = *q;
				*q = *p;
				*p = max;
			}
		}
	}

	for (p = b; p < (b + m); p++) {
		min = *p;
		for (q = p; q < (b + m); q++) {
			if (*q < min) {
				min = *q;
				*q = *p;
				*p = min;
			}
		}
	}

	for (p = a; p < (a + n); p++)
		printf("%d ", *p);
	printf("\n");
	for (p = b; p < (b + m); p++)
		printf("%d ", *p);

	return 0;
}
*/
// chapter9 문제 2-2
/*
int passengerN(int n);
int changeseat(int* ar);
void rebooking(int* ar);

int main()
{
	int human, humans[21];
	int* p;
	scanf("%d", &human);
	printf("%d\n", passengerN(human));
	if (passengerN(human) == -1) return 0;
		
	for (p = humans; p < humans + human; p++)
	{
		scanf("%d", p);
	}

	// printf("%d\n", changeseat(humans));

	rebooking(humans);

	for (p = humans; p < humans + human; p++)
	{
		printf("%d ", *p);
	}

	return 0;
}

int passengerN(int n)
{
	if (n >= 5) return 0;
	else if (n < 5) return -1;
}

int changeseat(int* ar)
{
	int i, min, flag = 1;
	int* pt = ar;
	for (i = 1; i <= 21; i++)
	{
		flag = 1;
		pt = ar;
		while (*pt >= 1 && *pt <= 21)
		{
			if (i == *pt) {
				flag = 0;
				break;
			}
			pt++;
		}
		if (flag) break;
	}

	return i;
}

void rebooking(int* ar)
{
	int* pt, *pt2;
	int change;
	for (pt = ar; *pt >= 1 && *pt <= 21; pt++)
	{
		for (pt2 = pt + 1; *pt2 >= 1 && *pt2 <= 21; pt2++)
		{
			if (*pt == *pt2)
			{
				change = changeseat(ar);
				*pt2 = change;
			}
		}
	}
}
*/
/*
// https://gmlwjd9405.github.io/2018/05/06/algorithm-insertion-sort.html
#define MAX_SIZE 5
#define SWAP(x, y, tmp) ((tmp) = (x), (x) = (y), (y)= (tmp))
void bubble_sort(int list[], int n);
void selection_sort(int list[], int size);
void insertion_sort(int list[], int n);

int main()
{
	int i;
	int list[5] = { 7, 5, 6, 1, 3 };

	// bubble_sort(list, 5);
	//selection_sort(list, 5);
	insertion_sort(list, 5);
	for (i = 0; i < 5; i++)
	{
		printf("%d ", list[i]);
	}


	return 0;
}

void bubble_sort(int list[], int n)
{
	int i, j, tmp;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - (i + 1); j++)
		{
			if (list[j] < list[j + 1])
			{
				tmp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = tmp;
			}
		}
	}
}

void selection_sort(int list[], int size)
{
	int i, j, least, tmp;

	for (i = 0; i < size - 1; i++)
	{
		least = i;

		for (j = i + 1; j < size; j++)
		{
			if (list[j] < list[least])
			{
				least = j;
			}
		}

		if (i != least) 
		{
			SWAP(list[i], list[least], tmp);
		}
	}
}

void insertion_sort(int list[], int n) {
	int i, j, key;

	// 인텍스 0은 이미 정렬된 것으로 볼 수 있다.
	for (i = 1; i < n; i++) {
		key = list[i]; // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사

		// 현재 정렬된 배열은 i-1까지이므로 i-1번째부터 역순으로 조사한다.
		// j 값은 음수가 아니어야 되고
		// key 값보다 정렬된 배열에 있는 값이 크면 j번째를 j+1번째로 이동
		for (j = i - 1; j >= 0 && list[j] > key; j--) {
			list[j + 1] = list[j]; // 레코드의 오른쪽으로 이동
		}

		list[j + 1] = key;
	}
}
*/
