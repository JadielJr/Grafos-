#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"

/*
////////////////////////////////////////////////////////////////
|  Função que cria uma adjacência  para ser inserida em uma    |
|	lista de adjacências;                     				   |
|															   |
|	Parâmetros da função:									   |
|	-Vertice onde chega a aresta;                              | 
|	-peso da aresta/ou zero, caso a aresta não seja ponderada; |
////////////////////////////////////////////////////////////////
*/

Adj* criaAdj(int v, int peso)
{
    if( v>=0 )
    /*testando a validade do vértice*/
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
//////////////////////////////////////////////////////////////////////////////////////////////////
|  Função que cria uma aresta, ou seja ela insere na lista de adjacências uma Adj retornada pela |
|  função criaAjd;                                                                               |
|                                                                                                |
|  OBS:para criar um grafo não direcional basta chamar a função duas vezes:a primeria            |
|  vez com VI indo pra VF e a segunda com VF indo pra VI;                                        |
//////////////////////////////////////////////////////////////////////////////////////////////////
*/

int criaAresta(Grafo* gr,int vi, int vf, int peso)
{
    if(gr==NULL)
    /*se o grafo não existir*/
    {
        return FALSE;
    }
    if((vf<0) || (vf>=gr->numVert))
    /*se o vértice final não existir*/
    {
        return FALSE;
    }
    if((vi<0) || (vi>=gr->numVert))
    /*se o vértice inicial não existir*/
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
////////////////////////////////////////////////////////////
|  Função que cria um grafo com v vertices e zero arestas; |
|                                                          |
////////////////////////////////////////////////////////////
*/
Grafo* grafoCreate(int v)
{
    if(v>0)
    {
        Grafo* g = (Grafo* )malloc(sizeof(Grafo));
        g->numVert = v;
        g->numArestas = 0;
        g->adj = (Vert* )malloc(sizeof(Vert)*v);        /*Alocação do vetor de vértices;*/

        for(int i=0; i<v; i++)
        {
            g->adj[i].cab = NULL;     /*Preenchendo o vetor todo com NULL;(Significa que não há arestas ou vértices adjacentes);*/
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
/////////////////////////////////////////////////
|  Função que mostra informações sobre o grafo; |
|                                               |
/////////////////////////////////////////////////
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
//////////////////////////////////////
|  Função de visita em profundidade; |
|                                    |
|  Parâmetros da função:             | 
|  -grafo;                           |
|  -índice do arranjo de vértices;   |
|  -arranjo de cores dos vértices;   |
|  -Chave da busca.                  |
//////////////////////////////////////
*/

int visita(Grafo* gr,int i,int* cor,int key)
{	
    cor[i]= CINZA;
	int flag;
    Adj* v = gr->adj[i].cab;	/*variável setada no inicio da lista de adjacências para que ela possa interar essa lista;*/
	if(gr->adj[i].dado==key || v->vertice == key)	/*verificando o vértice para saber se a busca foi bem sucedida;*/
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
////////////////////////////////////////////
|	Função de busca em profundidade(DFS);  |
|                                          |
|   Parâmetros da função:                  |
|	-ponteiro para o grafo;				   |
|	-chave da busca;					   |
////////////////////////////////////////////
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


/*
///////////////////////////////////////////////////
|	Função que cria uma fila, inicialmente vazia. |
|                                                 |
///////////////////////////////////////////////////
*/

SlList *sllCreate()
{
    SlList* l = (SlList*)malloc(sizeof(SlList));        //L é a variável que irá apontar para o primeiro elemento da lista.
    if(l!=NULL){                                        //Testa se a alocação ocorreu.
        l->first = NULL;                                //Inicializa a fila varia.
        return l;
    }
    return NULL;
}

/*
/////////////////////////////////////////////////////////
|	Função Destroy, só destroi se a fila estiver vazia. |
|	                                                    |
/////////////////////////////////////////////////////////
*/

int sllDestroy(SlList* l)
{
    if(l->first == NULL){       //testa se a fila esta devidamente vazia.
        free(l);                //Desaloca a lista.
        return TRUE;
    }
    return FALSE;
}

/*
/////////////////////////////////////////////////////////////////////////
|	Função que insere um elemento dado pelo usuário em ultimo na lista. |
|																	    |
/////////////////////////////////////////////////////////////////////////
*/

int sllInsertLast(SlList* l,void* data)
{
    if(l!=NULL){
        SlNode* aux;                                            //Variável que percorre a lista até o final.
        SlNode* newnode = (SlNode*)malloc(sizeof(SlNode));      //Novo nó referente ao elemento que irá ser inserido.
        if(newnode!=NULL){                                      //Teste da alocação.
            newnode->data = data;                               //Novo nó aponta para o dado inserido.
            newnode->next = NULL;                               //Novo nó aponta para NULL, indicando o fim da lista.
            if(l->first!=NULL){                                 //se houver elementos na lista.
                aux=l->first;
                while(aux->next!=NULL){                         //Interação da lista vai até o final.
                    aux = aux->next;
                }                                               //neste ponto é garantido que aux está no último elemento da lista.
                aux->next = newnode;                            //O último elemento aponta para o novo nó que passa a ser o último da lista.
            }
            else{                                               //Se não houver elementos na lista.
                l->first = newnode;                             //O novo nó irá encabeçar a lista.
            }
            return TRUE;
        }

    }
    return FALSE;
}
/*
///////////////////////////////////////////////////
|	Função que remove o último elemento da lista; |
|	                                              |
///////////////////////////////////////////////////
*/

void* sllRemoveLast(SlList* l)
{
	if(l!=NULL && l->first!=NULL)
	{
		SlNode* cur = l->first;
		while(cur->next!=NULL)
		{
			cur = cur->next;
		}
		void* lixo = cur->data;
		free(cur);
		return lixo;
	}
	return NULL;
}

