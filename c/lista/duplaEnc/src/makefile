CC=gcc
CFLAGS=-I.
OUTPUT_PATH=../bin/

all: duplaEnc.exe

duplaEnc.exe: lista_duplaEnc.o
	$(CC) -o $(OUTPUT_PATH)duplaEnc.exe lista_duplaEnc.o

duplaEnc.o: lista_duplaEnc.c
	$(CC) -c lista_duplaEnc.c

clean:
	rm duplaEnc.o $(OUTPUT_PATH)duplaEnc.exe
