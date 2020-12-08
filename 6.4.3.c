#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void rm_leading_blank(char *str)
{
	int i = strspn(str, " \t");
	if (i)
		memmove(str, str + i, strlen(str) - i + 1);
}

int main(void)
{
	int n;
	char t[81];
	scanf("%d ", &n);
	char *str[n];
	for (int i = 0; i < n; i++)
	{
		gets(t);
		str[i] = malloc(strlen(t) + 1);
		strcpy(str[i], t);
		rm_leading_blank(str[i]);
	}
	for (int i = 0; i < n; i++)
		puts(str[i]);
	return 0;
}