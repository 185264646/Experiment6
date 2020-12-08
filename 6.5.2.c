#include<stdio.h>
#include<string.h>

int main(void)
{
	char stra[100], strb[100], *ret;
	int choice;
	char *(*p[2])(const char *,const char *) = {strstr, strpbrk};
	printf("Input the first string:");
	gets(stra);
	printf("Input the second string:");
	gets(strb);
	printf("1. Perform strstr(stra, strb)\n"
		"2. Perform strpbrk(stra, strb)\n"
		"Select an option:");
	scanf("%d", &choice);
	if (0 < choice && choice < 3)
	{
		ret = p[choice](stra, strb);
		printf("That function returned %p, the content here is %s", ret, ret);
	}
	return 0;
}