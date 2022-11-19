#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
// 실습문제 1번
typedef struct student {
	char major[50];
	char id[10];
}student;

int main()
{
	int N, i, j;
	student stu[100] = {0};
	scanf("%d", &N); 
	getchar();

	for (i = 0; i < N; i++)
	{
		gets(stu[i].major);
		gets(stu[i].id);
	}

	for (i = 0; i < N - 1; i++)
	{
		for (j = 0; j < N - i - 1; j++) 
		{
			if (strcmp(stu[j].major, stu[j + 1].major) > 0)
			{
				student temp;
				temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
			}
		}
	}

	for (i = 0; i < N - 1; i++)
	{
		for (j = 0; j < N - i - 1; j++)
		{
			if (strcmp(stu[j].major, stu[j + 1].major) == 0 && strcmp(stu[j].id, stu[j+1].id) > 0)
			{
				student temp;
				temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		printf("%s %s\n", stu[i].major, stu[i].id);
	}
}
// 문제 8번
/*
typedef struct complex {
	double real, img;
} complex;

complex add(complex c1, complex c2);

int main()
{
	complex c1, c2, c3;
	scanf("%lf %lf", &c1.real, &c1.img);
	scanf("%lf %lf", &c2.real, &c2.img);

	c3 = add(c1, c2);

	printf("%.1f + %.1fi", c3.real, c3.img);

	return 0;
}

complex add(complex c1, complex c2)
{
	complex temp;
	temp.real = c1.real + c2.real;
	temp.img = c1.img + c2.img;

	return temp;
}
*/
// 문제 7번
typedef struct number {
	int num, rank;
} number;

int main()
{
	int i, j, r3, r7;
	number x[10];
	for (i = 0; i < 10; i++) scanf("%d", &x[i].num);

	for (i = 0; i < 10; i++)
	{
		x[i].rank = 0;
		for (j = 0; j < 10; j++)
		{
			if (x[i].num < x[j].num)
			{
				x[i].rank++;
			}
		}
	}
	
	// 여기서 직접 출력하면 랭크가 서로 뒤바뀐 상태로 출력될 수 있으니 변수로 따로 저장하고 출력하자
	for (i = 0; i < 10; i++)
	{
		if (x[i].rank == 2) r3 = x[i].num;
		else if (x[i].rank == 6) r7 = x[i].num;
	}

	printf("%d %d\n", x[2].num, x[6].num);
	printf("%d %d\n", r3, r7);

	return 0;
}

// 문제 6번
/*
typedef struct student {
	int sex, weight, height;
	int grade;
} student;

void input_studentInfo(student* st);

int main()
{
	int N, first = 0, second = 0, third = 0;
	student st[10];
	scanf("%d", &N);
	getchar();
	if (N <= 10)
	{
		for (int i = 0; i < N; i++)
		{
			input_studentInfo(&st[i]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (st[i].grade == 1) first++;
		else if (st[i].grade == 2) second++;
		else if (st[i].grade == 3) third++;
	}

	printf("%d %d %d", first, second, third);

	return 0;
}

void input_studentInfo(student* st)
{
	int standard;
	scanf("%d %d %d", &st->sex, &st->weight, &st->height);

	if (st->sex == 1) standard = 60;
	else if (st->sex == 2) standard = 50;
	else return;

	if (st->weight < standard)
	{
		if (st->height < 165) st->grade = 1;
		else if (st->height >= 165 && st->height < 175) st->grade = 2;
		else if (st->height > 175) st->grade = 3;
	}

	else if (st->weight >= standard && st->weight < standard + 10)
	{
		if (st->height < 165) st->grade = 3;
		else if (st->height >= 165 && st->height < 175) st->grade = 1;
		else if (st->height > 175) st->grade = 2;
	}

	else if (st->weight >= standard + 10)
	{
		if (st->height < 165) st->grade = 2;
		else if (st->height >= 165 && st->height < 175) st->grade = 3;
		else if (st->height > 175) st->grade = 1;
	}
}
*/

// 문제 5번
/*
typedef struct student {
	char name[9], grade;
	int korean, english, math;
	double avg;
}student;

int main()
{
	int N;
	student st[50];
	student* p;
	scanf("%d", &N);
	getchar();			// 엔터 제거
	if (N <= 50 && N >= 1)
	{
		for (p = st; p < st + N; p++)
		{
			scanf("%s", p->name);
			scanf("%d %d %d", &p->korean, &p->english, &p->math);
			p->avg = (p->korean + p->english + p->math) / 3.0;

			if (p->avg >= 90) p->grade = 'A';
			else if (p->avg >= 80) p->grade = 'B';
			else if (p->avg >= 70) p->grade = 'C';
			else p->grade = 'D';
		}
	}

	for (p = st; p < st + N; p++)
	{
		printf("%s %.1f %c\n", p->name, p->avg, p->grade);
	}

	return 0;
}
*/

// 문제 4번
/*
struct student {
	char name[20], grade;
	int score1, score2, score3;
	double avg;
};

void read_student(struct student* sp);
void print_student(struct student s);

int main()
{
	int N, i;
	struct student st[20];
	scanf("%d", &N); 
	getchar();

	if (N <= 20)
	{
		for (i = 0; i < N; i++) read_student(&st[i]);
		for (i = 0; i < N; i++) print_student(st[i]);
	}

	return 0;
}

void read_student(struct student* sp)
{
	scanf("%s", sp->name);
	scanf("%d %d %d", &sp->score1, &(*sp).score2, &sp->score3);
	sp->avg = (sp->score1 + sp->score2 + sp->score3) / 3.0;

	if (sp->avg >= 90) sp->grade = 'A';
	else if (sp->avg >= 80) sp->grade = 'B';
	else if (sp->avg >= 70) sp->grade = 'C';
	else sp->grade = 'F';
}

void print_student(struct student s)
{
	printf("%s %.1f %c\n", s.name, s.avg, s.grade);
}
*/
// 문제 3번
/*
struct score {
	char name[10]; 
	int result;
};
int main()
{
	int i, sum = 0;
	double avg;
	struct score st[5];

	for (i = 0; i < 5; i++)
	{
		scanf("%s", st[i].name);
		scanf("%d", &st[i].result);
		sum = sum + st[i].result;
	}

	avg = sum / 5.0;

	for (i = 0; i < 5; i++)
	{
		if (st[i].result < avg)
			printf("%s\n", st[i].name);
	}

	return 0;
}
*/