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
int lista_vazia(Lista* li){
    if( li == NULL )
        return -1;  //Lista nao existente
    else
        return (li->qtd == 0);
}

/*
# Inserção no final da lista
*/
int insere_lista_final(Lista* li, struct aluno al){
    if( li == NULL )
        return -1;  //Lista nao existente
    if( lista_cheia(li) )
        return 1;
    li->dados[li->qtd] = al;
    li->qtd++;

    return 0;
}

/*
# Inserção no inicio da lista
*/
int insere_lista_inicio(Lista* li, struct aluno al){
    if( li == NULL )
        return -1;  //Lista nao existente
    if( lista_cheia(li) )
        return 1;
    
    int i;
    for( i = li->qtd-1; i >= 0; i-- )
        li->dados[i + 1] = li->dados[i];
    li->dados[0] = al;
    li->qtd++;

    return 0;
}

/*
# Inserção no meio da lista
*/
int insere_lista_ordenada(Lista* li, struct aluno al){
    if( li == NULL )
        return -1;  //Lista nao existente
    if( lista_cheia(li) )
        return 1;
    
    int k, i = 0;
    while( i < li->qtd && li->dados[i].matricula < al.matricula )
        i++;

    for( k = li->qtd-1; k >= i; k-- )
        li->dados[k + 1] = li->dados[k];
    li->dados[0] = al;
    li->qtd++;

    return 0;
}

/*
# Remoção no inicio da lista
*/
int remove_lista_inicio(Lista* li){
    if( li == NULL )
        return -1;  //Lista nao existente
    if( lista_vazia(li) )
        return 1;
    
    int k;

    for( k = 0; k < li->qtd; k++ )
        li->dados[k] = li->dados[k + 1];
    li->qtd--;

    return 0;
}

/*
# Remoção no final da lista
*/
int remove_lista_final(Lista* li){
    if( li == NULL )
        return -1;  //Lista nao existente
    if( lista_vazia(li) ) 
        return 1;
    
    li->qtd--;

    return 0;
}

/*
# Remoção no meio da lista
*/
int remove_lista(Lista* li, int mat){
    if( li == NULL )
        return -1;  //Lista nao existente
    if( lista_vazia(li) )
        return 1;
    
    int k, i = 0;
    while( i < li->qtd && li->dados[i].matricula != mat )
        i++;

    if( i == li->qtd )
        return 1;  //Nao existe essa matricula

    for( k = i; k > li->qtd - 1; k++ )
        li->dados[k] = li->dados[k+1];
    
    li->qtd--;

    return 0;
}

/*
# Consulta a lista por posição
*/
int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
    if( li == NULL || pos < 0 || pos > li->qtd )
        return -1;
    
    *al = li->dados[pos-1];

    return 0;
}

/*
# Consulta a lista por conteudo
*/
int consulta_lista_mat(Lista* li, int mat, struct aluno *al){
    if( li == NULL )
        return -1;
   
   int k, i = 0;
    while( i < li->qtd && li->dados[i].matricula != mat )
        i++;

    if( i == li->qtd )
        return 1;  //Nao existe essa matricula

    *al = li->dados[i];

    return 0;
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
    
    struct aluno al1, al2, al3, al;
    al1.matricula = 1;
    al2.matricula = 3;
    al3.matricula = 2;

    
    printf("Inserindo aluno novo no inicio da lista...");
    ret = insere_lista_inicio(li, al1);
    printf("ret: %i\n", ret);
    
    printf("Inserindo aluno novo no final da lista...");
    ret = insere_lista_final(li, al1);
    printf("ret: %i\n", ret);
    
    printf("Inserindo aluno novo no final da lista...");
    ret = insere_lista_final(li, al1);
    printf("ret: %i\n", ret);
    
    printf("Inserindo aluno novo no meio da lista...");
    ret = insere_lista_ordenada(li, al1);
    printf("ret: %i\n", ret);
    
    printf("Inserindo aluno novo no inicio da lista...");
    ret = insere_lista_inicio(li, al1);
    printf("ret: %i\n", ret);
    
    int i;
    printf("Verificando a lista por posição...\n");
    for( i = 1; i < li->qtd; i++ ){
        consulta_lista_pos(li, i, &al);
        printf("%i",al.matricula);
    }

    printf("\nVerificando a lista por matricula...\n");
    printf("Matricula 1...");
    ret = consulta_lista_mat(li, al1.matricula, &al);
    printf("ret: %i\n", ret);
    
    printf("Matricula inexistente...");
    ret = consulta_lista_mat(li, 4, &al);
    printf("ret: %i\n", ret);

    printf("Removendo aluno no final da lista...");
    ret = remove_lista_final(li);
    printf("ret: %i\n", ret);
    
    printf("Removendo aluno no inicio da lista...");
    ret = remove_lista_inicio(li);
    printf("ret: %i\n", ret);
    
    printf("Removendo aluno no meio da lista...");
    ret = remove_lista(li, al1.matricula);
    printf("ret: %i\n", ret);
    
    printf("Removendo aluno no final da lista...");
    ret = remove_lista_final(li);
    printf("ret: %i\n", ret);


    printf("Liberando lista...\n");
    libera_lista(li);

    return 0;
}
