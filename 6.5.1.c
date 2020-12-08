#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct
{
	char integer[20];
	char interval;
	char decimal[10];
} num;

bool overflow = false;

void get_num(num *);
num num_add(num, num);
int main(void)
{
	num a, b, sum;
	get_num(&a);
	scanf(" + ");
	get_num(&b);
	sum = num_add(a, b);
	printf("%s.%s + %s.%s = %s%s.%s", a.integer, a.decimal, b.integer, b.decimal, overflow ? "" : "1" ,sum.integer, sum.decimal);
	return 0;
}

void get_num(num *a)
{
	a->interval = 0;
	scanf("%20s.%10s", a->integer, a->decimal);
}

num num_add(num a, num b)
{
	char temp[10];
	num ans = {.interval = '\0'};
	unsigned long long x, y;
	// Parse decimal part.
	x = strtoull(a.decimal, NULL, 10);
	y = strtoull(b.decimal, NULL, 10);
	y += x;
	if (y >= 10000000000)
	{
		overflow = true;
		y -= 10000000000;
	}
	sprintf(ans.decimal, "%010ull", y);
	// Parse the last 10 bytes of the integral part.
	a.decimal[0] = '\0';
	b.decimal[0] = '\0'; 
	x = strtoull(a.integer + 10, NULL, 10);
	y = strtoull(b.integer + 10, NULL, 10);
	y += x + overflow;
	if (y >= 10000000000)
	{
		overflow = true;
		y -= 10000000000;
	}
	sprintf(temp, "%010ull", y);
	
	a.integer[10] = '\0';
	b.integer[10] = '\0';
	x = strtoull(a.integer, NULL, 10);
	y = strtoull(b.integer, NULL, 10);
	y += x + overflow;
	if (y >= 10000000000)
	{
		overflow = true;
		y -= 10000000000;
	}
	sprintf(ans.integer, "%010ull", y);
	memcpy(ans.integer + 10, temp, 10);
	
	return ans;
}