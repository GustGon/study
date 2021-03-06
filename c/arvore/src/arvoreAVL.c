#include "arvoreAVL.h"

/*
Estrutura da Arvore
*/
struct NO{
    int info;
    int altura;    // Altura da sub-arvore
    struct NO *esq;
    struct NO *dir;
};


/*
Inicializando a arvore
*/
ArvAVL* cria_ArvAVL(){
    
    ArvAVL* raiz = (ArvAVL*) malloc(sizeof(ArvAVL));
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
void libera_ArvAVL(ArvAVL* raiz){
    
    if(raiz == NULL)
        return;
    
    libera_NO(*raiz);   //libera cada no
    free(raiz);         // libera a raiz
}


/*
Verificação se a arvore esta vazia
*/
int estaVazia( ArvAVL* raiz ){

    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;

    return 1;
}

/*
Identificando a altura da arvore
*/
int altura_ArvAVL( ArvAVL *raiz ){

    if( !estaVazia( raiz ) )
        return 0;
   
    int alt_esq = altura_ArvAVL(&((*raiz)->esq));
    int alt_dir = altura_ArvAVL(&((*raiz)->dir));

    if(alt_esq > alt_dir)
        return (alt_esq + 1);
    
    return(alt_dir + 1);
}


/*
Numero total de nos da arvore
*/
int totalNO_ArvAVL( ArvAVL *raiz ){
    
    if( !estaVazia( raiz ) )
        return 0;

    int alt_esq = totalNO_ArvAVL(&((*raiz)->esq));
    int alt_dir = totalNO_ArvAVL(&((*raiz)->dir));

    return(alt_esq + alt_dir + 1);
}

/*
Percorrendo arvore binaria em preordem
*/
void preOrdem_ArvAVL( ArvAVL *raiz ){
    
    if( raiz == NULL )
        return;
    if( *raiz != NULL ){
        printf("%d\n", (*raiz)->info);
        preOrdem_ArvAVL(&((*raiz)->esq));
        preOrdem_ArvAVL(&((*raiz)->dir));
    }
}

/*
Percorrendo arvore binaria em ordem
*/
void emOrdem_ArvAVL( ArvAVL *raiz ){
    
    if( raiz == NULL )
        return;
    if( *raiz != NULL ){
        emOrdem_ArvAVL(&((*raiz)->esq));
        printf("%d\n", (*raiz)->info);
        emOrdem_ArvAVL(&((*raiz)->dir));
    }
}

/*
Percorrendo arvore binaria em posordem
*/
void posOrdem_ArvAVL( ArvAVL *raiz ){
    
    if( raiz == NULL )  //Arvore valida??
        return;
    if( *raiz != NULL ){ //Arvore vazia??
        posOrdem_ArvAVL(&((*raiz)->esq));
        posOrdem_ArvAVL(&((*raiz)->dir));
        printf("%d\n", (*raiz)->info);
    }
}

/*
Inserir valores na arvore binaria
*/
int insere_ArvAVL( ArvAVL *raiz, int valor ){
    
    int res;
    if( raiz == NULL )  //Arvore valida??
        return 1;

    if( *raiz == NULL ){ //Arvore vazia??
        struct NO* novo;
        novo = (struct NO*) malloc(sizeof(struct NO));
    
        if( novo == NULL )
            return 1;
    
        novo->info = valor;
        novo->altura = 0;
        novo->dir = NULL;
        novo->esq = NULL;

        *raiz = novo;

        return 0;
    }
    
    struct NO* atual = *raiz;
    
    if( valor < atual->info ){
        if( (res=insere_ArvAVL(&(atual->esq), valor)) == 1) {
            if( fatorBalanceamento_NO( atual ) >= 2 ) {
                if( valor < (*raiz)->esq->info ) {
                    RotacaoLL(raiz);
                }else{
                    RotacaoLR(raiz);
                }
            }
        }
    }else{
        if( valor > atual->info ){
            if( (res=insere_ArvAVL(&(atual->dir), valor)) == 1) {
                if( fatorBalanceamento_NO( atual ) >= 2 ) {
                    if( (*raiz)->dir->info < valor ) {
                        RotacaoRR(raiz);
                    }else{
                        RotacaoRL(raiz);
                    }
                }
            }
        }else{
            printf("Valor duplicado!!\n");
            return 1;
        }
    }
    atual->altura = maior(altura_NO(atual->esq),
                          altura_NO(atual->dir)) + 1;
    return res;
}

/*
Removendo valores na arvore binaria
*/
int remove_ArvAVL( ArvAVL *raiz, int valor ){
    
    if( raiz == NULL )  //Arvore valida??
        return 1;
    if( *raiz == NULL ) // Valor nao existe
        return 1;
    
    int res;
    if( valor < (*raiz)->info ){
        if( (res=remove_ArvAVL(&((*raiz)->esq), valor)) == 1) {
            if( fatorBalanceamento_NO( *raiz ) >= 2 ) {
                if( altura_NO((*raiz)->dir->esq) <= 
                    altura_NO((*raiz)->dir->dir) ) 
                    RotacaoRR(raiz);
                else
                    RotacaoRL(raiz);
            }
        }
    }if( valor > (*raiz)->info ){
        if( (res=remove_ArvAVL(&((*raiz)->dir), valor)) == 1) {
            if( fatorBalanceamento_NO( (*raiz) ) >= 2 ) {
                if( altura_NO((*raiz)->esq->dir) <= 
                    altura_NO((*raiz)->esq->esq) )
                    RotacaoLL(raiz);
                else
                    RotacaoLR(raiz);
            }
        }
    }if( valor == (*raiz)->info ){
        if(( (*raiz)->esq == NULL || (*raiz)->dir == NULL )){
            struct NO *oldNode = (*raiz);
            if( (*raiz)->esq != NULL )
                *raiz = (*raiz)->esq;
            else
                *raiz = (*raiz)->dir;
            free(oldNode);
        }else{
            struct NO* temp = procuraMenor((*raiz)->dir);
            (*raiz)->info = temp->info;
            remove_ArvAVL(&(*raiz)->dir, (*raiz)->info);
            if( fatorBalanceamento_NO(*raiz) >= 2 ){
                if( altura_NO((*raiz)->esq->dir) <=
                    altura_NO((*raiz)->esq->esq) )
                    RotacaoLL(raiz);
                else
                    RotacaoLR(raiz);
            }
        }
        return 0;
    }
    return res;
}

/*
#Procura pelo menor no
*/
struct NO* procuraMenor( struct NO* atual ){
    struct NO *no1 = atual;
    struct NO *no2 = atual->esq;
    while( no2 != NULL ){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

/*
#Remove o nó atual
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
int consulta_ArvAVL( ArvAVL *raiz, int valor ){
    
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
Funçoes auxialiares para arvore AVL
*/
int altura_NO( struct NO* no ){
    
    if( no == NULL )
        return -1;
    else
        return no->altura;
}

int fatorBalanceamento_NO( struct NO* no ){
    return labs(altura_NO(no->esq) - altura_NO(no->dir));
}

int maior ( int x, int y ){
    
    if( x > y )
        return x;
    else
        return y;
}

/*
# Rotações de nós
*/
void RotacaoLL( ArvAVL *raiz ){

    struct NO* no;
    no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir = *raiz;
    (*raiz)->altura = maior( altura_NO( (*raiz)->esq),
                             altura_NO( (*raiz)->dir))
                             + 1;
    no->altura = maior(altura_NO(no->esq),
                        (*raiz)->altura) + 1;
    
    *raiz = no;
}

void RotacaoRR( ArvAVL *raiz ){

    struct NO* no;
    no = (*raiz)->dir;
    (*raiz)->dir = no->esq;
    no->esq = *raiz;
    (*raiz)->altura = maior( altura_NO( (*raiz)->esq),
                             altura_NO( (*raiz)->dir))
                             + 1;
    no->altura = maior(altura_NO(no->dir),
                        (*raiz)->altura) + 1;
    
    *raiz = no;
}

void RotacaoLR( ArvAVL *raiz ){
    RotacaoRR(&(*raiz)->esq);
    RotacaoLL(raiz);
}

void RotacaoRL( ArvAVL *raiz ){
    RotacaoLL(&(*raiz)->dir);
    RotacaoRR(raiz);
}

/*
MAIN
*/
int main(){
    
    int ret;

    ArvAVL* raiz = cria_ArvAVL();
    
    if( !estaVazia( raiz ) )
        printf("A arvore esta vazia!\n");
    else
        printf("A arvore NAO esta vazia!\n");
    
    int altura = altura_ArvAVL( raiz );

    printf("Altura da arvore é: %i\n",altura);

    int total_no = totalNO_ArvAVL( raiz );
    printf("Numero de Nos total é: %i\n",total_no);

    int valor = 50;
    /* 
    Inserindo valor na arvore.
    */
    ret = insere_ArvAVL(raiz, valor);
    if( !ret )
        printf("Inserção feita com sucesso!!\n");
    else
        printf("Erro na inserção. \nRET=%i\n",ret);
    ret = insere_ArvAVL(raiz, 20);
    if( !ret )
        printf("Inserção feita com sucesso!!\n");
    else
        printf("Erro na inserção. \nRET=%i\n",ret);
    ret = insere_ArvAVL(raiz, 70);
    if( !ret )
        printf("Inserção feita com sucesso!!\n");
    else
        printf("Erro na inserção. \nRET=%i\n",ret);



    /* 
    Verificação do  valor inserido na arvore.
    */
    ret = insere_ArvAVL(raiz, valor);
    if( !estaVazia( raiz ) )
        printf("A arvore esta vazia!\n");
    else
        printf("A arvore NAO esta vazia!\n");
    
    altura = altura_ArvAVL( raiz );
    printf("Altura da arvore é: %i\n",altura);

    total_no = totalNO_ArvAVL( raiz );
    printf("Numero de Nos total é: %i\n",altura);

    /*
    Algoritimos para percorrer a arvore
    */
    printf("Percorrendo a arvore...\n");
    printf("Pre Ordem...\n");
    preOrdem_ArvAVL(raiz);
    printf("Em Ordem...\n");
    emOrdem_ArvAVL(raiz);
    printf("Pos Ordem...\n");
    posOrdem_ArvAVL(raiz);

    /*
    Verifica se o valor existe na arvore.
    */
    ret = consulta_ArvAVL( raiz, valor );
    if( !ret )
        printf("O valor %i existe na arvore!!\n",valor);
    else
        printf("Erro na consulta. \nRET=%i\n",ret);

    /*
    Removendo No.
    */
    printf("Removendo No...\n");
    ret = remove_ArvAVL(raiz, valor);   

    printf("Liberando Arvore...\n");
    libera_ArvAVL(raiz);

    //system("pause");
    return 0;
}
