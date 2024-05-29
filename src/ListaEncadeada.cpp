#include "ListaEncadeada.hpp"

ListaEncadeada::ListaEncadeada()
{
    cabeca = nullptr;
}


ListaEncadeada::~ListaEncadeada()
{
    while(cabeca){
        No* temp = cabeca;
        cabeca = cabeca->getProx();
        delete temp;
    }
}


void ListaEncadeada::adicionar(int destino)
{
    No* NovoNo =  new No();
    NovoNo->setcounteudo(destino);
    NovoNo->setProx(cabeca);
    cabeca = NovoNo;
}


No* ListaEncadeada::obterCabeca()
{
    return cabeca;
}