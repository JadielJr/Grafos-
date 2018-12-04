#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#define TRUE 1
#define FALSE 0

#define BRANCO 0
#define CINZA 1
#define PRETO 2

/*
//////////////////////
| Estruturas do TAD; |
|                    |
//////////////////////
*/

/*Estrutura que será inserida em uma lista que fica dentro da classe vertice;*/
typedef struct _adjacencia{
	int vertice;	                /*vertice onde se chega;*/
	int peso;                       /*peso da aresta(Zero para aresta não ponderada);*/
	struct _adjacencia* prox;       /*poteiro para a próximo adjacencia da lista;*/
}Adj;

/*Estrutura vertice que será armazenada em um arranjo na estrutura grafo;*/
typedef struct _vertice{
    int dado;                       /*Identificaçõa do vertice;*/
    Adj* cab;                       /*Cabeça da lista de adjacências(Suas respectivas arestas);*/
}Vert;

/*Estrutura Grafo;*/
typedef struct _grafo{
	int numVert;					/*Números de vértices;*/
	int numArestas;					/*Números de arestas;*/
	Vert* adj;                      /*Arranjo de todos os vértices do grafo;*/
}Grafo;

/*Estrutura de nó da lista*/
typedef struct _slnode_{
    struct _slnode_ *next;
    void* data;
}SlNode;

typedef struct _sll_{
    SlNode *first;
}SlList;

/*
/////////////////////////
| Funções do TAD grafo; |
|                       |
/////////////////////////
*/

Adj* criaAdj(int v, int peso);
int criaAresta(Grafo* gr, int vi, int vf, int peso);
Grafo* grafoCreate(int v);
void printGrafo(Grafo* gr);
int visita(Grafo* gr, int u, int* cor,int key);
int profundidade(Grafo* gr,int key);
/*
///////////////
|	TAD lista |
|             |
///////////////
*/
SlList *sllCreate();
int sllDestroy(SlList* l);
int sllInsertLast(SlList* l,void* data);
void* sllRemoveLast(SlList* l);
void* sllRemoveFirst(SlList* l);
int sllInsertFirst(SlList* l,void* data);

#endif // GRAFO_H_INCLUDED

