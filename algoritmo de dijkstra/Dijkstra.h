#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

typedef struct Dijkstra{
	int origem;
	int destino;	
	double *distancia; //Menor distance entre o no de origem e cada um dos outros nos. valor incial 2147483647 
	int *predecessor; //O id da cidade anterios. Iniciar com -1 para não ter anterior. -2 para a origem.
}DIJKSTRA;

DIJKSTRA *iniciar(int origem, int destino, int quantidadeCidade);

void exibirD(DIJKSTRA *dijkstra, int quantidadeCidade);

void caminhoMinimo(DIJKSTRA *dijkstra, GRAFO *grafo);
