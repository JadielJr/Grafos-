#include "main.hpp"
using namespace std;

int main(void)
{
	//TODO: Fazer function em file.hpp pra ler arquivo
	Grafo* gr;
    //Ler arquivo
    ifstream arquivo("grafo.txt",ios_base::in); /*Ler arquivo*/
    string linha, strAux = "";
    int n, contaA=0; //Qnt de vértices, contador de Arestas

    if (arquivo.is_open())
    {
        string v1,v2;
        string sentidoV; // Esquerda-Direita,Direita-Esquerda ou ambos
        //Ler 1a linha, qnt de Vertices
        getline(arquivo,linha);
        //printf("%s\n",linha.c_str());
        int i;
        for(i=0;i<linha.size();i++)
        {
            strAux = "";/*reseta strAux*/
            if (isNum(linha[i]))
            {
                strAux += linha[i];/*Concatenação String*/
            }
            else
            {
                break;
            }
        }
        n =  atoi(strAux.c_str()); //QNT DE VERTICES
        gr = grafoCreate(n);
        printf("Qnt vertices:\t%i\n",n);

        //ler o restante do arquivo
        while(arquivo.good())
        {   /*PARA CADA ARESTA LIDA*/
            strAux = "";/*reseta strAux*/
            i=0;/*Reseta i*/
            getline(arquivo,linha);
            //printf("%s\n",linha.c_str());
            /*
            ///////////////////////////////////////////////////
            |LER ARESTA                                       |
            |                                                 |
            ///////////////////////////////////////////////////
            */
            /*OBTER Vertice V1*/
            for(i=i;i<linha.size();i++){
                if(isAlphaNum(linha[i]))
                    strAux += linha[i];
                else break;
            }
            v1 = strAux.c_str();
            strAux = "";/*Reseta strAux*/
            //printf("Vertice V1:%s\t",v1.c_str());

             /*OBTER Sentido da Aresta*/
            strAux+= linha[i];
            strAux+= linha[i+1];
            sentidoV = strAux.c_str(); /*Direção da aresta*/
            strAux = "";/*Reseta strAux*/
            //printf("SentidoV:'%s'\t",sentidoV.c_str());

            /*OBTER Vertice V2*/
            for(i+=2;i<linha.size();i++){
                if(isAlphaNum(linha[i]))
                    strAux += linha[i];
                else break;
            }
            v2 = strAux.c_str();
            strAux = "";/*Reseta strAux*/
            printf("Vertice V2:%s\n",v2.c_str());

            // TODO : Ponderada


            // TODO : Add arestas
            if (strcmp(">>",sentidoV.c_str())==0){
                /*DIRECIONADA U,V*/
            }else if (strcmp(">>",sentidoV.c_str())==0){
                /*DIRECIONADA V,U*/
            }else{
                /*As duas direcoes*/
            }

        }
        /*Após ler todas as arestas*/
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
