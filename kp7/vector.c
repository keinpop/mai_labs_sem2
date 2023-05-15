#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "vector.h"

void readFile(FILE* file) {

    int m = 0, n = 0; // Переменные колличества строк и столбцов
    fscanf(file, "%d", &m);
    fscanf(file, "%d", &n);

    printf("%d - this i\n%d - this j\n", m, n);

    int element[m][n];
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

void createVA(VecA* va) {
    va->allocated = 1;
    va->size = 0;
    va->begin = malloc(va->allocated * sizeof(ElementA));
}

void createVM(VecM* vm) {
    vm->allocated = 1;
    vm->size = 0;
    vm->begin = malloc(vm->allocated * sizeof(int));
}

void deleteV(Vector *v) {
    free(v->begin);
    v->allocated = 0;
    v->size = 0;
    v->begin = NULL;
}

void deleteVA(VecA* va) { // !!!ЗДЕСЬ ВОЗМОЖНА УТЕЧКА ПАМЯТИ!!!
    free(va->begin);
    va->allocated = 0;
    va->size = 0;
    va->begin = NULL;
}

void deleteVM(VecM* vm) {
    free(vm->begin);
    vm->allocated  = 0;
    vm->size = 0;
    vm->begin = NULL;
}

void pushBackV(Vector* v, int value) {
    if (v->size + 1 >= v->allocated) { // Проверка на необходимость выделения еще памяти
        v->allocated *= 2;
        v->begin = realloc(v->begin, sizeof(int) * v->allocated);
    }
    v->begin[v->size++] = value;
}

void insertValueVecA(VecA* va, int column, int value, int index) {
    if (va->size + 1 >= va->allocated) {
        va->allocated *= 2;
        va->begin = realloc(va->begin, sizeof(ElementA) * va->allocated);
    }
    va->begin[va->size].column = column;
    va->begin[va->size].value = value;
    va->begin[va->size].index_next = index;
    ++va->size;
}

void insertValueVecM(VecM* vm, int value) {
    if (vm->size + 1 >= vm->allocated) { // Проверка на необходимость выделения еще памяти
        vm->allocated *= 2;
        vm->begin = realloc(vm->begin, sizeof(int) * vm->allocated);
    }
    vm->begin[vm->size++] = value;
}

void printV(Vector* v) {
    for (int i = 0; i < v->size; i++) {
        printf("%d ", v->begin[i]);
    }
    printf("\n");
}

void printVA(VecA* va) {
    printf("Vector A = ");
    for (int i = 0; i < va->size; i++) {
        printf("(%d;", va->begin[i].column);
        printf("%d;", va->begin[i].value);
        printf("%d) ", va->begin[i].index_next);
    }
    printf("\n");
}

void printVM(VecM* vm) {
    printf("Vector M = ( ");
    for (int i = 0; i < vm->size; i++) {
        printf("%d ", vm->begin[i]);
    }
    printf(")\n");
}

VecA copyFrom(VecA* va) {
    VecA copyVa;
    createVA(&copyVa);
    for (int i = 0; i < va->size; i++) {
        insertValueVecA(&copyVa, va->begin[i].column, va->begin[i].value, va->begin[i].index_next);
    }
    return copyVa;
}

int sizeV(Vector* v) {
    return v->size;
}