#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Grafo.h"

void inicializar(GRAFO *grafo, char url[]){
	char info[500];
	FILE *arq = fopen(url, "r");
	
	if(arq != NULL) {		
		fgets(info, 499, arq);
		char *arquivo = NULL;
		int i, j;
		int quantidade = atoi(info);
		grafo->quantidadeCidade = quantidade;
		
		//alocar matriz
		grafo->cidades = (CIDADE**) malloc(sizeof(CIDADE*)*quantidade);
		for(i=0; i<quantidade; i++){ 
			grafo->cidades[i] = (CIDADE*) malloc(sizeof(CIDADE)*quantidade);
		}	
		
		//pegar nomes
		for(i=0; i<quantidade; i++){
			fgets(info, 499, arq)!=NULL;
			arquivo = strtok(info, ";");		
			arquivo = strtok(NULL, "\n");
			strcpy(grafo->cidades[i][i].nome, arquivo);	
			//printf("|id: %d, nome: %s\n", i, grafo->cidades[i][i].nome);
		}
		
		//pegar distancias para outras cidades
		int auxQtd = quantidade-1;
		for(i=0; i<quantidade; i++){
			fgets(info, 499, arq);
			for (j=0; j<auxQtd; j++){
				if(j==0){						
					arquivo = strtok(info, ";");			
					grafo->cidades[i][j].distancia = atof(arquivo);
					j=j+1;
				}
				arquivo = strtok(NULL, ";");			
				grafo->cidades[i][j].distancia = atof(arquivo);
			}
			arquivo = strtok(NULL, "\n");			
			grafo->cidades[i][j].distancia = atoi(arquivo);
		}
	}else{
		printf("Erro, nao foi possivel abrir o arquivo\n");
	}
	fclose(arq);
}

void exibir(GRAFO *grafo){
	int quantidade = grafo->quantidadeCidade;
	if(grafo != NULL) {
		int i, j;
		for(i=0; i<quantidade; i++){
			printf("|id: %d, nome: %s\n", i, grafo->cidades[i][i].nome);
		}
		/*
		int auxQtd = quantidade;
		for(i=0; i<quantidade; i++){
			for (j=0; j<auxQtd; j++){
				if(j==0){						
					printf("|%.2f ", grafo->cidades[i][j].distancia);
					j=j+1;
				}
				printf("|%.2f ", grafo->cidades[i][j].distancia);
			}
			printf("\n");
		}
		*/
	}else{
		printf("Erro, não foi possivel abrir o arquivo\n");
	}
}








