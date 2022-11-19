#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 3. 복소수 구조체 배열
typedef struct complex {
	double real, imag;
} Complex; 

typedef struct lunchBox {
	int maindish;
	int sidedish[3];
	int beverage;
} LunchBox;

Complex complexAdd(Complex a, Complex b)
{
	Complex result;
	result.real = a.real + b.real;
	result.imag = a.imag + b.imag;

	return result;
}

void printLunchBox(LunchBox box)
{
	int total = 0;
	total += box.maindish;
	for (int i = 0; i < 3; i++)
	{
		total += box.sidedish[i];
	}
	total += box.beverage;

	printf("Total1 : %d + %d + %d + %d + %d = %d\n",
		box.maindish, box.sidedish[0], box.sidedish[1], box.sidedish[2], box.beverage, total);
}

void setLunchBox(LunchBox* box)
{
	printf("======= box =======\n");
	printf("Main dish : ");
	scanf("%d", &box->maindish);
	for (int i = 0; i < 3; i++)
	{
		printf("Side dish %d : ", i + 1);
		scanf("%d", &box->sidedish[i]);
	}
	printf("Beverage : ");
	scanf("%d", &box->beverage);
}

int main()
{
	Complex arr[3] = { {1.2, 2.0}, {-2.2, -0.3}, {0.0, 0.0} };

	arr[2] = complexAdd(arr[0], arr[1]);

	for (int i = 0; i < 3; i++)
	{
		printf("%d = %.1f + %.1fi\n", i + 1, arr[i].real, arr[i].imag);
	}

	LunchBox box[2];

	for (int i = 0; i < 2; i++) 
	{
		setLunchBox(&box[i]);
	}

	for (int i = 0; i < 2; i++)
	{
		printLunchBox(box[i]);
	}

	return 0;
}

// 2. 구조체 실습
/*
struct lunchBox {
	int maindish;
	int sidedish[3];
	int beverage;
};

int main()
{

	struct lunchBox box1 = { 10, {2, 4, 5}, 5 };
	struct lunchBox box2 = { 5, {3, 7, 8}, 10 };
	int total1 = 0, total2 = 0;

	printf("======= box1 =======\n");
	printf("Main dish : ");
	scanf("%d", &box1.maindish);
	for (int i = 0; i < 3; i++)
	{
		printf("Side dish %d : ", i + 1);
		scanf("%d", &box1.sidedish[i]);
	}
	printf("Beverage : ");
	scanf("%d", &box1.beverage);
	
	printf("======= box2 =======\n");
	printf("Main dish : ");
	scanf("%d", &box2.maindish);
	for (int i = 0; i < 3; i++)
	{
		printf("Side dish %d : ", i + 1);
		scanf("%d", &box2.sidedish[i]);
	}
	printf("Beverage : ");
	scanf("%d", &box2.beverage);

	box2 = box1;

	printf("======= box2 =======\n");
	printf("Main dish : ");
	scanf("%d", &box2.maindish);

	total1 += box1.maindish;
	for (int i = 0; i < 3; i++)
	{
		total1 += box1.sidedish[i];
	}
	total1 += box1.beverage;

	printf("Total1 : %d + %d + %d + %d + %d = %d\n",
		box1.maindish, box1.sidedish[0], box1.sidedish[1], box1.sidedish[2], box1.beverage, total1);

	total2 += box2.maindish;
	for (int i = 0; i < 3; i++)
	{
		total2 += box2.sidedish[i];
	}
	total2 += box2.beverage;

	printf("Total2 : %d + %d + %d + %d + %d = %d\n",
		box2.maindish, box2.sidedish[0], box2.sidedish[1], box2.sidedish[2], box2.beverage, total2);
	
	return 0;

	struct lunchBox box = { 0, 0 ,0 };
	int total = 0;
	printf("Main dish : ");
	scanf("%d", &box.maindish);
	for (int i = 0; i < 3; i++)
	{
		printf("Side dish %d : ", i + 1);
		scanf("%d", &box.sidedish[i]);
	}
	printf("Beverage : ");
	scanf("%d", &box.beverage);

	total += box.maindish;
	for (int i = 0; i < 3; i++)
	{
		total += box.sidedish[i];
	}
	total += box.beverage;

	printf("Total : %d + %d + %d + %d + %d = %d",
			box.maindish, box.sidedish[0], box.sidedish[1], box.sidedish[2], box.beverage, total);
	
	return 0;
}
*/
// 1. 구조체 기본문법 연습
/*
struct student {
	int id;
	char name[8];
	double grade;
};

int main()
{
	struct student st1 = { 10, "Tom", 3.2 };

	st1.id += 20;
	strcpy(st1.name, "alice");
	st1.name[0] = 'A';
	st1.grade += 0.5;

	printf("id : %d\n", st1.id);
	printf("name : %s\n", st1.name);
	printf("grade : %.1f\n", st1.grade);
	return 0;
}
*/