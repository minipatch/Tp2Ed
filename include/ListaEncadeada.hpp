#ifndef LISTAENCADEADA_HPP
#define LISTAENCADEADA_HPP

#include "no.hpp"

class ListaEncadeada
{
    private:
        No* cabeca;

    public:
        ListaEncadeada();

        ~ListaEncadeada();


        void adicionar(int caminho,int peso);

        No* obterCabeca();

        void print();

};


#endif