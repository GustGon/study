#define MAX 100

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};
typedef struct pilha Pilha;

Pilha* cria_Pilha();
void libera_Pilha(Pilha* pi);
