#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main() 
{
    List list;
    initList(&list);

    printf("Введите элемент, который хотите добавить в начало:\n");
    color clr;
    scanf("%d", &clr);
    pushFront(&list, clr);
    printf("%d - 1 elem\n", list.front->value);

    printf("Введите элемент, который хотите добавить в начало:\n");
    scanf("%d", &clr);
    pushFront(&list, clr);
    printf("%d - 2 elem\n", list.front->value);

    printf("Введите элемент, который хотите добавить в начало:\n");
    scanf("%d", &clr);
    pushFront(&list, clr);
    printf("%d - 3 elem\n", list.front->value);

    printList(&list);

    printf("Добавьте элемент по индексу, сначала индекс, затем значение:");
    int index;
    color clr1;
    scanf("%d %d", &index, &clr1);
    insertIndex(&list, clr1, index);

    printList(&list);

    printf("Введите элемент, по которому удалять:\n");
    color foundElem;
    scanf("%d", &foundElem);
    foundElementDeleteList(&list, foundElem);
    printList(&list);

    deleteList(&list);

    return 0;
}