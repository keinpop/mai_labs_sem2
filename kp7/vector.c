#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "vector.h"

void readFile() {
    printf("Enter filename:\n");
    char filename[50];
    scanf("%s", filename);
    
    FILE* file = fopen(filename, "r");
    int m = 0, n = 0; // Переменные колличества строк и столбцов
    fscanf(file, "%d", &m);
    fscanf(file, "%d", &n);

    printf("%d - this i\n%d - this j\n", m, n);

    int element[m][n];
    Element test;
    for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                fscanf(file, "%d", &element[i][j]);
                if (element[i][j] != 0) {
                    printf("%d ", element[i][j]);
                }
            }
    }
    
    
    fclose(file);
}

void createV(Vector* v) {
    v->allocated = 1;
    v->size = 0;
    v->begin = malloc(v->allocated * sizeof(int));
}

void deleteV(Vector *v) {
    free(v->begin);
    v->allocated = 0;
    v->size = 0;
    v->begin = NULL;
}

void pushBackV(Vector* v, int value) {
    if (v->size + 1 >= v->allocated) { // Проверка на необходимость выделения еще памяти
        v->allocated *= 2;
        v->begin = realloc(v->begin, sizeof(int) * v->allocated);
    }
    v->begin[v->size++] = value;
}

void printV(Vector* v) {
    for (int i = 0; i < v->size; i++) {
        printf("%d ", v->begin[i]);
    }
    printf("\n");
}