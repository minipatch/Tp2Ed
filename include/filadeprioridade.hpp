#ifndef FILADEPRIORIDADE_HPP
#define FILADEPRIORIDADE_HPP

#include <iostream>
#include <stdexcept>

struct Elemento{
    double distancia;
    int vertice;
};

class Fila{
    private:
        Elemento *heap;

        int _tamanho;

        int count;


        void heapifyUp(int idenx);

        void heapifyDown(int index);

    public:

        Fila(int tamanho);

        Fila();

        ~Fila();

        void restruturar();

        void insert(Elemento element);

        Elemento Limpa();

        bool Vazio();

        int getMin();


        
};




#endif