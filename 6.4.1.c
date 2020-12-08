#include<stdio.h>
char itoch[] = "0123456789ABCDEF";
union node
{
	unsigned int i;
	char c[4];
};

int main(void)
{
	union node num;
	scanf("%d", (int *)&num.i);
#if 0
	for (int i = 0; i < 4; i++)
#endif
	for (int i = 3; i >= 0; i--)
	{
		printf("%c%c", itoch[num.c[i] >> 4], itoch[num.c[i] & 0xF]);
	}
	return 0;
}