#ifndef FILA_PRIORIDADE_HPP
#define FILA_PRIORIDADE_HPP

#include <iostream>
#include <string>
#include <limits>

struct Elemento{
    int vertice;
    double distancia;
    int portais_usados;

    bool operator<(const Elemento& other) const {
        return distancia > other.distancia; // Inverte para obter fila de mínimos
    }
};

class Minheap{
    private:
        Elemento* heap;
        int _capacidade;
        int _tamanho;

        void heapifydown(int i);

        void heapifyUp(int i);
    
    public:

        Minheap(int capacidade);

        
        ~Minheap();

        void push(Elemento e);

        Elemento pop();

        bool vazio() const;
};








#endif