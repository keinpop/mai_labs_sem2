#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

int main() 
{
    Vector vector;
    size_t size = 1;

    createV(&vector, size);
    destroyV(&vector);
    return 0;
}