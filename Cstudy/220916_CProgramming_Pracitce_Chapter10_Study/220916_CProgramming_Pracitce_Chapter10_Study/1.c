#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 문자열 포인터 변수 연습
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
	printf("문자열 \"%s\"에 \n", pc);
	printf("문자 \'t\'가 %d번 나타남", count);

}
// 문자열 연습
/*
int main()
{
	char str[6];
	scanf("%s", str);
	printf("%s\n", str);
	str[5] = '?';
	printf("%s\n", str);		// 널 문자가 없어서 쓰레기 값이 출력됨
}
*/