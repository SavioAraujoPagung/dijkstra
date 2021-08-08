#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "dijkstra.h"
/*
Seu programa deve ent�o solicitar que o usu�rio informe o c�digo da cidade de origem e o
c�digo da cidade de destino.

c. Ent�o, seu programa deve calcular o menor caminho entre as duas cidades e exibir na tela
a dist�ncia total e o caminho (conjunto ordenado de n�s) a ser percorrido da origem ao
destino.

d. Por fim o programa deve questionar se o usu�rio deseja calcular um novo caminho. Se a
resposta for negativa, o programa deve encerrar. Se for positiva, deve voltar ao passo (b)
*/

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	GRAFO *grafo = (GRAFO*) malloc(sizeof(GRAFO));
	inicializar(grafo, "entradaExemplo.txt");
	
	int origem; //entrada do usuario
	int destino; //entrado do usuario
	int continuar = 1; //validar realizar busca
	while(continuar){
		do{
			system("CLS");
			exibir(grafo);
			printf("\nID CIDADE ORIGEM: ");
			scanf("%d", &origem);
			printf("\nID CIDADE DESTINO: ");
			scanf("%d", &destino);
		}while((origem<0||destino<0)||(origem>=grafo->quantidadeCidade||destino>=grafo->quantidadeCidade));
		system("cls");
		DIJKSTRA *dijkstra = iniciar(origem, destino, grafo->quantidadeCidade);
		caminhoMinimo(dijkstra, grafo);
		free(dijkstra);
		printf("\nCONTINUAR(0/1): ");
		scanf("%d", &continuar);
	}

	system("pause");
	return 0;
}
