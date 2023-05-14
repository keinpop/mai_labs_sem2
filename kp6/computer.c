#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "computer.h"
#include "serialization.h"

void create() {
    char name[100]; // Имя файла
    FILE *file; // Указатель на файл
    printf("Enter filename to create:\n");
    scanf("%s", name); // Вводим имя (& нет, тк ссылка на 1 элемент массива)
    file = fopen(name, "a"); // Открыть файл на чтение
    if (file != NULL) {
        fclose(file);
    }
}

int add() {
    char name[100];
    FILE *file;
    pc rec; // Переменная типа 'pc' для записи характеристик компа
    printf("Enter a filename:\n");
    scanf("%s", name);
    file = fopen(name, "r");

    if (!file) {
        printf("File not found\n");
        return -1;
    }

    file = fopen(name, "a");
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
    scanf("%d", &rec.num_of_disk);
    printf("Enter a capacity of disk\n");
    scanf("%d", &rec.cap_of_disk);
    printf("Enter a number of integrated controllers\n");
    scanf("%d", &rec.num_of_intcontr);
    printf("Enter a number of peripheral devises\n");
    scanf("%d", &rec.num_of_dev);
    printf("Enter an OS\n");
    scanf("%s", rec.os);

    studentWriteBin(&rec, file);
    fclose(file);
}


int printTable() {
    FILE *file;
    pc read;
    memset(&read, 0, sizeof(pc));
    char name[100];
    printf("Enter a filename:\n");
    scanf("%s", name);
    file = fopen(name, "rb");
    if (!file) { // Если файл не найден
        return -1;
    } else {
        printf("Surname\t\tPNum\tPType\tRAM\tCType\tVMem\tDType\tDNum\tDCap\tICNum\tPDNum\tOS\n");
        while (studentReadBin(&read, file)) {
            printf("%s\t%d\t%s\t%d\t%s\t%d\t%s\t%d\t%d\t%d\t%d\t%s\n", read.surname, read.num_of_proc, read.type_of_proc, read.mem_size_ram, read.type_of_contr, read.mem_size_video_proc, read.type_of_disk, read.num_of_disk, read.cap_of_disk, read.num_of_intcontr, read.num_of_dev, read.os);
            memset(&read, 0, sizeof(pc));
        }
        fclose(file);
    }
}

int delete() {
    FILE *file;
    char name[100];
    printf("Enter file name:\n");
    scanf("%s", name);
    file = fopen(name, "rb");
    if (!file) {
        return -1; // Если файл не найден
    } else {
        remove(name); // Удаление файла
    }
}


void delete_student() {
    printf("Enter file name:\n");
    FILE* file;
    char name[100];
    scanf("%s", name);
    printf("Enter student surname:\n");
    char surname[100];
    scanf("%s", surname);
    file = fopen(name, "rb");
    if (!file) {
        return;
    }  
    char tmp_name[100];
    FILE* tmp_file;
    int name_lenght = strlen(name);
    strcpy(tmp_name, name);
    tmp_name[name_lenght] = '_';
    tmp_name[name_lenght + 1] = '\0';
    tmp_file = fopen(tmp_name, "ab");
    if (!tmp_file) {
        printf("fopen failed, errno = %d\n", errno);
        return;
    }

    pc row;
    while (studentReadBin(&row, file)) {
        if (strcmp(row.surname, surname) != 0) {
            studentWriteBin(&row, tmp_file);
        }
        memset(&row, 0, sizeof(pc));
    }
    fclose(tmp_file);
    fclose(file);
    
    remove(file);
    rename(tmp_name, name);
}

int func(int p) {
    pc find, select; // find - для поиска компьютеров, select - для хранения минимальных значений характеристик
    memset(&find, 0, sizeof(pc));
    char name[100];
    FILE *file;
    int count = 0;
    printf("Enter file name\n");
    scanf("%s", name);
    file = fopen(name, "rb");
    if (file == NULL) { // Если файл не найден
        return -1;
    } else {
        file = fopen(name, "rb");

        printf("Enter minimal number of proccesors\n");
        scanf("%d", &select.num_of_proc);
        printf("Enter minimal size of RAM, GB\n");
        scanf("%d", &select.mem_size_ram);
        printf("Enter minimal size of video memory, GB\n");
        scanf("%d", &select.mem_size_video_proc);
        printf("Enter minimal number of disks\n");
        scanf("%d", &select.num_of_disk);
        printf("Enter minimal capacity of disk, GB\n");
        scanf("%d", &select.cap_of_disk);
        printf("Enter minimal number of integrated controllers\n");
        scanf("%d", &select.num_of_intcontr);
        printf("Enter necessary OS\n");
        scanf("%s", select.os);

        while (studentReadBin(&find, file)) { 
            if ((find.num_of_proc < select.num_of_proc) || (find.mem_size_ram < select.mem_size_ram) || (find.mem_size_video_proc < select.mem_size_video_proc) || (find.num_of_disk < select.num_of_disk) || (find.cap_of_disk < select.cap_of_disk) | (find.num_of_intcontr < select.num_of_intcontr) || (!strcmp(find.os, select.os))) { // Если минимальные значения больше имеющихся
                count ++;
            }
            memset(&find, 0, sizeof(pc));
        }
        if (count < p) { // Если слишком мало компютеров
            fclose(file);
            return -1;            
        } else {
            file = fopen(name, "r");
            printf("\nList of student which computers need to upgrade\n");
            while (studentReadBin(&find, file)) { 
                if (!((find.num_of_proc >= select.num_of_proc) && (find.mem_size_ram >= select.mem_size_ram) && (find.mem_size_video_proc >= select.mem_size_video_proc) && (find.num_of_disk >= select.num_of_dev) && (find.cap_of_disk >= select.cap_of_disk) && (find.num_of_intcontr >= select.num_of_intcontr) && (!strcmp(find.os, select.os) ))) { // Ищем компютеры, нуждающиеся в обновлении
                    printf("\t%s\n", find.surname);
                }
                memset(&find, 0, sizeof(pc));
            }
        }
        fclose(file);
    }
}