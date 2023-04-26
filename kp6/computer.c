#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "computer.h"

int create() {
    char name[100]; // Имя файла
    FILE *data; // Указатель на файл
    printf("Enter filename to create\n");
    scanf("%s", name); // Вводим имя (& нет, тк ссылка на 1 элемент массива)
    data = fopen(name, "rb");
    if (data != NULL) {
        return -1; // Если файл уже есть
    } else {
        data = fopen(name, "a"); // Иначе открыть файл для саписи в конец файла 
    }
    fclose(data); // Закрыть поток ввода данных
}