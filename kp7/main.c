#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "vector.h"

// m - КОЛИЧЕСТВО СТРОК, n - КОЛИЧЕСТВО СТОЛБЦОВ!!!
void AddedElementVectorA(VecA* va) {
    printf("Enter filename:\n");
    char filename[50];
    scanf("%s", filename);
    
    FILE* file = fopen(filename, "r");

    int m, n;
    fscanf(file, "%d", &m); // Строка
    fscanf(file, "%d", &n); // Столбец

    for (int i = 0; i < m; i++) {
        int nonzero_count = 0; // Счетчик ненулевых элементов в текущей строке
        int last_inserted_index = -1; // Индекс последнего вставленного элемента

        for (int j = 0; j < n; j++) {
            Item num;
            fscanf(file, "%f", &num);

            if (num != 0) {
                int column = j;
                Item value = num;
                int index = -1;
                insertValueVecA(va, column, value, index);
                nonzero_count++;

                if (last_inserted_index != -1) {
                    va->begin[last_inserted_index].index_next = va->size - 1;
                }
                last_inserted_index = va->size - 1;
            }
        }

        if (nonzero_count == 0 && last_inserted_index != -1) {
            va->begin[last_inserted_index].index_next = -1;
        }
    }

    fclose(file);
}

void AddedElementVectorM(VecM* vm, VecA* va) {
    printf("Enter filename:\n");
    char filename[50];
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");

    int m, n;
    fscanf(file, "%d", &m); // Строка
    fscanf(file, "%d", &n); // Столбец
    VecA copyVa = copyFrom(va);
    for (int i = 0; i < m; i++) {
        int check = 0; // Сбросить check в ноль перед каждой строкой

        Item tmp_num = 0;
        for (int j = 0; j < n; j++) {
            Item num;
            fscanf(file, "%f", &num);
            if (num != 0 && check == 0) { // Добавить условие, чтобы сохранять только первый ненулевой элемент
                tmp_num = num;
                check = 1;
            }
        }

        if (check == 0) {
            insertValueVecM(vm, -1);
        } else {
            int foundIndex = -1;
            for (int k = 0; k < copyVa.size; k++) {
                if (tmp_num == copyVa.begin[k].value && copyVa.begin[k].column != -1) {
                    foundIndex = k;
                    copyVa.begin[k].column = -1;
                    break; // Добавить прерывание цикла, чтобы сохранять только первое совпадение
                }
            }
            if (foundIndex != -1) {
                insertValueVecM(vm, foundIndex);
            }
        }
    }

    fclose(file);
}

void printSparceMatrix(VecA* va, VecM* vm) {
    printf("Enter filename:\n");
    char filename[50];
    scanf("%s", filename);

    FILE* file_in = fopen(filename, "r");

    int m, n;
    fscanf(file_in, "%d", &m); // Строка
    fscanf(file_in, "%d", &n); // Столбец

    FILE* file_out = fopen("out.txt", "a");

    for (int i = 0; i < m; i++) {
        bool checkIndexM = false;
        int IndexM = -1;
        if (vm->begin[i] != -1) {
            checkIndexM = true;
            IndexM = vm->begin[i];
        }
        int count = 0;
        for (int k = IndexM; k != -1; k = va->begin[k].index_next) {
            count++;
        }
        int nextIndex = IndexM;
        for (int j = 0; j < n; j++) {
            if (nextIndex != -1 && va->begin[nextIndex].column == j) {
                fprintf(file_out, "%.1f ", va->begin[nextIndex].value);
                nextIndex = va->begin[nextIndex].index_next;
            } else {
                fprintf(file_out, "0.0 ");
            }
        }
        fprintf(file_out, "\n");
    }
    fclose(file_in);
    fclose(file_out);
}


int main() 
{
    // readFile();
    // printf("Enter filename:\n");
    // char filename[50];
    // scanf("%s", filename);
    
    // FILE* file = fopen(filename, "r");


    VecA vectorA;
    VecM vectorM;
    createVA(&vectorA);
    createVM(&vectorM);

    AddedElementVectorA(&vectorA);
    AddedElementVectorM(&vectorM, &vectorA);
    printVA(&vectorA);
    printVM(&vectorM);
    printSparceMatrix(&vectorA,&vectorM);
    

    deleteVA(&vectorA);
    deleteVM(&vectorM);

    return 0;
}