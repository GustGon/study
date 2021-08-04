struct pilha{
    int qtd;
    struct aluno dados[MAX];
};

Pilha* cria_Pilha(){
    Pilha *pi;
    pi = (Pilha*) malloc(sizeof(struct pilha));
    if(pi != NULL)
        pi->qtd = 0;
    return;
}

void libera_Pilha(Pilha* pi){
    free(pi);
}

int main(){
    Pilha *pi;

    pi = cria_Pilha();
}
