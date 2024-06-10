#include "edge.hpp"


Edge::Edge(int peso,int dest){
    this->_prox = nullptr;
    this->_peso = peso;
    this->_dest = dest;
}



int Edge::getPeso(){
    return _peso;
}


int Edge::getDest(){
    return _dest;
}

Edge* Edge::getprox(){
    return _prox;
}

void Edge::setnext(Edge* n)
{
    _prox = n;
}

