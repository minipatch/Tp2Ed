#include "fila.hpp"


FilaAux::FilaAux(int tam){
    this->_tam = tam;

    this->_count = 0;

    this->_inicio = 0;

    this->_fin = 0;

    vetor =  new par[tam];
}

FilaAux::~FilaAux(){
    delete[] vetor;
}

bool FilaAux::isCheio(){
    return _count  == _tam;
}

void FilaAux::insert(double x,double y){
    if(isCheio()){
        std::cerr<<"a fila esta cheia"<<std::endl;
        
        return;
    }

    vetor[_count].x = x;
    vetor[_count].y = y;

    _fin = (_fin+1) % _tam;

    _count ++;
}


bool FilaAux::isVazio(){
    return _count == 0;
}


par FilaAux::remove(){
    if(isVazio()){
        std::cerr<<"a fila esta vazia"<< std::endl;
        return {-1,-1};
    }

    par aux;

    aux = vetor[_inicio];

    _inicio = (_inicio + 1) % _tam;

    _count -= 1;
    return aux;
}

