#include <stdio.h>
#include <stdlib.h>

typedef int Item; // Тип данных элементов стэка

typedef struct _node { // Создаем структуру узла стэка
    Item data; // Поле значения
    struct _node* next; // Указатель на следующий узел
} Node;

typedef struct _stack {
    Node* top; // Указатель на верхушку стэка
} Stack;

void stackInit(Stack* stack) { // Функция инициализации стека
    stack->top = NULL; // ЗаNULLяем указатель стэка
}

void stackPush(Stack* stack, Item value) { // Функция добавления узла в стек
    Node* newNode = (Node*)malloc(sizeof(Node)); // Аллоцируем память на новый элемент
    newNode->data = value; // Присваиваем значение новому узлу
    newNode->next = stack->top; // Указатель нового узла на следующий является указателем дека на верхушку
    stack->top = newNode; // Указатель на верхушку стека - новый элемент
}

Item stackPop(Stack* stack) { // Функция вытаскивания из стэка верхнего узла
    if (stack->top == NULL) { // Если стэк пуст
        return -1; // Выход из функции
    } else {
        int value = stack->top->data; // В переменную значения копируем значение верхушки стэка
        Node* tmp = stack->top; // Временная переменная узла стэка - указатель на верхушку
        stack->top = stack->top->next; // Указатель на верхушку стэка на следующий после него узел
        free(tmp); // Удаляем элемент из стэка
        return value; // Возвращаем вытащенный элемент стэка
    }
}

void stackPrint(Stack* stack) { // Функция печати стэка
    Node* tmp = stack->top; // Временная переменная узла
    while (tmp != NULL) { // Пока последний элемент не пустой
        printf("%d\n", tmp->data); // Печать
        tmp = tmp->next; // Двигаемся по стеку
    }
    printf("\n");
}

void stackSort(Stack* stack) { // Функция сортировки стэка
    Stack tmpStack; // Создаем временный стэк
    stackInit(&tmpStack); // Инициализируем в памяти его

    while (stack->top != NULL) { // Пока стэк не пуст
        Item tmp = stackPop(stack); // Переменная, хронящая в себе вытащенный элемент 
        while (tmpStack.top != NULL && tmpStack.top->data > tmp) { // Пока ВС не пуст и верхушка его больше вытащенного элемента
            stackPush(stack, stackPop(&tmpStack)); // Вставляем в стэк элементы временного
        }
        stackPush(&tmpStack, tmp); // Засовываем в ВС элементы из нашего стэка
    }

    while (tmpStack.top != NULL) {
        stackPush(stack, stackPop(&tmpStack)); // Переносим из временного в наш
    }
}

int main()
{
    Stack stack;
    stackInit(&stack);

    int a = 5, b = 3, c = 1, d = 9, e = 6;
    stackPush(&stack, c);
    stackPush(&stack, a);
    stackPush(&stack, b);
    stackPush(&stack, d);
    stackPush(&stack, e);
    printf("\tИзначальный стэк:\n");
    stackPrint(&stack);

    stackSort(&stack);
    printf("\tСтэк после сортировки:\n");
    stackPrint(&stack);

    return 0;
}