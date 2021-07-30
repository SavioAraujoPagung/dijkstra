#include <stdio.h>
#include <stdlib.h>

typedef struct Cidade{	
	char nome[30];
	double distancia;
}CIDADE;

typedef struct Grafo{	
	char nome[30];
	int quantidadeCidade;
	double distancia;
	CIDADE **cidades;
}GRAFO;

void inicializar(GRAFO *grafo, char url[]);

void exibir(GRAFO *grafo);
