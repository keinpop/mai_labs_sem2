#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef double Item;

typedef struct _vector {
    int* begin;
    int size;
    int allocated;
} Vector;

typedef struct _vector_m {
    int row;
} VectorM;

typedef struct _element { // _vector_a
    Item value;
    int column;
    int index_next;
} Element;

void readFile();
void createV(Vector* v);
void deleteV(Vector* v);
void pushBackV(Vector* v, int value);
void printV(Vector* v);

#endif // __VECTOR_H__