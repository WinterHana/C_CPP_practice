#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXCONTACT 10
/*
1
B
01012345678
19990808
1
A
01023456789
20000101
1
C
01045678901
20040315
*/

//TestData1
/*
2
3
1
Kim
0001112222
19960101
1
Lee
0103332222
19960202
1
Han
0114445555
20000101
2
3
Kim
2
5
*/

// TestData2
/*
1
Kim
0112223333
19950101
1
Han
01011112222
19960302
1
Lee
0101234567
19970903
2
4
1
5
*/
typedef struct ContactInfo {
	char name[21];
	char phone[16];
	char birth[9];
} Contact;

void printMainMenu();
void swapContact(Contact* contactData, int index1, int index2);
void sortContact(Contact* contactData, int numContact);
void insertContact(Contact* contactData, int* numContact);
void deleteContact(Contact* contactData, int* numContact);
void printAll(Contact* contactData, int numContact);
void findContactByBirth(Contact* contactData, int numContact);

int main()
{
	Contact contactData[MAXCONTACT];	//100�� ����ü���� ����
	int numContact = 0;					//����� �ε���
	int menu;
	while (1) {
		printMainMenu();				//�޴� ���
		scanf("%d", &menu);				//�޴�����
		switch (menu) {
		case 1: 
			insertContact(contactData, &numContact);		//���
			break;
		case 2:
			printAll(contactData, numContact);				// ����
			break;
		case 3: 
			deleteContact(contactData, &numContact);		//����
			break;
		case 4: 
			findContactByBirth(contactData, numContact);	//������ �˻�
			break;
		case 5:
			return 0;
		default:
			printf("error\n");
		}
	}
	return 0;
}

// �⺻ ���� �޴��� ����Ѵ�.
void printMainMenu()
{
	printf("*****Menu*****\n");
	printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
	printf("Enter_the_menu_number:");
}

// ������ ���� ��Ҹ� ���� �ٲ۴�.
void swapContact(Contact* contactData, int index1, int index2)
{
	Contact tmp;
	tmp = contactData[index1];
	contactData[index1] = contactData[index2];
	contactData[index2] = tmp;
}

// ���� �� �����͸� �̸������� �����Ѵ�.
void sortContact(Contact* contactData, int numContact)
{
	int i;
	if (numContact <= 1) return;				// �����Ͱ� �ϳ� ���ϸ� ������ �ʿ䰡 �����Ƿ� ����
	else				// ������ �ʿ䰡 �ִٸ� �� �ڿ� �����ͺ��� �ڱ� ��ġ�� ã�������� ����
	{
		for (i = numContact - 1; i >= 1; i--)
		{
			if (strcmp(contactData[i - 1].name, contactData[i].name) > 0)
				swapContact(contactData, i, i - 1);
		}
	}
}

// ������ �߰��ϱ�
void insertContact(Contact* contactData, int* numContact)
{
	if (*numContact >= MAXCONTACT) {
		printf("OVERFLOW\n");
		return;
	}

	// ������ �Է�
	printf("Name:");
	scanf("%s", contactData[*numContact].name);
	printf("Phone_number:");
	scanf("%s", contactData[*numContact].phone);
	printf("Birth:");
	scanf("%s", contactData[*numContact].birth);
	(*numContact)++;								//�ε��� ����

	sortContact(contactData, *numContact);		// ��� �Էµ� �����͸� ������ ��ġ�� �̵�
	
	// ���� �ο� ���
	printf("<<%d>>\n", *numContact);
	return;
}

void deleteContact(Contact* contactData, int* numContact)
{
	char name[21];
	int deleteIndex, i;
	// ������ �����Ͱ� ������ ����
	if (*numContact == 0)
	{
		printf("NO MEMBER\n");
		return;
	}
	// ������ �̸� �Է��ϱ�
	printf("Name:");
	scanf("%s", name);

	// ������ �̸��� ��� �ε����� �ִ��� Ȯ���ϱ�
	for (deleteIndex = 0; deleteIndex < *numContact; deleteIndex++)
	{
		if (strcmp(contactData[deleteIndex].name, name) == 0)
		{
			break;
		}
	}

	// ������ �ε��� ���� �ε����� �� ĭ�� �մ���
	for (i = deleteIndex; i < *numContact; i++)
	{
		contactData[i] = contactData[i + 1];
	}
	
	(*numContact)--;
}

// ��ü ���� ���
void printAll(Contact* contactData, int numContact)
{
	int i;
	for (i = 0; i < numContact; i++)
	{
		printf("%s %s %s\n", contactData[i].name, contactData[i].phone, contactData[i].birth);
	}
}

// ���� ���
void findContactByBirth(Contact* contactData, int numContact)
{
	int birth, i;
	int month, fullBirth;
	printf("Birth:");
	scanf("%d", &birth);

	for (i = 0; i < numContact; i++)
	{
		fullBirth = atoi(contactData[i].birth);	// ������� ���� ���ڷ� ��ȯ
		month = fullBirth % 10000;				// ���ϸ� ��������
		month = month / 100;					// ���� ��������
		if (month == birth)			// ���� ���̸� ����Ѵ�
		{
			printf("%s %s %s\n", contactData[i].name, contactData[i].phone, contactData[i].birth);
		}
	}
}

