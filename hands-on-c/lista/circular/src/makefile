CC=gcc
CFLAGS=-I.
OUTPUT_PATH=../bin/

all: cir.exe

cir.exe: lista_circular.o
	$(CC) -o $(OUTPUT_PATH)cir.exe lista_circular.o

cir.o: lista_circular.c
	$(CC) -c lista_circular.c

clean:
	rm cir.o $(OUTPUT_PATH)cir.exe
