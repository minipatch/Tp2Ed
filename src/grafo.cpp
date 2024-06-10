#include "grafo.hpp"

Grafo::Grafo(int verticesmax)
{
    this->verticesMax =  verticesMax;


    matrizAdjacencia = new int*[verticesMax];

    for(int i=0;i<verticesMax;i++){
        matrizAdjacencia[i] = new int[verticesMax];
    }
}

Grafo::~Grafo(){
    for(int i=0;i<verticesMax;i++){
        delete[] matrizAdjacencia[i];
    }

    delete[]matrizAdjacencia;
}

void Grafo::addEdge(int u,int verticesmax,int weight)
{
    Edge* ed = new Edge(verticesMax,weight);

}   


