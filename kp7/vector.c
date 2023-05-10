#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

void createV(Vector *vector, size_t size) {
    vector->size = size;
    vector->value = malloc(sizeof(int) * vector->size);
}

void destroyV(Vector *vector) {
    vector->size = 0;
    free(vector->value);
}