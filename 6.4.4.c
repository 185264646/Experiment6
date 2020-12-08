#include <stdio.h>
void task0(void)
{
	puts("task0 is called.");
}
void task1(void)
{
	puts("task1 is called.");
}
void task2(void)
{
	puts("task2 is called.");
}
void task3(void)
{
	puts("task3 is called.");
}
void task4(void)
{
	puts("task4 is called.");
}
void task5(void)
{
	puts("task5 is called.");
}
void task6(void)
{
	puts("task6 is called.");
}
void task7(void)
{
	puts("task7 is called.");
}
void execute(void (**)(void), int);
void scheduler(void)
{
	void (*const funcarr[])(void) = {task0, task1, task2, task3, task4, task5, task6, task7};
	void (*sch_funcarr[100])(void);
	int i = 0, ch;
	while ((ch = getchar()) != '\n' && ch != EOF)
	{
		sch_funcarr[i++] = funcarr[ch - '0'];
	}
	execute(sch_funcarr, i);
}

void execute(void (**pfunc)(void), int n)
{
	for (int i = 0; i < n; i++)
		pfunc[i]();
}

int main(void)
{
	scheduler();
	return 0;
}