#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "computer.h"

void helpBoard() {
    printf("\n -c \t\t for creating new dataset\n -a \t\t for adding new record\n -p \t\t for printing dataset\n -d \t\t for delering dataset\n -f 'value'\t for make a task sample\n -ds \t\t for delete student info in file\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Need two or three arguments:\n");
        helpBoard();
        exit(1);
    }
    if (!strcmp(argv[1], "-a")) {
        add();
    } else if (!strcmp(argv[1], "-p")) {
        printTable();
    } else if (!strcmp(argv[1], "-d")) {
        delete();
    } else if (!strcmp(argv[1], "-c")) {
        create();
    } else if (!strcmp(argv[1], "-f")) {
        int p;
        sscanf(argv[2], "d", &p);
        func(p);
    } else if(!strcmp(argv[1], "-ds")) {
        delete_student();
    } else {
        printf("Command not found\n");
        helpBoard();
    }
    
    return 0;
}