//Arquivo Arvore binária
#include <stdio.h>
#include <stdlib.h>


typedef struct NO* ArvAVL;

ArvAVL* cria_ArvAVL();
void libera_ArvAVL( ArvAVL *raiz );
int estaVazia_ArvAVL( ArvAVL *raiz );
int altura_ArvAVL( ArvAVL *raiz );
int totalNO_ArvAVL( ArvAVL *raiz );
void preOrdem_ArvAVL( ArvAVL *raiz );
void emOrdem_ArvAVL( ArvAVL *raiz );
void posOrdem_ArvAVL( ArvAVL *raiz );
int insere_ArvAVL( ArvAVL *raiz, int valor );
int remove_ArvAVL( ArvAVL *raiz, int valor );
struct NO* remove_atual( struct NO* atual );
int consulta_ArvAVL( ArvAVL *raiz, int valor );
int altura_NO( struct NO* no );
int fatorBalanceamento_NO( struct NO* no );
int maior( int x, int y );
void RotacaoLL( ArvAVL *raiz );
void RotacaoRR( ArvAVL *raiz );
void RotacaoRL( ArvAVL *raiz );
void RotacaoLR( ArvAVL *raiz );
void RotacaoRL( ArvAVL *raiz );
