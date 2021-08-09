CC=gcc
CFLAGS=-I.
OUTPUT_PATH=../bin/

all: pilha.exe

pilha.exe: pilha_din.o
	$(CC) -o $(OUTPUT_PATH)pilha.exe pilha_din.o

pilha.o: pilha_din.c
	$(CC) -c pilha_din.c

clean:
	rm pilha.o $(OUTPUT_PATH)pilha.exe
