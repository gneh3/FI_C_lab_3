#include <stdio.h>

#ifdef _DEBUG
#include <conio.h>
#endif
// у меня багалась IDE при передаче ввода с tests.txt, поэтому я нагуглил ожидание ввода

#include "matrix.h"
#include "spiral.h"
#include "columns.h"

// чтобы запустить на винде через visual studio у меня на компе
// cmd /c "x64\Debug\FI_C_lab3.exe < FI_C_lab3\tests.txt"

int main(void)
{
	int a[MAX_N][MAX_N];
	int n;
	int number = 1;

	while (read_matrix(a, &n))
	{
		printf("matrix %d %dx%d:\n", number, n, n);
		print_matrix(a, n, n);

		printf("spiral: ");
		print_spiral(a, n);

		int cols = remove_duplicate_columns(a, n);
		printf("without duplicate cols %dx%d:\n", n, cols);
		print_matrix(a, n, cols);

		printf("\n");
		number++;
	}

#ifdef _DEBUG
	// stdin уже занят файлом, поэтому ждём клавишу напрямую с клавиатуры
	printf("press any key...");
	_getch();
#endif

	return 0;
}
