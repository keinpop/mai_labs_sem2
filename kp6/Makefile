CC = gcc
CFLAGS ?= -g -Wall -Wextra -std=c99 -w -lm

all:
	$(CC) $(CFLAGS) computer.c main.c -o main

main: main.o computer.o
	${CC} -o main main.o computer.o converted.o

main.o: main.c 
	${CC} ${CFLAGS} -c main.c

functions.o: computer.c computer.o converted.c converted.o
	${CC} ${CFLAGS} -c computer.c converted.c

converted:
	${CC} ${CFLAGS} computer.c converted.c -o conv

#Use this command, and run: ./a.out [number_of_students], then give filename wich will record
generate:
	${CC} ${CFLAGS} make_test.c

clean: 
	rm -rf *.bin *.txt *.o main