CC=gcc
CFLAGS=-I.
OUTPUT_PATH=../bin/

all: seq.exe

seq.exe: lista_sequencial.o
	$(CC) -o $(OUTPUT_PATH)seq.exe lista_sequencial.o

seq.o: lista_sequencial.c
	$(CC) -c lista_sequencial.c

clean:
	rm seq.o $(OUTPUT_PATH)seq.exe
