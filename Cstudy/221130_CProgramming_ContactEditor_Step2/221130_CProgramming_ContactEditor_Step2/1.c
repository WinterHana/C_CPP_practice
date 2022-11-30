#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
<test 1>
3
1
Hong
01111112222
20000101
1
KimEunJoo
222111333
19960303
1
HanGeul
010222333
19980101
1
5
*/

/*
<test 2>
5
1
KimEunJoo
0001112222
20001010
1
Park
+820010101013211221321321
19900101
1
LeeEunJoo_MS
3401222
19950101
2
3
LeeEunJoo_MS
2
5
*/
// ������ ����ü ����
typedef struct tel {
	char* name;
	char* phone;
	char* birth;
}TEL;

// �ʿ��� �Լ� ����
void printMainMenu();
void swapContact(TEL** tel_list, int index1, int index2);
void sortContact(TEL** tel_list, int count);
void insertContact(TEL** tel_list, int* count, int max_num);
void deleteContact(TEL** tel_list, int* count);
void printAll(TEL** tel_list, int count);
void findContactByBirth(TEL** tel_list, int count);

int main()
{
	TEL** tel_list;
	int max_num;						// �ִ� ȸ����
	int count = 0;						// ���� ����ó ����
	int menu;
	printf("Max_num:");
	scanf("%d", &max_num);
	tel_list = (TEL**)malloc(sizeof(TEL*) * max_num);

	while (1) {
		printMainMenu();				//�޴� ���
		scanf("%d", &menu);				//�޴�����
		switch (menu) {
		case 1:
			insertContact(tel_list, &count, max_num);		//���
			break;
		case 2:
			printAll(tel_list, count);				//����
			break;
		case 3:
			deleteContact(tel_list, &count);		//����
			break;
		case 4:
			findContactByBirth(tel_list, count);	//������ �˻�
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
void swapContact(TEL** tel_list, int index1, int index2)
{
	TEL tmp;
	tmp = *(tel_list[index1]);
	*(tel_list[index1]) = *(tel_list[index2]);
	*(tel_list[index2]) = tmp;
}

// ���� �� �����͸� �̸������� �����Ѵ�.
void sortContact(TEL** tel_list, int count)
{
	int i;
	if (count <= 1) return;				// �����Ͱ� �ϳ� ���ϸ� ������ �ʿ䰡 �����Ƿ� ����
	else								// ������ �ʿ䰡 �ִٸ� �� �ڿ� �����ͺ��� �ڱ� ��ġ�� ã�������� ����
	{
		for (i = count - 1; i >= 1; i--)
		{
			if (strcmp(tel_list[i - 1]->name, tel_list[i]->name) > 0)
				swapContact(tel_list, i, i - 1);
		}
	}
}


// ������ �߰��ϱ�
void insertContact(TEL** tel_list, int* count, int max_num)
{
	char str[101];
	int len;
	TEL *tmp = (TEL*)malloc(sizeof(TEL));			// ���ο� ����ü �����Ҵ��� �޴´�.
	// ���� MAXCONTACT �̻��� �����Ͱ� ���Դٸ� ������
	if (*count >= max_num) {
		printf("OVERFLOW\n");
		return;
	}

	// ������ �Է�
	// 1, �̸�
	printf("Name:");
	scanf("%s", str);
	len = strlen(str);
	tmp->name = (char*)malloc(sizeof(char) * (len + 1));
	strcpy(tmp->name, str);

	// 2. ��ȭ��ȣ
	printf("Phone_number:");
	scanf("%s", str);
	len = strlen(str);
	tmp->phone = (char*)malloc(sizeof(char) * (len + 1));
	strcpy(tmp->phone, str);

	// 3. ����
	printf("Birth:");
	scanf("%s", str);
	len = strlen(str);
	tmp->birth = (char*)malloc(sizeof(char) * (len + 1));
	strcpy(tmp->birth, str);

	tel_list[*count] = tmp;
	(*count)++;								//�ε��� ����

	sortContact(tel_list, *count);				// ��� �Էµ� �����͸� ������ ��ġ�� �̵�

	// ���� �ο� ���
	printf("<<%d>>\n", *count);
	return;
}

// ������ �����ϱ�
void deleteContact(TEL** tel_list, int* count)
{
	char name[101];
	int deleteIndex, i;
	// ������ �����Ͱ� ������ ������
	if (*count == 0)
	{
		printf("NO MEMBER\n");
		return;
	}
	// ������ �̸� �Է��ϱ�
	printf("Name:");
	scanf("%s", name);

	// ������ �̸��� ��� �ε����� �ִ��� Ȯ���ϱ�
	for (deleteIndex = 0; deleteIndex < *count; deleteIndex++)
	{
		if (strcmp(tel_list[deleteIndex]->name, name) == 0)
		{
			break; // ã������ �ݺ��� Ż��
		}
	}

	// ������ �ε����� �������� ����ü �����Ҵ� �� �޸𸮸� ������ �� �ٽ� NULL�� �ʱ�ȭ
	free(tel_list[deleteIndex]);
	tel_list[deleteIndex] = NULL;

	// ������ �ε��� ���� �ε����� �� ĭ�� �մ���
	for (i = deleteIndex; i < *count; i++)
	{
		tel_list[i] = tel_list[i + 1];
	}

	(*count)--; // �������� �� �ϳ� ���̱�
}


// ��ü ���� ���
void printAll(TEL** tel_list, int count)
{
	int i;
	for (i = 0; i < count; i++)
	{
		printf("%s %s %s\n", tel_list[i]->name, tel_list[i]->phone, tel_list[i]->birth);
	}
}


// ���� ���
void findContactByBirth(TEL** tel_list, int count)
{
	int birth, i;
	int month, fullBirth;
	printf("Birth:");
	scanf("%d", &birth);

	for (i = 0; i < count; i++)
	{
		fullBirth = atoi(tel_list[i]->birth);	// ������� ���� ���ڷ� ��ȯ
		month = fullBirth % 10000;				// ���ϸ� ��������
		month = month / 100;					// ���� ��������
		if (month == birth)						// ���� ���̸� ����Ѵ�
		{
			printf("%s %s %s\n", tel_list[i]->name, tel_list[i]->phone, tel_list[i]->birth);
		}
	}
}
