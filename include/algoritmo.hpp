#ifndef ALGORITMO_HPP
#define ALGORITMO_HPP

#include "DigrafoM.hpp"
#include "filadeprioridade.hpp"
#include <iostream>
#include <limits>

class Distrah{
    private:
        Fila _f;
        DigrafoM _grafo;

    public:
        Distrah();

        void alg(const DigrafoM& grafo,int origem,int destino);
        void imprimirCaminho(int destino,int* prev,int origem);
};






#endif