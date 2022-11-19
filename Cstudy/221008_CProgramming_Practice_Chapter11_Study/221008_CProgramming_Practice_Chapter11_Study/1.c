#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct Complex {
	double real, img;
} Complex;

Complex* larger_complex(Complex* pc1, Complex* pc2);
int main()
{
	Complex cp1, cp2;
	scanf("%lf %lf", &cp1.real, &cp1.img);
	scanf("%lf %lf", &cp2.real, &cp2.img);

	Complex *result = larger_complex(&cp1, &cp2);

	printf("%.1f %.1f", result->real, result->img);
	return 0;
}

Complex* larger_complex(Complex* pc1, Complex* pc2)
{
	double result1 = (pc1->real) * (pc1->real) + (pc1->img) + (pc1->img);
	double result2 = (pc2->real) * (pc2->real) + (pc2->img) + (pc2->img);
	
	if (result1 > result2) return pc1;
	else return pc2;
}

// 1. 포인터를 써서 구조체에 접근
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

	// 포인터 구조체 변수 선언
	struct lunchBox* pBox1 = &box1;
	struct lunchBox* pBox2 = &box2;

	int total1 = 0, total2 = 0;

	printf("======= box1 =======\n");
	printf("Main dish : ");
	scanf("%d", &pBox1->maindish);
	for (int i = 0; i < 3; i++)
	{
		printf("Side dish %d : ", i + 1);
		scanf("%d", &pBox1->sidedish[i]);
	}
	printf("Beverage : ");
	scanf("%d", &pBox1->beverage);

	printf("======= box2 =======\n");
	printf("Main dish : ");
	scanf("%d", &pBox2->maindish);
	for (int i = 0; i < 3; i++)
	{
		printf("Side dish %d : ", i + 1);
		scanf("%d", &pBox2->sidedish[i]);
	}
	printf("Beverage : ");
	scanf("%d", &pBox2->beverage);

	total1 += pBox1->maindish;
	for (int i = 0; i < 3; i++)
	{
		total1 += pBox1->sidedish[i];
	}
	total1 += pBox1->beverage;

	printf("Total1 : %d + %d + %d + %d + %d = %d\n",
		pBox1->maindish, pBox1->sidedish[0], pBox1->sidedish[1], pBox1->sidedish[2], pBox1->beverage, total1);

	total2 += pBox2->maindish;
	for (int i = 0; i < 3; i++)
	{
		total2 += pBox2->sidedish[i];
	}
	total2 += pBox2->beverage;

	printf("Total2 : %d + %d + %d + %d + %d = %d\n",
		pBox2->maindish, pBox2->sidedish[0], pBox2->sidedish[1], pBox2->sidedish[2], pBox2->beverage, total2);


		return 0;
}
*/