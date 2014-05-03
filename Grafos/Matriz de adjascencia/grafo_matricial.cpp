/**
*	exemplo de uso... matriz esparsa... grafo de matriz de adjascencia (WEB)
*/

#include<stdio.h>

#define V 4

typedef int boolean;
#define TRUE 1
#define FALSE 0

void inicializar(int g[V][V]) {
	// Inicializacao
	int i,j;
	
	for (i = 0; i < V; i++)
		for (j = 0; j< V; j++)
			g[i][j] = 0;
}

boolean existeAresta(int i, int j, int g[V][V]) {
	if (g[i][j] == 1) return TRUE;
	return FALSE;
}

boolean excluirAresta(int i, int j, int g[V][V]) {
	if (!existeAresta(i,j,g))
		return FALSE;
	
	g[i][j] = 0;
	return TRUE;
}

boolean adicionarAresta(int i, int j, int g[V][V]) {
	if (existeAresta(i,j,g))
		return FALSE;
		
	g[i][j] = 1;
	return TRUE;
}

int grauEntradaVertice(int vertice, int g[V][V]) {
	int i;
	int grau = 0;
	
	for (i = 0; i<V; i++)
		if (g[i][vertice-1] == 1)
			grau++;
	
	return grau;
}

int grauSaidaVertice(int vertice, int g[V][V]) {
	int j;
	int grau = 0;
	
	for (j = 0; j<V; j++)
		if (g[vertice-1][j] == 1)
			grau++;
	
	return grau;
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

int main() {
	//printf("Matriz por adjascencia");
	// Criacao desconsiderando posicao 0 - por isso V = 5
	int g[V][V];
	inicializar(g);
	imprimirGrafo(g);
	
	adicionarAresta(0,3,g);
	adicionarAresta(0,1,g);
	adicionarAresta(1,3,g);
	adicionarAresta(2,3,g);
	adicionarAresta(3,1,g);
	imprimirGrafo(g);
	
	excluirAresta(2,3,g);
	imprimirGrafo(g);
	
	printf("Grau de saida do vertice 1 %d\n", grauSaidaVertice(1,g));
	printf("Grau de saida do vertice 3 %d\n", grauSaidaVertice(3,g));
	printf("Grau de entrada do vertice 4 %d\n", grauEntradaVertice(4,g));
}
