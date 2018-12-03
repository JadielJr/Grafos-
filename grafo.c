#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"

/*
/////////////////////////////////////////////////////////////////
//  Fun��o que cria uma adjac�ncia  para ser inserida em uma   //
//	lista de adjac�ncias;                     				   //
//															   //
//	Par�metros da fun��o:									   //
//	-Vertice onde chega a aresta;                              //
//	-peso da aresta/ou zero, caso a aresta n�o seja ponderada; //
/////////////////////////////////////////////////////////////////
*/

Adj* criaAdj(int v, int peso)
{
    if( v>=0 )
    /*testando a validade do v�rtice*/
    {

        Adj* newAdj = (Adj* )malloc(sizeof(Adj));
        newAdj->vertice = v;
        newAdj->peso = peso;
        newAdj->prox = NULL;
        return newAdj;
    }
    else
    {
        return NULL;
    }
}

/*
////////////////////////////////////////////////////////////////////////////////////////////////////
//  Fun��o que cria uma aresta, ou seja ela insere na lista de adjac�ncias uma Adj retornada pela //
//  fun��o criaAjd;                                                                               //
//                                                                                                //
//  OBS:para criar um grafo n�o direcional basta chamar a fun��o duas vezes:a primeria            //
//  vez com VI indo pra VF e a segunda com VF indo pra VI;                                        //
////////////////////////////////////////////////////////////////////////////////////////////////////
*/

int criaAresta(Grafo* gr,int vi, int vf, int peso)
{
    if(gr==NULL)
    /*se o grafo n�o existir*/
    {
        return FALSE;
    }
    if((vf<0) || (vf>=gr->numVert))
    /*se o v�rtice final n�o existir*/
    {
        return FALSE;
    }
    if((vi<0) || (vi>=gr->numVert))
    /*se o v�rtice inicial n�o existir*/
    {
        return FALSE;
    }
    Adj* newAdj =criaAdj(vf,peso);
    newAdj->prox = gr->adj[vi].cab;
    gr->adj[vi].cab = newAdj;
    gr->numArestas++;
    return TRUE;
}

/*
/////////////////////////////////////////////////////////////
//  Fun��o que cria um grafo com v vertices e zero arestas;//
//                                                         //
/////////////////////////////////////////////////////////////
*/
Grafo* grafoCreate(int v)
{
    if(v>0)
    {
        Grafo* g = (Grafo* )malloc(sizeof(Grafo));
        g->numVert = v;
        g->numArestas = 0;
        g->adj = (Vert* )malloc(sizeof(Vert)*v);        /*Aloca��o do vetor de v�rtices;*/

        for(int i=0; i<v; i++)
        {
            g->adj[i].cab = NULL;     /*Preenchendo o vetor todo com NUlL;(Significa que n�o h� arestas ou v�rtices adjacentes);*/
            g->adj[i].dado = i;
        }
        return g;
    }
    else
    {
        return NULL;
    }
}

/*
//////////////////////////////////////////////////
//  Fun��o que mostra informa��es sobre o grafo;//
//                                              //
//////////////////////////////////////////////////
*/

void printGrafo(Grafo* gr)
{
    if(gr!=NULL)
    {
        printf("Informacoes do grafo:\nNumeros de vertices:%d;\nNumeros de arestas:%d;\n\nAdjacencias entre os vertices:\n",
               gr->numVert,gr->numArestas);
        for(int i = 0; i<gr->numVert; i++)
        {
            printf("V%d: ",i);
            Adj* aux = gr->adj[i].cab;
            while(aux)
            {
                printf("v%d(%d) ",aux->vertice,aux->peso);
                aux = aux->prox;
            }
            printf("\n");
        }
    }
}

/*
///////////////////////////////////////
//  Fun��o de visita em profundidade;//
//                                   //
//  Par�metros da fun��o:            //
//  -grafo;                          //
//	-�ndice do arranjo de v�rtices;  //
//  -arranjo de cores dos v�rtices;  //
//	-Chave da busca.                 //
///////////////////////////////////////
*/

int visita(Grafo* gr,int i,int* cor,int key)
{
    cor[i]= CINZA;
	int flag;
    Adj* v = gr->adj[i].cab;	/*vari�vel setada no inicio da lista de adjac�ncias para que ela possa interar essa lista;*/
	if(gr->adj[i].dado==key || v->vertice == key)	/*verificando o v�rtice para saber se a busca foi bem sucedida;*/
	{
		return TRUE;
	}
    while(v)
    {
        if(cor[v->vertice]==BRANCO)
        {
            flag = visita(gr,v->vertice,cor,key);
			if(flag)
			{
				return TRUE;
			}
		}
        v = v->prox;
    }
    cor[i] = PRETO;
	return FALSE;
}

/*
/////////////////////////////////////////////
//	Fun��o de busca em profundidade(DFS);  //
//                                         //
//  Par�metros da fun��o:                  //
//	-ponteiro para o grafo;				   //
//	-chave da busca;					   //
/////////////////////////////////////////////
*/

int profundidade(Grafo* gr, int key)
{
	int flag;
    int cor[gr->numVert];
    for(int i=0; i<gr->numVert; i++)
    {
        cor[i] = BRANCO;
    }
    for(int i=0; i<gr->numVert; i++)
    {
        if(cor[i]== BRANCO)
        {
            flag = visita(gr,i,cor,key);
			if(flag)
			{
				return TRUE;
			}
        }
    }
	return FALSE;
}
