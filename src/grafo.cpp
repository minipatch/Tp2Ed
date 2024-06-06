#include "grafo.hpp"


Grafo::Grafo(int Clareiras,int trilhas,int portal)
{
    this-> maxClareiras = Clareiras;
    this-> trilhas = trilhas;
    this-> portal = portal;
    this-> isportal = false;

    vetor = new No[maxClareiras]; 

    matrizAdjacente = new int *[maxClareiras];

    for(int i=0;i<maxClareiras;i++)
    {
        matrizAdjacente[i] = new int[maxClareiras];
    }
}

Grafo::~Grafo()
{
    delete[] vetor;

    for(int i=0;i<maxClareiras;i++){
        delete[] matrizAdjacente[i];
    }

    delete[] matrizAdjacente;
}

bool Grafo::getisPortal(int linha,int coluna){
    if(matrizAdjacente[linha][coluna] == 0){
        return true;
    }
    else if(matrizAdjacente[linha][coluna] > 0){
        return false;
    }
    else{
        return false;
    }
}

void Grafo::gerargrafo(int vertice,int peso)
{
    for(int i=0;i<maxClareiras;i++){
        for(int j=0;j<maxClareiras;j++){
            matrizAdjacente[i][j] = peso;
        }
    }
}
    




