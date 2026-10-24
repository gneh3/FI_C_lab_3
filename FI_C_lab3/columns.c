#include "columns.h"

int columns_equal(int a[MAX_N][MAX_N], int rows, int c1, int c2)
{
	for (int i = 0; i < rows; i++)
		if (a[i][c1] != a[i][c2])
			return 0;

	return 1;
}

void delete_column(int a[MAX_N][MAX_N], int rows, int cols, int c)
{
	for (int i = 0; i < rows; i++)
		for (int j = c; j < cols - 1; j++)
			a[i][j] = a[i][j + 1];
}

// возвращает новое число столбцов
int remove_duplicate_columns(int a[MAX_N][MAX_N], int n)
{
	int cols = n;

	for (int j = 0; j < cols; j++)
	{
		int k = j + 1;
		while (k < cols)
		{
			if (columns_equal(a, n, j, k))
			{
				delete_column(a, n, cols, k);
				cols--;
			}
			else
				k++;
		}
	}

	return cols;
}
