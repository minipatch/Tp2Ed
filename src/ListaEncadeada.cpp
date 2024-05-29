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


void ListaEncadeada::adicionar(int destino,int peso)
{
    No* NovoNo =  new No();
    NovoNo->setcounteudo(destino);
    NovoNo->setPeso(peso);
    NovoNo->setProx(cabeca);
    cabeca = NovoNo;
}



No* ListaEncadeada::obterCabeca()
{
    return cabeca;
}

void ListaEncadeada::print()
{
    No* temp = cabeca;

    while(temp)
    {
        std::cout<<"("<<temp->getdestino()<<")"<<std::endl; 
        temp = temp->getProx();
    }
    std::cout<<std::endl;
}


