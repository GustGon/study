CC=gcc
CFLAGS=-I.
OUTPUT_PATH=../bin/

all: din.exe

din.exe: lista_dinamica.o
	$(CC) -o $(OUTPUT_PATH)din.exe lista_dinamica.o

din.o: lista_dinamica.c
	$(CC) -c lista_dinamica.c

clean:
	rm din.o $(OUTPUT_PATH)din.exe
