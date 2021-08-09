#include <pilha_din.h>

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

Pilha* cria_Pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}

void libera_Pilha(Pilha* pi){
    if( pi != NULL ){
        Elem* no;
        while( (*pi) != NULL ){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}

int tamanho_Pilha(Pilha* pi){
    if(pi == NULL)  return -1;
    int cont = 0;
    Elem* no = *pi;
    while( no != NULL ){
        cont++;
        no = no->prox;
    }
    return cont;
}

int Pilha_cheia(Pilha* pi){
    return 0;
}

int Pilha_vazia(Pilha* pi){
    if( pi == NULL ) return -1;
    if( *pi == NULL ) return 1;
    return 0;
}

int insere_Pilha(Pilha* pi, struct aluno al){
    if( pi == NULL ) return 1;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if( no == NULL ) return 2;
    no->dados = al;
    no->prox = (*pi);
    *pi = no;

    return 0;
}

int remove_Pilha(Pilha* pi){
    if( pi == NULL ) return 1;
    if( Pilha_vazia(pi) ) return 2;
    Elem *no = *pi;
    *pi = no->prox;
    free(no);

    return 0;
}

int consulta_Pilha(Pilha* pi, struct aluno *al){
    if( pi == NULL ) return 1;
    if( Pilha_vazia(pi) ) return 2;
    *al = (*pi)->dados;

    return 0;
}

int main(){
    Pilha *pi;

    pi = cria_Pilha();
}
