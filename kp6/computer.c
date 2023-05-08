#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "computer.h"

void create() {
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
    data = fopen(name, "r");

    if (!data) {
        printf("File not found\n");
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
        scanf("%d", &rec.num_of_disk);
        printf("Enter a capacity of disk\n");
        scanf("%d", &rec.cap_of_disk);
        printf("Enter a number of integrated controllers\n");
        scanf("%d", &rec.num_of_intcontr);
        printf("Enter a number of peripheral devises\n");
        scanf("%d", &rec.num_of_dev);
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
            printf("%s\t%d\t%s\t%d\t%s\t%d\t%s\t%d\t%d\t%d\t%d\t%s\n", read.surname, read.num_of_proc, read.type_of_proc, read.mem_size_ram, read.type_of_contr, read.mem_size_video_proc, read.type_of_disk, read.num_of_disk, read.cap_of_disk, read.num_of_intcontr, read.num_of_dev, read.os);
        }
        fclose(data);
    }
}

int delete() {
    FILE *data;
    char name[100];
    printf("Enter file name\n");
    scanf("%s", name);
    data = fopen(name, "rb");
    if (!data) {
        return -1; // Если файл не найден
    } else {
        remove(name); // Удаление файла
    }
}

int func(int p) {
    pc find, select; // find - для поиска компьютеров, select - для хранения минимальных значений характеристик
    char name[100];
    FILE *data;
    int count = 0;
    printf("Enter file name\n");
    scanf("%s", name);
    data = fopen(name, "rb");
    if (data == NULL) { // Если файл не найден
        return -1;
    } else {
        data = fopen(name, "rb");

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

        while (fread(&find, sizeof(pc), 1, data) != EOF && !feof(data)) { 
            if ((find.num_of_proc < select.num_of_proc) || (find.mem_size_ram < select.mem_size_ram) || (find.mem_size_video_proc < select.mem_size_video_proc) || (find.num_of_disk < select.num_of_disk) || (find.cap_of_disk < select.cap_of_disk) | (find.num_of_intcontr < select.num_of_intcontr) || (!strcmp(find.os, select.os))) { // Если минимальные значения больше имеющихся
                count ++;
            }
        }
        if (count < p) { // Если слишком мало компютеров
            fclose(data);
            return -1;            
        } else {
            data = fopen(name, "r");
            printf("\nList of student which computers need to upgrade\n");
            while (fread(&find, sizeof(pc), 1, data) != EOF && !feof(data)) { 
                if (!((find.num_of_proc >= select.num_of_proc) && (find.mem_size_ram >= select.mem_size_ram) && (find.mem_size_video_proc >= select.mem_size_video_proc) && (find.num_of_disk >= select.num_of_dev) && (find.cap_of_disk >= select.cap_of_disk) && (find.num_of_intcontr >= select.num_of_intcontr) && (!strcmp(find.os, select.os) ))) { // Ищем компютеры, нуждающиеся в обновлении
                    printf("\t%s\n", find.surname);
                }
            }
        }
        fclose(data);
    }
}

void delete_student() {
    FILE *f;
    char name[100];
    printf("Enter file name\n");
    scanf("%s", name);
    if ((f = fopen(name, "rb")) != NULL) {
        char tmp[100];
        printf("Enter delete name\n");
        scanf("%s", tmp);
        const int size = 1024;
        char pattern[size];
        fseek(f, 0, SEEK_END);
        char *storyData = malloc((ftell(f) + 1) * sizeof(char));
        char *ptr = storyData;
        *ptr = 0;
        fseek(f, 0, SEEK_SET);
        while (fread(pattern,sizeof(char), size, f)) {
            if (strstr(pattern, tmp) == NULL) {
                strcat (ptr, pattern);
                ptr += strlen(pattern);
            }
        }
        fclose(f);
        f = fopen(name, "w");
        fputs(storyData, f);
        fclose(f);

        free(storyData);
    }
}