#include <stdio.h>
#include <stdlib.h>

typedef struct _node { // Создаем структуру узла стэка
    int data; // Поле значения
    struct _node* prev; // Указатель на следующий узел
} Node;

typedef struct _stack {
    Node* last; // Указатель на верхушку стэка
    size_t size;
} Stack;

void stackInit(Stack* stack) { // Функция инициализации стека
    stack->last = NULL; // ЗаNULLяем указатель стэка
    stack->size = 0;
}

int stackIsEmpty(Stack* stack) {
    return stack->size == 0;
}

size_t stackSize(Stack* stack) {
    return stack->size;
}

int stackTop(Stack* stack) {
    return stack->last->data;
}

void stackPushBack(Stack* stack, int value) { // Функция добавления узла в стек
    Node* newNode = (Node*)malloc(sizeof(Node)); // Аллоцируем память на новый элемент
    newNode->data = value; // Присваиваем значение новому узлу
    newNode->prev = stack->last; // Указатель нового узла на следующий является указателем дека на верхушку
    stack->last = newNode; // Указатель на верхушку стека - новый элемент
    stack->size++;
}

int stackPopBack(Stack* stack) { // Функция вытаскивания из стэка верхнего узла
    if (stack->last == NULL) { // Если стэк пуст
        return __INT_MAX__; // Выход из функции
    } else {
        int value = stack->last->data; // В переменную значения копируем значение верхушки стэка
        Node* tmp = stack->last; // Временная переменная узла стэка - указатель на верхушку
        stack->last = stack->last->prev; // Указатель на верхушку стэка на следующий после него узел
        stack->size--;
        free(tmp); // Удаляем элемент из стэка
        return value; // Возвращаем вытащенный элемент стэка
    }
}

void stackPrint(Stack* stack) { // Функция печати стэка
    Node* tmp = stack->last; // Временная переменная узла
    while (tmp != NULL) { // Пока последний элемент не пустой
        printf("%d\t", tmp->data); // Печать
        tmp = tmp->prev; // Двигаемся по стеку
    }
    printf("\n");
}

void stackRemove(Stack* stack) { // Функция удаления стэка
    if (stackIsEmpty(stack)) {
        return;
    }

    Node* tmp = stack->last;
    for (int i = 0; i < stack->size; i++) {
        Node* prevElem = tmp->prev;
        free(tmp);
        tmp = prevElem;
    }
    stack->size = 0;
    stack->last = NULL;
}

Stack stackCopyFrom(Stack* inS) { // Функция копирования элементов стэка
    Stack outS;
    stackInit(&outS);

    Stack conteiner;
    stackInit(&conteiner);

    Node* tmp = inS->last;
    for (int i = 0; i < stackSize(inS); i++) {
        stackPushBack(&conteiner, tmp->data);
        tmp = tmp->prev;
    }
    
    tmp = conteiner.last;
    for (int i = 0; i < stackSize(&conteiner); i++) {
        stackPushBack(&outS, tmp->data);
        tmp = tmp->prev;
    }

    stackRemove(&conteiner);
    return outS;
}

int stackCountOfDiffElem(Stack* stack) { // Подсчет различных элементов
    int count = 0;
    Node* tmp = stack->last;
    int data = tmp->data;
    tmp = tmp->prev; // Переход к следующему узлу

    for (int i = 1; i < stackSize(stack); i++) {
        if (tmp->data != data) {
            count++;
        }
        data = tmp->data;
        tmp = tmp->prev; // Переход к следующему узлу
    }

    return count;
}


int main() 
{
    Stack stack;
    stackInit(&stack);

    int a = 1, b = 2, c = 3, d = 4, e = 5;
    stackPushBack(&stack, a);
    stackPushBack(&stack, b);
    stackPushBack(&stack, c);
    stackPushBack(&stack, d);
    stackPushBack(&stack, e);
    printf("\tИзначальный стэк:\n");
    stackPrint(&stack);

    int count = stackCountOfDiffElem(&stack);
    printf("Различных элементов в стэке - %d\n", count);

    return 0;
}