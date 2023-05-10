#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct _vector 
{
    int *value;
    size_t size;
} Vector;

void createV(Vector *vector, size_t size);
void destroyV(Vector *vector);

#endif // __VECTOR_H__