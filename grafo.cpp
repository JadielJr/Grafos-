#include "main.hpp"
using namespace std;

/*
/////////////////////////////////////////////////////////////////////
|  Função que cria uma adjacência  para ser inserida em uma         |
|	lista de adjacências;                     	            |
|					                            |
|	Parâmetros da função:				            |
|	-Vertice onde chega a aresta;                               |
|	-peso da aresta/ou zero, caso a aresta não seja ponderada;  |
/////////////////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////////////////////////////////////////////
|  Função que cria uma aresta, ou seja ela insere na lista de adjacências uma Adj retornada pela  |
|  função criaAjd;                                                                                |
|                                                                                                 |
|  OBS:para criar um grafo não direcional basta chamar a função duas vezes:a primeria             |
|  vez com VI indo pra VF e a segunda com VF indo pra VI;                                         |
///////////////////////////////////////////////////////////////////////////////////////////////////
*/

int criaAresta(Grafo* gr, int vi, int vf, int peso=1)
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
            g->adj[i].cab = NULL;     /*Preenchendo o vetor todo com NUlL;(Significa que não há arestas ou vértices adjacentes);*/
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
///////////////////////////////////////////
|  Função de busca em profundidade(DFS);  |
|                                         |
|  Parâmetros da função:                  |
|  -ponteiro para o grafo;                |
|  -chave da busca;                       |
///////////////////////////////////////////
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
