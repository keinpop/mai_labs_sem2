#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void initList(List* list) {
    list->front = NULL;
    list->size = 0;
}

int isEmpty(List* list) { // Возвращает 1, если пустой
    return list->size == 0;
}

void pushFront(List* list, color clr) {
    List_node* listNode = malloc(sizeof(List_node));
    listNode->next = NULL;
    listNode->value = clr;

    if (list->size == 0) {
        list->front = listNode;
    } else {
        listNode->next = list->front;
        list->front = listNode;
    }
    list->size++;
}

void insertIndex(List* list, color clr, int index) {
    if (index > list->size || index < 0) {
        printf("\tOut of bounds list\n");
        return;
    }
    
    List_node* listNode = malloc(sizeof(List_node));
    listNode->value = clr;

    if (index == 0) {
        listNode->next = list->front;
        list->front = listNode;
    } else {
        List_node* tmp = list->front;
        for (int i = 0; i < index - 1; i++) {
            tmp = tmp->next;
        }
        listNode->next = tmp->next;
        tmp->next = listNode;
    }
    list->size++;
}

void popIndex(List* list, int index) {
    if (index > list->size || index < 0) {
        printf("\tOut of bounds list\n");
        return;
    }

    if (isEmpty(list)) {
        printf("\tList is empty\n");
        return;
    }

    List_node* tmp = list->front; // Временная переменная
    List_node* prev = NULL; // Предидущая переменная

    if (index == 0) {
        list->front = tmp->next;
    } else {
        for (int i = 0; i < index; i++) {
            prev = tmp;
            tmp = tmp->next;
        }    
        prev->next = tmp->next;
    }
    printf("\tRemoved element: %d\n", tmp->value);
    free(tmp);
    if (prev != NULL) {
        free(prev);
    }

    list->size--;
}

void printList(List* list) {
    if (isEmpty(list)) {
        printf("\tList is empty\n");
        return;
    }

    List_node* tmp = list->front;

    printf("\tList:\n");
    for (int i = 0; i < list->size; i++) {
        printf("%d\t", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

void deleteList(List* list) {
    if (isEmpty(list)) {
        printf("\tList is empty\n");
        return;
    }

    List_node* tmp = list->front;
    for (int i = 0; i < list->size; i++) {
        List_node* next = tmp->next;
        free(tmp);
        tmp = next; 
    }
    list->front = NULL;
    list->size = 0;
}

void foundElementDeleteList(List* list, color foundElement) {
    if (isEmpty(list)) {
        printf("\tList is empty\n");
        return;
    }
    
    List_node* tmp = list->front;

    while (tmp != NULL) {
        if (tmp->value == foundElement) {
            deleteList(list);
            printf("\tElement was finded! List was deleted\n");
            return;
        } 
        tmp = tmp->next;
    }
    printf("\tElement was not finded!\n");
}