#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};
typedef struct pilha Pilha;

Pilha* cria_Pilha();
void libera_Pilha(Pilha* pi);
int tamanho_Pilha(Pilha* pi);
int Pilha_cheia(Pilha* pi);
int Pilha_vazia(Pilha* pi);
int insere_Pilha(Pilha* pi, struct aluno al);
int remove_Pilha(Pilha* pi);
int consulta_Pilha(Pilha* pi, struct aluno *al);
