#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    Red,
    Green,
    Blue,
    Yellow,
    Black
} color;

typedef struct _list_node {
    struct _list_node* next;
    color value;
} List_node;

typedef struct _list {
    List_node* front;
    size_t size;
} List;

void initList(List* list);
int isEmpty(List* list);
void pushFront(List* list, color clr);
void insertIndex(List* list, color clr, int index);
void popIndex(List* list, int index);
void printList(List* list);
void deleteList(List* list);
void foundElementDeleteList(List* list, color foundElement);

#endif // __LIST_H__