#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ���� 5
// ���� ���� ����ü ����
/*
typedef struct subject {
	char name[31];			// ���� �̸�
	double score;			// �� ���� ���� ����
} Subject;

// �л� ������ ���� ����ü ����
typedef struct student {
	char name[31];			// �̸�
	int id;					// �й�
	int subjectNum;			// ���� ����
	Subject subject[10];	// subject ����ü�� �迭(���� �ִ� 10��)
	double avgScore;		// �� ��� ����
} Student;

// �Լ� ����
void inputStudent(Student sp[], int count);
void print_s(Student sp[], int count);
void sort_s(Student sp[], int count);
void deleteStudent(Student sp[], int count, char deleteName[]);

int main()
{
	Student students[100];		// Student �迭 ����
	int count = 0;				// ����� Student�� ���� ���������� ������Ʈ
	char order;					// ��ɾ ���� ����
	char deleteName[31];		// ���� �̸��� ���� ����
	// 'Q'�� �Էµ� ������ ���� �ݺ�
	while (1)
	{
		scanf("%c", &order);	// ��ɾ� �Է�

		switch (order) {
		case 'I':
			inputStudent(students, count);		// �л� ���� �Է�
			count++;							// �л� �� +1
			break;
		case 'P':
			print_s(students, count);			// ���� �л� ���
			break;
		case 'S':
			sort_s(students, count);			// �л� �̸��� ������������ ���� �� ���
			break;
		case 'D':
			scanf("%s", deleteName);			// ���� �л��� �̸��� �ް�
			deleteStudent(students, count, deleteName);		// �л��� �����.
			count--;							// �л� �� -1
			break;
		case 'Q':								// ���α׷� ����
			return 0;
		}

		if (count <= 0) count = 0;				// count�� ������ �� ��(deleteStudent ���� ��) 0���� �ٽ� �ٲٱ�
	}
}

// �л� ���� �Է�
void inputStudent(Student sp[], int count)
{
	double sumScore = 0;		// �л� ������ �հ� ����
	// 1. �̸�, �й�, ����� ���� �Է¹޴´�.
	scanf("%s %d %d", sp[count].name, &sp[count].id, &sp[count].subjectNum);
	// 2. ���� ���� ���� ������ ����� ������ �Է¹޴´�.
	for (int i = 0; i < sp[count].subjectNum; i++)
	{
		scanf("%s %lf", sp[count].subject[i].name, &sp[count].subject[i].score);
		sumScore += sp[count].subject[i].score;			// �̶�, ������ �հ�� �ٷ� ��ģ��.
	}
	if(sp[count].subjectNum > 0) sp[count].avgScore = sumScore / sp[count].subjectNum;	// ������ ����� ���ؼ� �߰����ش�.
}

// �迭 ���� �����ִ� �л� ���
void print_s(Student sp[], int count)
{
	if (count <= 0) return;		// �л��� ������ ������� ����
	// �迭�� ��ȸ�ϸ� ������ ����Ѵ�
	for (int i = 0; i < count; i++)
	{
		printf("%s %d %d %.2f\n", sp[i].name, sp[i].id, sp[i].subjectNum, sp[i].avgScore);		// �̸�, �й�, ���� ����, ��� ����
	}
}

// �̸��� ������������ �����ؼ� ����ϱ�
void sort_s(Student sp[], int count)
{
	Student tmp[100];			// �ӽ÷� ������ �迭
	Student tmpOne;
	// ���ڷ� ���� �迭�� �ӽ� �迭�� �����Ѵ�.
	for (int i = 0; i < count; i++)
	{
		tmp[i] = sp[i];			// Student ����ü�� ���� ����
	}

	// ���� ���ķ� �ӽ� �迭�� �����Ѵ�.
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count - 1 - i; j++)
		{
			// �̸� �������� ������������ �����Ѵ�.
			if (strcmp(tmp[j].name, tmp[j + 1].name) > 0)
			{
				tmpOne = tmp[j];
				tmp[j] = tmp[j + 1];
				tmp[j + 1] = tmpOne;
			}
		}
	}
	// �ӽ� �迭�� �ٷ� ����Ѵ�.
	print_s(tmp, count);
}

// �Է¹��� �л��� �̸����� �л� ���� �����
void deleteStudent(Student sp[], int count, char deleteName[])
{
	if (count <= 0) return;			// �л��� ������ �ٷ� ����
	int i;
	// �л��� ��� �ε����� �ִ��� ã�´� > i�� ����
	for (i = 0; i < count; i++)
	{
		if (strcmp(sp[i].name, deleteName) == 0)
		{
			break;			// ã������, �ٷ� �ݺ��� Ż��
		}
	}

	// �� �ε������� �迭���� �� ĭ�� �մ���.
	for (; i < count - 1; i++)
	{
		sp[i] = sp[i + 1];
	}
}
*/

