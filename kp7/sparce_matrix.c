#include <stdio.h>

typedef struct
{
    unsigned rows, cols; // Количество строк и столбцов 
    int max_size; // Размер матрицы
    unsigned *row_index; //
    unsigned *col_index; //
    int *values;
} Sparce_matrix;
