#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef float Item;

typedef struct _vector {
    int* begin;
    int size;
    int allocated;
} Vector;

typedef struct _vector_m {
    int* begin;
    int size;
    int allocated;
} VecM;

typedef struct _element_a { // _vector_a
    int column;
    Item value;
    int indexNext;
} ElementA;

typedef struct _vector_a {
    ElementA* begin;
    int size;
    int allocated;
} VecA;


void readFile(FILE* file);
void createV(Vector* v); // Создание вектора
void createVA(VecA* va); // Создание вектора А
void createVM(VecM* vm); // Создание вектора M

void deleteV(Vector* v);
void deleteVA(VecA* va);
void deleteVM(VecM* vm);

void pushBackV(Vector* v, int value);
void insertValueVecA(VecA* va, int column, Item value, int index);
void insertValueVecM(VecM* vm, int value);

void printV(Vector* v);
void printVA(VecA* va);
void printVM(VecM* vm);

VecA copyFrom(VecA* va);

float findMaxElementSparceMatrix(VecA* va);
void divideSparceMatrixElem(VecA* va, Item maxElem);

#endif // __VECTOR_H__