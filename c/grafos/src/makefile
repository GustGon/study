CC=gcc
CFLAGS=-I.
OUTPUT_PATH=../bin/

all: grafo.exe

grafo.exe: grafo.o
	$(CC) -o $(OUTPUT_PATH)grafo.exe grafo.o

grafo.o: grafo.c
	$(CC) -c grafo.c

clean:
	rm grafo.o $(OUTPUT_PATH)grafo.exe
