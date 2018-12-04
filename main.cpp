#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int cmp(void* a, void* b);

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


//Função que faz comparação entre dois elementos.
int cmp(void* a, void* b)
{
    int *pa;            //Variável que irá converte o tipo do dado para int*.
    int *pb;            //Variável que irá converte o tipo do dado para int*.
                        //Realizando a conversão.
    pa = (int*) a;
    pb = (int*) b;
    if(*pb == *pa){     //comparando os dados.
        return TRUE;    //retorna true se for igual.
    }
    else{
        return FALSE;   //retorna false se for diferente.
    }
}
