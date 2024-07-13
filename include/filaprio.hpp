#ifndef FILA_HPP
#define FILA_HPP

#include <iostream>
#include <limits>

namespace direct
{
    struct Elemento
    {
        int vertice;
        double distancia;
        double energia_restante;
        int portais_usados;
    };

    class Minheap
    {
    private:
        Elemento *heap;
        int _capacidade;
        int _tamanho;

        void heapifyDown(int i);
        

        void heapifyUp(int i);

    public:
        Minheap(int capacidade);

        ~Minheap();
        

        void push(const Elemento &e);
        

        Elemento pop();

        bool vazio() const;
        
    };

};

#endif