#include "main.hpp"
using namespace std;

int main(void)
{

	Grafo* gr;
    //Ler arquivo
    ifstream arquivo("grafo.txt",ios_base::in); /*Ler arquivo*/
    string linha, strAux = "";
    int n, contaA=0; //Qnt de vértices, contador de Arestas
    if (arquivo.is_open()){
        string v1,v2;
        //Ler 1a linha, qnt de Vertices
        getline(arquivo,linha);
        //printf("%s\n",linha.c_str());
        for(int i=0;i<linha.size();i++){
            if (isNum(linha[i])){
                strAux += linha[i];/*Concatenação String*/
            }else{
                break;
            }
        }
        n =  atoi(strAux.c_str()); //QNT DE VERTICES
        printf("Qnt vertices:\t%i\n",n);
        //ler N linhas, todos os vértices
        for(contaA;arquivo.good()&&contaA<n;contaA++){// PARA CADA LINHA
            strAux = "";/*reseta strAux*/
            getline(arquivo,linha);
            //printf("%s\n",linha.c_str());
            for(int i=0;i<linha.size();i++){
                if(isAlphaNum(linha[i]))
                    strAux += linha[i];
                else break;
            }
            v1 = strAux.c_str();
            printf("Aresta %i. Vertice V1\t:%s\n",contaA,v1.c_str());
            strAux = "";
            //FALTA TRATAR: Direcionada, V2, Ponderada, Add Aresta
        }
        arquivo.close();
        printf("Arquivo fechado.\n\n");
        cin.ignore();
        system("cls");

        //Ler as proximas N linhas
        /*
        criaAresta(gr,0,1,0);
        criaAresta(gr, 1, 2, 0);
        criaAresta(gr, 2, 0, 0);
        criaAresta(gr, 2, 4, 0);
        criaAresta(gr, 3, 1, 0);
        criaAresta(gr, 4, 3, 0);
        printGrafo(gr);
        */
    }

    /*
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

    */
	return EXIT_SUCCESS;
}
