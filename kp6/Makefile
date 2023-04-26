CC = gcc
CFLAGS ?= -g -Wall -Wextra -std=c99 -w -lm

all:
	$(CC) $(CFLAGS) computer.c main.c -o main

main: main.o computer.o
	${CC} -o main main.o computer.o

main.o: main.c 
	${CC} ${CFLAGS} -c main.c

functions.o: computer.c computer.o
	${CC} ${CFLAGS} -c computer.c

clean: 
	rm -rf *.o main