#include<stdio.h>
#include<stdlib.h>

#define V 5

#define TRUE  1
#define FALSE 0

typedef int boolean;

typedef struct s{
    s* prox;
    int v;
} NO;

typedef struct VERTICE {
    NO* inicio;
} VERTICEPOINTER;

void inicializar(int g[V][V]) {
    int i,j;

    for (i=0; i<V; i++)
        for (j=0;j<V; j++)
            g[i][j] = 0;

    printf("Grafo matricial inicializado");
}

void imprimirGrafo(int g[V][V]) {
	printf("Imprimindo grafo... \n");
	int i, j;
	for (i = 0; i < V; i++) {
		printf("|");
		for (j = 0; j< V; j++)
			printf("%d|", g[i][j]);
		printf("\n");
	}		
}

boolean existeArestaMatriz(int i, int j, int g[V][V]) {
	if (g[i][j] == 1) return TRUE;
	return FALSE;
}

boolean adicionarArestaMatriz(int i, int j, int g[V][V]) {
	if (existeArestaMatriz(i,j,g))
		return FALSE;

	g[i][j] = 1;
	return TRUE;
}

void transformaTransposto(int g[V][V]) {
	int i,j;
	
	int newg[V][V];
	inicializar(newg);
	
	// ALTER
	for (i=0;i<V;i++)
		for(j=0;j<V;j++) {
			newg[j][i] = g[i][j];	
		}
	
	// COPY
	for (i=0;i<V;i++)
		for(j=0;j<V;j++) {
			g[i][j] = newg[i][j];	
		}
}

int main() {
    int g[V][V];

    inicializar(g);

    adicionarArestaMatriz(0,1,g);
    adicionarArestaMatriz(0,2,g);
    adicionarArestaMatriz(1,3,g);
    adicionarArestaMatriz(3,2,g);
    adicionarArestaMatriz(3,4,g);
	
	imprimirGrafo(g);
	
	transformaTransposto(g);
	
	imprimirGrafo(g);
		
    return 0;
}
