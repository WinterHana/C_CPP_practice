#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ���ڿ� ������ ���� ����
int main()
{
	char* pc = "To be, or not to be : that is the question";
	int i = 0;
	int count = 0;
	while (pc[i] != '\0')
	{
		if (pc[i] == 't') count++;
		i++;
	}
	/*
	* for(i = 0; pc[i] != '\0', i++)
	* { if(pc[i] == 't') count++; }
	*/
	printf("���ڿ� \"%s\"�� \n", pc);
	printf("���� \'t\'�� %d�� ��Ÿ��", count);

}
// ���ڿ� ����
/*
int main()
{
	char str[6];
	scanf("%s", str);
	printf("%s\n", str);
	str[5] = '?';
	printf("%s\n", str);		// �� ���ڰ� ��� ������ ���� ��µ�
}
*/