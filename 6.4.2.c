#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int m, n;
	scanf("%d%d", &m, &n);
	int (*pvct_orig)[m];
	pvct_orig = (int (*)[m])malloc(m * n * sizeof(int));
	int (*pvct_new)[n];
	pvct_new = (int (*)[n])malloc(m * n *sizeof(int));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			int *p = &pvct_orig[i][j];
			scanf("%d", p);
			pvct_new[n - j - 1][i] = *p;
		}
	for (int i = 0; i < n; i++)
		{
		for (int j = 0; j < m; j++)
			printf("%d ",pvct_new[i][j]);
		putchar('\n');
		}
	free(pvct_orig);
	free(pvct_new);
	return 0;
}