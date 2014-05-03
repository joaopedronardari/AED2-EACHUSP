#include<stdio.h>
#include<malloc.h>

#define V 4

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

NO* existeAresta(int i, int j, VERTICE* g, NO* ant) {
	// TODO
}

boolean excluirAresta(int i, int j, VERTICE* g) {
	// TODO
	return FALSE;
}

boolean adicionarAresta(int i, int j, VERTICE* g) {
	// TODO
	return FALSE;
}

int main() {
	VERTICE *g = (VERTICE *) malloc(sizeof(VERTICE) * (V));
	
	
}
