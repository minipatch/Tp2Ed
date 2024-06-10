#ifndef FILA_HPP
#define FILA_HPP

#include "no.hpp"

class FilaP{
    private:
        NGFO::No* fila;

        int contador;
    
        int nomax;


    public:

        FilaP();

        FilaP(int max);


        ~FilaP();

        bool ischeio();

        void Heapifyup(int index);

        void Heapifydown(int index);


        void prioridade();

        NGFO::No top();

        void enfileira(NGFO::No item);

        void deseinfileira();
};





#endif