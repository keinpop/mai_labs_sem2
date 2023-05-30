#ifndef __VECTOR_STR_H__
#define __VECTOR_STR_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STRSIZE 100

typedef struct _row {
    char key[6];
    char string[STRSIZE];
} Row;

typedef struct _vector {
    Row* value;
    int size;
} Vector;

void createVec(Vector* vec, int size);
int isEmpty(Vector* vec);
int sizeVector(Vector* v);
Row getVecElem(Vector* vec, int index);
void addVec(Vector* vec, int index, Row value);
void resizeVec(Vector* vec, int size);
void deleteVec(Vector* vec);
void printTable(Vector* vec);
int compareKeys(Row first, Row second);

void mergeSort(Vector* vec);

Row binarySearch(Vector* table, char key[6]);

bool checkSortTable(Vector* table);
bool checkSortTableDescending(Vector* table);
void vectorReverse(Vector* vecF, Vector* vecS);

#endif // __VECTOR_STR_H__