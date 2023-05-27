#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "vector_str.h"

void createVec(Vector* vec, size_t size) {
    vec->size = size;
    vec->value = malloc(size * sizeof(Row));
    
    for (int i = 0; i < size; i++) {
        strcpy(vec->value[i].key, "");
        strcpy(vec->value[i].string, "");
    }
}

int isEmpty(Vector* vec) {
    return vec->size == 0;
}

Row getVecElem(Vector* vec, int index) {
    Row emptyRow;
    strcpy(emptyRow.key, "");
    strcpy(emptyRow.string, "");

    if (index >= 0 && index < vec->size) {
        return vec->value[index];
    } else {
        return emptyRow;
    }
}

void addVec(Vector* vec, int index, Row value) {
    if (index >= 0 && index < vec->size) {
        vec->value[index] = value;
    }
}

void resizeVec(Vector* vec, size_t size) {
    Row* newRow = malloc(size * sizeof(Row));
    vec->value = newRow;
    vec->size = size;
}

void deleteVec(Vector* vec) {
    vec->size = 0;
    free(vec->value);
    vec->value = NULL;
}

void printTable(Vector* vec) {
    printf("|--------------------------------------------|\n");
    printf("|   KEY   | STRING                            \n");
    printf("|--------------------------------------------|\n");
    for (int i = 0; i < vec->size; i++) {
        Row tmp = getVecElem(vec, i);
        printf("| %6s | %-41s \n");
    }
    printf("|--------------------------------------------|\n");    
}

int compareKeys(Row first, Row second) {
    return strcmp(first.key, second.key);
}

Row binarySearch(Vector* table, char key[6]) {
    int left = 0;
    int right = table->size - 1;
    int middle;
    Row empty = {"", ""};

    while (left <= right) {
        middle = (left + right) / 2;

        if (strcmp(key, table->value[middle].key) < 0) {
            right = middle - 1;
        } else if (strcmp(key, table->value[middle].key) > 0) {
            left = middle + 1;
        } else {
            return table->value[middle];
        }
    }

    return empty;
}

bool checkSortTable(Vector* table) {
    for (int i = 0; i < table->size - 1; i++) {
        Row a = getVecElem(table, i);
        Row b = getVecElem(table, i + 1);

        if (compareKeys(a, b) > 0) { // Если нарушен порядок
            return false;
        }
    }

    return true;
}

bool checkSortTableDescending(Vector* table) {
    for (int i = 0; i < table->size - 1; i++) {
        Row a = getVecElem(table, i);
        Row b = getVecElem(table, i + 1);

        if (compareKeys(a, b) < 0) {
            return false;
        }
    }
    
    return true;
}

void vectorReverse(Vector* vecF, Vector* vecS) {
    int pos = 0;

    for (int i = vecF->size - 1; i >= 0; i--) {
        Row tmp = getVecElem(vecF, i);
        addVec(vecS, pos, tmp);
        pos++;
    }
}