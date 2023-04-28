#ifndef _COMPUTER_H_
#define _COMPUTER_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct _comp 
{
    char surname[50]; // Фамилия студента
    int num_of_proc; // Значение процессора
    char type_of_proc[50]; // Тип процессора
    int mem_size_ram; // Размер оперативной памяти
    char type_of_contr[50]; // Тип плажки оперативы
    int mem_size_video_proc; // Объем видеопамяти
    char type_of_disk[50]; // Тип хранилища
    int num_of_disk; // Количество хранилищ
    int cap_of_disk; // Объем хранилища в Гб
    int num_of_intcontr; // Количество интерфейсных контроллеров
    int num_of_dev; // Количество устройств i/o
    char os[50];
} pc;

int create();
int add();
int printTable();
int delete();
int func(int p);

#endif //_COMPUTER_H_
