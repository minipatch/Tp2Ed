#include "no.hpp"


No::No(){}


std::string No::getClareira()
{
    return _clareira;
}

void No::setClareira(std::string Clareira)
{
    _clareira = Clareira;
}


void No::setProx(No* prox)
{
    _prox = prox;
}

No* No::getprox()
{
    return _prox;
}

void No::setProx(No* prox)
{
    _prox = prox;
}



