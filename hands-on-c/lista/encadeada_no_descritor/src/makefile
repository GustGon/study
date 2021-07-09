CC=gcc
CFLAGS=-I.
OUTPUT_PATH=../bin/

all: descr.exe

descr.exe: lista_din_enc_descr.o
	$(CC) -o $(OUTPUT_PATH)descr.exe lista_din_enc_descr.o

descr.o: lista_din_enc_descr.c
	$(CC) -c lista_din_enc_descr.c

clean:
	rm descr.o $(OUTPUT_PATH)descr.exe
