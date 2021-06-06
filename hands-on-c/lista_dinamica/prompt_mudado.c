/*
 ============================================================================
 Name        : Prompt.c
 Author      : 
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_entry(char *entry) {
	printf("You entered: %s\n", entry);
}

int put(Lista *din_list, char value) {
	printf("%s\n", ptr.val);
}

char get(Lista *din_list, int pos) {
	return din_list.val;
	printf("You entered: %s\n", entry);
}

int list(Lista *din_list) {
	printf("You entered: %s\n", entry);
	return 0
}

int remove(Lista *din_list, int pos) {
	printf("You entered: %s\n", entry);
	return 0
}

int clear(Lista *din_list) {
	printf("You entered: %s\n", entry);
	return 0
}

int first(Lista *din_list) {
	printf("You entered: %s\n", entry);
	return 0
}

int last(Lista *din_list) {
	printf("%s\n", din_list.val);
	return 0
}

int sort(Lista *din_list){
}

int main(int argc, char *argv[]) {
	char input[201];
	char *list;
	Lista *L
	
	L = malloc(sizeof(Lista))
	L.val = 0
	L.prox = NULL;

	while(1) {
		printf("prompt> ");
		if (fgets(input, 200, stdin) == NULL) {
			printf("An error ocurred.\n");
			break;
		}

		if (strncmp(input, "exit\n", 5) == 0) {
			printf("Leaving. Good bye.\n");
			break;
		}else if (strncmp(input, "put\n", 4) == 0) {
			put(L, char value)
			break;
		}else if (strncmp(input, "get\n", 4) == 0) {
			get(L, int pos)
			break;
		}else if (strncmp(input, "list\n", 5) == 0) {
			list(L)
			break;
		}else if (strncmp(input, "remove\n", 7) == 0) {
			remove(L, int pos)
			break;
		}else if (strncmp(input, "clear\n", 6) == 0) {
			clear(L)
			break;
		}else if (strncmp(input, "first\n", 6) == 0) {
			first(L)
			break;
		}else if (strncmp(input, "last\n", 5) == 0) {
			last(L)
			break;
		}

		print_entry(input);
	}

	return EXIT_SUCCESS;
}
