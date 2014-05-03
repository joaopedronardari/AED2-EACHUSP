#include<stdio.h>
#include<malloc.h>

#define V 5

#define TRUE 0
#define FALSE 1
typedef int boolean;

/* Um array de listas cada posicao do array representa um vertice */

typedef struct s {
	s* prox;
	int v;
} NO;

typedef struct VERTICE {
	NO *inicio;
} VERTICEPOINTER;

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

boolean excluirAresta(int i, int j, VERTICE *g) {
	NO *ant;
	NO *p = existeAresta(i,j,g,&ant);
	
	if (!p)
		return FALSE;
	
	if (ant) ant->prox = p->prox;
	else g[i].inicio = p->prox;
	free(p);
	return TRUE;
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

void inicializar(VERTICE *g) {
	int i;
	for (i = 0; i< V; i++)
		g[i].inicio = NULL;
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

int grauEntradaVertice(int vertice, VERTICE *g) {
	int i;
	int grau = 0;
	
	for (i = 0; i<V; i++) {
		NO *p = g[i].inicio;
		
		while(p) {
			if (p->v == vertice) {
				grau++;
				break;
			}
			
			p = p->prox;
		}
	}
	
	return grau;
}

int grauSaidaVertice(int vertice, VERTICE *g) {
	NO *p = g[vertice-1].inicio;
	
	int grau = 0;
	
	while (p) {
		grau++;
		p = p->prox;
	}
	
	return grau;
}

int main() {
	VERTICE *g = (VERTICE *) malloc(sizeof(VERTICE) * (V));
	inicializar(g);
	
	imprimir(g);
	
	adicionarAresta(1,4,g);
	adicionarAresta(1,2,g);
	adicionarAresta(2,4,g);
	adicionarAresta(3,4,g);
	adicionarAresta(4,2,g);
	imprimir(g);
	
	excluirAresta(3,4,g);
	excluirAresta(2,4,g);
	imprimir(g);
	
	printf("Grau de saida do vertice 1 %d\n", grauSaidaVertice(1,g));
	printf("Grau de saida do vertice 3 %d\n", grauSaidaVertice(3,g));
	printf("Grau de entrada do vertice 4 %d\n", grauEntradaVertice(4,g));
	
}


