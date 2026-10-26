#pragma once

int** create_matrix(int n);

void free_matrix(int** a, int n);

int** read_matrix(int* n);

void print_matrix(int** a, int rows, int cols);
