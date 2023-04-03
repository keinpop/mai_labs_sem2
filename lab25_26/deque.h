#ifndef __DEQUE_H__
#define __DEQUE_H__

#include <stdio.h>
#include <stdlib.h>

typedef int Item; 

typedef struct _deque_node {
    struct _deque_node *prev; 
    struct _deque_node *next; 
    Item value; 
} Deque_node; 

typedef struct _deque { 
    Deque_node *front;  
    Deque_node *back; 
    size_t size; 
} Deque;


// Функции для работы с деком
void initDeque(Deque *dq);
int isEmpty(Deque *dq);
void insertFront(Deque *dq, Item data);
void insertBack(Deque *dq, Item data);
int deleteFront(Deque *dq);
int deleteBack(Deque *dq);
int deleteDq(Deque *dq);
int printDq(Deque *dq);
void bubbleSort(Deque *dq);


#endif // __DEQUE_H__