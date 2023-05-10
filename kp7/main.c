#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "vector.h"

int main() 
{
    // readFile();
    Vector vector;
    createV(&vector);
    printf("Enter value:\n");
    int value = 0;
    scanf("%d", &value);
    pushBackV(&vector, value);
    scanf("%d", &value);
    pushBackV(&vector, value);
    printV(&vector);
    printf("%d", vector.size);

    deleteV(&vector);
    return 0;
}