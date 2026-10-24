#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "matrix.h"

// возвращает 1, если матрица прочитана и 0 при конце файла/ошибке
int read_matrix(int a[MAX_N][MAX_N], int* n)
{
	if ((scanf("%d", n) != 1) || *n < 1 || *n > MAX_N)
		return 0;

	for (int i = 0; i < *n; i++)
		for (int j = 0; j < *n; j++)
			if (scanf("%d", &a[i][j]) != 1)
				return 0;

	return 1;
}

void print_matrix(int a[MAX_N][MAX_N], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			printf("%4d", a[i][j]);
		printf("\n");
	}
}
