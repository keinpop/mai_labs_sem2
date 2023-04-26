#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "computer.h"

int create() {
    char name[100]; // Имя файла
    FILE *data; // Указатель на файл
    printf("Enter filename to create:\n");
    scanf("%s", name); // Вводим имя (& нет, тк ссылка на 1 элемент массива)
    data = fopen(name, "rb"); // Открыть файл на чтение
    if (data != NULL) {
        return -1; // Если файл уже есть
    } else {
        data = fopen(name, "a"); // Иначе открыть файл для саписи в конец файла 
    }
    fclose(data); // Закрыть поток ввода данных
}

int add() {
    char name[100];
    FILE *data;
    pc rec; // Переменная типа 'pc' для записи характеристик компа
    printf("Enter a filename:\n");
    scanf("%s", name);
    data = fopen(name, "rb");

    if (!data) {
        return -1;
    } else {
        data = fopen(name, "a");
        printf("Enter a surname\n");
        scanf("%s", rec.surname);
        printf("Enter a number of processors\n");
        scanf("%d", &rec.num_of_proc);
        printf("Enter a type of processors\n");
        scanf("%s", rec.type_of_proc);
        printf("Enter a RAM size\n");
        scanf("%d", &rec.mem_size_ram);
        printf("Enter a type of controller\n");
        scanf("%s", rec.type_of_contr);
        printf("Enter a video memmory size\n");
        scanf("%d", &rec.mem_size_video_proc);
        printf("Enter a type of disk\n");
        scanf("%s", rec.type_of_disk);
        printf("Enter a number of disks\n");
        scanf("%d", rec.num_of_disc);
        printf("Enter a capacity of disk\n");
        scanf("%d", rec.cap_of_disc);
        printf("Enter a number of integrated controllers\n");
        scanf("%d", rec.num_of_intcontr);
        printf("Enter a number of peripheral devises\n");
        scanf("%d", rec.num_of_dev);
        printf("Enter an OS\n");
        scanf("%s", rec.os);
        fwrite(&rec, sizeof(pc), 1, data);
        fclose(data);
    }
}

int printTable() {
    FILE *data;
    pc read;
    char name[100];
    printf("Enter a filename:\n");
    scanf("%s", name);
    data = fopen(name, "rb");
    if (!data) { // Если файл не найден
        return -1;
    } else {
        printf("Surname\t\tPNum\tPType\tRAM\tCType\tVMem\tDType\tDNum\tDCap\tICNum\tPDNum\tOS\n");
        while (fread(&read, sizeof(pc), 1, data) != EOF && !feof(data)) {
            printf("%s\t%d\t%s\t%d\t%s\t%d\t%s\t%d\t%d\t%d\t%d\t%s\n", read.surname, read.num_of_proc, read.type_of_proc, read.mem_size_ram, read.type_of_contr, read.mem_size_video_proc, read.type_of_disk, read.num_of_disc, read.cap_of_disc, read.num_of_intcontr, read.num_of_dev, read.os);
        }
        fclose(data);
    }
}