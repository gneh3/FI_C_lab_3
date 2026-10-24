#include <stdio.h>
#include "spiral.h"

// k - номер кольца
void print_spiral(int a[MAX_N][MAX_N], int n)
{
	for (int k = 0; k < (n + 1) / 2; k++)
	{
		for (int i = k; i <= n - 1 - k; i++)
			printf("%d ", a[i][n - 1 - k]);

		for (int j = n - 2 - k; j >= k; j--)
			printf("%d ", a[n - 1 - k][j]);

		for (int i = n - 2 - k; i >= k + 1; i--)
			printf("%d ", a[i][k]);

		for (int j = k; j <= n - 2 - k; j++)
			printf("%d ", a[k][j]);
	}

	printf("\n");
}
