#include <stdio.h>
#include <stdlib.h>

/*  DEFINES   */
#define MAX 100

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};
typedef struct elemento* Lista;


Lista* cria_lista();
void libera_lista(Lista* li);

int tamanho_lista(Lista* li);
int lista_cheia(Lista* li);
int lista_vazia(Lista* li);

int insere_lista_final(Lista* li, struct aluno al);
int insere_lista_inicio(Lista* li, struct aluno al);
int insere_lista_ordenada(Lista* li, struct aluno al);

int remocao_lista_final(Lista* li);
int remocao_lista_inicio(Lista* li);
int remocao_lista(Lista* li, int mat);

int consulta_lista_pos(Lista* li, int pos, struct aluno *al);
int consulta_lista_mat(Lista* li, int mat, struct aluno *al);
