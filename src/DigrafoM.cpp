#include "DigrafoM.hpp"
#include <iostream>

DigrafoM::DigrafoM(int numVertices) {
    this->_numVertices = numVertices;

    matriz = new int*[_numVertices];
    for (int i = 0; i < _numVertices; i++) {
        matriz[i] = new int[_numVertices];
    }
}

DigrafoM::DigrafoM(){}

DigrafoM::~DigrafoM() {
    for (int i = 0; i < _numVertices; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

void DigrafoM::adicionaaresta(int origem, int destino, int peso) {
    if (origem >= 0 && origem < _numVertices && destino >= 0 && destino < _numVertices) {
        matriz[origem][destino] = peso;
    } else {
        std::cerr << "Erro: índice de vértice inválido" << std::endl;
    }
}

void DigrafoM::removearesta(int origem, int destino) {
    if (origem >= 0 && origem < _numVertices && destino >= 0 && destino < _numVertices) {
        matriz[origem][destino] = 0;
    } else {
        std::cerr << "Erro: índice de vértice inválido" << std::endl;
    }
}

bool DigrafoM::existearesta(int origem, int destino) {
    if (origem >= 0 && origem < _numVertices && destino >= 0 && destino < _numVertices) {
        return matriz[origem][destino] != 0;
    } else {
        std::cerr << "Índice inválido" << std::endl;
        return false;
    }
}

void DigrafoM::print() const {
    for (int i = 0; i < _numVertices; i++) {
        for (int j = 0; j < _numVertices; j++) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


void DigrafoM::ObterVizinhos(int vertice,int *vizinhos,int *pesos,int& count) const{
    count=0;
    for(int i=0;i<_numVertices;i++){
        if(matriz[vertice][i] != 0){
            vizinhos[count] = i;
            pesos[count] = matriz[vertice][i];
            count++;
        }
    }
}

int DigrafoM::getVertices() const{
    return _numVertices;
}