// �ڼ��� �ּ�
/*
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXCONTACT 10

// ������ ����ü ����
typedef struct ContactInfo {
	char name[21];
	char phone[16];
	char birth[9];
} Contact;

// �ʿ��� �Լ� ����
void printMainMenu();
void swapContact(Contact* contactData, int index1, int index2);
void sortContact(Contact* contactData, int numContact);
void insertContact(Contact* contactData, int* numContact);
void deleteContact(Contact* contactData, int* numContact);
void printAll(Contact* contactData, int numContact);
void findContactByBirth(Contact* contactData, int numContact);

int main()
{
	Contact contactData[MAXCONTACT];	//100�� ����ü���� ����
	int numContact = 0;					//����� �ε���
	int menu;
	while (1) {
		printMainMenu();				//�޴� ���
		scanf("%d", &menu);				//�޴�����
		switch (menu) {
		case 1:
			insertContact(contactData, &numContact);		//���
			break;
		case 2:
			printAll(contactData, numContact);				//����
			break;
		case 3:
			deleteContact(contactData, &numContact);		//����
			break;
		case 4:
			findContactByBirth(contactData, numContact);	//������ �˻�
			break;
		case 5:
			return 0;
		default:
			printf("error\n");
		}
	}
	return 0;
}

// ���� �޴��� ����Ѵ�.
void printMainMenu()
{
	printf("*****Menu*****\n");
	printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
	printf("Enter_the_menu_number:");
}

// ������ ���� ��Ҹ� ���� ��ȯ�Ѵ�.
void swapContact(Contact* contactData, int index1, int index2)
{
	Contact tmp;
	tmp = contactData[index1];
	contactData[index1] = contactData[index2];
	contactData[index2] = tmp;
}

// ���� �� �����͸� �̸������� �����Ѵ�.
void sortContact(Contact* contactData, int numContact)
{
	int i;
	if (numContact <= 1) return;				// �����Ͱ� �ϳ� ���ϸ� ������ �ʿ䰡 �����Ƿ� ����
	else				// ������ �ʿ䰡 �ִٸ� �� �ڿ� �����ͺ��� �ڱ� ��ġ�� ã�������� ����
	{
		for (i = numContact - 1; i >= 1; i--)
		{
			if (strcmp(contactData[i - 1].name, contactData[i].name) > 0)
				swapContact(contactData, i, i - 1);
		}
	}
}

// ������ �߰��ϱ�
void insertContact(Contact* contactData, int* numContact)
{
	// ���� MAXCONTACT �̻��� �����Ͱ� ���Դٸ� ������
	if (*numContact >= MAXCONTACT) {
		printf("OVERFLOW\n");
		return;
	}

	// ������ �Է�
	printf("Name:");
	scanf("%s", contactData[*numContact].name);
	printf("Phone_number:");
	scanf("%s", contactData[*numContact].phone);
	printf("Birth:");
	scanf("%s", contactData[*numContact].birth);
	(*numContact)++;								//�ε��� ����

	sortContact(contactData, *numContact);		// ��� �Էµ� �����͸� ������ ��ġ�� �̵�

	// ���� �ο� ���
	printf("<<%d>>\n", *numContact);
	return;
}

// ������ �����ϱ�
void deleteContact(Contact* contactData, int* numContact)
{
	char name[21];
	int deleteIndex, i;
	// ������ �����Ͱ� ������ ������
	if (*numContact == 0)
	{
		printf("NO MEMBER\n");
		return;
	}
	// ������ �̸� �Է��ϱ�
	printf("Name:");
	scanf("%s", name);

	// ������ �̸��� ��� �ε����� �ִ��� Ȯ���ϱ�
	for (deleteIndex = 0; deleteIndex < *numContact; deleteIndex++)
	{
		if (strcmp(contactData[deleteIndex].name, name) == 0)
		{
			break; // ã������ �ݺ��� Ż��
		}
	}

	// ������ �ε��� ���� �ε����� �� ĭ�� �մ���
	for (i = deleteIndex; i < *numContact; i++)
	{
		contactData[i] = contactData[i + 1];
	}

	(*numContact)--; // �������� �� �ϳ� ���̱�
}

// ��ü ���� ���
void printAll(Contact* contactData, int numContact)
{
	int i;
	for (i = 0; i < numContact; i++)
	{
		printf("%s %s %s\n", contactData[i].name, contactData[i].phone, contactData[i].birth);
	}
}

// ���� ���
void findContactByBirth(Contact* contactData, int numContact)
{
	int birth, i;
	int month, fullBirth;
	printf("Birth:");
	scanf("%d", &birth);

	for (i = 0; i < numContact; i++)
	{
		fullBirth = atoi(contactData[i].birth);	// ������� ���� ���ڷ� ��ȯ
		month = fullBirth % 10000;				// ���ϸ� ��������
		month = month / 100;					// ���� ��������
		if (month == birth)			// ���� ���̸� ����Ѵ�
		{
			printf("%s %s %s\n", contactData[i].name, contactData[i].phone, contactData[i].birth);
		}
	}
}
*/