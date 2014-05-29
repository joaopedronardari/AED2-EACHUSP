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

boolean verificaGrafoArvoreEnraizada(int g[V][V]) {
	int verticesUnico = 0;
	
	int i,z,j;
	
	for (i = 0; i< V; i++) {
		
		boolean noMark = TRUE;
		
		for (z=0; z<V; z++) {
			if (g[z][i] == 1) {
				noMark = FALSE;
				break;
			}
		}
		
		if (noMark)
			verticesUnico++;
	}
	
	printf("Vertices Unico %d", verticesUnico);
	
	if (verticesUnico == 1) return TRUE;
	return FALSE;
}

NO* existeAresta(int i, int j, VERTICE *g, NO** ant) {
	*ant = NULL;
	NO *p = g[i].inicio;

	while(p) {
		if (p->v == (j))
			return p;
		*ant = p;
		p = p->prox;
	}

	return NULL;
}

boolean adicionarAresta(int i, int j, VERTICE *g) {
	NO *ant;
	NO *p = existeAresta(i,j,g,&ant);

	if (p)
		return FALSE;

	NO *novoNo = (NO *) malloc(sizeof(NO));
	novoNo->v = j;
	novoNo->prox = g[i].inicio;
	g[i].inicio = novoNo;
	return TRUE;
}

void imprimir(VERTICE *g) {
	printf("imprimindo grafo...\n");

	int i;
	for (i = 1; i<V; i++) {
		printf("|");
		NO *p = g[i].inicio;

		while (p) {
			printf("%d|", p->v);
			p = p->prox;
		}

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

VERTICE* converterMatrizParaLista(int g[V][V]) {
    VERTICE* grafo = (VERTICE *) malloc(V * sizeof(VERTICE));

    int i,j;

    for (i=0; i<V; i++)
        for(j=0; j<V; j++) {
            if (g[i][j] == 1)
                adicionarAresta(i,j,grafo);
        }

    return grafo;
}

int main() {
    int g[V][V];

    inicializar(g);
	
	/* Test Error
	adicionarArestaMatriz(2,0,g);
	
    adicionarArestaMatriz(0,1,g);
    adicionarArestaMatriz(0,2,g);
    adicionarArestaMatriz(1,3,g);
    adicionarArestaMatriz(3,4,g);*/
    
    /* 
		TESTE 2
	*/
	adicionarArestaMatriz(0,1,g);
	adicionarArestaMatriz(0,2,g);
	adicionarArestaMatriz(3,1,g);
	adicionarArestaMatriz(3,4,g);
	
	verificaGrafoArvoreEnraizada(g);
    //VERTICE* grafo = converterMatrizParaLista(g);
    //imprimir(grafo);
    
    // TODO
    return 0;
}
