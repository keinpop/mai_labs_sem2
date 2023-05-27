#ifndef __VECTOR_STR_H__
#define __VECTOR_STR_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _row {
    char key[6];
    char string[100];
} Row;

typedef struct _vector {
    Row* value;
    size_t size;
} Vector;

void createVec(Vector* vec, size_t size);
int isEmpty(Vector* vec);
Row getVecElem(Vector* vec, int index);
void addVec(Vector* vec, int index, Row value);
void resizeVec(Vector* vec, size_t size);
void deleteVec(Vector* vec);
void printTable(Vector* vec);
int compareKeys(Row first, Row second);

// sort

Row binarySearch(Vector* table, char key[6]);

bool checkSortTable(Vector* table);
bool checkSortTableDescending(Vector* table);
void vectorReverse(Vector* vecF, Vector* vecS);

#endif // __VECTOR_STR_H__