// ���� 4 - 2
// ����ü ����
/*
struct parking_info {
	int carNum;			// ���� ��ȣ
	int phone;			// �� ��ȭ��ȣ
	char goods;			// ��ǰ
	char isTicket;		// ����� ��������
	int ticketType;		// ����� ����
	int parkingTime;	// ���� �ð�
	double fee;			// ���
};

// �Լ� ����
void input(struct parking_info* p, int N);
void compute(struct parking_info* p);
void display(struct parking_info* p, int N);
void bike_info_sort(struct parking_info* p, int N);

int main()
{
	int N;								// Parking�� ���� ����
	struct parking_info parkingList[100];			// ũ�� 100��ŭ�� Parking �迭 ����
	struct parking_info* pt;
	double sumD = 0, sumS = 0, sumTotal;// ����� ����

	// 1. N�� �Է¹޴´�.
	scanf("%d", &N);					

	// 2. N��ŭ parkingList�� Parking�� �����Ѵ�.
	input(parkingList, N);

	// 3. parkingList���� ����� ���� ����Ѵ�. �̶�, ����� ���յ� ���� ����Ѵ�.
	for (pt = parkingList; pt < parkingList + N; pt++)
	{
		compute(pt);
		if (pt->goods == 'D') sumD += pt->fee;			// ��ǰ�� ���� ��� �ջ��ϱ�
		else if (pt->goods == 'S') sumS += pt->fee;
	}
	sumTotal = sumD + sumS;								// �� ��ݱ��� ���ϱ�

	// 4. ���ǿ� ���� �����Ѵ�.
	bike_info_sort(parkingList, N);

	// 5. ���(�� Parking�� ����, ��� �Ѿ�)
	display(parkingList, N);
	printf("%.f %.f %.f", sumD, sumS, sumTotal);

	return 0;
}

// �־��� �迭 ���� ������ �Է¹޴´�.
void input(struct parking_info* p, int N)
{
	struct parking_info* pt;
	for (pt = p; pt < p + N; pt++)		// N�� ��ŭ �Է��� ����
	{
		// ���� ��ǰ �������� �Է¹޴´�.
		scanf("%d %d %s", &pt->carNum, &pt->phone, &pt->goods);
		if (pt->goods == 'D')			// ���� ��ǰ�� ���ϱ��̶��, �����ð��� �Է¹޴´�.
		{
			scanf("%d", &pt->parkingTime);
		}
		else if (pt->goods == 'S')		// ���� ��ǰ�� ������̶��, ������� ������ ������� ����, �׸��� �����ð��� �Է¹޴´�.
		{
			scanf("%s %d %d", &pt->isTicket, &pt->ticketType, &pt->parkingTime);
		}
	}
}

// �־��� �迭 ���� �������� ���� ������ �Ѿ��� ����Ѵ�.
void compute(struct parking_info* p)
{
	double result = 0;						// ����� ���� �����ϰ� ���߿� ����ü ���� ����
	int useTime = p->parkingTime - 240;		// ����� �ð��� ���ϴµ�, �⺻ 4�ð��� �����̹Ƿ�, 240���� ���� ����Ѵ�.
	if (useTime <= 0) useTime = 0;			// �̶�, ������ ������ 0���� �ʱ�ȭ
	if (p->goods == 'S')					// ����, ��ǰ�� ������̶��
	{
		if (p->isTicket == 'N')				// �׷��� ������� ���ٸ�
		{
			// ������� ������ ���� ������ �߰��Ѵ�.
			if (p->ticketType == 7) result += 30000;
			else if (p->ticketType == 30) result += 100000;
			else if (p->ticketType == 180) result += 500000;
		}
		// ������� ������ �⺻ 4�ð������� ����
	}
	else if (p->goods == 'D')				// ��ǰ�� ���ϱ��̶��
	{
		result += 5000;						// �⺻ 4�ð� ������ 5000���� �߰��Ѵ�.
	}

	result += useTime / 10 * 200;			// ����� �ð��� ����, ������ �߰��Ѵ�.

	p->fee = result;						// �־��� ����ü�� �Ѿ� ���� �߰�
}

// �־��� ����ü �迭�� ������ ����Ѵ�.
void display(struct parking_info* p, int N)
{
	struct parking_info* pt;
	for (pt = p; pt < p + N; pt++)			// �迭�� �ּҷ� �����ؼ�, �������� ����Ѵ�.
	{
		printf("%d %d %c %.f \n", pt->carNum, pt->phone, pt->goods, pt->fee);
	}
}

// �־��� ���ǿ� ���� ����ü �迭�� �����Ѵ�.
void bike_info_sort(struct parking_info* p, int N)
{
	int i, j;
	struct parking_info tmp;
	// ���� ������ �̿� (2��)
	// 1. ��ǰ�� �������� ������������ �����Ѵ�.
	for (i = 0; i < N - 1; i++)
	{
		for (j = 0; j < N - 1 - i; j++)
		{
			if (p[j].goods > p[j + 1].goods)		// D�� ������, S�� �ڷ� �����Ѵ�.
			{
				tmp = p[j];							// ��ü�� ���ش�.
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}

	// 2. ��ǰ�� ���� ��ȣ�� ���� ������������ �����Ѵ�.
	for (i = 0; i < N - 1; i++)
	{
		for (j = 0; j < N - 1 - i; j++)
		{
			// ��ǰ ������ ���� ��. ���� ��ȣ�� ������������ �����Ѵ�.
			if (p[j].goods == p[j + 1].goods && p[j].carNum > p[j+1].carNum)
			{
				tmp = p[j];					// ��ü�� ���ش�.
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}
}
*/
// ���� 3 - 2 : ������...
// ����ü ���� : ȣ���� ����
struct hotel_info {
	char name[31];			// �̸�
	int rank;				// ���
	double fame;			// ���ǵ�
	double distance;		// �Ÿ�
	char breakfast;			// �������Կ���
};

