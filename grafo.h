#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#define TRUE 1
#define FALSE 0

#define BRANCO 0
#define CINZA 1
#define PRETO 2

/*
////////////////////////
//	Estruturas do TAD;//
////////////////////////
*/

/*Estrutura que ser� inserida em uma lista que fica dentro da classe vertice;8*/
typedef struct _adjacencia{
	int vertice;	                /*vertice onde se chega;*/
	int peso;                       /*peso da aresta(Zero para aresta n�o ponderada);*/
	struct _adjacencia* prox;       /*poteiro para a pr�ximo adjacencia da lista;*/
}Adj;

/*Estrutura vertice que ser� armazenada em um arranjo na estrutura grafo;*/
typedef struct _vertice{
    int dado;                       /*Identifica��a do vertice;*/
    Adj* cab;                       /*Cabe�a da lista de adjac�ncias(Suas respectivas arestas);*/
}Vert;

/*Estrutura Grafo;*/
typedef struct _grafo{
	int numVert;					/*N�meros de v�rtices;*/
	int numArestas;					/*N�meros de arestas;*/
	Vert* adj;                      /*Arranjo de todos os v�rtices do grafo;*/
}Grafo;

/*
/////////////////////
//	Fun��es do TAD;//
/////////////////////
*/

Adj* criaAdj(int v, int peso);
int criaAresta(Grafo* gr, int vi, int vf, int peso);
Grafo* grafoCreate(int v);
void printGrafo(Grafo* gr);
int visita(Grafo* gr, int u, int* cor,int key);
int profundidade(Grafo* gr,int key);

#endif /* GRAFO_H_INCLUDED*/

