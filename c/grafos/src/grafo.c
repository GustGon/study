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

// Funçao principal: faz a interface com o usuario
void buscaLargura_Grafo(Grafo *gr, int ini, int *visitado){
    int i, vert, NV, cont = 1, *fila, IF = 0, FF = 0;
    
    // Marca vertices como nao visitados
    for(i = 0; i < gr->nro_vertices; i++)
        visitado[i] = 0;

    // Cria fila. Visita e insere "ini" na fila
    NV = gr->nro_vertices;
    fila = (int*) malloc( NV * sizeof(int) );
    FF++;
    fila[FF] = ini;
    visitado[ini] = cont;

    while( IF != FF){
        
        // Pega o primeiro da fila
        IF = ( IF + 1 ) % NV;
        vert = fila[IF];
        cont++;
        
        // Visita os vizinhos ainda nao visitados
        // e coloca na fila
        for(i = 0; i < gr->grau[vert]; i++){
            if( !visitado[gr->arestas[vert][i]] ){
                FF = (FF + 1) % NV;
                fila[FF] = gr->arestas[vert][i];
                visitado[gr->arestas[vert][i]] = cont;
            }
        }
    }
    free(fila);
}

// Função auxiliar: realiza o calculo
int procuraMenorDistancia(float *dist, int *visitado, int NV){
    int i, menor = -1, primeiro = 1;
    for(i = 0; i < NV; i++){
        // Procura vertice com a menor distancia q nao tenha sido visitado
        if( dist[i] >= 0 && visitado[i] == 0 ){
            if( primeiro ){
                menor = i;
                primeiro = 0;
            }else{
                if( dist[menor] > dist[i] )
                    menor = i;
            }
        }
    }
    return menor;
}

// Funçao principal: faz a interface com o usuario
void menorCaminho_Grafo(Grafo *gr, int ini, int *ant, float *dist){
    int i, cont, NV, ind, *visitado, u;
    cont = NV = gr->nro_vertices;
    // Cria vetor auxiliar. Inicializa distâncias e anteriores
    visitado = (int*) malloc(NV * sizeof(int));
    for( i = 0; i < NV; i++ ){
        ant[i] = -1;
        dist[i] = -1;
        visitado[i] = 0;
    }
    dist[ini] = 0;
    while( cont > 0 ){
        // Procura o vertice com menor distancia e marca como visitado
        u = procuraMenorDistancia(dist, visitado, NV);
        if( u == -1 )
            break;

        visitado[u] = 1;
        cont--;
        for( i = 0; i < gr->grau[u]; i ++ ){ // Para cada vertice visinho
            ind = gr->arestas[u][i];
            // Atualiza distancia dos visinhos
            if( dist[ind] < 0 ){
                dist[ind] = dist[u] + 1;
                //ou  peso da aresta
                //dist[ind] = dist[u] + gr->pesos[u][i]
                ant[ind] = u;
            }else{
                if( dist[ind] > dist[u] + 1 ){
                //if(dist[ind] > dist[u]+1){ ou peso da arest;
                    dist[ind] = dist[u] + 1 ;
                    //ou peso da aresta
                    //dist[ind] = dist[u]+gr->pesos[u][i];
                    ant[ind] = u;
                }
            }
        }
    }
    free(visitado);
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

    buscaLargura_Grafo(gr, 0, vis);

    int ant[5];
    float dist[5];

    //menorCaminho_Grafo(gr, 0, ant, dist);

    libera_Grafo(gr);

}