// �Լ� ����
int in_hotel_info(struct hotel_info* p);
void out_hotel_info(struct hotel_info* p, int N, int G, double D);

int main()
{
	struct hotel_info hotels[100];	// ȣ�ڿ� ���� �迭 ����
	int G;				// ����
	double D;			// �Ÿ�
	int count = in_hotel_info(hotels);		// in_hotel_info�� ���� ȣ���� ������ �� �� �޾Ҵ��� Ȯ��

	scanf("%d %lf", &G, &D);				// ���ǰ� �Ÿ� �Է¹ޱ�
	
	out_hotel_info(hotels, count, G, D);	// out_hotel_info�� ���� ���

	return 0;
}

// ȣ���� ���� �Է¹ޱ�
int in_hotel_info(struct hotel_info* p)
{
	int count = 0;		// �Է� ���� Ƚ��
	char tmp[31];		// �ӽ÷� �̸��� ������ char �迭 ����
	struct hotel_info* pt;
	for (pt = p; pt < p + 100; pt++)		// �ּҷ� ��ȸ�ϱ�
	{
		scanf("%s", tmp);			// �̸��� ���� �Է¹޾�, "0"�� �Է��ߴ��� Ȯ���Ѵ�.
		if (strcmp(tmp, "0") == 0)
		{
			break;					// 0�� �Է¹޾Ҵٸ�, �ݺ����� ������ �ٷ� count ��ȯ
		}
		else
		{
			strcpy(pt->name, tmp);	// �̸��� �Է¹޾Ҵٸ�, �̸��� ����ü ������ ����
			scanf("%d %lf %lf %c", &pt->rank, &pt->fame, &pt->distance, &pt->breakfast); // ������ ������ �Է¹���
			count++;				// count++�� �Է� Ƚ�� ����
		}
	}
	return count;
}

