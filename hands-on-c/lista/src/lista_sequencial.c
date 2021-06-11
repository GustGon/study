#include "lista_sequencial.h"

struct lista{
    int qtd;
    struct aluno dados[MAX];
};


/*
# Inicia a Lista
*/
Lista* cria_lista(){
    Lista *li;
    li = (Lista*) malloc(sizeof( struct lista ));

    if( li != NULL )
        li->qtd = 0;
    
    return li;
}

/*
# Libera a memora alocada da lista
*/
void libera_lista(Lista* li){
    free(li);
}

/*
# Tamanho da lista que esta preechida
*/
int tamanho_lista(Lista* li){
    if( li == NULL )
        return -1;  //Lista nao existente
    else
        return li->qtd;
}

/*
# Lista cheia ou nao
*/
int lista_cheia(Lista* li){
    if( li == NULL )
        return -1;  //Lista nao existente
    else
        return (li->qtd == MAX);
}

/*
# Lista vazia ou nao
*/
int lista_cheia(Lista* li){
    if( li == NULL )
        return -1;  //Lista nao existente
    else
        return (li->qtd == 0);
}

/*
# MAIN
*/
int main(){

    Lista *li;

    printf("Criando a lista...\n");
    li = cria_lista();

    int ret = 0;

    ret = tamanho_lista(li);
    printf("Tamanho da lista: %i\n", ret);
    printf("A lista está cheia?? ret: %i\n", lista_cheia(li));
    printf("A lista está vazia?? ret: %i\n", lista_vazia(li));
    

    libera_lista(li);

    return 0;
}
