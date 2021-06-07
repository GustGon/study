#include "arvoreBinaria.h"

/*
Estrutura da Arvore
*/
struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};


/*
Inicializando a arvore
*/
ArvBin* cria_ArvBin(){
    
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if( raiz != NULL )
        *raiz = NULL;

    return raiz;
}


/*
Matando o Nó
*/
void libera_NO( struct NO* no){
    
    if( no == NULL )
        return;

    libera_NO(no->esq);
    libera_NO(no->dir);

    free(no);
    no = NULL;
}


/*
Matando a arvore
*/
void libera_ArvBin(ArvBin* raiz){
    
    if(raiz == NULL)
        return;
    
    libera_NO(*raiz);   //libera cada no
    free(raiz);         // libera a raiz
}


/*
Verificação se a arvore esta vazia
*/
int estaVazia( ArvBin* raiz ){

    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;

    return 1;
}

/*
Identificando a altura da arvore
*/
int altura_ArvBin( ArvBin *raiz ){

    if( !estaVazia( raiz ) )
        return 0;
   
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));

    if(alt_esq > alt_dir)
        return (alt_esq + 1);
    
    return(alt_dir + 1);
}


/*
Numero total de nos da arvore
*/
int totalNO_ArvBin( ArvBin *raiz ){
    
    if( !estaVazia( raiz ) )
        return 0;

    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));

    return(alt_esq + alt_dir + 1);
}

/*
Percorrendo arvore binaria em preordem
*/
void preOrdem_ArvBin( ArvBin *raiz ){
    
    if( raiz == NULL )
        return;
    if( *raiz != NULL ){
        printf("%d\n", (*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

/*
Percorrendo arvore binaria em ordem
*/
void emOrdem_ArvBin( ArvBin *raiz ){
    
    if( raiz == NULL )
        return;
    if( *raiz != NULL ){
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%d\n", (*raiz)->info);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}

/*
Percorrendo arvore binaria em posordem
*/
void posOrdem_ArvBin( ArvBin *raiz ){
    
    if( raiz == NULL )  //Arvore valida??
        return;
    if( *raiz != NULL ){ //Arvore vazia??
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        printf("%d\n", (*raiz)->info);
    }
}

/*
Inserir valores na arvore binaria
*/
int insere_ArvBin( ArvBin *raiz, int valor ){
    
    if( raiz == NULL )  //Arvore valida??
        return 1;

    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    
    if( novo == NULL )
        return 1;
    
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if( *raiz == NULL ) //Arvore vazia??
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        
        while(atual != NULL){
            ant = atual;

            if( valor == atual->info ){
                free(novo);
                return 1;   //Elemento ja existe
            }
            if( valor > atual->info )
                atual = atual->dir;
            else
                atual = atual->esq;
        }

        if( valor > ant->info )
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 0;
}

/*
Removendo valores na arvore binaria
*/
int remove_ArvBin( ArvBin *raiz, int valor ){
    
    if( raiz == NULL )  //Arvore valida??
        return 1;

     struct NO* atual = *raiz;
     struct NO* ant = NULL;
        
     while(atual != NULL){

        if( valor == atual->info ){
            if( atual == *raiz )
                *raiz = remove_atual(atual);
            else{
                if( ant->dir == atual )
                    ant->dir = remove_atual(atual); //Novo nó a ser apontado
                else
                    ant->esq = remove_atual(atual); //Novo nó a ser apontado
            }
            return 0;   //Elemento removido
        }
        
        ant = atual;
        if( valor > atual->info )
            atual = atual->dir;
        else
            atual = atual->esq;

     }
    return 1; //Não encontrou o valor a ser removido;
}

/*
Remove o nó atual
*/
struct NO* remove_atual( struct NO* atual ){

    struct NO *no1, *no2;
    if( atual->esq == NULL ){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    
    no1 = atual;
    no2 = atual->esq;
    
    while( no2->dir != NULL ){
        no1 = no2;
        no2 = no2 -> dir;
    }

    if( no1 != atual ){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }

    no2->dir = atual->dir;
    free(atual);

    return no2;
}

/*
Busca um valor na arvore binaria
*/
int consulta_ArvBin( ArvBin *raiz, int valor ){
    
    if( raiz == NULL )  //Arvore valida??
        return 1;

    struct NO* atual = *raiz;
        
    while(atual != NULL){
        if( valor == atual->info ){
            return 0;   //Elemento existe
        }
        if( valor > atual->info )
            atual = atual->dir;
        else
            atual = atual->esq;
    }

    return 1;   //Elemento não existe
}

/*
MAIN
*/
int main(){
    
    int ret;

    ArvBin* raiz = cria_ArvBin();
    
    if( !estaVazia( raiz ) )
        printf("A arvore esta vazia!\n");
    else
        printf("A arvore NAO esta vazia!\n");
    
    int altura = altura_ArvBin( raiz );

    printf("Altura da arvore é: %i\n",altura);

    int total_no = totalNO_ArvBin( raiz );
    printf("Numero de Nos total é: %i\n",total_no);

    int valor = 50;
    /* 
    Inserindo valor na arvore.
    */
    ret = insere_ArvBin(raiz, valor);
    if( !ret )
        printf("Inserção feita com sucesso!!\n");
    else
        printf("Erro na inserção. \nRET=%i\n",ret);
    ret = insere_ArvBin(raiz, 20);
    if( !ret )
        printf("Inserção feita com sucesso!!\n");
    else
        printf("Erro na inserção. \nRET=%i\n",ret);
    ret = insere_ArvBin(raiz, 70);
    if( !ret )
        printf("Inserção feita com sucesso!!\n");
    else
        printf("Erro na inserção. \nRET=%i\n",ret);



    /* 
    Verificação do  valor inserido na arvore.
    */
    ret = insere_ArvBin(raiz, valor);
    if( !estaVazia( raiz ) )
        printf("A arvore esta vazia!\n");
    else
        printf("A arvore NAO esta vazia!\n");
    
    altura = altura_ArvBin( raiz );
    printf("Altura da arvore é: %i\n",altura);

    total_no = totalNO_ArvBin( raiz );
    printf("Numero de Nos total é: %i\n",altura);

    /*
    Algoritimos para percorrer a arvore
    */
    printf("Percorrendo a arvore...\n");
    printf("Pre Ordem...\n");
    preOrdem_ArvBin(raiz);
    printf("Em Ordem...\n");
    emOrdem_ArvBin(raiz);
    printf("Pos Ordem...\n");
    posOrdem_ArvBin(raiz);

    /*
    Verifica se o valor existe na arvore.
    */
    ret = consulta_ArvBin( raiz, valor );
    if( !ret )
        printf("O valor %i existe na arvore!!\n",valor);
    else
        printf("Erro na consulta. \nRET=%i\n",ret);

    /*
    Removendo No.
    */
    printf("Removendo No...\n");
    ret = remove_ArvBin(raiz, valor);   

    printf("Liberando Arvore...\n");
    libera_ArvBin(raiz);

    //system("pause");
    return 0;
}
