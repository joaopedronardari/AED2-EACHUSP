#include<stdio.h>
#include<malloc.h>
// V = 5 PARA DESCONSIDERAR O 0
#define V 5

#define TRUE 1
#define FALSE 0
typedef int boolean;

typedef struct s {
	s* prox;
	int v;
} NO;

typedef struct VERTICE {
	NO* inicio;
} VerticePointer;

/* GRAFO por lista de adj. nao-dirigido */

void inicializar(VERTICE* g) {
	int i;
	
	for (i=0;i<V;i++)
		g[i].inicio = NULL;
}

NO* buscaArestaDirecao(int i, int j, VERTICE* g, NO** ant) {
	*ant = NULL;
	NO* p = g[i].inicio;
	
	while (p) {
		if (p->v == j)
			return p;
		
		*ant = p;
		p = p->prox;
	}
	
	return NULL;
}

boolean existeAresta(int i, int j, VERTICE* g, NO** ant1, NO** ant2, NO** dir1, NO** dir2) {
	// Inicializa ponteiros
	*dir1 = NULL;
	*dir2 = NULL;
	*ant1 = NULL;
	*ant2 = NULL;
	
	// Busca nas duas direcoes
	*dir1 = buscaArestaDirecao(i,j,g,ant1);
	*dir2 = buscaArestaDirecao(j,i,g,ant2);
	
	if (*dir1 && *dir2)
		return TRUE;
	
	return FALSE;
}

boolean excluirAresta(int i, int j, VERTICE* g) {
	NO* dir1,dir2,ant1,ant2;
	
	if (!existeAresta(i,j,g,&ant1,&ant2,&dir1,&dir2))
		return FALSE;
	
	// Seta os ponteiros e libera da memoria direcao 1
	if (ant1) ant1->prox = dir1->prox;
	else g[i].inicio = dir1->prox;
	free(dir1);
	
	if (i != j) {
		// Seta os ponteiros e libera da memoria direcao 2
		if (ant2) ant2->prox = dir2->prox;
		else g[j].inicio = dir2->prox;
		free(dir2);
	}
	
	return TRUE;
}

boolean adicionarAresta(int i, int j, VERTICE* g) {
	NO* dir1,dir2,ant1,ant2;
	
	if (existeAresta(i,j,g,&ant1,&ant2,&dir1,&dir2))
		return FALSE;
	
	// Aloca para direcao 1 e configura
	dir1 = (NO *) malloc(sizeof(NO));
	dir1->v = j;
	dir1->prox = g[i].inicio;
	g[i].inicio = dir1;
	
	if (i != j) {
		// Aloca para direcao 2 e configura
		dir2 = (NO *) malloc(sizeof(NO));
		dir2->v = i;
		dir2->prox = g[j].inicio;
		g[j].inicio = dir2;
	}
}

void imprimirMatriz(VERTICE *g) {
	int i;
	
	printf("Imprimindo grafo...\n");
	
	for (i=1;i<V;i++) {
		printf("|");
		NO* p = g[i].inicio;
		while(p) {
			printf("%d|", p->v);
			p = p->prox;
		}
		printf("\n");
	}
}

int main() {
	VERTICE *g = (VERTICE *) malloc(sizeof(VERTICE) * (V));
	
	inicializar(g);
	
	imprimirMatriz(g);
	
	adicionarAresta(2,2,g);
	adicionarAresta(2,2,g);
	adicionarAresta(2,2,g);
	adicionarAresta(1,1,g);
	adicionarAresta(3,1,g);
	adicionarAresta(2,3,g);
	adicionarAresta(2,3,g);
	adicionarAresta(2,3,g);
	adicionarAresta(2,3,g);
	adicionarAresta(2,3,g);
	adicionarAresta(2,3,g);
	
	imprimirMatriz(g);
	excluirAresta(3,1,g);
	imprimirMatriz(g);
}
