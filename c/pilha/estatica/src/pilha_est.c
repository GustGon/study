#include <pilha_est.h>

struct pilha{
    int qtd;
    struct aluno dados[MAX];
};

Pilha* cria_Pilha(){
    Pilha *pi;
    pi = (Pilha*)malloc(sizeof(struct pilha));
    if(pi != NULL)
        pi->qtd = 0;
    return pi;
}

void libera_Pilha(Pilha* pi){
    free(pi);
}

int tamanho_Pilha(Pilha* pi){
    if(pi == NULL)
        return -1;
    else
        return pi->qtd;
}

int Pilha_cheia(Pilha* pi){
    if(pi == NULL)
        return -1;
    return (pi->qtd == MAX);
}

int Pilha_vazia(Pilha* pi){
    if( pi == NULL )
        return -1;
    return (pi->qtd == 0);
}

int insere_Pilha(Pilha* pi, struct aluno al){
    if( pi == NULL ) return 1;
    if( Pilha_cheia(pi) ) return 2;
    pi->dados[pi->qtd] = al;
    pi->qtd++;

    return 0;
}

int remove_Pilha(Pilha* pi){
    if( pi == NULL ) return 1;
    if( Pilha_vazia(pi) ) return 2;
    pi->qtd++;

    return 0;
}

int consulta_Pilha(Pilha* pi, struct aluno *al){
    if( pi == NULL ) return 1;
    if( Pilha_vazia(pi) ) return 2;
    *al = pi->dados[pi->qtd -1];

    return 0;
}

int main(){
    Pilha *pi;

    pi = cria_Pilha();
}
