#include<stdio.h>
#include<stdlib.h>
char *strcopy(char *, const char *);
int main(void)
{
	char *s1 = malloc(50 * sizeof(char)), *s2 = malloc(50 * sizeof(char)), *s3;
	printf("Input a string:\n", s2);
	scanf("%s", s2);
	strcopy(s1, s2);
	printf("%s\n", s1);
	printf("Input a string again:\n", s2);
	scanf("%s", s2);
	s3 = strcopy(s1, s2);
	printf("%s\n", s3);
	free(s1);
	free(s2);
	return 0;
}

/* 将字符串s复制给字符串t，并且返回串t的首地址 */
char *strcopy(char *t, const char *s)
{
	char *temp = t;
	while (*t++ = *s++);
	return temp;
}