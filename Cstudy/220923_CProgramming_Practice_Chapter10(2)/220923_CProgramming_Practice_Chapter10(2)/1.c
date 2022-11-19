#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 101

// 문자열 응용 2번
#define ch(A) (A >= '0' && A <= '9')
void convert(char* str1, char* str2, int N);

int main()
{
	char str1[91] = "", str2[91] = "";
	char tmp;
	int N;
	scanf("%s", str1);
	scanf("%c", &tmp);	// Enter 제외
	scanf("%d", &N);	// 정수 입력받아서 규칙대로 문자열 변경

	convert(str1, str2, N);
	printf("%s\n", str2);


	return 0;
}

void convert(char* str1, char* str2, int N)
{
	int i, j = 0, k = 0, M = 0;
	int len = strlen(str1);

	for (i = 0; i < len; i++)
	{
		if (ch(str1[i])) {
			M = 0;
			for (; i < len && ch(str1[i]); i++) {
				M = M * 10 + str1[i] - '0';
			}
			i--;
			for (k = 0; k < N; k++) {
				str2[j++] = 'A' + M - 1;
			}
		}
		else 
			str2[j++] = str1[i];
	}
	str2[j] = '\0';
}
// 문자열 응용 1번 : 응용은 과제 기출이다.
/*
#include <string.h>
#pragma warning(disable:4996)
void convert(char* str, int N);
int main()
{
	char str[21] = "";

	scanf("%s", str);
	convert(str, strlen(str));

	return 0;
}

void convert(char* str, int N)
{
	int i = 0, M;
	while (i < N) {
		if ('0' <= str[i] && str[i] <= '9') {
			M = 0;
			while (i < N && '0' <= str[i] && str[i] <= '9') {
				M = M * 10 + (str[i] - '0');
				i++;
			}
			printf("%d\n", M);
		}
		i++;
	}
}
*/
// 문제 8번
/*
int main()
{
	// 2개의 문자열 결합을 고려해서 50 + 50 + 1 = 101로 배열의 크기를 설정
	char str1[101], str2[101];

	scanf("%s %s", str1, str2);

	if (strcmp(str1, str2) >= 1) {
		strcat(str1, str2);
		printf("%s", str1);
	}
	else {
		strcat(str2, str1);
		printf("%s", str2);
	}

	return 0;
}
*/
// 문제 7번 
/*
int main()
{
	char* strnum[] = { "one", "two", "three", "four", "five", "six" , "seven", "eight", "nine" };
	char* strdigit[] = { "", "TEN", "HUN", "THO" };

	int input, idx, num = 1000, digit = 3;

	scanf("%d", &input);

	while (num != 0) {
		idx = input / num;
		if (idx != 0) {			// idx가 0 이면 출력할 필요 없음
			printf("%s %s", strnum[idx - 1], strdigit[digit]);
		}
		digit--;			// 단위 줄이기
		input %= num;		// 나머지 남기기
		num /= 10;			// 단위 줄이기 1000 > 100 > 10 > 1
		if (num && idx) printf(" ");			// 아직 안끝났으면 띄어쓰기
	}
	printf("\n");

	return 0;
}
*/
// 문제 6번
/*
int main()
{
	char s1[41], s2[41];
	int idx, mode, L1 = 0, L2 = 0, i;

	scanf("%s", s1);
	scanf("%s", s2);
	scanf("%d", &idx);
	scanf("%d", &mode);

	// 문자열의 크기 돌려받기
	L1 = strlen(s1); L2 = strlen(s2);

	// 비워둘 크기만큼 뒤로 미루기
	for (i = L1; i != idx - 1; i--)
	{
		s1[i + L2] = s1[i];
	}

	// mode에 따라 정순, 역순이 달라짐
	if (mode == 0) {					// 정순 삽입
		for (i = 0; i < L2; i++) {
			s1[idx + i] = s2[i];		// 그대로 빈칸따라 삽입
		}
	}
	else if (mode == 1) {				// 역순 삽입
		for (i = 0; i < L2; i++) {
			s1[idx + i] = s2[L2 - 1 - i];			// Null문자를 제외한 문자 삽입3 - 1 - 0 = 2; 3 - 1 - 1 = 1; 3 - 1 - 2 = 0
		}
	}

	printf("%s", s1);

	return 0;
}
*/
// 문제 5번 : %c 사용 금지, 배열 크기는 아마 20+20+1이 적당할 듯
/*
int main()
{
	char s1[41], s2[41];
	int idx, L1 = 0, L2 = 0, i;

	scanf("%s", s1);
	scanf("%s", s2);
	scanf("%d", &idx);

	L1 = strlen(s1); L2 = strlen(s2);
	for (i = L1; i != idx - 1; i--)
	{
		s1[i + L2] = s1[i];
	}

	for (i = 0; i < L2; i++)
	{
		s1[idx + i] = s2[i];
	}
	printf("%s", s1);

	return 0;
}
*/
/*
int main()
{
	// 문제 4번
	char x1[SIZE], x2[SIZE];
	int cnt1 = 0, cnt2 = 0, flag = 1, i = 0;
	scanf("%s", x1);
	scanf("%s", x2);
	while (x1[cnt1] != NULL) cnt1++;
	while (x2[cnt2] != NULL) cnt2++;

	while (i < cnt1 || i < cnt2) {
		if (x1[i] != x2[i]) {
			flag = 0;
			break;
		}
		i++;
	}

	if (flag) printf("%d 1\n", cnt1);
	else printf("%d 0\n", cnt1);

	return 0;
	// 문제 3번 : %c 사용 금지
	
	char x[SIZE];
	int i, n;
	scanf("%s", x);
	n = strlen(x);

	for (i = 0; i < n; i++)
	{
		printf("%s\n", x + i);
		x[n + i] = x[i];
		x[n + i + 1] = NULL;
	}

	return 0;
	
}
*/