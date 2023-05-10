CC = gcc
CFLAGS ?= -g -Wall -Wextra -std=c99 -w -lm

all:
	$(CC) $(CFLAGS) sparce_matrix.c vector.c main.c -o main

main: main.o sparce_matrix.o vector.o
	${CC} -o main main.o sparce_matrix.o vector.o

main.o: main.c 
	${CC} ${CFLAGS} -c main.c

functions.o: sparce_matrix.c sparce_matrix.o vector.c vector.o
	${CC} ${CFLAGS} -c sparce_matrix.c vector.c

clean: 
	rm -rf *.o main