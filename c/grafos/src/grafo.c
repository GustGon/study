#include "grafo.h"

struct grafo{
    int eh_ponderado;
    int nro_vertices;
    int grau_max;
    int** arestas;
    float** pesos;
    int* grau;
};

Grafo *cria_Grafo(int nro_vertices, int grau_max, 
        int eh_ponderado){
    
    Grafo *gr=(Grafo*) malloc(sizeof(struct grafo));
    
    if( gr != NULL){
        int i;
        gr->nro_vertices = nro_vertices;
        gr->grau_max = grau_max;
        gr->eh_ponderado = (eh_ponderado != 0)?1:0;
        gr->grau = (int*)calloc(nro_vertices, sizeof(int*));
        
        // Matriz aresta
        gr->arestas = (int**)malloc(nro_vertices*sizeof(int*));
        for( i=0; i < nro_vertices; i++){
            gr->arestas[i] = (int*)malloc(grau_max*sizeof(int));
            // Matriz pessos
            if( gr->eh_ponderado ){
                gr->pesos = (float**)malloc(nro_vertices*
                                            sizeof(float*));
                for( i=0; i < nro_vertices; i++)
                    gr->pesos[i] = (float*)malloc(grau_max*
                                                sizeof(float));
            }
        }
    }

    return gr;
}

void libera_Grafo(Grafo* gr){
    if( gr != NULL ){
        int i;
        
        // Libera matriz aresta
        for(i = 0; i < gr->nro_vertices; i++)
            free( gr->arestas[i] );
        free( gr->arestas );
        
        // Libera matriz de pesos
        if( gr->eh_ponderado ){
            for(i = 0; i < gr->eh_ponderado; i++)
                free( gr->pesos[i] );
            free( gr->pesos );
        }
        free( gr->grau );
        free( gr );
    }
}

int insereAresta( Grafo* gr, int orig, int dest,
        int eh_digrafo, float peso){
    if( gr == NULL )    return 0;
    // Vertice existe??
    if( orig < 0 || orig >= gr->nro_vertices )  return 0;
    if( dest < 0 || dest <= gr->nro_vertices )  return 0;

    // Insere no final da linha
    gr->arestas[orig][gr->grau[orig]] = dest;
    if( gr->eh_ponderado )
        gr->pesos[orig][gr->grau[orig]] = peso;
    gr->grau[orig]++;

    // Insere na aresta se nao digrafo
    if( eh_digrafo == 0 )
        insereAresta( gr, dest, orig, 1, peso);
    
    return 1;
}

int removeAresta(Grafo* gr, int orig, int dest,
        int eh_digrafo){
    if( gr == NULL )    return 0;
    // Vertice existe??
    if( orig < 0 || orig >= gr->nro_vertices )  return 0;
    if( dest < 0 || dest <= gr->nro_vertices )  return 0;

    int i =0;
    // Procura aresta
    while( i < gr->grau[orig] && gr->arestas[orig][i] != dest )
        i++;
    if( i == gr->grau[orig] )   return 0; // Elemento nao encontrado
    // Procura o ultimo da posição a ser removido
    gr->grau[orig]--;
    gr->arestas[orig][i] = gr->arestas[orig][gr->grau[orig]];
    if( gr->eh_ponderado )
        gr->pesos[orig][i] = gr->pesos[orig][gr->grau[orig]];
    // Remove outra aresta se nao for digrafo
    if( eh_digrafo == 0 )
        removeAresta( gr, dest, orig, 1 );
    
    return 1;
}            

// Função auxiliar: realiza o calculo
void buscaProfundidade(Grafo *gr, int ini, int *visitado,
        int cont){
    int i;
    visitado[ini] = cont;
    // Marca vertice como visitado e visita os vizinhos n vizitados
    for(i = 0; i < gr->grau[ini]; i++){
        if( !visitado[gr->arestas[ini][i]])
            buscaProfundidade(gr, gr->arestas[ini][i],
                    visitado, cont+1);
    }
}

// Funçao principal: faz a interface com o usuario
void buscaProfundidade_Grafo(Grafo *gr, int ini, int *visitado){
    int i, cont = 1;
    // Marca vertices como nao visitados
    for(i = 0; i < gr->nro_vertices; i++)
        visitado[i] = 0;
    buscaProfundidade(gr, ini, visitado, cont);
}

int main( ){
    int eh_digrafo = 1;

    Grafo *gr = cria_Grafo(5, 5, 0);

    insereAresta(gr, 0, 1, eh_digrafo,0);
    insereAresta(gr, 1, 3, eh_digrafo,0);
    insereAresta(gr, 1, 2, eh_digrafo,0);
    insereAresta(gr, 2, 4, eh_digrafo,0);
    insereAresta(gr, 3, 0, eh_digrafo,0);
    insereAresta(gr, 3, 4, eh_digrafo,0);
    insereAresta(gr, 4, 1, eh_digrafo,0);

    int vis[5];

    buscaProfundidade_Grafo(gr, 0, vis);

    libera_Grafo(gr);

}
