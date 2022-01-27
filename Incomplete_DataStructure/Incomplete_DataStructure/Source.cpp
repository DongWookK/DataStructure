#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char temp[5];
	for (int i = 0; i < 4; i++)
		scanf("%c", &temp[i]);
	temp[4] = '\0';
	printf("%s", temp);
}