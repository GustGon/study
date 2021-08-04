CC=gcc
CFLAGS=-I.
OUTPUT_PATH=../bin/

all: pilha.exe

pilha.exe: pilha_est.o
	$(CC) -o $(OUTPUT_PATH)pilha.exe pilha_est.o

pilha.o: pilha_est.c
	$(CC) -c pilha_est.c

clean:
	rm pilha.o $(OUTPUT_PATH)pilha.exe
