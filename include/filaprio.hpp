#ifndef FILA_HPP
#define FILA_HPP

#include <iostream>
#include <limits>

// Namespace para encapsular as definições e evitar conflitos de nomes.
namespace direct
{
    // Estrutura que representa um elemento na heap mínima.
    struct Elemento
    {
        int vertice;
        double distancia;
        double energia_restante;
        int portais_usados;
    };

    // Classe que implementa uma heap mínima (MinHeap).
    class Minheap
    {
    private:
        Elemento *heap;
        int _capacidade;
        int _tamanho;

        // Move um elemento para baixo na heap para restaurar a propriedade da heap mínima.
        void heapifyDown(int i);

        // Move um elemento para cima na heap para restaurar a propriedade da heap mínima.
        void heapifyUp(int i);

    public:
        Minheap(int capacidade);

        ~Minheap();

        // Adiciona um novo elemento à heap.
        void push(const Elemento &e);

        // Remove e retorna o elemento de menor valor da heap.
        Elemento pop();

        // Verifica se a heap está vazia.
        bool vazio() const;
    };

};

#endif