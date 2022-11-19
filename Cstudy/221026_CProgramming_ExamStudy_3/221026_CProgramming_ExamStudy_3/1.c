#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
typedef struct subject
{
	char subjectName[31];
	double score;
} Subject;

typedef struct student
{
	char name[31];
	int id;
	int subjectNum;
	Subject subject[10];
	double total;
} Student;

void input(Student* p, int count);
void sort_s(Student* p, int count);
void print_s(Student* p, int count);
void deleteStudent(Student* p, int count);

int main()
{
	Student students[100];
	char order = ' ';
	int count = 0;
	while (1)
	{
		scanf("%c", &order);
		switch(order)
		{
		case 'I':
			input(students, count);
			count++;
			break;
		case 'S':
			sort_s(students, count);
			break;
		case 'P':
			print_s(students, count);
			break;
		case 'D':
			deleteStudent(students, count);
			count--;
			break;
		case 'Q':
			return 0;
		}
		if (count < 0) count = 0;
	}
	return 0;
}

void input(Student* p, int count)
{
	int i;
	double sum = 0;
	scanf("%s %d %d", p[count].name, &p[count].id, &p[count].subjectNum);
	for (i = 0; i < p[count].subjectNum; i++)
	{
		scanf("%s %lf", p[count].subject[i].subjectName, &p[count].subject[i].score);
		sum += p[count].subject[i].score;
	}
	p[count].total = sum / (p[count].subjectNum);
}

void sort_s(Student* p, int count)
{
	Student tmp[100];
	Student t;
	int i, j;

	for (i = 0; i < count; i++)
	{
		tmp[i] = p[i];
	}

	for (i = 0; i < count; i++)
	{
		for (j = 0; j < count - (i + 1); j++)
		{
			if (strcmp(tmp[j].name, tmp[j + 1].name) > 0)
			{
				t = tmp[j];
				tmp[j] = tmp[j + 1];
				tmp[j + 1] = t;
			}
		}
	}

	print_s(tmp, count);
}

void print_s(Student* p, int count)
{
	if (count <= 0) return;
	for (int i = 0; i < count; i++)
	{
		printf("%s %d %d %.2f\n", p[i].name, p[i].id, p[i].subjectNum, p[i].total);
	}
}

void deleteStudent(Student* p, int count)
{
	char deletename[31];
	scanf("%s", deletename);
	int i;
	for (i = 0; i < count; i++)
	{
		if (strcmp(p[i].name, deletename) == 0)
			break;
	}

	for (; i < count - 1; i++)
	{
		p[i] = p[i + 1];
	}
}
*/
/*
struct parking_info
{
	int carnum;
	int phone;
	char gift;
	char isS;
	int S;
	int parkingTime;
	double fee;
};

void input(struct parking_info *p, int N);
void compute(struct parking_info* p);
void display(struct parking_info* p, int N);
void parking_info_sort(struct parking_info* p, int N);

int main()
{
	struct parking_info cars[100];
	struct parking_info * pt;
	int N;
	double Ssum = 0, Dsum = 0, total = 0;
	scanf("%d", &N);

	input(cars, N);

	for (pt = cars; pt < cars + N; pt++)
	{
		compute(pt);
		if (pt->gift == 'S') Ssum += pt->fee;
		else if (pt->gift == 'D') Dsum += pt->fee;
	}
	total = Ssum + Dsum;
	parking_info_sort(cars, N);

	display(cars, N);

	printf("%.f %.f %.f", Dsum, Ssum, total);

	return 0;
}

void input(struct parking_info * p, int N)
{
	struct parking_info* pt;

	for (pt = p; pt < p + N; pt++)
	{
		scanf("%d %d %c ", &pt->carnum, &pt->phone, &pt->gift);
		if (pt->gift == 'S')
		{
			scanf("%c %d %d", &pt->isS, &pt->S, &pt->parkingTime);
		}
		else if (pt->gift == 'D')
		{
			scanf("%d ", &pt->parkingTime);
		}
	}
}

void compute(struct parking_info* p)
{
	double result = 0;
	int parking = p->parkingTime - 240;
	if (parking < 0) parking = 0;

	if (p->gift == 'S')
	{
		if (p->isS == 'N')
		{
			if (p->S == 7) result += 30000;
			else if (p->S == 30) result += 100000;
			else if (p->S == 180) result += 500000;
		}
	}
	else if (p->gift == 'D') result += 5000;

	result += (parking / 10 * 200);
	p->fee = result;
}

void display(struct parking_info* p, int N)
{
	struct parking_info* pt;
	for (pt = p; pt < p + N; pt++)
	{
		printf("%d %d %c %.f\n", pt->carnum, pt->phone, pt->gift, pt->fee);
	}
}

void parking_info_sort(struct parking_info* p, int N)
{
	struct parking_info tmp;
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - (i + 1); j++)
		{
			if (p[j].gift > p[j + 1].gift)
			{
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - (i + 1); j++)
		{
			if (p[j].gift == p[j + 1].gift && p[j].carnum > p[j+1].carnum)
			{
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}
}
*/
/*
int main()
{
	int a[11], b[11], alen = 0, blen = 0;
	int* pt, *qt;
	int max, min;
	for (pt = a; pt < a + 11; pt++)
	{
		scanf("%d", pt);
		if (*pt == -1) break;
		alen++;
	}

	for (pt = b; pt < b + 11; pt++)
	{
		scanf("%d", pt);
		if (*pt == -1) break;
		blen++;
	}


	for (pt = a; pt < a + alen; pt++)
	{
		max = *pt;
		for (qt = pt; qt < a + alen; qt++)
		{
			if (*qt > max)
			{
				max = *qt;
				*qt = *pt;
				*pt = max;
			}
		}

		for (qt = b; qt < b + blen; qt++)
		{
			if (*qt > max)
			{
				max = *qt;
				*qt = *pt;
				*pt = max;
			}
		}
	}

	for (pt = b; pt < b + blen; pt++)
	{
		min = *pt;
		for (qt = pt; qt < b + blen; qt++)
		{
			if (*qt < min)
			{
				min = *qt;
				*qt = *pt;
				*pt = min;
			}
		}
	}

	for (pt = a; pt < a + alen; pt++) printf("%d ", *pt);
	printf("\n");
	for (pt = b; pt < b + blen; pt++) printf("%d ", *pt);

	return 0;
}
*/