// ����ü �迭 ������ ���� ��, ����Ѵ�.
void out_hotel_info(struct hotel_info* p, int N, int G, double D)
{
	struct hotel_info* pt, tmp;
	int index = 0;		// ���ǿ� �´� ����ü�� ������ ������ �̸� �����ϱ� ���� ����

	// 1. ����� �� ����, �Ÿ��� �� ª�� �͵� �����ϱ�
	for (pt = p; pt < p + N; pt++)
	{
		// �־��� ���ǿ��� ���� �� ����, �Ÿ��� �� ª�� ����ü�� �迭 ���� ������ ������.
		if (pt->rank >= G && pt->distance <= D)		
		{
			tmp = *(p + index);				// ��ü�ϱ�
			*(p + index) = *pt;
			*pt = tmp;
			index++;						// index�� +1 �ϱ�
		}
	}
	
	// 2. ������ ���� ������� ���������� �̿��� �����ϱ�
	// index�� �̿��� ���ǿ� �¾Ҵ� ����ü�鸸 �����ϸ� �ȴ�.
	for (int i = 0; i < index; i++)
	{
		for (pt = p; pt < p + index - 1 - i ; pt++)
		{
			if (pt->fame < (pt + 1)->fame)		// ������ �� ���� ����ü�� ������ ������.
			{
				tmp = *pt;						// ��ü ����
				*pt = *(pt + 1);
				*(pt + 1) = tmp;
			}
			
			else if (pt->fame == (pt + 1)->fame)	// ������ ���ٸ�
			{
				if (strcmp(pt->name, (pt + 1)->name) > 0)	// �̸��� ���� ������� �����ϰ� �Ѵ�.
				{
					tmp = *pt;					// ��ü ����
					*pt = *(pt + 1);
					*(pt + 1) = tmp;
				}
			}
		}
	}

	// ���ĵ� ���ǿ� �´� ����ü�� �ݺ����� �̿��ؼ� ����Ѵ�.
	for (pt = p; pt < p + index; pt++)
	{
		printf("%s %d %.1f %.1f %c\n", pt->name, pt->rank, pt->fame, pt->distance, pt->breakfast);
	}
}

// ���� 2 - 2
/*
// �л��� ������ �Է��� ����ü
struct student {
	char name[21];
	int korean, math, english;
	double avg;
};

// �Լ� ����
void read_data(struct student* st, int N);
void sort_score(struct student* st, int N);
struct student* select_out(struct student* st1, struct student* st2, int N);

int main()
{
	
	struct student st1[50], st2[50];		// student �迭 ����
	int N;									// �л��� ��

	// 1. �л��� ���� �Է¹޴´�.
	scanf("%d", &N);					

	// 2. �� �迭�� �л��� ������ �Է��Ѵ�.
	read_data(st1, N);
	read_data(st2, N);

	// 3. ����ü �迭�� �����Ѵ�.
	sort_score(st1, N);
	sort_score(st2, N);

	// 4. ��� �迭�� �߰� ��� �л��� ������ �� ū�� ����
	struct student* result = select_out(st1, st2, N);

	// 5. ���õ� �迭�� ���� ���
	for (int i = 0; i < N; i++)
	{
		printf("%s %d %d %d %.1f\n", result[i].name, result[i].korean, result[i].english, result[i].math, result[i].avg);
	}

	return 0;
}

// ���� �Է�
void read_data(struct student* st, int N)
{
	struct student* i;				// ������ ���� ����
	for (i = st; i < st + N; i++)	// �Է¹��� N��ŭ �л��� ������ �Է��Ѵ�.
	{
		scanf("%s %d %d %d", i->name, &i->korean, &i->english, &i->math);
		i->avg = (i->korean + i->english + i->math) / 3.0f;			// 3���� ������ ��հ� ���
	}
}

// ����
void sort_score(struct student *st, int N)
{
	struct student tmp, * i, *j;		// �ӽ� ����� ������ ���� tmp ���� 
	// ���� ������ ���� �迭�� �����Ѵ�.
	for (i = st + N - 1; i > st; i--) 
	{
		for (j = st; j < i; j++)
		{
			if (j->avg < (j + 1)->avg)		// ���� �л��� ��հ��� �� Ŭ ��, ���� ��ȯ�� �Ѵ�.
			{
				tmp = *j;					// swap ���·� ��ȯ�Ѵ�.
				*j = *(j + 1);
				*(j + 1) = tmp;
			}
			else if (j->avg == (j + 1)->avg)	// ����, ��հ��� ���ٸ�,
			{
				if (j->korean < (j + 1)->korean)	// ���� ������ �� ���� ����� ������ ����.
				{
					tmp = *j;
					*j = *(j + 1);
					*(j + 1) = tmp;
				}
				else if (j->korean == (j + 1)->korean)	// ����, ���� ������ ���ٸ�,
				{
					if (j->english < (j + 1)->english)	// ���� ������ �� ���� ����� ������ ����.
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

// �߰� ��� �л��� �� ū �׷� ����
struct student* select_out(struct student* st1, struct student* st2, int N)
{
	// �߰� �� ����
	// 1. N�� Ȧ������ ���ǿ� �ְ� 2. �ε����� 0���� �����ϹǷ� ������ ���� ������ �߰� ��� ����
	int num = N / 2;		

	// �� ū ���� �迭 �ּҸ� ��ȯ�Ѵ�.
	if ((st1 + num)->avg > (st2 + num)->avg)
		return st1;
	else
		return st2;
}
*/

