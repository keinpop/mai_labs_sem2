#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "computer.h"

int studentReadTxt(pc *s, FILE *in) {
    fscanf(in, "%s", s->surname);
    fscanf(in, "%d", s->num_of_proc);
    fscanf(in, "%s", s->type_of_proc);
    fscanf(in, "%d", s->mem_size_ram);
    fscanf(in, "%s", s->type_of_contr);
    fscanf(in, "%d", s->mem_size_video_proc);
    fscanf(in, "%s", s->type_of_disk);
    fscanf(in, "%d", s->num_of_disk);
    fscanf(in, "%d", s->cap_of_disk);
    fscanf(in, "%d", s->num_of_intcontr);
    fscanf(in, "%d", s->num_of_dev);
    fscanf(in, "%s", s->os);

    return !feof(in);
}

void studentWriteTxt(pc *s, FILE *out) {
    fprintf(out, "%s", s->surname);
    fprintf(out, "%d", s->num_of_proc);
    fprintf(out, "%s", s->type_of_proc);
    fprintf(out, "%d", s->mem_size_ram);
    fprintf(out, "%s", s->type_of_contr);
    fprintf(out, "%d", s->mem_size_video_proc);
    fprintf(out, "%s", s->type_of_disk);
    fprintf(out, "%d", s->num_of_disk);
    fprintf(out, "%d", s->cap_of_disk);
    fprintf(out, "%d", s->num_of_intcontr);
    fprintf(out, "%d", s->num_of_dev);
    fprintf(out, "%s", s->os);

    fprintf(out, "\n");
}

void writeStrBin(char *str, FILE *out) {
    int lenght = strlen(str);
    fwrite(&lenght, sizeof(int), 1, out);
    fwrite(str, sizeof(char), lenght, out);
}

void studentWriteBin(pc *s, FILE *out) {
    writeStrBin(s->surname, out);
    fwrite(s->num_of_proc, sizeof(int), 1, out);
    writeStrBin(s->type_of_proc, out);
    fwrite(s->mem_size_ram, sizeof(int), 1, out);
    writeStrBin(s->type_of_contr, out);
    fwrite(s->mem_size_video_proc, sizeof(int), 1, out);
    writeStrBin(s->type_of_disk, out);
    fwrite(s->cap_of_disk, sizeof(int), 1, out);
    fwrite(s->num_of_intcontr, sizeof(int), 1, out);
    fwrite(s->num_of_dev, sizeof(int), 1, out);
    writeStrBin(s->os, out);
}

void readStrBin(char *str, FILE *in) {
    int length;
    fread(&length, sizeof(int), 1, in);
    fread(str, sizeof(char), length, in);
}

int studentReadBin(pc *s, FILE *in) {
    readStrBin(s->surname, in);
    fread(s->num_of_proc, sizeof(int), 1, in);
    readStrBin(s->type_of_proc, in);
    fread(s->mem_size_ram, sizeof(int), 1, in);
    readStrBin(s->type_of_contr, in);
    fread(s->mem_size_video_proc, sizeof(int), 1, in);
    readStrBin(s->type_of_disk, in);
    fread(s->num_of_disk, sizeof(int), 1, in);
    fread(s->cap_of_disk, sizeof(int), 1, in);
    fread(s->num_of_intcontr, sizeof(int), 1, in);
    fread(s->num_of_dev, sizeof(int), 1, in);
    readStrBin(s->os, in);

    return !feof(in);
}

// void studentWriteBin(pc *s, FILE *out) {
//     fwrite(s, sizeof(pc), 1, out);
// }


int main(int argc, char *argv[]) 
{   
    if (argc != 4) {
        printf("Usage:\n\t%s  FILE_FROM FILE_TO\n", argv[0]);
        exit(0);
    }

    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");

    if(!in || !out) {
        printf("I/O Error: can't open file.\n");
        exit(1);
    }

    pc s;
    
    if (!strcmp(argv[3], "ttb")) {
        while(studentReadTxt(&s, in)) {
            studentWriteBin(&s, out);
        }
    } else if (strcmp(argv[3], "btt")) {
        while(studentReadBin(&s, in)) {
            studentWriteTxt(&s, out);
        }
    }
    fclose(in);
    fclose(out);

    return 0;
}
