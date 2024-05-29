#include "no.hpp"


No::No()
{
    this->prox = nullptr;
}


void No::setcounteudo(int caminho)
{
    destino  = caminho;
}


void No::setProx(No* p){
    prox = p;
}

int No::getdestino()
{
    return destino;
}

No* No::getProx()
{
    return prox;
}