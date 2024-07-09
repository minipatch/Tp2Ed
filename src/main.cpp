#include <iostream>
#include <fstream>
#include <sstream>
#include "DigrafoM.hpp"
#include "DigrafoF.hpp"
#include <filadeprioridade.hpp>
#include <string>
#include <cmath>
#include <limits>

void dijkstra(DigrafoM &grafo,int origem,int fim){
    int n = grafo.getVertice();
    double** Matriz = grafo.getMatriz();

    //array de distancia e  visitados

    double* distancia = new double[n];
    bool* visitado = new bool[n];

    for(int i=0;i<n;i++){
        distancia[i] = std::numeric_limits<double>::infinity();
        visitado[i] = false;
    }

    // inicializa a distancia das vertices inicial para 0

    Fila fila(n);

    fila.insert({0,0});

    while(!fila.Vazio()){
        Elemento u = fila.Limpa();
        int vertice_u = u.vertice;

        if(visitado[vertice_u]){
            continue;
        }

        visitado[vertice_u] = true;

        for(int v=0;v<n;v++){
            double peso = Matriz[vertice_u][v];
            if(peso  != -1 && !visitado[v] && distancia[vertice_u] + peso < distancia[v]){
                distancia[v] =  distancia[vertice_u] + peso;
                fila.insert({distancia[v],v});
            }
        }
    }

    for(int i=0;i<n;i++){
        std::cout<<" a  distancia do vertice 0 para o vertice " << i <<": "<<distancia[i]<< std::endl;
    }

    delete[] distancia;
    delete[] visitado;
}



int main() {




    std::ifstream file("arquivo de leitura");

    if(!file.is_open()){
        std::cerr<<"não foi possivel abrir o arquivo "<<std::endl;
        return 1;
    }

    int n; // referente a vertices
    int m; // referente a aresta
    int k; // referente ao numero de portais

    // criando um grafo
    DigrafoM grafo(n);



    // fazendo a leitura da primeira linha 
    file>>n>>m>>k;


    // ler as posições do ponto no plano cartesiano


    for(int i=0;i<n;i++){
        double x,y;
        file>>x>>y;
        grafo.AdicionaPonto(i,x,y);
    }

    // inserindo as arestas no grafo

    for(int i=0;i<m;i++){
        int u;
        int v;
        file>>u>>v;
        grafo.AdicionaAresta(u,v);
    }


    // inserindo os portais no grafo
    for(int i=0;i<k;i++){
        int u;
        int v;
        file>>u>>v;
        grafo.AdicionaPortal(u,v);
    }

    // energia e  quantos portais podem ser ultilizados 
    double s;
    int q; 

    file>>s>>q;


    // passando para classe a quantidade de energia,qtd de portal
    grafo.setEnergia(s);
    grafo.setQtdPortal(q);

    grafo.print();


    

    return 0;
}