// ���� 1 - 2
/*
// ���ǿ� �´� student ����ü ����
struct student {
	char name[10];
	char id[10];
	char grade;
};

int main()
{
	struct student students[5];							// student �迭 ����
	char findName[10], findYear[5], findGrade = "";		// �Է��� �̸��� ������ ������ ���� ����
	char tmp[5];										// ��ȸ�ϸ鼭 �迭�� �ִ� �л����� ���г⵵ ����
	int i, check = 0;									// check�� ���� ����, ���г⵵�� ���� �л��� ã�� ���� Ȯ��

	// 1. �迭�� ������ ����(�л� �̸�, �й�, ����)
	for (i = 0; i < 5; i++)
	{
		scanf("%s %s %c", students[i].name, students[i].id, &students[i].grade);
	}

	// 2. ã�� �л��� �̸� ����
	scanf("%s", findName);

	// 3. �� �� ��ȸ�ϸ鼭 �Է��� �л��� ������ ����
	for (i = 0; i < 5; i++)
	{
		if (strcmp(findName, students[i].name) == 0)
		{
			strncpy(findYear, students[i].id, 4);		// ���� ���г⵵ ������ �ִ� ù 4�ڸ��� ���ڿ��� ������
			findYear[4] = '\0';							// �������� null���ڸ� �ּ� ���ڿ� ���� �ϼ�
			findGrade = students[i].grade;				// ���� ����
			break;										// ã������ �ٷ� �ݺ����� Ż���Ѵ�..
		}
	}

	// 4, �ٽ� �� �� ��ȸ�ϸ鼭 ���� ����, ���г⵵�� ���� �л��� ã�´�.
	for (i = 0; i < 5; i++)
	{
		// �� �л��� ���г⵵�� �̸� ����
		strncpy(tmp, students[i].id, 4);
		tmp[4] = '\0';
		// 1) ���� ���� 2) ���г⵵ ���� 3) ���� ����� �ƴ�
		// ���ǿ� �´� �л��� ã�Ƽ� �̸��� ����Ѵ�.
		if ((students[i].grade == findGrade) && (strcmp(tmp, findYear) == 0) && (strcmp(students[i].name, findName) != 0))
		{
			check = 1;				// ���� ã������, check�� 1�� �ּ� 0�� ��µ��� �ʵ��� �Ѵ�.
			printf("%s ", students[i].name);
		}
	}
	if (check == 0) printf("%d", check);		// ���� �� �� ��ã������, 0�� ����Ѵ�.
	printf("\n");

	// ã���� �ϴ� �л��� ���г⵵�� 131�� ���� ������ ����
	// �̶� ���ڿ��� ������ �ٲٴ� ������ �ʿ��ϴ�.
	int num = atoi(findYear) % 131;				
	printf("%s %d\n", findYear, num);			// ���г⵵, ������ ������ num ���

	return 0;
}
*/


