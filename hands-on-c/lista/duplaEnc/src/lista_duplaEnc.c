#include "lista_duplaEnc.h"

struct elemento{
    struct elemento *ant;
    struct aluno dados; // Tipo do elemento a ser guardado
    struct elemento *prox;
};
typedef struct elemento Elem;   

/*
# Inicia a Lista
*/
Lista* cria_lista(){
    Lista* li;
    li = (Lista*) malloc(sizeof( Lista ));

    if( li != NULL )
        *li = NULL;
    
    return li;
}

/*
# Libera a memora alocada da lista
*/
void libera_lista(Lista* li){
    if( li != NULL ){
        Elem* no;
        while( (*li) != NULL ){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

/*
# Tamanho da lista que esta preechida
*/
int tamanho_lista(Lista* li){
    if( li == NULL )
        return -1;  //Lista nao existente
    int cont = 0;
    Elem* no = *li;
    while( no != NULL ){
        cont++;
        no = no->prox;
    }
    return cont;
}

/*
# Lista cheia ou nao
*/
int lista_cheia(Lista* li){
    return 0;  //Lista nao fica cheia
}

/*
# Lista vazia ou nao
*/
int lista_vazia(Lista* li){
    if( li == NULL )
        return -1;  //Lista nao existente
    if( *li == NULL )
        return 1;   // Lista esta vazia
    else
        return 0;   // Lista nao esta vazia
}

/*
# Inserção no final da lista
*/
int insere_lista_final(Lista* li, struct aluno al){
    if( li == NULL )
        return -1;  //Lista nao existente
    
    Elem* no = (Elem*) malloc(sizeof( Elem ));
    if( no == NULL )
        return 1;  // Sem espaço para alocação da memoria

    no->dados = al;
    no->prox = NULL;

    if( lista_vazia( li ) ){
        no->ant = NULL;
        *li = no;
    }else{
        Elem *aux = *li;
        while( aux->prox != NULL ){  // Percorrendo toda a lista
            aux = aux->prox;
        }
        aux->prox = no;
        no->ant = aux;
    }

    return 0;
}

/*
# Inserção no inicio da lista
*/
int insere_lista_inicio(Lista* li, struct aluno al){
    if( li == NULL )
        return -1;  //Lista nao existente
    
    Elem* no = (Elem*) malloc(sizeof( Elem ));
    
    if( no == NULL )
        return 1;  // Sem espaço para proximo elemento

    no->dados = al;
    no->prox = (*li);
    no->ant = NULL;

    if( *li != NULL )
        (*li)->ant = no;

    *li = no;
    return 0;
}

/*
# Inserção no meio da lista
*/
int insere_lista_ordenada(Lista* li, struct aluno al){
    if( li == NULL )
        return -1;  //Lista nao existente
    
    Elem *no = (Elem*) malloc(sizeof( Elem ));
    if( no == NULL )
        return 1;

    no->dados = al;
    if( lista_vazia(li) ){
        free(no);
        insere_lista_inicio( li, al);
    }else{
        Elem *ant, *atual = *li;
        while( atual != NULL && 
               atual->dados.matricula < al.matricula ){
            ant = atual;
            atual = atual->prox;
        }

        if( atual == *li ){
            free(no);
            insere_lista_inicio( li, al);
        }else{
            no->ant = ant;
            no->prox = ant->prox;
            ant->prox = no;
            if( autal != NULL )
                atual->ant = no;
        }
    }

    return 0;
}

/*
# Remoção no inicio da lista
*/
int remove_lista_inicio(Lista* li){
    if( li == NULL )
        return -1;  //Lista nao existente
    if( lista_vazia(li) )
        return 1; // Nao tem oq remover
    
    Elem *no = *li;
    *li = no->prox;
    if( no->prox != NULL )
        no->prox->ant = NULL;

    free(no);

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
    
    Elem *ant, *no = *li;
    while( no->prox != NULL )
        no = no->prox;

    if( no->ant == NULL )
        *li = no->prox;
    else
        no->ant->prox = NULL;
    
    free(no);

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
    
    Elem *no = *li;
    while( no != NULL &&
           no->dados.matricula != mat ){
        no = no->prox;
    }

    if( no == NULL )
        return 1;  // dado nao encontrado
    if( no->ant == NULL ){   // remove o primeiro?
        remove_lista_inicio(li);
        return 0;
    }else
        no->ant->prox = no->prox;

    if( no->prox != NULL )  // nao eh o ultimo elemento
        no->prox->ant = no->ant;

    free(no);

    return 0;
}

/*
# Consulta a lista por posição
*/
int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
    if( li == NULL || pos < 0 )
        return -1;
    
    Elem *no = *li;
    int i = 1;
    while( no != NULL && i < pos ){
        no = no->prox;
        i++;
    }
    if( no == NULL )
        return 1; // Lista esta vazia
    else
        *al = no->dados;

    return 0;
}

/*
# Consulta a lista por conteudo
*/
int consulta_lista_mat(Lista* li, int mat, struct aluno *al){
    if( li == NULL )
        return -1;
    
    Elem *no = *li;   
    while( no != NULL && no->dados.matricula != mat )
        no = no->prox;

    if( no == NULL )
        return 1;  //Nao existe essa matricula

    *al = no->dados;

    return 0;
}

/*
# MAIN
*/
int main(){

    Lista *li; // Ponteiro para ponteiro para struct elemento (inicio da lista

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
    ret = insere_lista_final(li, al2);
    printf("ret: %i\n", ret);
    
    printf("Inserindo aluno novo no final da lista...");
    ret = insere_lista_final(li, al3);
    printf("ret: %i\n", ret);
    
    printf("Inserindo aluno novo no meio da lista...");
    ret = insere_lista_ordenada(li, al1);
    printf("ret: %i\n", ret);
    
    printf("Inserindo aluno novo no inicio da lista...");
    ret = insere_lista_inicio(li, al2);
    printf("ret: %i\n", ret);
    
    int i;
    printf("Verificando a lista por posição...\n");
    for( i = 1; i < tamanho_lista(li); i++ ){
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
