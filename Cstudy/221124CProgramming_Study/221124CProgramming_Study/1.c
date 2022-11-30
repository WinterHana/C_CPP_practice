#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
hi
hello
nice to meet you
thank you
*/
/*
int main()
{
	char fname[] = "Cnty_list.txt", temp[50] = { '\0' };
	FILE* fp = fopen(fname, "w");
	int i;
	
	for (i = 0; i < 4; i++)
	{
		fgets(temp, 50, stdin);
		fputs(temp, fp);
	}
	fclose(fp);

	fp = fopen(fname, "r");

	for (i = 0; i < 4; i++)
	{
		fgets(temp, 50, fp);
		printf("%s", temp);
	}

	fclose(fp);

	fp = fopen("feof_test.txt", "r");
	// fgets(temp, sizeof(temp), fp);
	while (!feof(fp))
	{
		fgets(temp, sizeof(temp), fp);
		printf("%s", temp);
	} 

	return 0;
}
*/
/*
int main()
{
	char fn[] = "example.txt";
	FILE* fp = fopen(fn, "w");
	if (fp == NULL) return -1;

	char ch = getchar();
	while (ch != 'x')
	{
		fputc(ch, fp);
		ch = getchar();
	}

	fclose(fp);

	fp = fopen(fn, "r");
	if (fp == NULL) return -1;

	ch = fgetc(fp);
	while (!feof(fp)) 
	{
		putchar(ch);
		ch = fgetc(fp);
	}

	fclose(fp);

	return 0;
}
*/
/*
int main()
{
	double height, weight;
	int age, i;
	char fn1[20] = { '\0' };
	char fn2[20] = { '\0' };
	FILE* fp1, * fp2;

	printf("Input filename : ");
	scanf("%s", fn1);
	// getchar();				// ¿£ÅÍ¸¦ »©´Â ´À³¦?
	printf("Output filename : ");
	scanf("%s", fn2);


	fp1 = fopen(fn1, "r");
	if (fp1 == NULL)
	{
		printf("Could't open file");
		return -1;
	}
	fp2 = fopen(fn2, "w");
	if (fp2 == NULL)
	{
		printf("Could't open file");
		return -1;
	}

	for (i = 0; i < 3; i++)
	{
		fscanf(fp1, "%lf %lf %d", &height, &weight, &age);
		fprintf(fp2, "%.2f %.2f %d\n", height, weight, age);
	}

	fclose(fp1);
	fclose(fp2);

	return 0;

}
*/