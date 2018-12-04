#include "main.hpp"
using namespace std;


int cmp(void* a, void* b);

int main(void) 
{

	//TODO: Fazer function em file.hpp pra ler arquivo
	Grafo* gr;
    //Ler arquivo
    ifstream arquivo("grafo.txt",ios_base::in); /*Ler arquivo*/
    string linha, strAux = "";
    int n; /*Qnt de vértices*/
    int flag; /*Sinaliza booleano das operações*/

    if (arquivo.is_open())
    {
        int v1,v2;
        string sentidoV; // Esquerda-Direita,Direita-Esquerda ou ambos
        //Ler 1a linha, qnt de Vertices
        getline(arquivo,linha);
        //printf("%s\n",linha.c_str());
        unsigned i=0; /*itera a array de caracteres (string) linha*/
        double peso = 0.00;

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
        //printf("Qnt vertices:\t%i\n",n);

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
            for(i=i;i<linha.size();i++)
            {
                if(isAlphaNum(linha[i]))
                {
                    strAux += linha[i];
                }
                else break;
            }
            v1 = atoi(strAux.c_str());
            strAux = "";/*Reseta strAux*/
            //printf("Vertice V1:%s\t",v1.c_str());

             /*OBTER Sentido da Aresta*/
            strAux+= linha[i];
            strAux+= linha[i+1];
            sentidoV = strAux.c_str(); /*Direção da aresta*/
            strAux = "";/*Reseta strAux*/
            //printf("SentidoV:'%s'\t",sentidoV.c_str());

            /*OBTER Vertice V2*/
            for(i+=2;i<linha.size();i++)
            {
                if(isAlphaNum(linha[i]))
                {
                    strAux += linha[i];
                }
                else break;
            }
            v2 = atoi(strAux.c_str());
            strAux = "";/*Reseta strAux*/
            //printf("Vertice V2:%s\n",v2.c_str());

            /*OBTER Peso da aresta*/
            if (i<linha.size()){ // se o index continua na linha
                for(i+=2;i<linha.size();i++)
                {
                    if(isNum(linha[i])||linha[i]=='.')
                    {
                        strAux+=linha[i];
                    }
                    else break;
                }
            }
            peso = atof(strAux.c_str());
            //printf("Peso :%.3f\n",peso);

            // TODO : Add arestas
            if (strcmp(">>",sentidoV.c_str())==0)
            {
                /*DIRECIONADA U,V*/
                flag = criaAresta(gr,v1,v2,peso);
                if(!flag) printf("Aresta (U,V) não criada corretamente.\n");
            }
            else if (strcmp(">>",sentidoV.c_str())==0)
            {
                /*DIRECIONADA V,U*/
                flag = criaAresta(gr,v2,v1,peso);
                if(!flag) printf("Aresta (V,U) não criada corretamente.\n");
            }
            else
            {
                /*As duas direcoes, mesmo peso*/
                flag = criaAresta(gr,v1,v2,peso);
                if(!flag) printf("Aresta (U,V) não criada corretamente.\n");
                flag = criaAresta(gr,v2,v1,peso);
                if(!flag) printf("Aresta (V,U) não criada corretamente.\n");
            }


        }
        /*Após ler todas as arestas*/
        arquivo.close();
        printf("Arquivo fechado.\n\n");
        cin.ignore();
        system("cls");

    }// Fecha arquivo
    else
    {
        printf("O arquivo não foi aberto corretamente.\n");
        cin.ignore();
        return EXIT_FAILURE;
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
    cin.ignore();
    system("cls");
	return EXIT_SUCCESS;

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
