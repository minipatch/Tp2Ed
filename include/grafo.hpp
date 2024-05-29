#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <iostream>
#include "ListaEncadeada.hpp"


class Grafo
{
    private:
        int Vertices;
        ListaEncadeada* listadj; 

    public:

        Grafo(int v);

        ~Grafo();

        void adicionaAresta(int v1,int v2,int peso);

        ListaEncadeada obterListaadj(int v)const;

        int obterNumeroV()const;

        void exibirGrafo();

};









#endif 