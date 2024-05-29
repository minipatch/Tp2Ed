#include "no.hpp"


No::No()
{
    this->_prox = nullptr;
}


void No::setcounteudo(int caminho)
{
    _destino  = caminho;
}


void No::setProx(No* p){
    _prox = p;
}

int No::getdestino()
{
    return _destino;
}

No* No::getProx()
{
    return _prox;
}

int No::getPeso()
{
    return _peso;
}

void No::setPeso(int peso)
{
    _peso = peso;
}