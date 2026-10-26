#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

// массив указателей на строки, каждая строка выделяется отдельно
int** create_matrix(int n)
{
	int** a = malloc(n * sizeof(int*));
	if (a == NULL)
		return NULL;

	for (int i = 0; i < n; i++)
	{
		a[i] = malloc(n * sizeof(int));
		if (a[i] == NULL)
		{
			free_matrix(a, i);
			return NULL;
		}
	}

	return a;
}

void free_matrix(int** a, int n)
{
	for (int i = 0; i < n; i++)
		free(a[i]);
	free(a);
}

// возвращает матрицу или NULL при конце файла/ошибке
int** read_matrix(int* n)
{
	if ((scanf("%d", n) != 1) || *n < 1)
		return NULL;

	int** a = create_matrix(*n);
	if (a == NULL)
		return NULL;

	for (int i = 0; i < *n; i++)
		for (int j = 0; j < *n; j++)
			if (scanf("%d", &a[i][j]) != 1)
			{
				free_matrix(a, *n);
				return NULL;
			}

	return a;
}

void print_matrix(int** a, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			printf("%4d", a[i][j]);
		printf("\n");
	}
}
