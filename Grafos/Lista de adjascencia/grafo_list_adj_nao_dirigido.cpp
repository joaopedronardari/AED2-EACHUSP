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

boolean existeAresta(int i, int j, VERTICE* g, NO** ant1, NO** ant2, NO** direction1, NO** direction2) {
	
	*direction1 = buscaArestaDirecao(i,j,g,ant1);
	*direction2 = buscaArestaDirecao(j,i,g,ant2);
	
	if (*direction1 && *direction2)
		return TRUE;
	
	return FALSE;
}

boolean excluirAresta(int i, int j, VERTICE* g) {
	NO* direction1 = NULL;
	NO* direction2 = NULL;
	NO* ant1 = NULL;
	NO* ant2 = NULL;
	
	if (!existeAresta(i,j,g,&ant1,&ant2,&direction1,&direction2))
		return FALSE;
	
	if (ant1) ant1->prox = direction1->prox;
	else g[i].inicio = direction1->prox;
	free(direction1);
	
	if (i != j) {
		if (ant2) ant2->prox = direction2->prox;
		else g[j].inicio = direction2->prox;
		free(direction2);
	}
	
	return TRUE;
}

boolean adicionarAresta(int i, int j, VERTICE* g) {
	NO* direction1 = NULL;
	NO* direction2 = NULL;
	NO* ant1 = NULL;
	NO* ant2 = NULL;
	
	if (existeAresta(i,j,g,&ant1,&ant2,&direction1,&direction2))
		return FALSE;
	
	// Aloca para direcao 1 e configura
	direction1 = (NO *) malloc(sizeof(NO));
	direction1->v = j;
	direction1->prox = g[i].inicio;
	g[i].inicio = direction1;
	
	if (i != j) {
		// Aloca para direcao 2 e configura
		direction2 = (NO *) malloc(sizeof(NO));
		direction2->v = i;
		direction2->prox = g[j].inicio;
		g[j].inicio = direction2;
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
