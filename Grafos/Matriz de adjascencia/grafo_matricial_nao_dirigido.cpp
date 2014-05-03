#include<stdio.h>

#define V 4

#define TRUE 1
#define FALSE 0
typedef int boolean;

void inicializar(int g[V][V]) {
	int i,j;
	
	for (i=0;i<V;i++)
		for(j=0;j<V;j++)
			g[i][j] = 0;
}

boolean existeAresta(int i, int j, int g[V][V]) {
	if (g[i][j] == 1 && g[j][i] == 1)
		return TRUE;
	return FALSE;
}

boolean excluirAresta(int i, int j, int g[V][V]) {
	if (!existeAresta(i-1,j-1,g))
		return FALSE;
	
	g[i-1][j-1] = 0;
	g[j-1][i-1] = 0;
	return TRUE;
}

boolean adicionarAresta(int i, int j, int g[V][V]) {
	if (existeAresta(i-1,j-1,g))
		return FALSE;
		
	g[i-1][j-1] = 1;
	g[j-1][i-1] = 1;
	return TRUE;
}

void imprimirMatriz(int g[V][V]) {
	printf("imprimindo matriz... \n");
	
	int i,j;
	
	for (i=0;i<V;i++) {
		printf("|");
		
		for(j=0;j<V;j++)
			printf("%d|", g[i][j]);
		
		printf("\n");
	}
}

int main() {
	int g[V][V];
	inicializar(g);
	
	imprimirMatriz(g);
	adicionarAresta(3,3,g);
	adicionarAresta(1,2,g);
	adicionarAresta(3,4,g);
	imprimirMatriz(g);
	excluirAresta(1,2,g);
	imprimirMatriz(g);
}


