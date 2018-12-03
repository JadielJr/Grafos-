#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(void)
{
	Grafo* gr = grafoCreate(5);
	criaAresta(gr,0,1,0);
	criaAresta(gr, 1, 2, 0);
	criaAresta(gr, 2, 0, 0);
	criaAresta(gr, 2, 4, 0);
	criaAresta(gr, 3, 1, 0);
	criaAresta(gr, 4, 3, 0);
	printGrafo(gr);

	for(int i=0; i<12;i++)
	{
		printf("Procurando o vertice v%d:\n",i);
		int aux = profundidade(gr, i);
		if(aux == TRUE)
		{
			printf("Vertice encontrado.\n\n");
		}
		else
		{
			printf("Vertice nao encontrado.\n\n");
		}
	}
}
