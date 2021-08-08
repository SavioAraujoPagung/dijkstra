#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"

#define INFINITO 2147483647.0

DIJKSTRA *iniciar(int origem, int destino, int quantidadeCidade){
	DIJKSTRA *dijkstra = (DIJKSTRA*) malloc(sizeof(DIJKSTRA));
	dijkstra->origem = origem;
	dijkstra->destino = destino;
	
	dijkstra->distancia = (double*) malloc(sizeof(double)*quantidadeCidade);
	dijkstra->predecessor = (int*) malloc(sizeof(int)*quantidadeCidade);
	
	// DISTANCIA
	// 0 = é a origem.
	// 2147483647 = não foi rotulado
	// qualquer outro valoré uma distancia real
	
	//PREDECESSOR
	//-1 = não foi rotulado.
	//-2 = origem
	//qualquer outro valor é o id da cidade anterior
	
	int i;
	for(i=0; i<quantidadeCidade; i++){
		dijkstra->distancia[i] = INFINITO;
		dijkstra->predecessor[i] = -1;
	}
	
	dijkstra->distancia[dijkstra->origem] = 0;
	dijkstra->predecessor[dijkstra->origem] = -2;
	
	return dijkstra;
}

void exibirD(DIJKSTRA *dijkstra, int quantidadeCidade){
	int i;
	printf("Distancia: ");
	for(i=0; i<quantidadeCidade; i++){
		printf("|%.f", dijkstra->distancia[i]); 
	}
	printf("\n\n");
	printf("Predecessor: ");
	for(i=0; i<quantidadeCidade; i++){
		printf("|%d", dijkstra->predecessor[i]); 
	}
//	printf("\n\n");
	//system("pause");
}

int caminhoMinimo(DIJKSTRA *dijkstra, GRAFO *grafo){
	

	
	//index = id da cidade.
	//0 = nó não rotulado. VERMELHO
	//1 = último nó rotulado. AZUL
	//2 = nó rotulado. VERDE
	int *status = (int*) malloc(sizeof(int)*grafo->quantidadeCidade);
	int i;
	for(i=0; i<grafo->quantidadeCidade; i++){
		status[i] = 0; 
	}
	status[dijkstra->origem] = 1; 
	int azul = dijkstra->origem;
	
	while(status[dijkstra->destino]!=2){//enquanto o destino não for o ultimo no rotulado
		for(i=0; i<grafo->quantidadeCidade; i++){ //percorrendo as cidades que o AZUL faz ligação
			if((grafo->cidades[azul][i].distancia > 0)&&(status[i]==0)){ //verifica se realmente faz ligação e se a cidade não foi rotulada
				if((grafo->cidades[azul][i].distancia+dijkstra->distancia[azul]) < (dijkstra->distancia[i])){ //valida se 
					dijkstra->distancia[i] = dijkstra->distancia[azul] + grafo->cidades[azul][i].distancia;
					dijkstra->predecessor[i] = azul;
				}
			}
		}
		status[azul] = 2; //rotulando o nó, agora ele é VERDE
		int auxAzul = azul;
		int dist = INFINITO;
		for(i=0; i<grafo->quantidadeCidade; i++){//quem será o proximo rotulado
			if((dijkstra->distancia[i]<dist) && (status[i]!=2)){
				dist = dijkstra->distancia[i];
				azul = i;
			}				
		}
		
		if(azul != dijkstra->destino){
			status[azul] = 1;
		}
		
		if((auxAzul==azul)&&(status[dijkstra->destino]!=2)){
			printf("\n Não há caminho disponivel para ir de %s até %s\n", grafo->cidades[dijkstra->origem][dijkstra->origem].nome, grafo->cidades[dijkstra->destino][dijkstra->destino].nome);
			return 0;			
		}
	}
	
	int idAtual = dijkstra->destino;
	while(idAtual!=dijkstra->origem){
		printf("%s <- ", grafo->cidades[idAtual][idAtual].nome);
		idAtual = dijkstra->predecessor[idAtual];
	}
	
	printf("%s", grafo->cidades[idAtual][idAtual].nome);
	printf("\n");
	printf("Distancia total: %.2f\n\n\n", dijkstra->distancia[dijkstra->destino]);
	system("pause");
	return 1;
		
}














